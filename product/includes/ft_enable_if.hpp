#ifndef _FT_ENABLE_IF_H_
#define _FT_ENABLE_IF_H_

#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>
#include <iterator>

template <bool, typename _Tp = void>
struct ft_enable_if
{
};

template <typename _Tp>
struct ft_enable_if<true, _Tp>
{
  typedef _Tp type;
};

#endif