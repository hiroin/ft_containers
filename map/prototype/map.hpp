#ifndef _FT_MAP_H_
#define _FT_MAP_H_

#include "iterator.hpp"
#include "ft_pair.hpp"
#include "BinTree.hpp"

namespace ft
{

template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>,
    typename _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
  class map
{
 public:
  typedef _Key                        key_type;
  typedef _Tp                         mapped_type;
  typedef ft::pair<const _Key, _Tp>   value_type;
  typedef _Compare                    key_compare;
  typedef _Alloc                      allocator_type;
  typedef typename _Alloc::pointer          pointer;
  typedef typename _Alloc::const_pointer    const_pointer;
  typedef typename _Alloc::reference        reference;
  typedef typename _Alloc::const_reference  const_reference;

 private:
  typedef typename _Alloc::value_type _Alloc_value_type;
  typedef BinTree<key_type, mapped_type, key_compare, allocator_type> _AVL_type;

  _AVL_type _M_t;

 public:
  typedef typename _AVL_type::iterator               iterator;
  typedef typename _AVL_type::const_iterator         const_iterator;
  typedef typename _AVL_type::size_type              size_type;
  typedef typename _AVL_type::difference_type        difference_type;
  typedef typename _AVL_type::reverse_iterator       reverse_iterator;
  typedef typename _AVL_type::const_reverse_iterator const_reverse_iterator;

 public:
  class value_compare
  : public std::binary_function<value_type, value_type, bool>
  {
   public:
    key_compare comp;
    value_compare(key_compare __c)
    : comp(__c) { }

    bool operator()(const value_type& __x, const value_type& __y) const
    { return comp(__x.first, __y.first); }
  };

  explicit
  map(const _Compare& __comp = key_compare(),
    const allocator_type& __a = allocator_type())
    : _M_t(__comp, __a) { }

  template<typename _InputIterator>
  map(_InputIterator __first, _InputIterator __last,
    const _Compare& __comp = key_compare(),
    const allocator_type& __a = allocator_type())
    : _M_t(__comp, __a)
  { insert(__first, __last); }

  map& operator=(const map& __x)
  {
    if (this == &__x) {
      return *this;
    }
    _M_t.clear();
    insert(__x.begin(), __x.end());
    return *this;
  }

  bool empty()
  { return _M_t.empty(); }

  size_type size()
  { return _M_t.size(); }

  size_type max_size() const
  { return _M_t.max_size(); }

  ft::pair<iterator, bool> insert(const value_type& __x)
  { return _M_t.append(__x); }

  template<typename _InputIterator>
  void insert(_InputIterator __first, _InputIterator __last)
  { _M_t.append(__first, __last); }

  iterator begin()
  { return _M_t.begin(); }

  const_iterator begin() const
  { return _M_t.begin(); }

  iterator end()
  { return _M_t.end(); }

  const_iterator end() const
  { return _M_t.end(); }

  iterator lower_bound(const key_type& __x)
  { return _M_t.lower_bound(__x); }

  const_iterator lower_bound(const key_type& __x) const
  { return _M_t.lower_bound(__x); }

  mapped_type& operator[](const key_type& __k)
  {
    iterator __i = lower_bound(__k);
    // __i->first is greater than or equivalent to __k.
    // if (__i == end() || key_comp()(__k, (*__i).first))
    if (__i == end() || __k != (*__i).first)
    {
      // __i = insert(__i, value_type(__k, mapped_type()));
      __i = insert(value_type(__k, mapped_type())).first;
    }
    return (*__i).second;
  }

  key_compare key_comp() const
  { return _M_t.key_comp(); }

  value_compare value_comp() const
  { return value_compare(_M_t.key_comp()); }

  iterator find(const key_type& __x)
  { return _M_t.find(__x); }

  const_iterator find(const key_type& __x) const
  { return _M_t.find(__x); }

  void erase(iterator __position)
  { _M_t.wrapErase(__position); } 

  // size_type erase(const key_type& __x)
  // { return _M_t.erase(__x); }

#ifdef DEBUG
 public:
  void print() {
      _M_t.print();
  }
#endif

};

} // namespace ft
#endif