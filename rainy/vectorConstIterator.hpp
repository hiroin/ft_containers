#ifndef VECTORCONSTITERATER_HPP
#define VECTORCONSTITERATER_HPP

#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
#include "ft_enable_if.hpp"
#include "ft_is_integral.hpp"

namespace ft {

template < typename T>
class vectorConstIterator
{
 public:
  typedef std::ptrdiff_t difference_type;
  typedef const T value_type;
  typedef const value_type& reference;
  typedef const value_type* pointer;
  typedef random_access_iterator_tag iterator_category;

  pointer ptr_;

  vectorConstIterator() : ptr_(NULL){};
  vectorConstIterator(pointer ptr) : ptr_(ptr){};
  vectorConstIterator(const vectorIterator<T>& x) : ptr_(x.ptr_) {}
  vectorConstIterator(const vectorConstIterator& x) : ptr_(x.ptr_) {}
  ~vectorConstIterator(){};

  vectorConstIterator& operator=(const vectorConstIterator& x)
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

  vectorConstIterator& operator++()
  {
    ++ptr_;
    return *this;
  }

  vectorConstIterator operator++(int)
  {
    return vectorConstIterator(ptr_++);
  }

  vectorConstIterator& operator--()
  {
    --ptr_;
    return *this;
  }

  vectorConstIterator operator--(int)
  {
    return vectorConstIterator(ptr_--);
  }

  reference operator[](difference_type n) const
  {
    return ptr_[n];
  }

  vectorConstIterator& operator+=(difference_type n)
  {
    ptr_ += n;
    return *this;
  }

  vectorConstIterator operator+(difference_type n)
  {
    return vectorConstIterator(ptr_ + n);
  }

  vectorConstIterator& operator-=(difference_type n)
  {
    ptr_ -= n;
    return *this;
  }

  vectorConstIterator operator-(difference_type n)
  {
    return vectorConstIterator(ptr_ - n);
  }
};

template < typename T>
bool operator==(const vectorConstIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ == rhs.ptr_;
}

template < typename T>
bool operator!=(const vectorConstIterator<T>& lhs, const vectorIterator<T>& rhs)
{
  return lhs.ptr_ != rhs.ptr_;
}

template < typename T>
bool operator==(const vectorIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ == rhs.ptr_;
}

template < typename T>
bool operator!=(const vectorIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ != rhs.ptr_;
}

template < typename T>
bool operator==(const vectorConstIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ == rhs.ptr_;
}

template < typename T>
bool operator!=(const vectorConstIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ != rhs.ptr_;
}

template < typename T>
bool operator<(const vectorConstIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ < rhs.ptr_;
}

template < typename T>
bool operator>(const vectorConstIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ > rhs.ptr_;
}

template < typename T>
bool operator<=(const vectorConstIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ <= rhs.ptr_;
}

template < typename T>
bool operator>=(const vectorConstIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ >= rhs.ptr_;
}

template < typename T>
typename vectorConstIterator<T>::difference_type operator-(
  const vectorConstIterator<T>& lhs, const vectorConstIterator<T>& rhs)
{
  return lhs.ptr_ - rhs.ptr_;
}

}; // namespace ft

#endif /* VECTOR_HPP */