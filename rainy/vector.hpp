#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "ft_enable_if.hpp"
#include "ft_is_integral.hpp"

namespace ft {

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template < typename T>
class vectorIterator
{
 public:
  typedef std::ptrdiff_t difference_type;
  typedef T value_type;
  typedef value_type& reference;
  typedef value_type* pointer;
  typedef random_access_iterator_tag iterator_category;

  pointer ptr_;

  vectorIterator() : ptr_(NULL){};
  vectorIterator(pointer ptr) : ptr_(ptr){};
  // vectorIterator(const vectorIterator& x) : ptr_(x.ptr_) {} //謎
  ~vectorIterator(){};

  vectorIterator& operator=(const vectorIterator& x)
  {
    if (this == &x)
      return *this;
    ptr_ = x.ptr_;
    return *this;
  }

  reference operator *() const
  {
    return *ptr_;
  }

  pointer operator->() const
  {
    return ptr_;
  }

  vectorIterator& operator++()
  {
    ++ptr_;
    return *this;
  }

  vectorIterator operator++(int)
  {
    return vectorIterator(ptr_++);
  }

  vectorIterator& operator--()
  {
    --ptr_;
    return *this;
  }

  vectorIterator operator--(int)
  {
    return vectorIterator(ptr_--);
  }

  reference operator[](difference_type n) const
  {
    return ptr_[n];
  }

  vectorIterator& operator+=(difference_type n)
  {
    ptr_ += n;
    return *this;
  }

  vectorIterator operator+(difference_type n)
  {
    return vectorIterator(ptr_ + n);
  }

  vectorIterator& operator-=(difference_type n)
  {
    ptr_ -= n;
    return *this;
  }

  vectorIterator operator-(difference_type n)
  {
    return vectorIterator(ptr_ - n);
  }
};

template < typename T>
bool operator==(const vectorIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ == rhs.ptr_;
}

template < typename T>
bool operator!=(const vectorIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ != rhs.ptr_;
}

template < typename T>
bool operator<(const vectorIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ < rhs.ptr_;
}

template < typename T>
bool operator>(const vectorIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ > rhs.ptr_;
}

template < typename T>
bool operator<=(const vectorIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ <= rhs.ptr_;
}

template < typename T>
bool operator>=(const vectorIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ >= rhs.ptr_;
}

template < typename T>
bool operator-(const vectorIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ - rhs.ptr_;
}

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
  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

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
  vector( size_type size, const allocator_type & alloc_ = allocator_type() )
    : alloc_(alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  {
    resize(size);
  }
  vector( size_type size, const_reference value, const allocator_type & alloc_ = allocator_type() )
    : vector( alloc_ )
  {
    resize(size, value);
  }
  // template < typename InputIterator,
  //   typename std::enable_if< !std::is_integral<InputIterator>::value, std::nullptr_t>::type = nullptr >
  template <typename InputIterator>
  vector(InputIterator first,
    typename ft_enable_if<!ft_is_integral<InputIterator>::value, InputIterator>::type last, const Allocator & = Allocator())
    : first_(NULL), last_(NULL), reserved_last_(NULL)
  {
    reserve(std::distance(first, last));
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
    for (pointer dest = first_, src = r.begin(), last_ = r.end();
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
      std::copy(r.begin(), r.end(), begin()) ;
    }
    // 3. それ以外の場合で
    else 
      // 予約数が十分ならば、
      if (capacity() >= r.size())
      {
        // 有効な要素はコピー
        std::copy(r.begin(), r.begin() + r.size(), begin());
        // 残りはコピー構築
        for (iterator src_iter = r.begin() + r.size(), src_end = r.end();
          src_iter != src_end ; ++src_iter, ++last_ )
        {
          construct(last_, *src_iter);
        }
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
        for (iterator src_iter = r.begin(), src_end = r.end(), dest_iter = begin();
          src_iter != src_end; ++src_iter, ++dest_iter, ++last_)
        {
          construct(dest_iter, *src_iter);
        }
      }
    return *this ;
  }
  bool operator==(const vector<T, Allocator>& r)
  {
    return (this->size() == r.size()
      && std::equal(this->begin(), this->end(), r.begin()));
  }
  bool operator!=(const vector<T, Allocator>& r)
  {
    return !(*this == r);
  }

  // イテレーターアクセス
  iterator begin()
  {
    return first_;
  }
  iterator end()
  {
    return last_;
  }
  iterator begin() const
  {
    return first_;
  }
  iterator end() const
  {
    return last_;
  }
  reverse_iterator rbegin()
  {
    // return reverse_iterator{last_};
    return static_cast<reverse_iterator>(last_);
  }
  reverse_iterator rend()
  {
    // return reverse_iterator{first_};
    return static_cast<reverse_iterator>(first_);
  }

  size_type size() const
  {
    return end() - begin();
    // return std::distance(begin(), end());
  }
  size_type max_size() const
  {
    return (alloc_.max_size());
  }
  bool empty() const
  {
    return size() == 0;
    // return begin() == end();
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
    return first_;
  }
  const_reference front() const
  {
    return first_;
  }
  reference back()
  {
    return last_ - 1;
  }
  const_reference back() const
  {
    return last_ - 1;
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
    for (iterator old_iter = old_first_; old_iter != old_last_; ++old_iter, ++last_)
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

  void resize(size_type sz)
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
      reserve(sz) ;
      // デフォルト構築らしいけどいらないと思う
      // for (; last_ != reserved_last_ ; ++last_)
      // {
      //   construct(last_);
      // }
    }
  }

  void resize(size_type sz, const_reference value)
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
      reserve(sz) ;
      for (; last_ != reserved_last_ ; ++last_)
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

  // ここから作る
  template <class InputIterator>
  void assign(InputIterator first_, InputIterator last_)
  {

  }
  void assign(size_type n, const T& u)
  {

  }
  void pop_back()
  {

  }
  iterator insert(iterator position, const T& x)
  {

  }
  void insert(iterator position, size_type n, const T& x)
  {

  }
  template <class InputIterator>
  void insert(iterator position, InputIterator first_, InputIterator last_)
  {

  }
  iterator erase(iterator position)
  {

  }
  iterator erase(iterator first_, iterator last_)
  {

  }
  void swap(vector& x)
  {

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
    alloc_.construct(ptr);
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
};
}; // namespace ft

#endif /* VECTOR_HPP */