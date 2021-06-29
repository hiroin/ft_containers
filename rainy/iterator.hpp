#ifndef ITERATOR_HPP
#define ITERATOR_HPP


namespace ft
{

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template <class Iterator>
struct iterator_traits {
  typedef typename Iterator::difference_type difference_type;
  typedef typename Iterator::value_type value_type;
  typedef typename Iterator::pointer pointer;
  typedef typename Iterator::reference reference;
  typedef typename Iterator::iterator_category iterator_category;
};

template <typename Iterator>
class reverseIterator
{
protected:
  Iterator current;

public:
  typedef Iterator iterator_type;
  typedef std::ptrdiff_t difference_type;
  typedef typename Iterator::value_type &reference;
  typedef typename Iterator::value_type *pointer;
  typedef random_access_iterator_tag iterator_category;

  /**
 *  default constructor
*/
  reverseIterator() : current() {}
  reverseIterator(iterator_type x) : current(x) {}

  /**
 *  copy constructor
*/
  reverseIterator(const reverseIterator &x) : current(x.current) {}
  template <class Itr>
  reverseIterator(const reverseIterator<Itr>& x) : current(x.base()) {}

  ~reverseIterator(){};

  Iterator base() const
  {
    return current;
  }

  reverseIterator& operator=(const reverseIterator& x)
  {
    if (this == &x)
      return *this;
    current = x.current;
    return *this;
  }

  reference operator*() const
  {
    Iterator tmp = current;
    return *--tmp;
  }

  pointer operator->() const
  {
    return &(operator*());
  }

  reverseIterator &operator++()
  {
    --current;
    return *this;
  }

  reverseIterator operator++(int)
  {
    reverseIterator tmp = *this;
    --current;
    return tmp;
  }

  reverseIterator &operator--()
  {
    ++current;
    return *this;
  }

  reverseIterator operator--(int)
  {
    reverseIterator tmp = *this;
    ++current;
    return tmp;
  }

  reverseIterator operator+(difference_type n)
  {
    return reverseIterator(current - n);
  }

  reverseIterator &operator+=(difference_type n)
  {
    current -= n;
    return *this;
  }

  reverseIterator operator-(difference_type n)
  {
    return reverseIterator(current + n);
  }

  reverseIterator &operator-=(difference_type n)
  {
    current += n;
    return *this;
  }

  reference operator[](difference_type n)
  {
    return *(*this + n);
  }
};

template <typename Iterator>
bool operator==(const reverseIterator<Iterator> &x,
                const reverseIterator<Iterator> &y)
{
  return x.base() == y.base();
}

template <typename Iterator>
bool operator<(const reverseIterator<Iterator> &x,
                const reverseIterator<Iterator> &y)
{
  return y.base() < x.base();
}

template <typename Iterator>
bool operator!=(const reverseIterator<Iterator> &x,
                const reverseIterator<Iterator> &y)
{
  return !(x == y);
}

template <typename Iterator>
bool operator>(const reverseIterator<Iterator> &x,
                const reverseIterator<Iterator> &y)
{
  return y < x;
}

template <typename Iterator>
bool operator<=(const reverseIterator<Iterator> &x,
                const reverseIterator<Iterator> &y)
{
  return !(y < x);
}

template <typename Iterator>
bool operator>=(const reverseIterator<Iterator> &x,
            const reverseIterator<Iterator> &y)
{
  return !(x < y);
}

template <typename IteratorL, typename IteratorR>
bool
operator==(const reverseIterator<IteratorL> &x,
            const reverseIterator<IteratorR> &y)
{
  return x.base() == y.base();
}

template <typename IteratorL, typename IteratorR>
bool
operator<(const reverseIterator<IteratorL> &x,
          const reverseIterator<IteratorR> &y)
{
  return y.base() < x.base();
}

template <typename IteratorL, typename IteratorR>
bool
operator!=(const reverseIterator<IteratorL> &x,
            const reverseIterator<IteratorR> &y)
{
  return !(x == y);
}

template <typename IteratorL, typename IteratorR>
bool
operator>(const reverseIterator<IteratorL> &x,
          const reverseIterator<IteratorR> &y)
{
  return y < x;
}

template <typename IteratorL, typename IteratorR>
bool
operator<=(const reverseIterator<IteratorL> &x,
            const reverseIterator<IteratorR> &y)
{
  return !(y < x);
}

template <typename IteratorL, typename IteratorR>
bool
operator>=(const reverseIterator<IteratorL> &x,
            const reverseIterator<IteratorR> &y)
{
  return !(x < y);
}

template <typename Iterator>
typename reverseIterator<Iterator>::difference_type
operator-(const reverseIterator<Iterator> &x,
          const reverseIterator<Iterator> &y)
{
  return y.base() - x.base();
}

template <typename Iterator>
reverseIterator<Iterator>
operator+(typename reverseIterator<Iterator>::difference_type n,
          const reverseIterator<Iterator> &x)
{
  return reverseIterator<Iterator>(x.base() - n);
}

}; // namespace ft

#endif