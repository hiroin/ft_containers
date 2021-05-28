/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:39:34 by dnakano           #+#    #+#             */
/*   Updated: 2021/03/04 08:25:46 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file is re-impremantation of std::map<const T1, T2> as
** ft::map<const T1, T2>.
** Supports only C++98 features.
**
** References
** - 42 cursus subject
** - http://www.cplusplus.com/reference/map/map/
** - https://cpprefjp.github.io/reference/map/map.html
*/

#ifndef MAP_HPP
#define MAP_HPP

#include <limits>
#include "iterator.hpp"
#include "list.hpp"
#include "stack.hpp"

namespace ft {

template <class ValueType, class KeyType, class NodePointer,
          class DifferenceType, class ValueComp, class KeyComp>
class map_iterator_ {
 public:
  typedef ValueType value_type;
  typedef KeyType key_type;
  typedef DifferenceType difference_type;
  typedef value_type* pointer;
  typedef value_type& reference;
  typedef bidirectional_iterator_tag iterator_category;

 private:
  typedef NodePointer node_pointer;
  typedef ValueComp value_compare;
  typedef KeyComp key_compare;
  typedef stack<node_pointer> stack_type;

 public:
  node_pointer node_;
  stack_type node_stack_;

 private:
  key_compare key_comp_;
  value_compare value_comp_;

  void initStack_(node_pointer root) {
    if (node_ == NULL) {
      node_stack_.push(root);
      return;
    }
    node_pointer node = root;
    while (node != node_) {
      node_stack_.push(node);
      if (value_comp_(*node_->value_, *node->value_)) {
        node = node->left_;
      } else {
        node = node->right_;
      }
    }
  }

  // find node by key and store null to node if no matches
  void findAndInitStack_(const key_type& key, node_pointer root) {
    node_ = root;
    while (node_ != NULL) {
      if (key_comp_(key, node_->value_->first)) {
        node_stack_.push(node_);
        node_ = node_->left_;
      } else if (key_comp_(node_->value_->first, key)) {
        node_stack_.push(node_);
        node_ = node_->right_;
      } else {
        return;
      }
    }
    difference_type size = node_stack_.size();
    while (size-- > 1) {
      node_stack_.pop();
    }
  }

  void toLeftest_() {
    if (node_ == NULL || node_->left_ == NULL) {
      return;
    }
    node_stack_.push(node_);
    node_ = node_->left_;
    toLeftest_();
  }

  void toRightest_() {
    if (node_ == NULL || node_->right_ == NULL) {
      return;
    }
    node_stack_.push(node_);
    node_ = node_->right_;
    toRightest_();
  }

  void toNextNode_() {
    // case in end
    if (node_ == NULL) {
      node_ = node_stack_.top();
      toLeftest_();
      return;
    }
    // case has right child
    if (node_->right_ != NULL) {
      node_stack_.push(node_);
      node_ = node_->right_;
      toLeftest_();
      return;
    }
    // find next from parent
    node_pointer prev_node;
    while (!node_stack_.empty()) {
      prev_node = node_;
      node_ = node_stack_.top();
      node_stack_.pop();
      if (prev_node == node_->left_) {
        return;
      }
    }
    // case next is an end
    node_stack_.push(node_);
    node_ = NULL;
  }

  void toPrevNode_() {
    // case in end
    if (node_ == NULL) {
      node_ = node_stack_.top();
      toRightest_();
      return;
    }
    // case has left child
    if (node_->left_ != NULL) {
      node_stack_.push(node_);
      node_ = node_->left_;
      toRightest_();
      return;
    }
    // find next from parent
    node_pointer prev_node;
    while (!node_stack_.empty()) {
      prev_node = node_;
      node_ = node_stack_.top();
      node_stack_.pop();
      if (prev_node == node_->right_) {
        return;
      }
    }
    // case next is an end
    node_stack_.push(node_);
    node_ = NULL;
  }

 public:
  map_iterator_() : node_(NULL), value_comp_(key_compare()) {
    key_comp_ = key_compare();
    value_comp_ = value_compare(key_comp_);
  }

  map_iterator_(node_pointer node, node_pointer root)
      : node_(node), value_comp_(key_comp_) {
    initStack_(root);
  }

  map_iterator_(const key_type& key, node_pointer root)
      : value_comp_(key_comp_) {
    findAndInitStack_(key, root);
  }

  map_iterator_(const map_iterator_& x)
      : node_(x.node_), node_stack_(x.node_stack_), value_comp_(key_comp_) {}

  ~map_iterator_(){};

  map_iterator_& operator=(const map_iterator_& rhs) {
    value_comp_ = rhs.value_comp_;
    node_ = rhs.node_;
    node_stack_ = rhs.node_stack_;
    return *this;
  }

  reference operator*() const { return *node_->value_; }
  pointer operator->() const { return node_->value_; }

  map_iterator_& operator++() {
    toNextNode_();
    return *this;
  }

  map_iterator_ operator++(int) {
    map_iterator_ tmp(*this);
    toNextNode_();
    return tmp;
  }

  map_iterator_& operator--() {
    toPrevNode_();
    return *this;
  }

  map_iterator_ operator--(int) {
    map_iterator_ tmp(*this);
    toPrevNode_();
    return tmp;
  }

  friend bool operator==(const map_iterator_& x, const map_iterator_& y) {
    return x.node_ == y.node_;
  }

  friend bool operator!=(const map_iterator_& x, const map_iterator_& y) {
    return !(x == y);
  }
};

template <class ValueType, class KeyType, class NodePointer,
          class DifferenceType, class ValueComp, class KeyComp>
void swap(map_iterator_<ValueType, KeyType, NodePointer, DifferenceType,
                        ValueComp, KeyComp>& x,
          map_iterator_<ValueType, KeyType, NodePointer, DifferenceType,
                        ValueComp, KeyComp>& y) {
  map_iterator_<ValueType, KeyType, NodePointer, DifferenceType, ValueComp,
                KeyComp>
      tmp(x);
  x = y;
  y = tmp;
}

template <class ValueType, class KeyType, class NodePointer,
          class DifferenceType, class ValueComp, class KeyComp>
class map_const_iterator_ {
 public:
  typedef ValueType value_type;
  typedef KeyType key_type;
  typedef DifferenceType difference_type;
  typedef const value_type* pointer;
  typedef const value_type& reference;
  typedef bidirectional_iterator_tag iterator_category;

 private:
  typedef NodePointer node_pointer;
  typedef ValueComp value_compare;
  typedef KeyComp key_compare;
  typedef stack<node_pointer> stack_type;

 public:
  node_pointer node_;
  stack_type node_stack_;

 private:
  key_compare key_comp_;
  value_compare value_comp_;

  void initStack_(node_pointer root) {
    if (node_ == NULL) {
      node_stack_.push(root);
      return;
    }
    node_pointer node = root;
    while (node != node_) {
      node_stack_.push(node);
      if (value_comp_(*node_->value_, *node->value_)) {
        node = node->left_;
      } else {
        node = node->right_;
      }
    }
  }

  // find node by key and store null to node if no matches
  void findAndInitStack_(const key_type& key, node_pointer root) {
    node_ = root;
    while (node_ != NULL) {
      if (key_comp_(key, node_->value_->first)) {
        node_stack_.push(node_);
        node_ = node_->left_;
      } else if (key_comp_(node_->value_->first, key)) {
        node_stack_.push(node_);
        node_ = node_->right_;
      } else {
        return;
      }
    }
    difference_type size = node_stack_.size();
    while (size-- > 1) {
      node_stack_.pop();
    }
  }

  void toLeftest_() {
    if (node_ == NULL || node_->left_ == NULL) {
      return;
    }
    node_stack_.push(node_);
    node_ = node_->left_;
    toLeftest_();
  }

  void toRightest_() {
    if (node_ == NULL || node_->right_ == NULL) {
      return;
    }
    node_stack_.push(node_);
    node_ = node_->right_;
    toRightest_();
  }

  void toNextNode_() {
    // case in end
    if (node_ == NULL) {
      node_ = node_stack_.top();
      toLeftest_();
      return;
    }
    // case has right child
    if (node_->right_ != NULL) {
      node_stack_.push(node_);
      node_ = node_->right_;
      toLeftest_();
      return;
    }
    // find next from parent
    node_pointer prev_node;
    while (!node_stack_.empty()) {
      prev_node = node_;
      node_ = node_stack_.top();
      node_stack_.pop();
      if (prev_node == node_->left_) {
        return;
      }
    }
    // case next is an end
    node_stack_.push(node_);
    node_ = NULL;
  }

  void toPrevNode_() {
    // case in end
    if (node_ == NULL) {
      node_ = node_stack_.top();
      toRightest_();
      return;
    }
    // case has left child
    if (node_->left_ != NULL) {
      node_stack_.push(node_);
      node_ = node_->left_;
      toRightest_();
      return;
    }
    // find next from parent
    node_pointer prev_node;
    while (!node_stack_.empty()) {
      prev_node = node_;
      node_ = node_stack_.top();
      node_stack_.pop();
      if (prev_node == node_->right_) {
        return;
      }
    }
    // case next is an end
    node_stack_.push(node_);
    node_ = NULL;
  }

 public:
  map_const_iterator_() : node_(NULL), value_comp_(key_compare()) {
    key_comp_ = key_compare();
    value_comp_ = value_compare(key_comp_);
  }

  map_const_iterator_(node_pointer node, node_pointer root)
      : node_(node), value_comp_(key_comp_) {
    initStack_(root);
  }

  map_const_iterator_(const key_type& key, node_pointer root)
      : value_comp_(key_comp_) {
    findAndInitStack_(key, root);
  }

  map_const_iterator_(const map_const_iterator_& x)
      : node_(x.node_), node_stack_(x.node_stack_), value_comp_(key_comp_) {}

  map_const_iterator_(
      const map_iterator_<value_type, key_type, node_pointer, difference_type,
                          value_compare, key_compare>& x)
      : node_(x.node_), node_stack_(x.node_stack_), value_comp_(key_comp_) {}

  ~map_const_iterator_(){};

  map_const_iterator_& operator=(const map_const_iterator_& rhs) {
    value_comp_ = rhs.value_comp_;
    node_ = rhs.node_;
    node_stack_ = rhs.node_stack_;
    return *this;
  }

  reference operator*() const { return *node_->value_; }
  pointer operator->() const { return node_->value_; }

  map_const_iterator_& operator++() {
    toNextNode_();
    return *this;
  }

  map_const_iterator_ operator++(int) {
    map_const_iterator_ tmp(*this);
    toNextNode_();
    return tmp;
  }

  map_const_iterator_& operator--() {
    toPrevNode_();
    return *this;
  }

  map_const_iterator_ operator--(int) {
    map_const_iterator_ tmp(*this);
    toPrevNode_();
    return tmp;
  }

  friend bool operator==(const map_const_iterator_& x,
                         const map_const_iterator_& y) {
    return x.node_ == y.node_;
  }

  friend bool operator!=(const map_const_iterator_& x,
                         const map_const_iterator_& y) {
    return !(x == y);
  }
};

template <class ValueType, class KeyType, class NodePointer,
          class DifferenceType, class ValueComp, class KeyComp>
void swap(const map_const_iterator_<ValueType, KeyType, NodePointer,
                                    DifferenceType, ValueComp, KeyComp>& x,
          const map_const_iterator_<ValueType, KeyType, NodePointer,
                                    DifferenceType, ValueComp, KeyComp>& y) {
  map_const_iterator_<ValueType, KeyType, NodePointer, DifferenceType,
                      ValueComp, KeyComp>
      tmp(x);
  x = y;
  y = tmp;
}

// class of node tree
template <class Pointer>
struct TreeNode {
  Pointer value_;
  TreeNode* left_;
  TreeNode* right_;
  size_t height_;

  TreeNode(Pointer value = NULL, TreeNode* left = NULL,
           TreeNode* right = NULL) {
    value_ = value;
    left_ = left;
    right_ = right;
    updateHeight();
  }

  virtual ~TreeNode() {}

  size_t size() const {
    return (left_ ? left_->size() : 0) + (right_ ? right_->size() : 0) + 1;
  }

  TreeNode* findLeftest() {
    if (left_ == NULL) {
      return this;
    }
    return left_->findLeftest();
  }

  TreeNode* findRightest() {
    if (right_ == NULL) {
      return this;
    }
    return right_->findRightest();
  }

  void updateHeight() {
    if (value_ == NULL) {
      height_ = 0;
    } else {
      height_ = std::max((left_ ? left_->height_ + 1 : 1),
                         (right_ ? right_->height_ + 1 : 1));
    }
  }

  ssize_t heightDiff() {
    ssize_t left_height = left_ ? static_cast<ssize_t>(left_->height_) : 0;
    ssize_t right_height = right_ ? static_cast<ssize_t>(right_->height_) : 0;
    return left_height - right_height;
  }

  void rotateLeft() {
    if (right_ == NULL) {
      return;
    }
    std::swap(value_, right_->value_);
    TreeNode* tmp_left = left_;
    left_ = right_;
    right_ = left_->right_;
    left_->right_ = left_->left_;
    left_->left_ = tmp_left;
    left_->updateHeight();
    updateHeight();
  }

  void rotateRight() {
    if (left_ == NULL) {
      return;
    }
    std::swap(value_, left_->value_);
    TreeNode* tmp_right = right_;
    right_ = left_;
    left_ = right_->left_;
    right_->left_ = right_->right_;
    right_->right_ = tmp_right;
    right_->updateHeight();
    updateHeight();
  }

  bool getBalanced() {
    updateHeight();
    ssize_t height_diff = heightDiff();
    if (height_diff > 1) {
      if (left_->heightDiff() < 0) {
        left_->rotateLeft();
      }
      rotateRight();
      return true;
    } else if (height_diff < -1) {
      if (right_->heightDiff() > 0) {
        right_->rotateRight();
      }
      rotateLeft();
      return true;
    }
    return false;
  }

  bool rebalanceAll() {
    bool balanced = false;
    if (left_) {
      balanced = left_->rebalanceAll();
    }
    if (right_) {
      balanced = (right_->rebalanceAll() || balanced);
    }
    return (getBalanced() || balanced);
  }

  void displayInfo() {
    std::cout << "node: ";
    std::cout << value_->first << "=" << value_->second;
    std::cout << ", left: ";
    if (left_) {
      std::cout << left_->value_->first << "=" << left_->value_->second;
    }
    std::cout << ", right: ";
    if (right_) {
      std::cout << right_->value_->first << "=" << right_->value_->second;
    }
    std::cout << std::endl;
  }
};

template <class Key, class T, class Compare = std::less<Key>,
          class Allocator = std::allocator<std::pair<const Key, T> > >
class map {
 public:
  /*** member type definitions ***/
  typedef Key key_type;
  typedef T mapped_type;
  typedef std::pair<const key_type, mapped_type> value_type;
  typedef Compare key_compare;
  typedef Allocator allocator_type;
  typedef typename allocator_type::reference reference;
  typedef typename allocator_type::const_reference const_reference;
  typedef typename allocator_type::pointer pointer;
  typedef typename allocator_type::const_pointer const_pointer;
  typedef typename allocator_type::size_type size_type;
  typedef typename allocator_type::difference_type difference_type;

  /*** public class definitions ***/
  class value_compare
      : public std::binary_function<value_type, value_type, bool> {
   public:
    map::key_compare comp_;
    value_compare(map::key_compare c) : comp_(c) {}
    bool operator()(const value_type& x, const value_type& y) const {
      return comp_(x.first, y.first);
    }
  };

  /*** private class definitions ***/
  typedef TreeNode<pointer> node_type;
  typedef node_type* node_pointer;

  /*** iterators ***/
  typedef map_iterator_<value_type, key_type, node_pointer, difference_type,
                        value_compare, key_compare>
      iterator;
  typedef map_const_iterator_<value_type, key_type, node_pointer,
                              difference_type, value_compare, key_compare>
      const_iterator;
  typedef ft::reverse_iterator<iterator> reverse_iterator;
  typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

  /*** private members ***/
 private:
  key_compare comp_;
  value_compare val_comp_;
  allocator_type alloc_;
  node_pointer root_;

  /*** private member functions ***/
  pointer cloneVal_(const value_type& val = value_type()) {
    pointer val_ptr = alloc_.allocate(1);
    alloc_.construct(val_ptr, val);
    return val_ptr;
  }

  void deleteVal_(pointer val_ptr) {
    if (val_ptr == NULL) {
      return;
    }
    alloc_.destroy(val_ptr);
    alloc_.deallocate(val_ptr, 1);
  }

  node_pointer findNode_(node_pointer node, const key_type& k) const {
    if (node == NULL) {
      return NULL;
    } else if (comp_(k, (*node->value_).first)) {
      return findNode_(node->left_, k);
    } else if (comp_((*node->value_).first, k)) {
      return findNode_(node->right_, k);
    } else {
      return node;
    }
  }

  node_pointer findLowerBound_(node_pointer node, const key_type& k) const {
    if (node == NULL) {
      return NULL;
    } else if (comp_(k, node->value_->first)) {
      node_pointer res = findLowerBound_(node->left_, k);
      return res ? res : node;
    } else if (comp_(node->value_->first, k)) {
      return findLowerBound_(node->right_, k);
    }
    return node;
  }

  node_pointer findUpperBound_(node_pointer node, const key_type& k) const {
    if (node == NULL) {
      return NULL;
    } else if (comp_(k, node->value_->first)) {
      node_pointer res = findUpperBound_(node->left_, k);
      return res ? res : node;
    } else {
      return findUpperBound_(node->right_, k);
    }
  }

  // This tries to insert new node with val_ptr (pointer to newly allocated
  // value) to node. If there is no element which has same key as val_ptr,
  // it will create new node to proper position and is kept balanced, then
  // returns pointer to the new node. Otherwise it will NOT create any new node
  // but returns pointer to the aleready exsiting node which has same key as
  // val_ptr.
  node_pointer insertVal_(node_pointer node, pointer val_ptr) {
    // this means node == root_ and not initialized
    if (node == NULL) {
      root_ = new node_type(val_ptr);
      return root_;
    }

    node_pointer new_node;
    if (comp_(val_ptr->first, node->value_->first)) {
      if (node->left_ == NULL) {
        new_node = new node_type(val_ptr);
        node->left_ = new_node;
      } else {
        new_node = insertVal_(node->left_, val_ptr);
      }
    } else if (comp_(node->value_->first, val_ptr->first)) {
      if (node->right_ == NULL) {
        new_node = new node_type(val_ptr);
        node->right_ = new_node;
      } else {
        new_node = insertVal_(node->right_, val_ptr);
      }
    } else {
      new_node = node;
    }
    if (node->getBalanced() && new_node->value_ != val_ptr) {
      return findNode_(node, val_ptr->first);
    }
    return new_node;
  }

  node_pointer cloneNodes_(node_pointer node) {
    return node ? new node_type(cloneVal_(*node->value_),
                                cloneNodes_(node->left_),
                                cloneNodes_(node->right_))
                : NULL;
  }

  void eraseOneNode_(node_pointer node, node_pointer parent) {
    if (node->left_ != NULL && node->right_ != NULL) {
      parent = node;
      node_pointer node_next = node->right_;
      while (node_next->left_ != NULL) {
        parent = node_next;
        node_next = node_next->left_;
      }
      std::swap(node->value_, node_next->value_);
      eraseOneNode_(node_next, parent);
      return;
    } else if (node->left_ != NULL) {
      if (parent == NULL) {
        root_ = node->left_;
      } else {
        if (node == parent->left_) {
          parent->left_ = node->left_;
        } else {
          parent->right_ = node->left_;
        }
      }
    } else {  // means if (node->right != NULL || node->right == NULL)
      if (parent == NULL) {
        root_ = node->right_;
      } else if (node == parent->left_) {
        parent->left_ = node->right_;
      } else {
        parent->right_ = node->right_;
      }
    }
    delOneNode_(node);
  }

  void delOneNode_(node_pointer node) {
    if (node == NULL) {
      return;
    }
    deleteVal_(node->value_);
    delete node;
  }

  void deleteNodes_(node_pointer node) {
    if (node == NULL) {
      return;
    }
    deleteNodes_(node->left_);
    deleteNodes_(node->right_);
    delOneNode_(node);
  }

  /*** constructors ***/
 public:
  explicit map(const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type())
      : comp_(comp), val_comp_(comp), alloc_(alloc) {
    root_ = NULL;
  }

  template <class InputIterator>
  map(InputIterator first,
      typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                             InputIterator>::type last,
      const key_compare& comp = key_compare(),
      const allocator_type& alloc = allocator_type())
      : comp_(comp), val_comp_(comp), alloc_(alloc) {
    root_ = NULL;
    insert(first, last);
  }

  map(const map& x) : comp_(x.comp_), val_comp_(x.comp_), alloc_(x.alloc_) {
    root_ = cloneNodes_(x.root_);
  }

  ~map() { deleteNodes_(root_); }

  /*** operator overloads ***/
  map& operator=(const map& x) {
    if (this == &x) {
      return *this;
    }
    deleteNodes_(root_);
    comp_ = x.comp_;
    root_ = cloneNodes_(x.root_);
    return *this;
  }

  mapped_type& operator[](const key_type& k) {
    return (*(insert(value_type(k, mapped_type())).first)).second;
  }

  /*** iterator ***/
  iterator begin() {
    return iterator(
        root_ ? root_->findLeftest() : static_cast<node_pointer>(NULL), root_);
  }
  const_iterator begin() const {
    return const_iterator(
        root_ ? root_->findLeftest() : static_cast<node_pointer>(NULL), root_);
  }

  iterator end() { return iterator(static_cast<node_pointer>(NULL), root_); }

  const_iterator end() const {
    return const_iterator(static_cast<node_pointer>(NULL), root_);
  }

  reverse_iterator rbegin() { return reverse_iterator(end()); }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  reverse_iterator rend() { return reverse_iterator(begin()); }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

  /*** capacity ***/
  bool empty() const { return root_ == NULL; }

  size_type size() const {
    return root_ ? static_cast<size_type>(root_->size()) : 0;
  }

  size_type max_size() const {
    return std::min(
        std::numeric_limits<size_type>::max() /
            (sizeof(value_type) + sizeof(node_pointer) * 4),
        std::numeric_limits<size_type>::max() / (sizeof(value_type) * 2));
  }

  /*** modifiers ***/
  std::pair<iterator, bool> insert(const value_type& val) {
    pointer new_value = cloneVal_(val);
    node_pointer node = insertVal_(root_, new_value);
    if (node->value_ == new_value) {
      return std::pair<iterator, bool>(iterator(node, root_), true);
    }
    deleteVal_(new_value);
    return std::pair<iterator, bool>(iterator(node, root_), false);
  }

  iterator insert(iterator position, const value_type& val) {
    node_pointer node_to_insert;
    if (position == end() || position.node_ == root_) {
      node_to_insert = root_;
    } else if (!val_comp_(val, *position.node_->value_) &&
               !val_comp_(*position.node_->value_, val)) {
      return position;
    } else if (position.node_ == position.node_stack_.top()->left_ &&
               val_comp_(val, *position.node_stack_.top()->value_) &&
               val_comp_(*position.node_->value_, val)) {
      node_to_insert = position.node_;
    } else if (position.node_->left_ && position.node_->right_ &&
               !val_comp_(val, *position.node_->left_->value_) &&
               !val_comp_(*position.node_->right_->value_, val)) {
      node_to_insert = position.node_;
    } else {
      node_to_insert = root_;
    }
    pointer new_value = cloneVal_(val);
    node_pointer node = insertVal_(node_to_insert, new_value);
    if (node_to_insert != root_) {
      root_->rebalanceAll();
      node = findNode_(root_, new_value->first);
    }
    if (node->value_ != new_value) {
      deleteVal_(new_value);
    }
    return iterator(node, root_);
  }

  template <class InputIterator>
  typename ft::enable_if<ft::is_input_iterator<InputIterator>::value,
                         void>::type
  insert(InputIterator first, InputIterator last) {
    for (InputIterator itr = first; itr != last; ++itr) {
      insert(*itr);
    }
  }

  void erase(iterator position) {
    eraseOneNode_(position.node_,
                  position.node_ == root_ ? NULL : position.node_stack_.top());
    if (root_) {
      root_->rebalanceAll();
    }
  }

  size_type erase(const key_type& k) {
    iterator itr = find(k);
    if (itr == end()) {
      return 0;
    }
    erase(find(k));
    return 1;
  }

  void erase(iterator first, iterator last) {
    ft::stack<key_type> stk;
    while (first != last) {
      stk.push(first.node_->value_->first);
      ++first;
    }
    while (!stk.empty()) {
      erase(stk.top());
      stk.pop();
    }
  }

  void swap(map& x) { std::swap(root_, x.root_); }

  void clear() {
    deleteNodes_(root_);
    root_ = NULL;
  }

  /*** observers ***/
  value_compare value_comp() const { return val_comp_; }
  key_compare key_comp() const { return comp_; }

  /*** operations ***/
  iterator find(const key_type& k) { return iterator(k, root_); }
  const_iterator find(const key_type& k) const {
    return const_iterator(k, root_);
  }

  size_type count(const key_type& k) const {
    return (findNode_(root_, k) == NULL ? 0 : 1);
  }

  iterator lower_bound(const key_type& k) {
    return iterator(findLowerBound_(root_, k), root_);
  }

  const_iterator lower_bound(const key_type& k) const {
    return const_iterator(findLowerBound_(root_, k), root_);
  }

  iterator upper_bound(const key_type& k) {
    return iterator(findUpperBound_(root_, k), root_);
  }

  const_iterator upper_bound(const key_type& k) const {
    return const_iterator(findUpperBound_(root_, k), root_);
  }

  std::pair<iterator, iterator> equal_range(const key_type& k) {
    return std::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
  }

  std::pair<const_iterator, const_iterator> equal_range(
      const key_type& k) const {
    return std::pair<const_iterator, const_iterator>(lower_bound(k),
                                                     upper_bound(k));
  }
};

template <class Key, class T, class Compare, class Alloc>
void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
  x.swap(y);
}

}  // namespace ft

#endif /* MAP_HPP */
