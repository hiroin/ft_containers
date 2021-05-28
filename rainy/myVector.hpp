#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>

template < typename T, typename Allocator = std::allocator<T> >
class vector
{
public :
  using value_type      = T ;
  using pointer         = T *;
  using const_pointer   = const pointer;
  using reference       = value_type &;
  using const_reference = const value_type &;
  using allocator_type  = Allocator ;
  using size_type       = std::size_t ;
  using difference_type = std::ptrdiff_t ;
  using iterator        = pointer ;
  using const_iterator  = const_pointer ;
  using reverse_iterator       = std::reverse_iterator<iterator> ;
  using const_reverse_iterator = std::reverse_iterator<const_iterator> ;

private :
  // 先頭の要素へのポインター
  pointer first;
  // 最後の要素の1つ前方のポインター
  pointer last;
  // 確保したストレージの終端
  pointer reserved_last;
  // アロケーターの値
  allocator_type alloc;

public :
  // コンストラクター
  vector()
    : vector(allocator_type())
  {};
  vector(const allocator_type & alloc) noexcept
    : alloc(alloc), first(NULL), last(NULL), reserved_last(NULL)
  {};
  vector( size_type size, const allocator_type & alloc = allocator_type() )
    : vector( alloc )
  {
    resize(size);
  }
  vector( size_type size, const_reference value, const allocator_type & alloc = allocator_type() )
    : vector( alloc )
  {
    resize(size, value);
  }
  template < typename InputIterator >
  vector(InputIterator first, InputIterator last, const Allocator & = Allocator())
  {
    reserve(std::distance(first, last));
    for (auto i = first; i != last ; ++i)
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
    // アロケーターのコピー
    // アロケーターをコピーすべきかどうかは、アロケーターの実装が選べるようになっている
    : alloc(traits::select_on_container_copy_construction(r.alloc))
  {
    // コピー元の要素数を保持できるだけのストレージを確保
    reserve(r.size());
    // コピー元の要素をコピー構築
    // destはコピー先
    // [src, last)はコピー元
    for (auto dest = first, src = r.begin(), last = r.end();
      src != last ; ++dest, ++src)
    {
      construct(dest, *src);
    }
    last = first + r.size();
  }
  vector & operator =(const vector & x)
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
        for (auto src_iter = r.begin() + r.size(), src_end = r.end();
          src_iter != src_end ; ++src_iter, ++last )
        {
          construct(last, *src_iter);
        }
      }
      // 4. 予約数が不十分ならば
      else
      {
        // 要素をすべて破棄
        destroy_all() ;
        // 予約
        reserve(r.size());
        // コピー構築
        for (auto src_iter = r.begin(), src_end = r.end(), dest_iter = begin();
          src_iter != src_end; ++src_iter, ++dest_iter, ++last)
        {
          construct(dest_iter, *src_iter);
        }
      }
    return *this ;
  }

  // イテレーターアクセス
  iterator begin() noexcept
  {
    return first;
  }
  iterator end() noexcept
  {
    return last;
  }
  iterator begin() const noexcept
  {
    return first;
  }
  iterator end() const noexcept
  {
    return last;
  }
  reverse_iterator rbegin() noexcept
  {
    return reverse_iterator{last};
  }
  reverse_iterator rend() noexcept
  {
    return reverse_iterator{first};
  }

  size_type size() const noexcept
  {
    return end() - begin();
    // return std::distance(begin(), end());
  }
  // 実装する
  size_type max_size() const noexcept
  {
    return reserved_last - first;
  }
  bool empty() const noexcept
  {
    return size() == 0;
    // return begin() == end();
  }
  size_type capacity() const noexcept
  {
    return reserved_last - first;
  }  

  // 要素アクセス
  reference operator [](size_type i)
  {
    return first[i];
  }
  const_reference operator [](size_type i) const
  {
    return first[i];
  }
  reference at( size_type i )
  {
    if ( i >= size() )
      throw std::out_of_range( "index is out of range." ) ;
    return first[i] ;
  }
  const_reference at( size_type i ) const
  {
    if ( i >= size() )
      throw std::out_of_range( "index is out of range." ) ;
    return first[i] ;
  }
  reference front()
  {
    return first;
  }
  const_reference front() const
  {
    return first;
  }
  reference back()
  {
    return last - 1;
  }
  const_reference back() const
  {
    return last - 1;
  }

  void reserve(size_type sz)
  {
    // すでに指定された要素数以上に予約されているなら何もしない
    if (sz <= capacity())
      return ;

    // 動的メモリー確保をする
    auto ptr = allocate(sz) ;

    // 古いストレージの情報を保存
    auto old_first = first;
    auto old_last = last;
    auto old_capacity = capacity();

    // 新しいストレージに差し替え
    first = ptr;
    last = first;
    reserved_last = first + sz;

    // 例外安全のため
    // 関数を抜けるときに古いストレージを破棄する
    // C++20の機能
    // std::scope_exit e( [&]{
    //   traits::deallocate(alloc, old_first, old_capacity);
    // } );

    // 古いストレージから新しいストレージに要素をコピー構築
    // 実際にはムーブ構築
    for (auto old_iter = old_first; old_iter != old_last; ++old_iter, ++last)
    {
      // このコピーの理解にはムーブセマンティクスの理解が必要
      // C++11の機能
      construct(last, std::move(*old_iter)) ;
    }

    // 新しいストレージにコピーし終えたので
    // 古いストレージの値は破棄
    for (auto riter = reverse_iterator(old_last), rend = reverse_iterator(old_first);
          riter != rend ; ++riter)
    {
      destroy(&*riter);
    }
    // scope_exitによって自動的にストレージが破棄される
    // → C++20の機能なので、自分で破棄する
    traits::deallocate(alloc, old_first, old_capacity);
  }

  void resize(size_type sz)
  {
    // 現在の要素数より少ない
    if (sz < size())
    {
      auto diff = size() - sz;
      destroy_until(rbegin() + diff) ;
      last = first + sz ;
    }
    // 現在の要素数より大きい
    else if ( sz > size() )
    {
      reserve(sz) ;
      for (; last != reserved_last ; ++last)
      {
        construct(last);
      }
    }
  }

  void resize(size_type sz, const_reference value)
  {
    // 現在の要素数より少ない
    if (sz < size())
    {
      auto diff = size() - sz;
      destroy_until(rbegin() + diff) ;
      last = first + sz ;
    }
    // 現在の要素数より大きい
    else if ( sz > size() )
    {
      reserve(sz) ;
      for (; last != reserved_last ; ++last)
      {
        construct(last, value);
      }
    }
  }

  void push_back(const_reference value) 
  {
    // 予約メモリーが足りなければ拡張
    if (size() + 1 > capacity())
    {
        // 現在のストレージサイズ
        auto c = size();
        // 0の場合は1に
        if (c == 0)
            c = 1 ;
        else
            // それ以外の場合は2倍する
            c *= 2 ;
        reserve(c) ;
    }
    construct(last, value);
    ++last;
  }

  // ここから作る
  template <class InputIterator>
  void assign(InputIterator first, InputIterator last)
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
  void insert(iterator position, InputIterator first, InputIterator last)
  {

  }
  iterator erase(iterator position)
  {

  }
  iterator erase(iterator first, iterator last)
  {

  }
  void swap(vector& x)
  {

  }
  allocator_type get_allocator() const
  {
    return alloc;
  }
  void clear() noexcept
  {
    destroy_until(rend());
  }

 private :
  // アロケーターはallocator_traitsを経由して使う
  // allocator_traitsはc++11で使えないので書き換える必要がある
  using traits = std::allocator_traits<allocator_type>;

  pointer allocate(size_type n)
  {
    return traits::allocate(alloc, n);
  }
  void deallocate()
  {
    traits::deallocate(alloc, first, capacity());
  }
  void construct(pointer ptr)
  {
    traits::construct(alloc, ptr);
  }
  void construct(pointer ptr, const_reference value)
  {
    traits::construct(alloc, ptr, value);
  }
  // ムーブ用
  void construct(pointer ptr, value_type && value)
  {
    traits::construct(alloc, ptr, std::move(value));
  }
  void destroy(pointer ptr)
  {
    traits::destroy(alloc, ptr);
  }
  void destroy_until(reverse_iterator rend)
  {
    for (auto riter = rbegin(); riter != rend; ++riter, --last)
    {
      // 簡易vector<T>のiteratorは単なるT *だが、
      // riterはリバースイテレーターなのでポインターではない。
      // ポインターを取るために*riterでまずT &を得て、
      // そこに&を適用することでT *を得ている。
      destroy( &*riter );
    }
  }

};
