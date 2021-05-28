/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:11:53 by dnakano           #+#    #+#             */
/*   Updated: 2021/03/08 12:18:24 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is re-impremantation of std::list<T> as ft::list<T>.
** Supports only C++98 features.
**
** References
** - 42 cursus subject
** - http://www.cplusplus.com/reference/list/list/
** - https://cpprefjp.github.io/reference/list/list.html
*/

#ifndef LIST_HPP
#define LIST_HPP

#include <iterator>
#include <limits>
#include <memory>

#include "algorithm.hpp"
#include "iterator.hpp"
#include "type_traits.hpp"

namespace ft {

// lineked list class template
template <class Pointer>
struct ListNode_ {
  Pointer value_;
  ListNode_* prev_;
  ListNode_* next_;

  ListNode_() {
    value_ = NULL;
    prev_ = this;
    next_ = this;
  }

  ListNode_(Pointer value, ListNode_* prev, ListNode_* next) {
    value_ = value;
    prev_ = prev;
    next_ = next;
  }

  virtual ~ListNode_() {}
};

template <class Type, class NodePointer, class DifferenceType>
class list_iterator_ {
 public:
  typedef Type value_type;
  typedef DifferenceType difference_type;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef ft::bidirectional_iterator_tag iterator_category;
  typedef NodePointer node_pointer;

 public:
  node_pointer node_;

 public:
  list_iterator_() : node_(NULL){};

  list_iterator_(node_pointer node) : node_(node) {}

  list_iterator_(const list_iterator_& x) : node_(x.node_) {}

  virtual ~list_iterator_(){};

  list_iterator_& operator=(const list_iterator_& rhs) {
    node_ = rhs.node_;
    return *this;
  }

  reference operator*() const { return *node_->value_; }
  pointer operator->() const { return node_->value_; }

  list_iterator_& operator++() {
    node_ = node_->next_;
    return *this;
  }

  list_iterator_ operator++(int) {
    list_iterator_ tmp(*this);
    node_ = node_->next_;
    return tmp;
  }

  list_iterator_& operator--() {
    node_ = node_->prev_;
    return *this;
  }

  list_iterator_ operator--(int) {
    list_iterator_ tmp(*this);
    node_ = node_->prev_;
    return tmp;
  }

  friend void swap(const list_iterator_& x, const list_iterator_& y) {
    list_iterator_ tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const list_iterator_& x, const list_iterator_& y) {
    return x.node_ == y.node_;
  }

  friend bool operator!=(const list_iterator_& x, const list_iterator_& y) {
    return !(x == y);
  }
};

template <class Type, class NodePointer, class DifferenceType>
class list_const_iterator_ {
 public:
  typedef Type value_type;
  typedef DifferenceType difference_type;
  typedef const value_type* pointer;
  typedef const value_type& reference;
  typedef ft::bidirectional_iterator_tag iterator_category;
  typedef NodePointer node_pointer;

 public:
  // pointer to data
  node_pointer node_;

 public:
  list_const_iterator_() : node_(NULL){};

  list_const_iterator_(node_pointer node) : node_(node) {}

  list_const_iterator_(const list_const_iterator_& x) : node_(x.node_) {}

  list_const_iterator_(
      const list_iterator_<Type, NodePointer, DifferenceType>& x)
      : node_(x.node_) {}

  virtual ~list_const_iterator_(){};

  list_const_iterator_& operator=(const list_const_iterator_& rhs) {
    node_ = rhs.node_;
    return *this;
  }

  list_const_iterator_& operator=(
      const list_iterator_<Type, NodePointer, DifferenceType>& rhs) {
    node_ = rhs.node_;
    return *this;
  }

  reference operator*() const { return *node_->value_; }
  pointer operator->() const { return node_->value_; }

  list_const_iterator_& operator++() {
    node_ = node_->next_;
    return *this;
  }

  list_const_iterator_ operator++(int) {
    list_const_iterator_ tmp(*this);
    node_ = node_->next_;
    return tmp;
  }

  list_const_iterator_& operator--() {
    node_ = node_->prev_;
    return *this;
  }

  list_const_iterator_ operator--(int) {
    list_const_iterator_ tmp(*this);
    node_ = node_->prev_;
    return tmp;
  }

  friend void swap(const list_const_iterator_& x,
                   const list_const_iterator_& y) {
    list_const_iterator_ tmp(x);
    x = y;
    y = tmp;
  }

  friend bool operator==(const list_const_iterator_& x,
                         const list_const_iterator_& y) {
    return x.node_ == y.node_;
  }

  friend bool operator!=(const list_const_iterator_& x,
                         const list_const_iterator_& y) {
    return !(x == y);
  }
};

template <class T, class Allocator = std::allocator<T> >
class list {
  /*** member type definitions ***/
 public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;

 private:
  typedef ListNode_<pointer> node_type;
  typedef node_type* node_pointer;

  /*** iterators ***/
 public:
  typedef list_iterator_<value_type, node_pointer, difference_type> iterator;
  typedef list_const_iterator_<value_type, node_pointer, difference_type>
      const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

 private:
  /*** private attributes ***/
  allocator_type alloc_;
  node_pointer head_;

  /*** private functions ***/
  pointer cloneVal_(const value_type& val) {
    pointer val_ptr = alloc_.allocate(1);
    alloc_.construct(val_ptr, val);
    return val_ptr;
  }

  node_pointer delOneNode_(node_pointer node) {
    node_pointer next = node->next_;
    alloc_.destroy(node->value_);
    alloc_.deallocate(node->value_, 1);
    delete node;
    return next;
  }

  node_pointer getNthNode_(node_pointer head, size_type n) {
    head = head->next_;
    while (n-- > 0) {
      head = head->next_;
    }
    return head;
  }

  node_pointer findNodeFromIterator_(const iterator& itr) const {
    node_pointer node = head_->next_;
    while (node->value_ != &(*itr) && node != head_) {
      node = node->next_;
    }
    return node;
  }

  void spliceNode_(node_pointer pos, node_pointer first, node_pointer last) {
    // connect first_->prev and last->next_
    first->prev_->next_ = last->next_;
    last->next_->prev_ = first->prev_;
    // connect pos->prev_ and first
    pos->prev_->next_ = first;
    first->prev_ = pos->prev_;
    // connect last and pos
    last->next_ = pos;
    pos->prev_ = last;
  }

  void mergeNode_(node_pointer head1, node_pointer head2) {
    if (head2->next_ == head2) {
      return;
    } else if (head1->next_ == head1) {
      spliceNode_(head1, head2->next_, head2->prev_);
      return;
    }

    node_pointer first;
    node_pointer last;
    node_pointer pos = head1->next_;
    while (1) {
      first = head2->next_;
      while (*pos->value_ <= *first->value_) {
        pos = pos->next_;
        if (pos == head1) {
          spliceNode_(pos, first, head2->prev_);
          return;
        }
      }
      last = first;
      if (last->next_ == head2) {
        spliceNode_(pos, first, head2->prev_);
        return;
      }
      while (*last->next_->value_ < *pos->value_) {
        last = last->next_;
        if (last->next_ == head2) {
          spliceNode_(pos, first, head2->prev_);
          return;
        }
      }
      spliceNode_(pos, first, last);
    }
  }

  template <class Compare>
  void mergeNode_(node_pointer head1, node_pointer head2, Compare comp) {
    if (head2->next_ == head2) {
      return;
    } else if (head1->next_ == head1) {
      spliceNode_(head1, head2->next_, head2->prev_);
      return;
    }

    node_pointer first;
    node_pointer last;
    node_pointer pos = head1->next_;
    while (1) {
      first = head2->next_;
      while (comp(*pos->value_, *first->value_) ||
             (!comp(*pos->value_, *first->value_) &&
              !comp(*first->value_, *pos->value_))) {
        pos = pos->next_;
        if (pos == head1) {
          spliceNode_(pos, first, head2->prev_);
          return;
        }
      }
      last = first;
      if (last->next_ == head2) {
        spliceNode_(pos, first, head2->prev_);
        return;
      }
      while (comp(*pos->value_, *first->value_)) {
        last = last->next_;
        if (last->next_ == head2) {
          spliceNode_(pos, first, head2->prev_);
          return;
        }
      }
      spliceNode_(pos, first, last);
    }
  }

  node_pointer mergeSort_(node_pointer head, size_type n) {
    if (n <= 1) {
      return head;
    }
    size_type n1 = n / 2;
    size_type n2 = n / 2 + n % 2;
    node_pointer tmp = getNthNode_(head, n1 - 1);
    node_type head2;
    spliceNode_(&head2, tmp->next_, head->prev_);
    mergeNode_(mergeSort_(head, n1), mergeSort_(&head2, n2));
    return head;
  }

  template <class Compare>
  node_pointer mergeSort_(node_pointer head, size_type n, Compare comp) {
    if (n <= 1) {
      return head;
    }
    size_type n1 = n / 2;
    size_type n2 = n / 2 + n % 2;
    node_pointer tmp = getNthNode_(head, n1 - 1);
    node_type head2;
    spliceNode_(&head2, tmp->next_, head->prev_);
    mergeNode_(mergeSort_(head, n1, comp), mergeSort_(&head2, n2, comp), comp);
    return head;
  }

  void allClear_() {
    clear();
    delete head_;
  }

 public:
  /*** constructor ***/
  // default constructor
  explicit list(const allocator_type& alloc = allocator_type()) {
    head_ = new node_type;
    alloc_ = alloc;
  }

  // fill construtcor
  explicit list(size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) {
    head_ = new node_type;
    alloc_ = alloc;
    assign(n, val);
  }

  // range construtcor
  template <class InputIterator>
  list(InputIterator first,
       typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                              InputIterator>::type last,
       const allocator_type& alloc = allocator_type()) {
    head_ = new node_type;
    alloc_ = alloc;
    assign(first, last);
  }

  // copy constructor
  list(const list& x) {
    head_ = new node_type;
    alloc_ = x.alloc_;
    *this = x;
  }

  ~list() { allClear_(); }

  /*** operator overload ***/
  list& operator=(const list& x) {
    if (this == &x) {
      return *this;
    }
    assign(x.begin(), x.end());
    return *this;
  }

  friend bool operator==(const list& x, const list& y) {
    node_pointer node_x = x.head_->next_;
    node_pointer node_y = y.head_->next_;
    while (node_x != x.head_ && node_y != y.head_) {
      if (*node_x->value_ != *node_y->value_) {
        return false;
      }
      node_x = node_x->next_;
      node_y = node_y->next_;
    }
    return (node_x == x.head_ && node_y == y.head_);
  }

  friend bool operator!=(const list& x, const list& y) { return !(x == y); }

  friend bool operator<(const list& x, const list& y) {
    return (
        ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
  }

  friend bool operator>(const list& x, const list& y) {
    return (
        ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end()));
  }

  friend bool operator<=(const list& x, const list& y) { return !(x > y); }
  friend bool operator>=(const list& x, const list& y) { return !(x < y); }

  /*** iterators ***/
  iterator begin() { return iterator(head_->next_); }
  const_iterator begin() const { return const_iterator(head_->next_); }
  iterator end() { return iterator(head_); }
  const_iterator end() const { return const_iterator(head_); }
  reverse_iterator rbegin() { return reverse_iterator(end()); }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

  /*** capacity ***/
  size_type size() const {
    node_pointer node = head_;
    size_type cnt = 0;
    while (head_ != node->next_) {
      node = node->next_;
      ++cnt;
    }
    return cnt;
  }

  bool empty() const { return head_ == head_->next_; }

  size_type max_size() const {
    size_type typesize = sizeof(value_type) + sizeof(value_type) % 8;
    return std::min(std::numeric_limits<size_type>::max() /
                        (typesize + sizeof(node_pointer)),
                    std::numeric_limits<size_type>::max() /
                        (typesize + sizeof(size_type) * 2));
  }

  /*** Element access ***/
  reference front() { return *head_->next_->value_; }
  const_reference front() const { return *head_->next_->value_; }
  reference back() { return *head_->prev_->value_; }
  const_reference back() const { return *head_->prev_->value_; }

  /*** Modifier ***/
  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         void>::type
  assign(InputIterator first, InputIterator last) {
    node_pointer node;
    node_pointer new_node;

    clear();
    node = head_;
    for (InputIterator itr = first; itr != last; ++itr) {
      new_node = new node_type(cloneVal_(*itr), node, node->next_);
      node->next_ = new_node;
      node = new_node;
    }
    head_->prev_ = node;
  }

  void assign(size_type n, const value_type& val) {
    node_pointer node;
    node_pointer new_node;

    clear();
    node = head_;
    while (n > 0) {
      new_node = new node_type(cloneVal_(val), node, node->next_);
      node->next_ = new_node;
      node = new_node;
      --n;
    }
    head_->prev_ = node;
  }

  void push_front(const value_type& val) {
    node_pointer new_node = new node_type(cloneVal_(val), head_, head_->next_);
    head_->next_->prev_ = new_node;
    head_->next_ = new_node;
  }

  void push_back(const value_type& val) {
    node_pointer new_node = new node_type(cloneVal_(val), head_->prev_, head_);
    head_->prev_->next_ = new_node;
    head_->prev_ = new_node;
  }

  void pop_front() {
    head_->next_ = delOneNode_(head_->next_);
    head_->next_->prev_ = head_;
  }

  void pop_back() {
    node_pointer new_last_node = head_->prev_->prev_;
    new_last_node->next_ = delOneNode_(head_->prev_);
    head_->prev_ = new_last_node;
  }

  iterator insert(iterator position, const value_type& val) {
    node_pointer node = findNodeFromIterator_(position);
    node_pointer new_node = new node_type(cloneVal_(val), node->prev_, node);
    node->prev_->next_ = new_node;
    node->prev_ = new_node;
    return iterator(new_node);
  }

  void insert(iterator position, size_type n, const value_type& val) {
    node_pointer node = findNodeFromIterator_(position);
    node_pointer new_node;
    while (n > 0) {
      new_node = new node_type(cloneVal_(val), node->prev_, node);
      node->prev_->next_ = new_node;
      node->prev_ = new_node;
      node = new_node->next_;
      --n;
    }
  }

  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         void>::type
  insert(iterator position, InputIterator first, InputIterator last) {
    node_pointer node = findNodeFromIterator_(position);
    node_pointer new_node;
    for (InputIterator itr = first; itr != last; ++itr) {
      new_node = new node_type(cloneVal_(*itr), node->prev_, node);
      node->prev_->next_ = new_node;
      node->prev_ = new_node;
      node = new_node->next_;
    }
  }

  iterator erase(iterator position) {
    node_pointer node = findNodeFromIterator_(position);
    node->next_->prev_ = node->prev_;
    node->prev_->next_ = node->next_;
    return iterator(delOneNode_(node));
  }

  iterator erase(iterator first, iterator last) {
    node_pointer node = findNodeFromIterator_(first);
    while (node->value_ != &(*last)) {
      node->next_->prev_ = node->prev_;
      node->prev_->next_ = node->next_;
      node = delOneNode_(node);
    }
    return iterator(node);
  }

  void swap(list& x) {
    node_pointer tmp = head_;
    head_ = x.head_;
    x.head_ = tmp;
  }

  void resize(size_type n, value_type val = value_type()) {
    size_type current_size = size();
    if (n > current_size) {
      insert(end(), n - current_size, val);
    } else {
      while (current_size-- > n) {
        erase(--end());
      }
    }
  }

  void clear() {
    node_pointer node = head_->next_;
    while (node != head_) {
      node = delOneNode_(node);
    }
    head_->next_ = head_;
    head_->prev_ = head_;
  }

  /*** Operations ***/
  void splice(iterator position, list& x) {
    if (x.empty()) {
      return;
    }
    spliceNode_(findNodeFromIterator_(position), x.head_->next_,
                x.head_->prev_);
  }

  void splice(iterator position, list& x, iterator i) {
    node_pointer x_node = x.findNodeFromIterator_(i);
    spliceNode_(findNodeFromIterator_(position), x_node, x_node);
  }

  void splice (iterator position, list& x, iterator first, iterator last) {
    node_pointer x_node_first = x.findNodeFromIterator_(first);
    node_pointer x_node_last = x.findNodeFromIterator_(last);
    if (x_node_first == x_node_last) {
      return ;
    }
    spliceNode_(findNodeFromIterator_(position), x_node_first, x_node_last->prev_);
  }

  void remove(const value_type& val) {
    node_pointer node = head_->next_;
    while (node != head_) {
      if (*node->value_ == val) {
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
        node = delOneNode_(node);
      } else {
        node = node->next_;
      }
    }
  }

  template <class Predicate>
  void remove_if(Predicate pred) {
    node_pointer node = head_->next_;
    while (node != head_) {
      if (pred(*node->value_)) {
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
        node = delOneNode_(node);
      } else {
        node = node->next_;
      }
    }
  }

  void unique() {
    // case size == 0
    if (head_->next_ == head_) {
      return;
    }

    node_pointer node = head_->next_->next_;
    while (node != head_) {
      if (*node->value_ == *node->prev_->value_) {
        // erase a node
        node->next_->prev_ = node->prev_;
        node->prev_->next_ = node->next_;
        node = delOneNode_(node);
      } else {
        node = node->next_;
      }
    }
  }

  template <class BinaryPredicate>
  void unique(BinaryPredicate binary_pred) {
    // case size == 0
    if (head_->next_ == head_) {
      return;
    }

    node_pointer node = head_->next_->next_;
    while (node != head_) {
      if ((*binary_pred)(*node->prev_->value_, *node->value_)) {
        // erase a node
        node->next_->prev_ = node->prev_;
        node->prev_->next_ = node->next_;
        node = delOneNode_(node);
      } else {
        node = node->next_;
      }
    }
  }

  void merge(list& x) { mergeNode_(head_, x.head_); }

  template <class Compare>
  void merge(list& x, Compare comp) {
    mergeNode_(head_, x.head_, comp);
  }

  void sort() { head_ = mergeSort_(head_, size()); }

  template <class Compare>
  void sort(Compare comp) {
    head_ = mergeSort_(head_, size(), comp);
  }

  void reverse() {
    node_pointer node1 = head_->next_;
    node_pointer node2 = head_->prev_;

    while (node1 != node2) {
      // swap value
      pointer tmp = node1->value_;
      node1->value_ = node2->value_;
      node2->value_ = tmp;

      // check end meets
      if (node1->next_ == node2) {
        return;
      }

      // go next
      node1 = node1->next_;
      node2 = node2->prev_;
    }
  }
};

template <class T, class Allocator>
void swap(list<T, Allocator>& a, list<T, Allocator>& b) {
  a.swap(b);
}

}  // namespace ft

#endif /* LIST_HPP */
