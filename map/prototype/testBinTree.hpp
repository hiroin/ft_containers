#include <fstream>
#include <iostream>
#include <queue>
#include "iterator.hpp"
#include "ft_pair.hpp"

namespace ft
{

template <typename _Val> struct BinTreeNode {
  typedef BinTreeNode<_Val>*   _Link_type;
  typedef std::allocator<_Val> allocator_type;

  _Val *data;
  _Link_type Parent;
  _Link_type LHS;
  _Link_type RHS;
  int height;
  int bias;
  allocator_type alloc_;

  BinTreeNode()
    : data(NULL), Parent(NULL), LHS(NULL), RHS(NULL), height(1), bias(0) {}
  BinTreeNode(_Val val)
    : Parent(NULL), LHS(NULL), RHS(NULL), height(1), bias(0) {
    data = alloc_.allocate(1);
    alloc_.construct(data, val);
  }
  ~BinTreeNode() {
    if (data != NULL)
    {
      // alloc_.destroy(data);
      // alloc_.deallocate(data, 1);
      std::cout << "destuct!" << std::endl;
    }
  }

};

template<typename _Key, typename _Tp, typename _Compare = std::less<_Key>
  , typename _Alloc = std::allocator<BinTreeNode<ft::pair<const _Key, _Tp> > > >
class BinTree {
 public:
  typedef _Key                       key_type;
  typedef _Tp                        mapped_type;
  typedef ft::pair<const _Key, _Tp>  value_type;
  typedef value_type*                pointer;
  typedef const value_type*          const_pointer;
  typedef value_type&                reference;
  typedef const value_type&          const_reference;
  typedef size_t                     size_type;
  typedef std::ptrdiff_t             difference_type;
  typedef _Alloc                     allocator_type;

  allocator_type alloc_;
  BinTreeNode<value_type> *root;
  BinTreeNode<value_type> *nullNode;

  BinTree() {
    nullNode = alloc_.allocate(1);
    alloc_.construct(nullNode, BinTreeNode<value_type>());
    root = nullNode;
  }

  ~BinTree() {
  }

  bool append(ft::pair<const _Key, _Tp> data) {
    if (root == nullNode) {
      BinTreeNode<value_type> *newNode = alloc_.allocate(1);
      BinTreeNode<value_type> tmpNode(data);
      alloc_.construct(newNode, tmpNode);
      root = newNode;
      std::cout << "append() root->data->first: " << root->data->first << std::endl;
      return true;
    }
    return true;
  }
};

}