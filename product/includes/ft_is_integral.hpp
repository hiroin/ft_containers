#ifndef _FT_IS_INTEGRAL_H_
#define _FT_IS_INTEGRAL_H_

#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "ft_enable_if.hpp"

/// remove_const
template <typename _Tp>
struct ft_remove_const
{
  typedef _Tp type;
};

/// remove_volatile
template <typename _Tp>
struct ft_remove_volatile
{
  typedef _Tp type;
};

/// remove_cv
template <typename _Tp>
struct ft_remove_cv
{
  typedef typename ft_remove_const<typename ft_remove_volatile<_Tp>::type>::type type;
};

/// integral_constant
template <typename _Tp, _Tp __v>
struct ft_integral_constant
{
  static const _Tp value = __v;
  typedef _Tp value_type;
  typedef ft_integral_constant<_Tp, __v> type;
  operator value_type() const { return value; }
};

/// The type used as a compile-time boolean with true value.
typedef ft_integral_constant<bool, true> true_type;

/// The type used as a compile-time boolean with false value.
typedef ft_integral_constant<bool, false> false_type;

template <typename>
struct __ft_is_integral_helper
    : public false_type
{
};

template <>
struct __ft_is_integral_helper<bool>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<char>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<signed char>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<unsigned char>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<short>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<unsigned short>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<int>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<unsigned int>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<long>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<unsigned long>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<long long>
    : public true_type
{
};

template <>
struct __ft_is_integral_helper<unsigned long long>
    : public true_type
{
};

/// is_integral
template <typename _Tp>
struct ft_is_integral
    : public __ft_is_integral_helper<typename ft_remove_cv<_Tp>::type>::type
{
};

template <typename T>
// typename std::enable_if<ft_is_integral<T>::value>::type
typename ft_enable_if<ft_is_integral<T>::value>::type
test_ft_is_integral(T t)
{
  // std::cout << "std::is_integral<T>::value : " << std::is_integral<T>::value << std::endl;
  std::cout << "ft_is_integral<T>::value : " << ft_is_integral<T>::value << std::endl;
  std::cout << t << "???????????????" << std::endl;
}

template <typename T>
typename ft_enable_if<!ft_is_integral<T>::value>::type
test_ft_is_integral(T t)
{
  // std::cout << "std::is_integral<T>::value : " << std::is_integral<T>::value << std::endl;
  std::cout << "ft_is_integral<T>::value : " << ft_is_integral<T>::value << std::endl;
  std::cout << t << "????????????????????????" << std::endl;
}

#endif