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
  vector( size_type size, const allocator_type & alloc_ = allocator_type() )
    : alloc_(alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  {
    resize(size);
  }
  vector( size_type size, const_reference value, const allocator_type & alloc_ = allocator_type() )
    : alloc_(alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
  {
    resize(size, value);
  }
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
        src_iter != src_end; ++src_iter, ++dest_iter, ++last_)
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
        last_ = first_;
        if (size() >= r.size())
        {
          for (src_iter = r.begin(), dest_iter = begin();
            src_iter != src_end;
            ++src_iter, ++dest_iter, last_++)
          {
            *dest_iter = *src_iter;
          }
        }
        else
        {
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
      // insertの処理と一緒 ( https://cpprefjp.github.io/reference/vector/vector/resize.html )
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
    if (empty() == false)
    {
      last_--;
      destroy(last_);
    }
  }
  iterator insert(iterator position, const T& x)
  {
    return position;
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
    return position;
  }
  iterator erase(iterator first_, iterator last_)
  {
    return first_;
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