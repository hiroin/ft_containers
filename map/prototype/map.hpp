#ifndef _FT_MAP_H_
#define _FT_MAP_H_

#include "iterator.hpp"
#include "ft_pair.hpp"
#include "BinTree.hpp"

namespace ft
{

template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
    typename _Alloc = std::allocator<std::pair<const _Key, _Tp> > >
  class map
{
 public:
  typedef _Key                        key_type;
  typedef _Tp                         mapped_type;
  typedef std::pair<const _Key, _Tp>  value_type;
  typedef _Compare                    key_compare;
  typedef _Alloc                      allocator_type;

 private:
  typedef typename _Alloc::value_type _Alloc_value_type;

 public:
  class value_compare
  : public std::binary_function<value_type, value_type, bool>
  {
    protected:
    key_compare comp;

    value_compare(key_compare __c)
    : comp(__c) { }

    public:
    bool operator()(const value_type& __x, const value_type& __y) const
    { return comp(__x.first, __y.first); }
  };
};

} // namespace ft
#endif