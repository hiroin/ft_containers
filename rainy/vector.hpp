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
  // typedef pointer iterator;
  typedef vectorIterator<T> iterator;
  // typedef const_pointer const_iterator;
  typedef vectorConstIterator<T> const_iterator;
  // typedef std::reverse_iterator<pointer> reverse_iterator;
  typedef reverseIterator<iterator> reverse_iterator;
  // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
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
  // vector( size_type size, const allocator_type & alloc_ = allocator_type() )
  //   : alloc_(alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  // {
  //   resize(size);
  // }
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
    // コピー元の要素数を保持できるだけのストレージを確保
    reserve(r.size());
    // コピー元の要素をコピー構築
    // destはコピー先
    // [src, last_)はコピー元
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
    // 1. 自分自身への代入なら何もしない
    if (this == &r)
      return *this;
  
    // 2. 要素数が同じならば
    if (size() == r.size())
    {   // 要素ごとにコピー代入
      // std::copy(r.begin(), r.end(), begin()) ;
      iterator dest_iter = begin();
      for (const_iterator src_iter = r.begin(), src_end = r.end();
        src_iter != src_end; ++src_iter, ++dest_iter)
      {
        *dest_iter = *src_iter;
      }      
    }
    // 3. それ以外の場合で
    else 
      // 予約数が十分ならば、
      if (capacity() >= r.size())
      {
        iterator dest_iter;
        iterator dest_end = end();
        const_iterator src_iter;
        const_iterator src_end = r.end();
        for (dest_iter = begin() + r.size(), dest_end = end();
          dest_iter != dest_end;
          ++dest_iter)
        {
          destroy(&*dest_iter);
        }
        if (size() >= r.size())
        {
          last_ = first_;
          for (src_iter = r.begin(), dest_iter = begin();
            src_iter != src_end;
            ++src_iter, ++dest_iter, last_++)
          {
            *dest_iter = *src_iter;
          }
        }
        else
        {
          last_ = first_;
          for (src_iter = r.begin(), dest_iter = begin();
            dest_iter != dest_end;
            ++src_iter, ++dest_iter, last_++)
          {
            *dest_iter = *src_iter;
          }
          for (src_end = r.end();
            src_iter != src_end;
            ++src_iter, ++dest_iter, ++last_)
          {
            construct(&*dest_iter, *src_iter);
          }
        }
        // clear();
        // iterator dest_iter = begin();
        // for (const_iterator src_iter = r.begin(), src_end = r.end();
        //   src_iter != src_end; ++src_iter, ++dest_iter, ++last_)
        // {
        //   construct(&*dest_iter, *src_iter);
        // }
      }
      // 4. 予約数が不十分ならば
      else
      {
        // 要素をすべて破棄
        // destroy_all();
        clear();
        // 予約
        reserve(r.size());
        // コピー構築
        iterator dest_iter = begin();
        for (const_iterator src_iter = r.begin(), src_end = r.end();
          src_iter != src_end; ++src_iter, ++dest_iter, ++last_)
        {
          construct(&*dest_iter, *src_iter);
        }
      }
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

  // イテレーターアクセス
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
    // return size() == 0;
    return begin() == end();
  }
  size_type capacity() const
  {
    return reserved_last_ - first_;
  }  

  // 要素アクセス
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
    // return last_ - 1;

  }
  const_reference back() const
  {
    const_iterator tmp = end();
    --tmp;
    return *tmp;
    // return last_ - 1;
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

    // 例外安全のため
    // 関数を抜けるときに古いストレージを破棄する
    // C++20の機能
    // std::scope_exit e( [&]{
    //   traits::deallocate(alloc_, old_first_, old_capacity);
    // } );

    // 古いストレージから新しいストレージに要素をコピー構築
    for (iterator old_iter = old_first_, old_end_ = old_last_;
      old_iter != old_end_; ++old_iter, ++last_)
    {
      // construct(last_, std::move(*old_iter)) ;
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

  // void resize(size_type sz)
  // {
  //   // 現在の要素数より少ない
  //   if (sz < size())
  //   {
  //     size_type diff = size() - sz;
  //     destroy_until(rbegin() + diff) ;
  //     last_ = first_ + sz ;
  //   }
  //   // 現在の要素数より大きい
  //   else if ( sz > size() )
  //   {
  //     reserve(sz) ;
  //     for (; last_ != reserved_last_ ; ++last_)
  //     {
  //       construct(last_);
  //     }
  //   }
  // }

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
      // insertの処理と一緒 ( https://cpprefjp.github.io/reference/vector/vector/resize.html )
      if (sz < size() * 2)
        reserve(size() * 2);
      else
        reserve(sz);
      for (size_t i = 0; sz - size(); ++i, ++last_)
      {
        construct(last_, value);
      }
      // for (; last_ != reserved_last_ ; ++last_)
      // {
      //   construct(last_, value);
      // }
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
    vector<T> tmp(first, last);
    *this = tmp;
  }

  void assign(size_type n, const T& u)
  {
    vector<T> tmp(n, u);
    *this = tmp;
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
  // この関数いるのかな…
  void construct(pointer ptr)
  {
    // traits::construct(alloc_, ptr);
    alloc_.construct(ptr, value_type());
  }
  void construct(pointer ptr, const_reference value)
  {
    // traits::construct(alloc_, ptr, value);
    alloc_.construct(ptr, value);
  }
  // ムーブ用
  // c++11の機能
  // void construct(pointer ptr, value_type && value)
  // {
  //   traits::construct(alloc_, ptr, std::move(value));
  // }
  void destroy(pointer ptr)
  {
    // traits::destroy(alloc_, ptr);
    alloc_.destroy(ptr);
   }
  void destroy_until(reverse_iterator rend)
  {
    for (reverse_iterator riter = rbegin(); riter != rend; ++riter, --last_)
    {
      // 簡易vector<T>のiteratorは単なるT *だが、
      // riterはリバースイテレーターなのでポインターではない。
      // ポインターを取るために*riterでまずT &を得て、
      // そこに&を適用することでT *を得ている。
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

typedef unsigned long _Bit_type;
# ifdef __MACH__
enum { _S_word_bit = int(CHAR_BIT * sizeof(_Bit_type)) };
# else
enum { _S_word_bit = int(__CHAR_BIT__ * sizeof(_Bit_type)) };
# endif

static size_t _S_nword(size_t __n)
{
  return (__n + int(_S_word_bit) - 1) / int(_S_word_bit);
}

struct _Bit_reference
{
  _Bit_type * _M_p;
  _Bit_type _M_mask;

  _Bit_reference(_Bit_type * __x, _Bit_type __y) : _M_p(__x), _M_mask(__y) {}
  _Bit_reference() : _M_p(0), _M_mask(0) {}

  operator bool() const
  {
    return !!(*_M_p & _M_mask);
  }

  _Bit_reference& operator=(bool __x)
  {
    if (__x)
      *_M_p |= _M_mask;
    else
      *_M_p &= ~_M_mask;
    return *this;
  }

  _Bit_reference& operator=(const _Bit_reference& __x)
  {
    return *this = bool(__x);
  }

  bool operator==(const _Bit_reference& __x) const
  {
    return bool(*this) == bool(__x);
  }

  bool operator<(const _Bit_reference& __x) const
  {
    return !bool(*this) && bool(__x);
  }

  void flip()
  {
    *_M_p ^= _M_mask;
  }
};

struct _Bit_iterator_base
{
  _Bit_type * _M_p;
  unsigned int _M_offset;

  _Bit_iterator_base(_Bit_type * __x, unsigned int __y)
  : _M_p(__x), _M_offset(__y) { }

  void _M_bump_up()
  {
    if (_M_offset++ == int(_S_word_bit) - 1)
    {
      _M_offset = 0;
      ++_M_p;
    }
  }

  void _M_bump_down()
  {
    if (_M_offset-- == 0)
    {
      _M_offset = int(_S_word_bit) - 1;
      --_M_p;
    }
  }

  void _M_incr(std::ptrdiff_t __i)
  {
    std::ptrdiff_t __n = __i + _M_offset;
    _M_p += __n / int(_S_word_bit);
    __n = __n % int(_S_word_bit);
    if (__n < 0)
    {
      __n += int(_S_word_bit);
      --_M_p;
    }
    _M_offset = static_cast<unsigned int>(__n);
  }

  bool operator==(const _Bit_iterator_base& __i) const
  {
    return _M_p == __i._M_p && _M_offset == __i._M_offset;
  }

  bool operator<(const _Bit_iterator_base& __i) const
  {
    return _M_p < __i._M_p
      || (_M_p == __i._M_p && _M_offset < __i._M_offset);
  }

  bool operator!=(const _Bit_iterator_base& __i) const
  {
    return !(*this == __i);
  }

  bool operator>(const _Bit_iterator_base& __i) const
  {
    return __i < *this;
  }

  bool operator<=(const _Bit_iterator_base& __i) const
  {
    return !(__i < *this);
  }

  bool operator>=(const _Bit_iterator_base& __i) const
  {
    return !(*this < __i);
  }
};

std::ptrdiff_t operator-(const _Bit_iterator_base& __x,
  const _Bit_iterator_base& __y)
{
  return (int(_S_word_bit) * (__x._M_p - __y._M_p)
    + __x._M_offset - __y._M_offset);
}

struct _Bit_iterator : public _Bit_iterator_base
{
  typedef _Bit_reference  reference;
  typedef _Bit_reference* pointer;
  typedef _Bit_iterator   iterator;
  typedef std::ptrdiff_t  difference_type;

  _Bit_iterator() : _Bit_iterator_base(0, 0) { }

  _Bit_iterator(_Bit_type * __x, unsigned int __y)
  : _Bit_iterator_base(__x, __y) { }

  iterator _M_const_cast() const
  {
    return *this;
  }

  reference operator*() const
  {
    return reference(_M_p, 1UL << _M_offset);
  }

  iterator& operator++()
  {
    _M_bump_up();
    return *this;
  }

  iterator operator++(int)
  {
    iterator __tmp = *this;
    _M_bump_up();
    return __tmp;
  }

  iterator& operator--()
  {
    _M_bump_down();
    return *this;
  }

  iterator operator--(int)
  {
    iterator __tmp = *this;
    _M_bump_down();
    return __tmp;
  }

  iterator& operator+=(difference_type __i)
  {
    _M_incr(__i);
    return *this;
  }

  iterator& operator-=(difference_type __i)
  {
    *this += -__i;
    return *this;
  }

  iterator operator+(difference_type __i) const
  {
    iterator __tmp = *this;
    return __tmp += __i;
  }

  iterator operator-(difference_type __i) const
  {
    iterator __tmp = *this;
    return __tmp -= __i;
  }

  reference operator[](difference_type __i) const
  {
    return *(*this + __i);
  }
};

_Bit_iterator operator+(std::ptrdiff_t __n, const _Bit_iterator& __x)
{
  return __x + __n;
}

struct _Bit_const_iterator : public _Bit_iterator_base
{
  typedef bool                 reference;
  typedef bool                 const_reference;
  typedef const bool*          pointer;
  typedef _Bit_const_iterator  const_iterator;
  typedef std::ptrdiff_t       difference_type;

  _Bit_const_iterator() : _Bit_iterator_base(0, 0) { }

  _Bit_const_iterator(_Bit_type * __x, unsigned int __y)
  : _Bit_iterator_base(__x, __y) { }

  _Bit_const_iterator(const _Bit_iterator& __x)
  : _Bit_iterator_base(__x._M_p, __x._M_offset) { }

  _Bit_iterator _M_const_cast() const
  {
    return _Bit_iterator(_M_p, _M_offset);
  }

  const_reference operator*() const
  {
    return _Bit_reference(_M_p, 1UL << _M_offset);
  }

  const_iterator& operator++()
  {
    _M_bump_up();
    return *this;
  }

  const_iterator operator++(int)
  {
    const_iterator __tmp = *this;
    _M_bump_up();
    return __tmp;
  }

  const_iterator& operator--()
  {
    _M_bump_down();
    return *this;
  }

  const_iterator operator--(int)
  {
    const_iterator __tmp = *this;
    _M_bump_down();
    return __tmp;
  }

  const_iterator& operator+=(difference_type __i)
  {
    _M_incr(__i);
    return *this;
  }

  const_iterator& operator-=(difference_type __i)
  {
    *this += -__i;
    return *this;
  }

  const_iterator operator+(difference_type __i) const
  {
    const_iterator __tmp = *this;
    return __tmp += __i;
  }

  const_iterator operator-(difference_type __i) const
  {
    const_iterator __tmp = *this;
    return __tmp -= __i;
  }

  const_reference operator[](difference_type __i) const
  {
    return *(*this + __i);
  }
};

_Bit_const_iterator operator+(std::ptrdiff_t __n, const _Bit_const_iterator& __x)
{
  return __x + __n;
}

void __fill_bvector(_Bit_iterator __first, _Bit_iterator __last, bool __x)
{
  for (; __first != __last; ++__first)
    *__first = __x;
}

void fill(_Bit_iterator __first, _Bit_iterator __last, const bool& __x)
{
  if (__first._M_p != __last._M_p)
    {
      std::fill(__first._M_p + 1, __last._M_p, __x ? ~0 : 0);
      __fill_bvector(__first, _Bit_iterator(__first._M_p + 1, 0), __x);
      __fill_bvector(_Bit_iterator(__last._M_p, 0), __last, __x);
    }
  else
    __fill_bvector(__first, __last, __x);
}



template < typename Allocator >
class vector<bool, Allocator>
{
 public :
  typedef bool             value_type;
  typedef std::size_t      size_type;
  typedef std::ptrdiff_t   difference_type;
  // typedef _Bit_reference   reference;
  // typedef bool             const_reference;
  // typedef _Bit_reference*  pointer;
  // typedef const bool*      const_pointer;
  // typedef _Bit_iterator                          iterator;
  // typedef _Bit_const_iterator                    const_iterator;
  // typedef std::reverse_iterator<const_iterator>  const_reverse_iterator;
  // typedef std::reverse_iterator<iterator>        reverse_iterator;
  typedef Allocator        allocator_type;

  typedef bool* pointer;
  typedef const pointer const_pointer;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef vectorIterator<bool> iterator;
  typedef vectorConstIterator<bool> const_iterator;
  typedef reverseIterator<iterator> reverse_iterator;
  typedef reverseIterator<const_iterator> const_reverse_iterator;

private :
  pointer first_;
  pointer last_;
  pointer reserved_last_;
  allocator_type alloc_;



public :
  // コンストラクター
  vector(const allocator_type & alloc_ = allocator_type())
    : alloc_(alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  {};
  // vector( size_type size, const allocator_type & alloc_ = allocator_type() )
  //   : alloc_(alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  // {
  //   resize(size);
  // }
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
    // コピー元の要素数を保持できるだけのストレージを確保
    reserve(r.size());
    // コピー元の要素をコピー構築
    // destはコピー先
    // [src, last_)はコピー元
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
    // 1. 自分自身への代入なら何もしない
    if (this == &r)
      return *this;
  
    // 2. 要素数が同じならば
    if (size() == r.size())
    {   // 要素ごとにコピー代入
      // std::copy(r.begin(), r.end(), begin()) ;
      iterator dest_iter = begin();
      for (const_iterator src_iter = r.begin(), src_end = r.end();
        src_iter != src_end; ++src_iter, ++dest_iter)
      {
        *dest_iter = *src_iter;
      }      
    }
    // 3. それ以外の場合で
    else 
      // 予約数が十分ならば、
      if (capacity() >= r.size())
      {
        iterator dest_iter;
        iterator dest_end = end();
        const_iterator src_iter;
        const_iterator src_end = r.end();
        for (dest_iter = begin() + r.size(), dest_end = end();
          dest_iter != dest_end;
          ++dest_iter)
        {
          destroy(&*dest_iter);
        }
        if (size() >= r.size())
        {
          last_ = first_;
          for (src_iter = r.begin(), dest_iter = begin();
            src_iter != src_end;
            ++src_iter, ++dest_iter, last_++)
          {
            *dest_iter = *src_iter;
          }
        }
        else
        {
          last_ = first_;
          for (src_iter = r.begin(), dest_iter = begin();
            dest_iter != dest_end;
            ++src_iter, ++dest_iter, last_++)
          {
            *dest_iter = *src_iter;
          }
          for (src_end = r.end();
            src_iter != src_end;
            ++src_iter, ++dest_iter, ++last_)
          {
            construct(&*dest_iter, *src_iter);
          }
        }
        // clear();
        // iterator dest_iter = begin();
        // for (const_iterator src_iter = r.begin(), src_end = r.end();
        //   src_iter != src_end; ++src_iter, ++dest_iter, ++last_)
        // {
        //   construct(&*dest_iter, *src_iter);
        // }
      }
      // 4. 予約数が不十分ならば
      else
      {
        // 要素をすべて破棄
        // destroy_all();
        clear();
        // 予約
        reserve(r.size());
        // コピー構築
        iterator dest_iter = begin();
        for (const_iterator src_iter = r.begin(), src_end = r.end();
          src_iter != src_end; ++src_iter, ++dest_iter, ++last_)
        {
          construct(&*dest_iter, *src_iter);
        }
      }
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
  bool operator==(const vector<bool, Allocator>& r)
  {
    return (this->size() == r.size()
      && equal(this->begin(), this->end(), r.begin()));
  }
  bool operator!=(const vector<bool, Allocator>& r)
  {
    return !(*this == r);
  }
  bool operator<(const vector<bool, Allocator>& r)
  {
    return lexicographical_compare(begin(), end(), r.begin(), r.end());
  }
  bool operator<=(const vector<bool, Allocator>& r)
  {
    return !(*this > r);
  }
  bool operator>(const vector<bool, Allocator>& r)
  {
    return lexicographical_compare(r.begin(), r.end(), begin(), end());
  }
  bool operator>=(const vector<bool, Allocator>& r)
  {
    return !(*this < r);
  }

  // イテレーターアクセス
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
    return (alloc_.max_size() / 2);
  }
  bool empty() const
  {
    // return size() == 0;
    return begin() == end();
  }
  size_type capacity() const
  {
    return reserved_last_ - first_;
  }  

  // 要素アクセス
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
    // return last_ - 1;

  }
  const_reference back() const
  {
    const_iterator tmp = end();
    --tmp;
    return *tmp;
    // return last_ - 1;
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

    // 例外安全のため
    // 関数を抜けるときに古いストレージを破棄する
    // C++20の機能
    // std::scope_exit e( [&]{
    //   traits::deallocate(alloc_, old_first_, old_capacity);
    // } );

    // 古いストレージから新しいストレージに要素をコピー構築
    for (iterator old_iter = old_first_, old_end_ = old_last_;
      old_iter != old_end_; ++old_iter, ++last_)
    {
      // construct(last_, std::move(*old_iter)) ;
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

  // void resize(size_type sz)
  // {
  //   // 現在の要素数より少ない
  //   if (sz < size())
  //   {
  //     size_type diff = size() - sz;
  //     destroy_until(rbegin() + diff) ;
  //     last_ = first_ + sz ;
  //   }
  //   // 現在の要素数より大きい
  //   else if ( sz > size() )
  //   {
  //     reserve(sz) ;
  //     for (; last_ != reserved_last_ ; ++last_)
  //     {
  //       construct(last_);
  //     }
  //   }
  // }

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
      // bool以外
      // if (sz < size() * 2)
      //   reserve(size() * 2);
      // else
      //   reserve(sz);
      // boolの場合
      size_t allocsize = sz / 64 * 64;
      if (sz % 64 != 0)
        allocsize += 64;
      reserve(allocsize);

      for (size_t i = 0; sz - size(); ++i, ++last_)
      {
        construct(last_, value);
      }
      // for (; last_ != reserved_last_ ; ++last_)
      // {
      //   construct(last_, value);
      // }
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
    vector<bool> tmp(first, last);
    *this = tmp;
  }

  void assign(size_type n, const bool& u)
  {
    vector<bool> tmp(n, u);
    *this = tmp;
  }

  void pop_back()
  {
    if (empty() == false)
    {
      last_--;
      destroy(last_);
    }
  }

  iterator insert(iterator position, const bool& x)
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

  void insert(iterator position, size_type n, const bool& x)
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
  // この関数いるのかな…
  void construct(pointer ptr)
  {
    // traits::construct(alloc_, ptr);
    alloc_.construct(ptr, value_type());
  }
  void construct(pointer ptr, const_reference value)
  {
    // traits::construct(alloc_, ptr, value);
    alloc_.construct(ptr, value);
  }
  // ムーブ用
  // c++11の機能
  // void construct(pointer ptr, value_type && value)
  // {
  //   traits::construct(alloc_, ptr, std::move(value));
  // }
  void destroy(pointer ptr)
  {
    // traits::destroy(alloc_, ptr);
    alloc_.destroy(ptr);
   }
  void destroy_until(reverse_iterator rend)
  {
    for (reverse_iterator riter = rbegin(); riter != rend; ++riter, --last_)
    {
      // 簡易vector<T>のiteratorは単なるT *だが、
      // riterはリバースイテレーターなのでポインターではない。
      // ポインターを取るために*riterでまずT &を得て、
      // そこに&を適用することでT *を得ている。
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








}; // namespace ft

#endif /* VECTOR_HPP */