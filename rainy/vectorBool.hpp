#ifndef VECTORBOOL_HPP
#define VECTORBOOL_HPP

#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
#include "ft_enable_if.hpp"
#include "ft_is_integral.hpp"
#include "vectorIterator.hpp"
#include "vectorConstIterator.hpp"
#include "vector.hpp"

namespace ft {

typedef unsigned long Bit_type_;
# ifdef __MACH__
enum { S_word_bit = int(CHAR_BIT * sizeof(Bit_type)) };
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
  bitIterator(BitReference_& ref) : ref_(ref.ptr_, ref.index_){};
  bitIterator(const BitReference_& ref) : ref_(){};
  bitIterator(bitIterator& x) : ref_(x.ref_) {};
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

  // 作っていないもの
  //  イテレーター同士の引き算
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
  constBitIterator(const BitReference_& ref) : ref_(){};
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
  typedef const BitReference_  const_reference;
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

  // デストラクター
  ~vector()
  {
    storageAlloc_.deallocate(storage_, storageSize_);
  };

  reference operator [](size_type i)
  {
    return reference(storage_, i);
  }

  // const_reference operator [](size_type i) const
  // {
  //   return first_[i];
  // }

  void resize(size_type sz, value_type value = value_type())
  {
    // 現在の要素数より少ない
    if (sz < size())
    {
      // 後で実装
      // size_type diff = size() - sz;
      // destroy_until(rbegin() + diff) ;
      // last_ = first_ + sz ;
    }
    // 現在の要素数より大きい
    else if ( sz > size() )
    {
      if (sz < size() * 2)
        reserve(size() * 2);
      else
        reserve(sz);
      // あとで実装しなおし、とりあえず0で埋める
      // 本当はあらかじめ値が入っている場所は何もしない
      for (size_type idx = 0; idx < storageSize_; ++idx)
      {
        storage_[idx] = static_cast<size_type>(0);
      }    

      // コンストラクトがいらない?
      // for (size_t i = 0; sz - size(); ++i, ++last_)
      // {
      //   construct(last_, value);
      // }
    }
    size_ = sz;
  }

  void reserve(size_type sz)
  {
    // すでに指定された要素数以上に予約されているなら何もしない
    if (sz <= capacity())
      return ;

    // 動的メモリー確保をする
    size_type* ptr = allocate(sz) ;

    // 古いストレージの情報を保存
    size_type* old_storage_ = storage_;
    size_type old_capacity = capacity();

    // 新しいストレージに差し替え
    storage_ = ptr;

    // 古いストレージから新しいストレージに要素をコピー構築
    // 後で実装
    // for (iterator old_iter = old_first_, old_end_ = old_last_;
    //   old_iter != old_end_; ++old_iter, ++last_)
    // {
    //   construct(last_, *old_iter) ;
    // }

    // 新しいストレージにコピーし終えたので
    // 古いストレージの値は破棄
    // 後で実装
    // for (reverse_iterator riter = reverse_iterator(old_last_), rend = reverse_iterator(old_first_);
    //       riter != rend ; ++riter)
    // {
    //   destroy(&*riter);
    // }

    // ストレージを破棄する
    storageAlloc_.deallocate(old_storage_, old_capacity);
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

 private :
  size_type* allocate(size_type n)
  {
    storageSize_ = n / S_word_bit_ + 1;
    return storageAlloc_.allocate(storageSize_);
  }
};


}; // namespace ft

#endif /* VECTOR_HPP */