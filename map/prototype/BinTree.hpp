#include <fstream>
#include <iostream>
#include <queue>
#include "iterator.hpp"
#include "ft_pair.hpp"

namespace ft
{

// template<typename _Tp>
// struct _AVL_tree_iterator
// {
//   typedef _Tp  value_type;
//   typedef _Tp& reference;
//   typedef _Tp* pointer;

//   typedef bidirectional_iterator_tag iterator_category;
//   typedef std::ptrdiff_t             difference_type;

//   typedef _Rb_tree_iterator<_Tp>        _Self;
//   typedef _Rb_tree_node_base::_Base_ptr _Base_ptr;
//   typedef _Rb_tree_node<_Tp>*           _Link_type;

//   _Rb_tree_iterator() _GLIBCXX_NOEXCEPT
//   : _M_node() { }

//   explicit
//   _Rb_tree_iterator(_Base_ptr __x) _GLIBCXX_NOEXCEPT
//   : _M_node(__x) { }

//   reference
//   operator*() const _GLIBCXX_NOEXCEPT
//   { return *static_cast<_Link_type>(_M_node)->_M_valptr(); }

//   pointer
//   operator->() const _GLIBCXX_NOEXCEPT
//   { return static_cast<_Link_type> (_M_node)->_M_valptr(); }

//   _Self&
//   operator++() _GLIBCXX_NOEXCEPT
//   {
// _M_node = _Rb_tree_increment(_M_node);
// return *this;
//   }

//   _Self
//   operator++(int) _GLIBCXX_NOEXCEPT
//   {
// _Self __tmp = *this;
// _M_node = _Rb_tree_increment(_M_node);
// return __tmp;
//   }

//   _Self&
//   operator--() _GLIBCXX_NOEXCEPT
//   {
// _M_node = _Rb_tree_decrement(_M_node);
// return *this;
//   }

//   _Self
//   operator--(int) _GLIBCXX_NOEXCEPT
//   {
// _Self __tmp = *this;
// _M_node = _Rb_tree_decrement(_M_node);
// return __tmp;
//   }

//   bool
//   operator==(const _Self& __x) const _GLIBCXX_NOEXCEPT
//   { return _M_node == __x._M_node; }

//   bool
//   operator!=(const _Self& __x) const _GLIBCXX_NOEXCEPT
//   { return _M_node != __x._M_node; }

//   _Base_ptr _M_node;
// };

template <typename _Val> struct BinTreeNode {
  typedef BinTreeNode<_Val>* _Link_type;

  _Val data;
  _Link_type Parent;
  _Link_type LHS;
  _Link_type RHS;
  int height;
  int bias;

  BinTreeNode()
    : Parent(NULL), LHS(NULL), RHS(NULL), height(1), bias(0) {}
  BinTreeNode(_Val data)
    : data(data), Parent(NULL), LHS(NULL), RHS(NULL), height(1), bias(0) {}

};

template<typename _Key, typename _Tp, typename _Compare = std::less<_Key>
  , typename _Alloc = std::allocator<BinTreeNode<ft::pair<const _Key, _Tp> > > >
// template<typename T, typename _Alloc = std::allocator<value_type > >
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

  typedef BinTreeNode<value_type>    node_type;
  typedef node_type*                 node_pointer;

  BinTree() {
    nullNode = alloc_.allocate(1);
    alloc_.construct(nullNode, node_type());
    root = nullNode;
  }

  ~BinTree() {
    if (root == nullNode) {
      alloc_.destroy(nullNode);
      alloc_.deallocate(nullNode, 1);
      return;
    }
    deleteTree(root);
    alloc_.destroy(nullNode);
    alloc_.deallocate(nullNode, 1);
  }

  node_pointer getRoot() {
    return root;
  }

  void deleteTree(node_pointer node) {
    if (node == NULL)
      return;
    deleteTree(node->RHS);
    deleteTree(node->LHS);
    alloc_.destroy(node);
    alloc_.deallocate(node, 1);
  }

  //--------------------
  // search
  //--------------------
  bool search(node_pointer data) {
    node_pointer result = searchNode(root, data);
    if (result == NULL) {
      return false;
    }
    return true;
  }

  node_pointer searchNode(node_pointer node, value_type data) {
    if (node == NULL) {
      return node;
    }
    node_pointer tmp = node;
    while (tmp != NULL && tmp->data.first != data.first) {
      tmp = data.first < tmp->data.first ? tmp->LHS : tmp->RHS;
    }
    return tmp;
  }

  //--------------------
  // append
  //--------------------
  bool append(value_type data) {
    // initial append
    if (root == nullNode) {
      // node_pointer newNode = new value_type;
      node_pointer newNode = alloc_.allocate(1);
      node_type tmpNode(data);
      alloc_.construct(newNode, tmpNode);
      // newNode->data = data;
      // newNode->Parent = nullNode;
      // newNode->LHS = nullNode;
      // newNode->RHS = nullNode;
      // newNode->height = 1;
      // newNode->bias = 0;
      root = newNode;
      return true;
    }

    node_pointer parent = searchParentNode(root, data);

    if (parent->data.first == data.first) {
      return false;
    }

    // 念の為のガード、ありえないパターン
    if (data.first < parent->data.first) {
      if (parent->LHS != NULL) {
        return false;
      }
    } else {
      if (parent->RHS != NULL) {
        return false;
      }
    }

    // node_pointer newNode = new value_type;
    node_pointer newNode = alloc_.allocate(1);
    node_type tmpNode(data);
    alloc_.construct(newNode, tmpNode);
    // alloc_.construct(newNode, node_type());  
    // newNode->data = data;
    // newNode->Parent = parent;
    // newNode->LHS = nullNode;
    // newNode->RHS = nullNode;
    // newNode->height = 1;
    // newNode->bias = 0;

    if (data.first < parent->data.first) {
      parent->LHS = newNode;
      BalanceA(parent->LHS);
    } else {
      parent->RHS = newNode;
      BalanceA(parent->RHS);
    }

    return true;
  }

  // return parent node's pointer whose child will have "data".
  node_pointer searchParentNode(node_pointer node, value_type data) {
    // if node is root or NULL,return themself.
    if (node->data.first == data.first || node == NULL) {
      return node;
    }
    node_pointer parent = node;
    node_pointer canditate
      = data.first < node->data.first ? node->LHS : node->RHS;

    while (canditate != NULL && canditate->data.first != data.first) {
      parent = canditate;
      canditate = data.first < canditate->data.first
        ? canditate->LHS : canditate->RHS;
    }
    return parent;
  }

  //--------------------
  // erase
  //--------------------
  // bool erase(value_type data) {
  bool erase(value_type data) {
    node_pointer deleteNode = searchNode(root, data);

    if (deleteNode == NULL) {
      return false;
    }
    if (deleteNode->LHS == NULL) {
      if (deleteNode->RHS != NULL)
      {
        Replace(deleteNode, deleteNode->RHS);
        BalanceE(deleteNode->RHS);
      }
      alloc_.destroy(deleteNode);
      alloc_.deallocate(deleteNode, 1);
      if (deleteNode == root)
        root = nullNode;
    } else {
      node_pointer leftMaxNode = LeftMax(deleteNode);
      // deleteNode->data = leftMaxNode->data;
      // std::swap(deleteNode->data, leftMaxNode->data);
      // Replace(leftMaxNode, leftMaxNode->LHS);
      // BalanceE(leftMaxNode->LHS);
      // alloc_.destroy(leftMaxNode);
      // alloc_.deallocate(leftMaxNode, 1);

      // leftMaxNodeの親と子のリンク張替え
      if (leftMaxNode->LHS)
      {
        leftMaxNode->LHS->Parent = leftMaxNode->Parent;
        leftMaxNode->Parent->RHS = leftMaxNode->LHS;
      }

      // deleteNodeの位置にleftMaxNodeを移動
      leftMaxNode->Parent = deleteNode->Parent;
      leftMaxNode->LHS = deleteNode->LHS;
      leftMaxNode->RHS = deleteNode->RHS;

      // 移動したleftMaxNodeに親と子からリンクを設定
      if (deleteNode->LHS)
        deleteNode->LHS->Parent = leftMaxNode;
      if (deleteNode->RHS)
        deleteNode->RHS->Parent = leftMaxNode;
      if (deleteNode->Parent)
      {
        if (deleteNode->Parent->LHS == deleteNode)
          deleteNode->Parent->LHS = leftMaxNode;
        if (deleteNode->Parent->RHS == deleteNode)
          deleteNode->Parent->RHS = leftMaxNode;
      }
      BalanceE(leftMaxNode->LHS);
      alloc_.destroy(deleteNode);
      alloc_.deallocate(deleteNode, 1);
      deleteNode = NULL;
    }
    return true;
  }

  node_pointer LeftMax(node_pointer node) {
    node_pointer leftMaxNode = node->LHS;

    while (leftMaxNode->RHS != NULL) {
      leftMaxNode = leftMaxNode->RHS;
    }
    return leftMaxNode;
  }

private:
  allocator_type alloc_;
  node_pointer root;
  node_pointer nullNode;

  int bias(node_pointer node) {
    return node->LHS->height - node->RHS->height;
  }

  void modHeight(node_pointer node) {
    int lHeight = node->LHS->height;
    int rHeight = node->RHS->height;
    node->height = 1 + (lHeight > rHeight ? lHeight : rHeight);
    node->bias = lHeight - rHeight;
  }

  // after要素について、beforeの親からafterへのポインタをはる
  void Replace(node_pointer before, node_pointer after) {
    node_pointer parentNode = before->Parent;
    if (before == root) {
      root = after;
    } else if (parentNode->LHS == before) {
      parentNode->LHS = after;
    } else {
      parentNode->RHS = after;
    }
    after->Parent = parentNode;
  }

  //--------------------
  // rotate
  //--------------------

  //      node            LHS
  //   LHS    Z   -->    X   node
  //  X   Y                 Y    Z
  node_pointer RotateR(node_pointer node) {
    node_pointer LHS = node->LHS;
    node_pointer Y = node->LHS->RHS;
    node_pointer partitionRoot = LHS;

    node->LHS = Y;
    if (Y != NULL) {
      Y->Parent = node;
    }
    partitionRoot->RHS = node;
    Replace(node, LHS);
    node->Parent = LHS;
    modHeight(partitionRoot->RHS);
    modHeight(partitionRoot);
    return partitionRoot;
  }

  //   node                   LHS
  // W      RHS          node     RHS
  //     LHS   Z  -->   W    X   Y   Z
  //    X   Y
  node_pointer RotateRL(node_pointer node) {
    RotateR(node->RHS);
    return RotateL(node);
  }

  //   node                RHS
  //  X    RHS   -->   node   Z
  //     Y    Z       X    Y
  node_pointer RotateL(node_pointer node) {
    node_pointer RHS = node->RHS;
    node_pointer Y = node->RHS->LHS;
    node_pointer partitionRoot = RHS;

    node->RHS = Y;
    if (Y != NULL) {
      Y->Parent = node;
    }
    partitionRoot->LHS = node;
    Replace(node, RHS);
    node->Parent = RHS;
    modHeight(partitionRoot->LHS);
    modHeight(partitionRoot);
    return partitionRoot;
  }

  //       node            RHS
  //   LHS      Z      LHS     node
  //  W   RHS     --> W   X   Y    Z
  //     X   Y
  node_pointer RotateLR(node_pointer node) {
    RotateL(node->LHS);
    return RotateR(node);
  }

  //--------------------
  // balance
  //--------------------
  void BalanceA(node_pointer node) {
    node_pointer targetNode = node;

    while (targetNode->Parent != NULL) {
      node_pointer parentNode = targetNode->Parent;
      int height = parentNode->height;

      // when target node is LHS
      if (parentNode->LHS == targetNode) {
        if (bias(parentNode) == 2) {

          parentNode = bias(parentNode->LHS) >= 0 ? RotateR(parentNode)
                                                  : RotateLR(parentNode);
        } else {
          modHeight(parentNode);
        }
        // when target node is RHS
      } else {
        if (bias(parentNode) == -2) {
          parentNode = bias(parentNode->RHS) <= 0 ? RotateL(parentNode)
                                                  : RotateRL(parentNode);
        } else {
          modHeight(parentNode);
        }
      }

      if (height == parentNode->height) {
        break;
      }

      targetNode = parentNode;
    }
  }

  void BalanceE(node_pointer node) {
    node_pointer targetNode = node;

    while (targetNode->Parent != NULL) {
      node_pointer parentNode = targetNode->Parent;
      int height = parentNode->height;

      // when objective node is RHS
      if (parentNode->RHS == targetNode) {
        if (bias(parentNode) == 2) {

          parentNode = bias(parentNode->LHS) >= 0 ? RotateR(parentNode)
                                                  : RotateLR(parentNode);
        } else {
          modHeight(parentNode);
        }
        // when objective node is LHS
      } else {
        if (bias(parentNode) == -2) {
          parentNode = bias(parentNode->RHS) <= 0 ? RotateL(parentNode)
                                                  : RotateRL(parentNode);
        } else {
          modHeight(parentNode);
        }
      }

      if (height == parentNode->height) {
        break;
      }

      targetNode = parentNode;
    }
  }

  //--------------------
  // debug
  //--------------------
 public:
  void print() {
      printTree(root, 1);
  }

  void printTree(node_pointer node, size_t depth) {
    if (node == NULL)
      return;
    printTree(node->RHS, depth + 1);
    for (size_t i = 0; i < depth; i++) {
      std::cout << "";
    }
    std::cout << node->data.first << std::endl;
    printTree(node->LHS, depth + 1);
    ++depth;
  }

  void DumpNode(node_pointer node) {
    if (node == nullNode) {
      std::cout << "nullNode" << std::endl;
      return;
    }
    std::cout << "data:" << node->data.first << ",height:" << node->height
              << ",bias:" << bias(node) << ",LHS:" << node->LHS->data.first
              << ",RHS:" << node->RHS->data.first << std::endl;

    if (node->LHS == NULL) {
      std::cout << "LHS is nullNode" << std::endl;
    }
    if (node->RHS == NULL) {
      std::cout << "RHS is nullNode" << std::endl;
    }
    if (node == root) {
      std::cout << "root node" << std::endl;
    }
  }
};

}
