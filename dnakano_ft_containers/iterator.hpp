/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:16:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/23 08:21:08 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this was made for avoid to use __xxx (like __wrap_iter) or anything that
** newer than c++98.
*/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>

#include "type_traits.hpp"

namespace ft {

/*
** iterator tags
*/

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

/*
** reverse_itarator
*/

template <class Iterator>
class reverse_iterator {
 protected:
  Iterator normal_;

 public:
  typedef Iterator iterator;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::iterator_category iterator_category;

  reverse_iterator() { normal_ = Iterator(); };
  reverse_iterator(const Iterator& ref) : normal_(ref) {}

  template <class Itr>
  reverse_iterator(const reverse_iterator<Itr>& x) : normal_(x.base()) {}

  ~reverse_iterator(){};

  Iterator base() const { return normal_; }

  reverse_iterator& operator=(const reverse_iterator& rhs) {
    normal_ = rhs.normal_;
    return *this;
  }

  reference operator*() const {
    Iterator tmp = normal_;
    return *--tmp;
  }

  pointer operator->() const {
    Iterator tmp = normal_;
    return &(*--tmp);
  }

  reference operator[](difference_type idx) const { return *(*this + idx); }

  reverse_iterator& operator++() {
    --normal_;
    return *this;
  }

  reverse_iterator operator++(int) {
    reverse_iterator tmp(*this);
    ++(*this);
    return tmp;
  }

  reverse_iterator& operator--() {
    ++normal_;
    return *this;
  }

  reverse_iterator operator--(int) {
    reverse_iterator tmp(*this);
    --(*this);
    return tmp;
  }

  reverse_iterator& operator+=(difference_type diff) {
    normal_ -= diff;
    return *this;
  }

  reverse_iterator& operator-=(difference_type diff) {
    normal_ += diff;
    return *this;
  }

  friend reverse_iterator operator+(const reverse_iterator& lhs,
                                    difference_type rhs) {
    return reverse_iterator(lhs.normal_ - rhs);
  }

  friend reverse_iterator operator+(difference_type lhs,
                                    const reverse_iterator& rhs) {
    return reverse_iterator(rhs.normal_ - lhs);
  }

  friend reverse_iterator operator-(const reverse_iterator& lhs,
                                    difference_type rhs) {
    return reverse_iterator(lhs.normal_ + rhs);
  }

  friend reverse_iterator operator-(difference_type lhs,
                                    const reverse_iterator& rhs) {
    return reverse_iterator(rhs.normal_ + lhs);
  }
};

template <class Itr1, class Itr2>
typename reverse_iterator<Itr1>::difference_type operator-(
    const reverse_iterator<Itr1>& lhs, const reverse_iterator<Itr2>& rhs) {
  return rhs.base() - lhs.base();
}

template <class Itr1, class Itr2>
bool operator==(const reverse_iterator<Itr1>& x,
                const reverse_iterator<Itr2>& y) {
  return x.base() == y.base();
}

template <class Itr1, class Itr2>
bool operator!=(const reverse_iterator<Itr1>& x,
                const reverse_iterator<Itr2>& y) {
  return !(x == y);
}

template <class Itr1, class Itr2>
bool operator<(const reverse_iterator<Itr1>& x,
               const reverse_iterator<Itr2>& y) {
  return x.base() > y.base();
}

template <class Itr1, class Itr2>
bool operator<=(const reverse_iterator<Itr1>& x,
                const reverse_iterator<Itr2>& y) {
  return !(x > y);
}

template <class Itr1, class Itr2>
bool operator>(const reverse_iterator<Itr1>& x,
               const reverse_iterator<Itr2>& y) {
  return x.base() < y.base();
}

template <class Itr1, class Itr2>
bool operator>=(const reverse_iterator<Itr1>& x,
                const reverse_iterator<Itr2>& y) {
  return !(x < y);
}

template <class InputIterator, typename = void>
struct is_input_iterator : public ft::false_type {};

template <class InputIterator>
struct is_input_iterator<
    InputIterator,
    typename ft::enable_if<
        ft::is_same<std::input_iterator_tag,
                    typename InputIterator::iterator_category>::value ||
            ft::is_same<std::forward_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<std::bidirectional_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<std::random_access_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<ft::input_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<ft::forward_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<ft::bidirectional_iterator_tag,
                        typename InputIterator::iterator_category>::value ||
            ft::is_same<ft::random_access_iterator_tag,
                        typename InputIterator::iterator_category>::value,
        void>::type> : public ft::true_type {};

template <class InputIterator>
struct is_input_iterator<
    InputIterator,
    typename ft::enable_if<ft::is_pointer<InputIterator>::value, void>::type>
    : public ft::true_type {};

}  // namespace ft

#endif /* ITERATOR_HPP */
