#ifndef VECTORITERATER_HPP
#define VECTORITERATER_HPP

#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
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

}; // namespace ft

#endif /* VECTOR_HPP */