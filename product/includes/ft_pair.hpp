#ifndef _FT_PAIR_H_
#define _FT_PAIR_H_

namespace ft
{
  template<typename _T1, typename _T2>
  struct pair
  {
    typedef _T1 first_type;
    typedef _T2 second_type;
    _T1 first;
    _T2 second;

    pair() : first(), second() { }

    pair(const _T1& __a, const _T2& __b)
      : first(__a), second(__b) { }

    template<typename _U1, typename _U2>
    pair(const pair<_U1, _U2>& __p)
      : first(__p.first), second(__p.second) { }

    pair operator=(const pair<_T1, _T2>& __x)
    {
      first = __x.first;
      second = __x.second;
      return *this;
    }
  };

  template<typename _T1, typename _T2>
  bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first == __y.first && __x.second == __y.second; }

  template<typename _T1, typename _T2>
  bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __x.first < __y.first
	     || (!(__y.first < __x.first) && __x.second < __y.second); }

  template<typename _T1, typename _T2>
  bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__x == __y); }

  template<typename _T1, typename _T2>
  bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return __y < __x; }

  template<typename _T1, typename _T2>
  bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__y < __x); }

  template<typename _T1, typename _T2>
  bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
    { return !(__x < __y); }

  template<typename _T>
  void swap(pair<_T, _T>& __x, pair<_T, _T>& __y)
  {
    _T __tmp = __x;
    __x = __y;
    __y = __tmp;
  }

  template<typename _T1, typename _T2>
  pair<_T1, _T2> make_pair(_T1 __x, _T2 __y)
    { return pair<_T1, _T2>(__x, __y); }
} // namespace ft
#endif