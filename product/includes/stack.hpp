#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"

namespace ft {

template<typename _Tp, typename _Sequence = ft::vector<_Tp> >
class stack
{
 public:
  typedef typename _Sequence::value_type      value_type;
  typedef typename _Sequence::reference       reference;
  typedef typename _Sequence::const_reference const_reference;
  typedef typename _Sequence::size_type       size_type;
  typedef	         _Sequence                  container_type;

 protected:
  //  See queue::c for notes on this name.
  _Sequence c;

 public:
  explicit
  stack(const _Sequence& __c = _Sequence())
  : c(__c) { }

  bool empty() const
  { return c.empty(); }

  size_type size() const
  { return c.size(); }

  reference top()
  { return c.back(); }

  const_reference top() const
  { return c.back(); }

  void push(const value_type& __x)
  { c.push_back(__x); }

  void pop()
  { c.pop_back(); }

  friend bool operator==(const ft::stack<_Tp, _Sequence>& __x,
                        const ft::stack<_Tp, _Sequence>& __y)
  { return __x.c == __y.c; }

  friend bool operator<(const ft::stack<_Tp, _Sequence>& __x,
                        const ft::stack<_Tp, _Sequence>& __y)
  { return __x.c < __y.c; }

};

template<typename _Tp, typename _Seq>
bool operator!=(const ft::stack<_Tp, _Seq>& __x, const ft::stack<_Tp, _Seq>& __y)
{ return !(__x == __y); }

template<typename _Tp, typename _Seq>
bool operator>(const ft::stack<_Tp, _Seq>& __x, const ft::stack<_Tp, _Seq>& __y)
{ return __y < __x; }

template<typename _Tp, typename _Seq>
bool operator<=(const ft::stack<_Tp, _Seq>& __x, const ft::stack<_Tp, _Seq>& __y)
{ return !(__y < __x); }

template<typename _Tp, typename _Seq>
bool operator>=(const ft::stack<_Tp, _Seq>& __x, const ft::stack<_Tp, _Seq>& __y)
{ return !(__x < __y); }

}; // namespace ft

#endif