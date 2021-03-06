#ifndef _FT_LEXICOGRAPHICAL_COMPARE_H_
#define _FT_LEXICOGRAPHICAL_COMPARE_H_

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(
        InputIterator1 first1,
        InputIterator1 last1,
        InputIterator2 first2,
        InputIterator2 last2)
{
  for ( ; first1 != last1 && first2 != last2 ; ++first1, ++first2)
  {
    if (*first1 < *first2) return true;
    if (*first2 < *first1) return false;
  }
  return first1 == last1 && first2 != last2;
}

#endif