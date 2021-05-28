/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 21:35:28 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/11 20:14:14 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

#include <type_traits>

namespace ft {

/*** remove_cv (const and volatile) ***/
template <class T>
struct remove_cv {
  typedef T type;
};

template <class T>
struct remove_cv<const T> {
  typedef T type;
};

template <class T>
struct remove_cv<volatile T> {
  typedef T type;
};

template <class T>
struct remove_cv<const volatile T> {
  typedef T type;
};

/*** true_type and false type ***/
// rekkaban copy of std::integral_constant
template <class T, T val>
struct integral_constant {
  enum { value = val };
  typedef T value_type;
  typedef integral_constant type;
  operator value_type() const { return value; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

/*** is_same ***/
template <class T, class U>
struct is_same : public false_type {};

template <class T>
struct is_same<T, T> : public true_type {};

/*** is_pointer ***/
template<class T>
struct is_pointer_helper : false_type {};
 
template<class T>
struct is_pointer_helper<T*> : true_type {};
 
template<class T>
struct is_pointer : is_pointer_helper< typename remove_cv<T>::type > {};

/*** enable_if ***/
template <bool B, class T = void>
struct enable_if {};

template <class T>
struct enable_if<true, T> {
  typedef T type;
};

}  // namespace ft

#endif /* TYPE_TRAITS_HPP */
