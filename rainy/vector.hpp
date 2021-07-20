#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
#include "ft_enable_if.hpp"
#include "ft_is_integral.hpp"
#include "vectorIterator.hpp"
#include "vectorConstIterator.hpp"

namespace ft {

template < typename T, typename Allocator = std::allocator<T> >
class vector
{
 public :
  typedef T value_type;
  typedef T* pointer;
  typedef const pointer const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef std::ptrdiff_t difference_type;
  typedef vectorIterator<T> iterator;
  typedef vectorConstIterator<T> const_iterator;
  typedef reverseIterator<iterator> reverse_iterator;
  typedef reverseIterator<const_iterator> const_reverse_iterator;

private :
  // 先頭の要素へのポインター
  pointer first_;
  // 最後の要素の1つ前方のポインター
  pointer last_;
  // 確保したストレージの終端
  pointer reserved_last_;
  // アロケーターの値
  allocator_type alloc_;

public :
  // コンストラクター
  vector(const allocator_type & alloc_ = allocator_type())
    : alloc_(alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  {};
  vector( size_type size, const_reference value = value_type(), const allocator_type & alloc_ = allocator_type() )
    : alloc_(alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  {
    resize(size, value);
  }
  template <typename InputIterator>
  vector(InputIterator first,
    typename ft_enable_if<!ft_is_integral<InputIterator>::value, InputIterator>::type last, const Allocator & = Allocator())
    : first_(NULL), last_(NULL), reserved_last_(NULL)
  {
    reserve(getSizeFromIterator(first, last));
    for (InputIterator i = first; i != last ; i++)
    {
      push_back(*i);
    }
  }

  // デストラクター
  ~vector()
  {
    // 1. 要素を末尾から先頭に向かう順番で破棄
    clear();
    // 2. 生のメモリーを解放する
    deallocate();
  };

  // コピー
  vector(const vector & r)
    : alloc_(r.alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  {
    reserve(r.size());
    pointer dest = first_;
    for (const_iterator src = r.begin(), last_ = r.end();
      src != last_ ; ++dest, ++src)
    {
      construct(dest, *src);
    }
    last_ = first_ + r.size();
  }

  vector & operator =(const vector & r)
  {
    if (this == &r)
      return *this;
    assign(r.begin(), r.end());
    return *this ;
  }

  bool equal(iterator first, iterator last, const_iterator rfirst)
  {
    const_iterator cfirst = first;
    const_iterator clast = last;
    for (; cfirst != clast; ++cfirst, ++rfirst)
    {
      if (*cfirst != *rfirst)
        return false;
    }
    return true;
  }

  bool operator==(const vector<T, Allocator>& r)
  {
    return (this->size() == r.size()
      && equal(this->begin(), this->end(), r.begin()));
  }

  bool operator!=(const vector<T, Allocator>& r)
  {
    return !(*this == r);
  }

  bool operator<(const vector<T, Allocator>& r)
  {
    return lexicographical_compare(begin(), end(), r.begin(), r.end());
  }

  bool operator<=(const vector<T, Allocator>& r)
  {
    return !(*this > r);
  }

  bool operator>(const vector<T, Allocator>& r)
  {
    return lexicographical_compare(r.begin(), r.end(), begin(), end());
  }

  bool operator>=(const vector<T, Allocator>& r)
  {
    return !(*this < r);
  }

  iterator begin()
  {
    return iterator(first_);
  }

  iterator end()
  {
    return iterator(last_);
  }

  const_iterator begin() const
  {
    return const_iterator(first_);
  }

  const_iterator end() const
  {
    return const_iterator(last_);
  }

  reverse_iterator rbegin()
  {
    return reverse_iterator(end());
  }

  reverse_iterator rend()
  {
    return reverse_iterator(begin());
  }

  const_reverse_iterator rbegin() const
  {
    return const_reverse_iterator(end());
  }

  const_reverse_iterator rend() const
  {
    return const_reverse_iterator(begin());
  }

  size_type size() const
  {
    return end() - begin();
  }

  size_type max_size() const
  {
    return (alloc_.max_size());
  }

  bool empty() const
  {
    return begin() == end();
  }

  size_type capacity() const
  {
    return reserved_last_ - first_;
  }  

  reference operator [](size_type i)
  {
    return first_[i];
  }

  const_reference operator [](size_type i) const
  {
    return first_[i];
  }

  reference at( size_type i )
  {
    if ( i >= size() )
      throw std::out_of_range( "vector" ) ;
    return first_[i] ;
  }

  const_reference at( size_type i ) const
  {
    if ( i >= size() )
      throw std::out_of_range( "vector" ) ;
    return first_[i] ;
  }

  reference front()
  {
    return *begin();
  }

  const_reference front() const
  {
    return *begin();
  }

  reference back()
  {
    iterator tmp = end();
    --tmp;
    return *tmp;
  }

  const_reference back() const
  {
    const_iterator tmp = end();
    --tmp;
    return *tmp;
  }

  void reserve(size_type sz)
  {
    // すでに指定された要素数以上に予約されているなら何もしない
    if (sz <= capacity())
      return ;

    // 動的メモリー確保をする
    pointer ptr = allocate(sz) ;

    // 古いストレージの情報を保存
    pointer old_first_ = first_;
    pointer old_last_ = last_;
    size_type old_capacity = capacity();

    // 新しいストレージに差し替え
    first_ = ptr;
    last_ = first_;
    reserved_last_ = first_ + sz;

    // 古いストレージから新しいストレージに要素をコピー構築
    for (iterator old_iter = old_first_, old_end_ = old_last_;
      old_iter != old_end_; ++old_iter, ++last_)
    {
      construct(last_, *old_iter) ;
    }

    // 新しいストレージにコピーし終えたので
    // 古いストレージの値は破棄
    for (reverse_iterator riter = reverse_iterator(old_last_), rend = reverse_iterator(old_first_);
          riter != rend ; ++riter)
    {
      destroy(&*riter);
    }
    // ストレージを破棄する
    alloc_.deallocate(old_first_, old_capacity);
  }

  void resize(size_type sz, const_reference value = value_type())
  {
    // 現在の要素数より少ない
    if (sz < size())
    {
      size_type diff = size() - sz;
      destroy_until(rbegin() + diff) ;
      last_ = first_ + sz ;
    }
    // 現在の要素数より大きい
    else if ( sz > size() )
    {
      if (sz < size() * 2)
        reserve(size() * 2);
      else
        reserve(sz);
      for (size_t i = 0; sz - size(); ++i, ++last_)
      {
        construct(last_, value);
      }
    }
  }

  void push_back(const_reference value) 
  {
    // 予約メモリーが足りなければ拡張
    if (size() + 1 > capacity())
    {
      // 現在のストレージサイズ
      size_type c = size();
      // 0の場合は1に
      if (c == 0)
        c = 1 ;
      else
      // それ以外の場合は2倍する
        c *= 2 ;
      reserve(c) ;
    }
    construct(last_, value);
    ++last_;
  }

  template <class InputIterator>
  void assign(InputIterator first,
    typename ft_enable_if<!ft_is_integral<InputIterator>::value, InputIterator>::type last)
  {
    size_t n = getSizeFromIterator(first, last);
    if (size() == n)
    {
      for (iterator dest_iter = begin();
        first != last; ++first, ++dest_iter)
      {
        *dest_iter = *first;
      }
    }
    else
    {
      if (capacity() >= n)
      {
        iterator dest_iter;
        iterator dest_end;
        for (dest_iter = begin() + n, dest_end = end();
          dest_iter != dest_end; ++dest_iter)
        {
          destroy(&*dest_iter);
        }
        if (size() >= n)
        {
          last_ = first_;
          for (dest_iter = begin(); first != last;
            ++first, ++dest_iter, last_++)
          {
            *dest_iter = *first;
          }
        }
        else
        {
          last_ = first_;
          for (dest_iter = begin(); dest_iter != dest_end;
            ++first, ++dest_iter, last_++)
          {
            *dest_iter = *first;
          }
          for ( ; first != last; ++first, ++dest_iter, ++last_)
          {
            construct(&*dest_iter, *first);
          }
        }
      }
      else
      {
        clear();
        reserve(n);
        for (iterator dest_iter = begin(); first != last;
          ++first, ++dest_iter, ++last_)
        {
          construct(&*dest_iter, *first);
        }
      }
    }
  }

  void assign(size_type n, const T& u)
  {
    if (size() == n)
    {
      iterator dest_iter = begin();
      for (size_t i = 0; i < n; ++i)
      {
        *dest_iter++ = u;
      }
    }
    else
    {
      if (capacity() >= n)
      {
        iterator dest_iter;
        iterator dest_end;
        for (dest_iter = begin() + n, dest_end = end();
          dest_iter != dest_end; ++dest_iter)
        {
          destroy(&*dest_iter);
        }
        if (size() >= n)
        {
          last_ = first_;
          dest_iter = begin();
          for (size_t i = 0; i < n; ++i, ++last_)
          {
            *dest_iter++ = u;
          }
        }
        else
        {
          last_ = first_;
          size_t i = 0;
          for (dest_iter = begin(); dest_iter != dest_end;
            ++dest_iter, ++last_, ++i)
          {
            *dest_iter = u;
          }
          for ( ; i < n; ++dest_iter, ++last_)
          {
            construct(&*dest_iter, u);
          }
        }
      }
      else
      {
        clear();
        reserve(n);
        iterator dest_iter = begin();
        for (size_t i = 0; i < n; ++i, ++last_, ++dest_iter)
        {
          construct(&*dest_iter, u);
        }
      }
    }
  }

  void pop_back()
  {
    if (empty() == false)
    {
      last_--;
      destroy(last_);
    }
  }

  iterator insert(iterator position, const T& x)
  {
    if (position == iterator(NULL))
    {
      assign(1, x);
      return begin();
    }
    else if
    (position == end())
    {
      push_back(x);
      return end() - 1;
    }
    const size_type index = position - begin();
    const size_type numOfMove = end() - position;
    if (size() + 1 > capacity())
    {
      size_type c = size();
      if (c == 0)
          c = 1 ;
      else
          c *= 2 ;
      reserve(c) ;
      for (size_t i = 0; i < numOfMove; ++i)
      {
        // *(end() - i) = *(end() - i - 1);
        construct((end() - i).ptr_, *(end() - i - 1));
        destroy((end() - i - 1).ptr_);
      }
      // destroy(&first_[index]);
      construct(&first_[index], x);
    }
    else
    {
      construct(&*end(), *(end() - 1));
      for (size_t i = 0; i < numOfMove; ++i)
      {
        *(end() - i) = *(end() - i - 1);
      }
      first_[index] = x;
    }
    last_++;
    return iterator(&first_[index]);
  }

  void insert(iterator position, size_type n, const T& x)
  {
    if (position == iterator(NULL))
    {
      assign(n, x);
      return;
    }
    size_type index = position - begin();
    size_type numOfMove = end() - position;
    if (size() + n > capacity())
    {
      size_type c = size();
      if (c == 0)
        c = n ;
      else if(size() + n < c * 2)
        c *= 2;
      else
        c = size() + n;
      reserve(c) ;
      for (size_t i = 0; i < numOfMove; ++i)
      {
        // *(end() + n - 1 - i) = *(end() - 1 - i);
        construct(&*(end() + n - 1 - i), *(end() - i - 1));
        destroy(&*(end() - i - 1));        
      }
      for (size_t i = 0; i < n; ++i)
      {
        construct(&first_[index++], x);
        // first_[index++] = x;
        last_++;
      }
    }
    else
    {
      for (size_t i = 0; i < numOfMove; ++i)
      {
        if ((end() + n - 1 - i) >= end())
          construct(&*(end() + n - 1 - i), *(end() - 1 - i));
        else
          *(end() + n - 1 - i) = *(end() - 1 - i);
      }
      iterator oldEnd = end();
      for (size_t i = 0; i < n; ++i)
      {
        if (begin() + index >= oldEnd)
          construct(&first_[index++], x);
        else
          first_[index++] = x;
        last_++;
      }
    }
  }

  template <class InputIterator>
  void insert(iterator position,
    typename ft_enable_if<!ft_is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
  {
    if (position == iterator(NULL))
    {
      assign(first, last);
      return;
    }
    size_type index = position - begin();
    size_type numOfMove = end() - position;
    size_type n = getSizeFromIterator(first, last);
    if (size() + n > capacity())
    {
      size_type c = size();
      if (c == 0)
        c = n ;
      else if(size() + n < c * 2)
        c *= 2;
      else
        c = size() + n;
      reserve(c) ;

      for (size_t i = 0; i < numOfMove; ++i)
      {
        // *(end() - i) = *(end() - i - 1);
        construct(&*(end() + n - 1 - i), *(end() - i - 1));
        destroy(&*(end() - i - 1));
      }
      for (size_t i = 0; i < n; ++i)
      {
        construct(&first_[index++], *first++);
        // first_[index++] = *first;
        last_++;
      }      
    }
    else
    {
      for (size_t i = 0; i < numOfMove; ++i)
      {
        *(end() + n - 1 - i) = *(end() - 1 - i);
      }
      for (size_t i = 0; i < n; ++i)
      {
        construct(&first_[index++], *first++);
        // first_[index++] = *first;
        // first++;
        last_++;
      }
    }
  }

  iterator erase(iterator position)
  {
    for (iterator itr = position; itr != end() - 1; ++itr)
    {
      *itr = *(itr + 1);
    }
    last_--;
    destroy(last_);
    return position;
  }

  iterator erase(iterator first, iterator last)
  {
    iterator firstPosition = first;
    size_type n = end() - last;
    for (size_t i = 0; i < n; ++i)
    {
      *first++ = *last++;
    }
    // last_ -= last - first;
    for (size_t i = 0; i < getSizeFromIterator(first, last); ++i)
    {
      last_--;
      destroy(last_);
    }
    return firstPosition;
  }

  void swap(vector& x)
  {
    pointer first = x.first_;
    pointer last = x.last_;
    pointer reserved_last = x.reserved_last_;

    x.first_ = this->first_;
    x.last_ = this->last_;
    x.reserved_last_ = this->reserved_last_;
    this->first_ = first;
    this->last_ = last;
    this->reserved_last_ = reserved_last;
  }

  allocator_type get_allocator() const
  {
    return alloc_;
  }

  void clear()
  {
    destroy_until(rend());
  }

 private :
  pointer allocate(size_type n)
  {
    // return traits::allocate(alloc_, n);
    return alloc_.allocate(n);
  }

  void deallocate()
  {
    if (capacity() > 0)
      // traits::deallocate(alloc_, first_, capacity());
      alloc_.deallocate(first_, capacity());
  }

  void construct(pointer ptr)
  {
    alloc_.construct(ptr, value_type());
  }

  void construct(pointer ptr, const_reference value)
  {
    alloc_.construct(ptr, value);
  }

  void destroy(pointer ptr)
  {
    alloc_.destroy(ptr);
   }

  void destroy_until(reverse_iterator rend)
  {
    for (reverse_iterator riter = rbegin(); riter != rend; ++riter, --last_)
    {
      destroy( &*riter );
    }
  }

  template <class InputIterator>
  size_t getSizeFromIterator(InputIterator first, InputIterator last)
  {
    InputIterator iter = first;
    size_type n = 0;
    while (iter != last)
    {
      ++iter;
      ++n;
    }
    return n;
  }
};

template < typename T, class Allocator >
void swap(vector<T, Allocator>& lhs, vector<T, Allocator>& rhs)
{
  lhs.swap(rhs);
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(
        InputIterator1 first1,
        InputIterator1 last1,
        InputIterator2 first2,
        InputIterator2 last2)
{
  for ( ; first1 != last1 && first2 != last2 ; ++first1, ++first2)
  {
    if (*first1 < *first2) return true;
    if (*first2 < *first1) return false;
  }
  return first1 == last1 && first2 != last2;
}

template<class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1,
           InputIterator2 first2) {
  for ( ; first1 != last1; ++first1, ++first2)
    if (!bool(*first1 == *first2))
      return false;
  return true;
}

template<class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1,
           InputIterator2 first2, BinaryPredicate pred) {
  for ( ; first1 != last1; ++first1, ++first2)
    if (!bool(pred(*first1, *first2)))
      return false;
  return true;
}

}; // namespace ft

#endif /* VECTOR_HPP */