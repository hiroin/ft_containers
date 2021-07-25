#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstring>
#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
#include "ft_enable_if.hpp"
#include "ft_is_integral.hpp"
#include "ft_equal.hpp"
#include "ft_lexicographical_compare.hpp"
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
    : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc_)
  {};
  vector( size_type size, const_reference value = value_type(),
    const allocator_type & alloc_ = allocator_type() )
    : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc_)
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
    : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(r.alloc_)
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

template <class T, class Alloc>
bool	operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
  return (lhs.size() == rhs.size()
    && equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template <class T, class Alloc>
bool	operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
  return lexicographical_compare(lhs.begin(), lhs.end(),
                                rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool	operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
  return !(lhs == rhs);
}

template <class T, class Alloc>
bool	operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
  return !(lhs > rhs);
}

template <class T, class Alloc>
bool	operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
  return lexicographical_compare(rhs.begin(), rhs.end(),
                                lhs.begin(), lhs.end());
}

template <class T, class Alloc>
bool	operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
  return !(lhs < rhs);
}

template < typename T, class Allocator >
void swap(vector<T, Allocator>& lhs, vector<T, Allocator>& rhs)
{
  lhs.swap(rhs);
}

typedef unsigned long Bit_type_;
# ifdef __MACH__
enum { S_word_bit_ = int(CHAR_BIT * sizeof(Bit_type_)) };
# else
enum { S_word_bit_ = int(__CHAR_BIT__ * sizeof(Bit_type_)) };
# endif
static size_t numPtrIndex_(size_t n)
{
  return (n / int(S_word_bit_));
}

struct BitReference_
{
  Bit_type_* ptr_;
  Bit_type_  index_;

  BitReference_(Bit_type_ * ptr, Bit_type_ index) : ptr_(ptr), index_(index) {}
  BitReference_() : ptr_(NULL), index_(0) {}
  // BitReference_(const BitReference_& x) : ptr_(x.ptr_), index_(x.index_) {}
  ~BitReference_(){};

  operator bool() const
  {
    return ptr_[numPtrIndex_(index_)] & (1ULL << index_ % S_word_bit_);
  }

  BitReference_& operator=(bool x)
  {
    if (x)
      ptr_[numPtrIndex_(index_)] |= (1ULL << index_ % S_word_bit_);
    else
      ptr_[numPtrIndex_(index_)] &= ~(1ULL << index_ % S_word_bit_);
    return *this;
  }

  BitReference_& operator=(const BitReference_& x)
  {
    return *this = bool(x);
  }

  bool operator==(const BitReference_& x) const
  {
    return bool(*this) == bool(x);
  }

  bool operator<(const BitReference_& x) const
  {
    return !bool(*this) && bool(x);
  }

  void flip()
  {
    ptr_[numPtrIndex_(index_)] ^= (1ULL << index_ % S_word_bit_);
  }

  void moveIndex_(std::ptrdiff_t x)
  {
    index_ += x;
  }
};

class bitIterator
{
 public:
  typedef bool value_type;
  typedef std::ptrdiff_t difference_type;
  typedef BitReference_* pointer;
  typedef BitReference_  reference;
  typedef bitIterator    iterator;
  // typedef random_access_iterator_tag iterator_category;

 private:
  BitReference_ ref_;

 public:
  bitIterator(){};
  bitIterator(Bit_type_* ptr, size_t index) : ref_(ptr, index){};
  // bitIterator(BitReference_& ref) : ref_(ref.ptr_, ref.index_){};
  // bitIterator(const BitReference_& ref) : ref_(){};
  // bitIterator(bitIterator& x) : ref_(x.ref_) {};
  bitIterator(const bitIterator& x) : ref_(x.ref_) {};
  ~bitIterator(){};

  iterator& operator=(const iterator& x)
  {
    if (this == &x)
      return *this;
    ref_.index_ = x.ref_.index_;
    ref_.ptr_ = x.ref_.ptr_;
    return *this;
  }

  reference operator *() const
  {
    return ref_;
  }

  iterator operator++()
  {
    ++(ref_.index_);
    return *this;
  }

  iterator operator++(int)
  {
    bitIterator tmp = *this;
    ++ref_.index_;
    return tmp;
  }

  iterator& operator--()
  {
    --(ref_.index_);
    return *this;
  }

  iterator operator--(int)
  {
    bitIterator tmp = *this;
    --ref_.index_;
    return tmp;
  }

  reference operator[](difference_type n) const
  {
    return BitReference_(ref_.ptr_, ref_.index_ + n);
  }

  iterator& operator+=(difference_type n)
  {
    ref_.index_ += n;
    return *this;
  }

  iterator operator+(difference_type n) const
  {
    bitIterator tmp = bitIterator(*this);
    tmp.ref_.index_ += n;
    return bitIterator(tmp);
  }

  iterator& operator-=(difference_type n)
  {
    ref_.index_ -= n;
    return *this;
  }

  iterator operator-(difference_type n)
  {
    bitIterator tmp = bitIterator(*this);
    tmp.ref_.index_ -= n;
    return bitIterator(tmp);
  }

  friend bool operator==(const iterator& lhs, const iterator& rhs)
  {
    return lhs.ref_.ptr_ == rhs.ref_.ptr_ && lhs.ref_.index_ == rhs.ref_.index_;
  }

  friend bool operator!=(const iterator& lhs, const iterator& rhs)
  {
    return !(lhs == rhs);
  }

  friend bool operator<(const iterator& lhs, const iterator& rhs)
  {
    return lhs.ref_.ptr_ < rhs.ref_.ptr_
      || (lhs.ref_.ptr_ == rhs.ref_.ptr_ && lhs.ref_.index_ == rhs.ref_.index_);
  }

  friend bool operator>(const iterator& lhs, const iterator& rhs)
  {
    return rhs < lhs;
  }

  friend bool operator<=(const iterator& lhs, const iterator& rhs)
  {
    return lhs < rhs || lhs == rhs;
  }

  friend bool operator>=(const iterator& lhs, const iterator& rhs)
  {
    return lhs > rhs || lhs == rhs;
  }

  friend iterator operator+(std::ptrdiff_t n, const iterator& x)
  {
    return x + n;
  }

  friend difference_type operator-(const iterator& lhs, const iterator& rhs)
  {
    return lhs.ref_.index_ - rhs.ref_.index_;
  }

  // 作っていないもの
  //  swap
};

class constBitIterator
{
 public:
  typedef bool value_type;
  typedef std::ptrdiff_t       difference_type;
  typedef BitReference_*       pointer;
  typedef const BitReference_  reference;
  typedef constBitIterator     iterator;
  // typedef random_access_iterator_tag iterator_category;

 private:
  BitReference_ ref_;

 public:
  constBitIterator(){};
  constBitIterator(Bit_type_* ptr, size_t index) : ref_(ptr, index){};
  constBitIterator(BitReference_& ref) : ref_(ref.ptr_, ref.index_){};
  // constBitIterator(const BitReference_& ref) : ref_(){};
  constBitIterator(const bitIterator& x) : ref_(*x) {};
  constBitIterator(const constBitIterator& x) : ref_(x.ref_) {};
  ~constBitIterator(){};

  iterator& operator=(const iterator& x)
  {
    if (this == &x)
      return *this;
    ref_.index_ = x.ref_.index_;
    ref_.ptr_ = x.ref_.ptr_;
    return *this;
  }

  reference operator *() const
  {
    return ref_;
  }

  iterator operator++()
  {
    ++(ref_.index_);
    return *this;
  }

  iterator operator++(int)
  {
    iterator tmp = *this;
    ++ref_.index_;
    return tmp;
  }

  iterator& operator--()
  {
    --(ref_.index_);
    return *this;
  }

  iterator operator--(int)
  {
    iterator tmp = *this;
    --ref_.index_;
    return tmp;
  }

  reference operator[](difference_type n) const
  {
    return BitReference_(ref_.ptr_, ref_.index_ + n);
  }

  iterator& operator+=(difference_type n)
  {
    ref_.index_ += n;
    return *this;
  }

  iterator operator+(difference_type n) const
  {
    iterator tmp = iterator(*this);
    tmp.ref_.index_ += n;
    return iterator(tmp);
  }

  iterator& operator-=(difference_type n)
  {
    ref_.index_ -= n;
    return *this;
  }

  iterator operator-(difference_type n)
  {
    iterator tmp = iterator(*this);
    tmp.ref_.index_ -= n;
    return iterator(tmp);
  }

  friend bool operator==(const iterator& lhs, const iterator& rhs)
  {
    return lhs.ref_.ptr_ == rhs.ref_.ptr_ && lhs.ref_.index_ == rhs.ref_.index_;
  }

  friend bool operator!=(const iterator& lhs, const iterator& rhs)
  {
    return !(lhs == rhs);
  }

  friend bool operator<(const iterator& lhs, const iterator& rhs)
  {
    return lhs.ref_.ptr_ < rhs.ref_.ptr_
      || (lhs.ref_.ptr_ == rhs.ref_.ptr_ && lhs.ref_.index_ == rhs.ref_.index_);
  }

  friend bool operator>(const iterator& lhs, const iterator& rhs)
  {
    return rhs < lhs;
  }

  friend bool operator<=(const iterator& lhs, const iterator& rhs)
  {
    return lhs < rhs || lhs == rhs;
  }

  friend bool operator>=(const iterator& lhs, const iterator& rhs)
  {
    return lhs > rhs || lhs == rhs;
  }

  friend iterator operator+(std::ptrdiff_t n, const iterator& x)
  {
    return x + n;
  }

  // 作っていないもの
  //  イテレーター同士の引き算
  //  swap
};

template < typename Allocator >
class vector<bool, Allocator>
{
 public :
  typedef bool                 value_type;
  typedef std::size_t          size_type;
  typedef std::ptrdiff_t       difference_type;
  typedef BitReference_        reference;
  typedef bool                 const_reference;
  typedef BitReference_*       pointer;       // 使わないのであればいい
  typedef const BitReference_* const_pointer; // 使わないのであればいい
  typedef bitIterator          iterator;
  typedef constBitIterator     const_iterator;
  typedef reverseIterator<iterator>        reverse_iterator;
  typedef reverseIterator<const_iterator>  const_reverse_iterator;
  typedef Allocator            allocator_type;

 private :
  typedef std::allocator<size_t>  storage_allocator_type;
  size_type* storage_;
  size_type  size_;
  size_type  storageSize_;
  allocator_type         alloc_;
  storage_allocator_type storageAlloc_; 

public :
  // コンストラクター
  vector(const allocator_type & alloc_ = allocator_type())
    : storage_(NULL), size_(0), storageSize_(0), alloc_(alloc_)
  {};

  vector(size_type size, value_type value = value_type(),
    const allocator_type & alloc_ = allocator_type())
    : storage_(NULL), size_(0), storageSize_(0), alloc_(alloc_)
  {
    resize(size, value);
  };

  template <typename InputIterator>
  vector(InputIterator first,
    typename ft_enable_if<!ft_is_integral<InputIterator>::value, InputIterator>::type last,
    const allocator_type & alloc_ = allocator_type())
    : storage_(NULL), size_(0), storageSize_(0), alloc_(alloc_)
  {
    size_ = getSizeFromIterator(first, last);
    reserve(size_);
    size_t i = 0;
    for (InputIterator itr = first; itr != last ; ++itr, ++i)
    {
      operator [](i) = *itr; 
    }
  }
  // デストラクター
  ~vector()
  {
    storageAlloc_.deallocate(storage_, storageSize_);
  };

  vector & operator =(const vector & r)
  {
    if (this == &r)
      return *this;
    assign(r.begin(), r.end());
    return *this ;
  }

  reference operator [](size_type i)
  {
    return reference(storage_, i);
  }

  const_reference operator [](size_type i) const
  {
    return reference(storage_, i);
  }

  reference at( size_type i )
  {
    if ( i >= size() )
      throw std::out_of_range( "vector" ) ;
    return reference(storage_, i);
  }

  const_reference at( size_type i ) const
  {
    if ( i >= size() )
      throw std::out_of_range( "vector" ) ;
    return reference(storage_, i);
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

  void push_back(bool x) 
  {
    if (size() + 1 > capacity())
    {
      size_type c = size();
      if (c == 0)
        c = 1 ;
      else
        c *= 2 ;
      reserve(c) ;
    }
    *end() = x;
    size_++;
  }

  void pop_back()
  {
    if (empty() == false)
    {
      size_--;
    }
  }

  iterator insert(iterator position, const bool& u)
  {
    if (position == iterator(NULL, 0))
    {
      assign(1, u);
      return begin();
    }
    else if
    (position == end())
    {
      push_back(u);
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
    }
    for (size_t i = 0; i < numOfMove; ++i)
    {
      operator [](size() - i) = operator [](size() - i - 1); 
    }
    operator [](index) = u;
    size_++;
    return iterator(storage_, index);
  }

  void insert(iterator position, size_type n, const bool& u)
  {
    if (position == iterator(NULL, 0))
    {
      assign(n, u);
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
    }
    for (size_t i = 0; i < numOfMove; ++i)
    {
      operator [](size() + n - i - 1) = operator [](size() - i - 1); 
    }
    for (size_t i = 0; i < n; ++i)
    {
      operator [](index + i) = u;
      size_++;
    }
  }

  template <class InputIterator>
  void insert(iterator position,
    typename ft_enable_if<!ft_is_integral<InputIterator>::value, InputIterator>::type first,
    InputIterator last)
  {
    if (position == iterator(NULL, 0))
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
    }
    for (size_t i = 0; i < numOfMove; ++i)
    {
      operator [](size() + n - i - 1) = operator [](size() - i - 1); 
    }
    for (size_t i = 0; i < n; ++i)
    {
      operator [](index + i) = *first++;
      size_++;
    }
  }

  iterator erase(iterator position)
  {
    for (iterator itr = position; itr != end() - 1; ++itr)
    {
      *itr = *(itr + 1);
    }
    size_--;
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
    size_ -= getSizeFromIterator(first, last);
    return firstPosition;
  }

  void clear()
  {
    size_ = 0;
  }

  void swap(vector& x)
  {
    size_type* storage = x.storage_;
    size_type  size = x.size_;
    size_type  storageSize = x.storageSize_;

    x.storage_ = this->storage_;
    x.size_ = this->size_;
    x.storageSize_ = this->storageSize_;
    this->storage_ = storage;
    this->size_ = size;
    this->storageSize_ = storageSize;
  }

  static void swap(reference x, reference y)
  {
    bool tmp = x;
    x = y;
    y = tmp;
  }

  void resize(size_type sz, value_type value = value_type())
  {
    // 現在の要素数より少ない
    if (sz < size())
    {
      erase(begin() + sz, end());
    }
    // 現在の要素数より大きい
    else if (sz > size())
    {
      size_type oldSize = size();
      if(sz > capacity())
      {
        if (sz < size() * 2)
          reserve(size() * 2);
        else
          reserve(sz);
      }
      size_t bit;
      if (value)
        bit = -1;
      else
        bit = 0;
      for (size_t i = oldSize; i < getNeedStrageSize(sz); ++i)
        storage_[i] = bit;
    }
    size_ = sz;
  }

  void reserve(size_type sz)
  {
    // すでに指定された要素数以上に予約されているなら何もしない
    if (sz <= capacity())
      return ;

    // 古いストレージの情報を保存
    size_type* oldStorage = storage_;
    size_type  oldStorageSize = storageSize_;

    // 動的メモリー確保をする
    // storageSize_ = sz / S_word_bit_ + 1;
    size_type* ptr = allocate(sz) ;

    // 新しいストレージに差し替え
    storage_ = ptr;

    // 古いストレージから新しいストレージに要素をコピー構築
    for (size_t i = 0; i < oldStorageSize; i++)
    {
      storage_[i] = oldStorage[i];
    }
    // ストレージを破棄する
    storageAlloc_.deallocate(oldStorage, oldStorageSize);
  }

  void assign(size_type n, const bool& u)
  {
    if (n == 0)
    {
      size_ = n;
      return;
    }
    // 予約数が不十分ならば
    if (capacity() < n)
    {
      if (n < size() * 2)
        reserve(size() * 2);
      else
        reserve(n);
    }
    size_t bit;
    if (u)
      bit = -1;
    else
      bit = 0;
    for (size_t i = 0; i < getNeedStrageSize(n); ++i)
      storage_[i] = bit;
    size_ = n;
  }

  template <typename InputIterator>
  void assign(InputIterator first,
    typename ft_enable_if<!ft_is_integral<InputIterator>::value,
                          InputIterator>::type last)
  {
    size_t n = getSizeFromIterator(first, last);
    if (n == 0)
    {
      size_ = n;
      return;
    }
    if (capacity() < n)
    {
      if (n < size() * 2)
        reserve(size() * 2);
      else
        reserve(n);      
    }
    size_t i = 0;
    for (InputIterator itr = first; itr != last ; ++itr, ++i)
    {
      operator [](i) = *itr; 
    }
    size_ = n;
  }

  void flip()
  {
    for (size_t i = 0; i < storageSize_; i++)
    {
      storage_[i] = ~storage_[i];
    }
  }

  size_type size() const
  {
    return size_;
  }

  size_type max_size() const
  {
    return (alloc_.max_size() / 2);
  }

  bool empty() const
  {
    return size() == 0;
  }

  size_type capacity() const
  {
    return storageSize_ * S_word_bit_ ;
  }

  allocator_type get_allocator() const
  {
    return alloc_;
  }

  // イテレーターアクセス
  iterator begin()
  {
    return iterator(storage_, 0);
  }
  iterator end()
  {
    return iterator(storage_, size_);
  }
  const_iterator begin() const
  {
    return const_iterator(storage_, 0);
  }
  const_iterator end() const
  {
    return const_iterator(storage_, size_);
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

  bool operator==(const vector& r)
  {
    if (this->size() != r.size())
      return false;  
    for (const_iterator cfirst = begin(), clast = end(), rfirst = r.begin();
      cfirst != clast; ++cfirst, ++rfirst)
    {
      if (*cfirst != *rfirst)
        return false;
    }
    return true;    
  }

  bool operator!=(const vector& r)
  {
    return !(*this == r);
  }

  bool operator<(const vector& r)
  {
    return lexicographical_compare(begin(), end(), r.begin(), r.end());
  }

  bool operator<=(const vector& r)
  {
    return !(*this > r);
  }
  bool operator>(const vector& r)
  {
    return lexicographical_compare(r.begin(), r.end(), begin(), end());
  }
  bool operator>=(const vector& r)
  {
    return !(*this < r);
  }

 private :
  size_type* allocate(size_type n)
  {
    if (n == 0)
    {
      storageSize_ = 0;
      return NULL;
    }
    storageSize_ = getNeedStrageSize(n);
    size_type* ptr = storageAlloc_.allocate(storageSize_);
    std::memset(ptr, 0, sizeof(size_type) * storageSize_);
    return ptr;
  }

  size_type getNeedStrageSize(size_type n)
  {
    return (n - 1) / S_word_bit_ + 1;
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


}; // namespace ft

#endif /* VECTOR_HPP */