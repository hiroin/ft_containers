#include <fstream>
#include <iostream>
#include <queue>
#include "iterator.hpp"

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

template <typename T> struct BinTreeNode {
  T data;
  struct BinTreeNode<T> *Parent;
  struct BinTreeNode<T> *LHS;
  struct BinTreeNode<T> *RHS;
  int height;
  int bias;
};

template <typename T, typename _Alloc = std::allocator<BinTreeNode<T>>>
class BinTree {
public:
  typedef _Alloc allocator_type;

  BinTree();
  ~BinTree();

  BinTreeNode<T> *getRoot();
  
  void deleteTree(BinTreeNode<T> *node);
  bool search(T data);
  bool append(T data);
  bool erase(T data);
  void print();
  void printTree(BinTreeNode<T> *node, size_t depth);
  void graph();
  void animation(std::string dir);
  void graphDebug();
  // bool checkBin();
  bool checkAVL();

private:
  allocator_type alloc_;

  struct BinTreeNode<T> *root;
  struct BinTreeNode<T> *nullNode;
  int animationCount;

  int bias(struct BinTreeNode<T> *node);
  void modHeight(struct BinTreeNode<T> *node);

  BinTreeNode<T> *searchNode(struct BinTreeNode<T> *node, T data);
  BinTreeNode<T> *searchParentNode(struct BinTreeNode<T> *node, T data);

  struct BinTreeNode<T> *LeftMax(struct BinTreeNode<T> *node);

  void Replace(struct BinTreeNode<T> *before, struct BinTreeNode<T> *after);

  struct BinTreeNode<T> *RotateR(struct BinTreeNode<T> *node);
  struct BinTreeNode<T> *RotateL(struct BinTreeNode<T> *node);
  struct BinTreeNode<T> *RotateRL(struct BinTreeNode<T> *node);
  struct BinTreeNode<T> *RotateLR(struct BinTreeNode<T> *node);

  void ToDot();

  void BalanceA(struct BinTreeNode<T> *node);
  void BalanceE(struct BinTreeNode<T> *node);

  void DumpNode(struct BinTreeNode<T> *node);
};

template <typename T, typename _Alloc>
BinTree<T, _Alloc>::BinTree() {
  // nullNode = new struct BinTreeNode<T>;
  nullNode = alloc_.allocate(1);
  alloc_.construct(nullNode, BinTreeNode<T>());
  nullNode->LHS = nullptr;
  nullNode->RHS = nullptr;
  nullNode->Parent = nullptr;
  nullNode->height = 0;

  root = nullNode;

  animationCount = 0;
}

template <typename T, typename _Alloc>
BinTree<T, _Alloc>::~BinTree() {

  if (root == nullNode) {
    alloc_.destroy(nullNode);
    alloc_.deallocate(nullNode, 1);
    return;
  }
  deleteTree(root);
  alloc_.destroy(nullNode);
  alloc_.deallocate(nullNode, 1);
}


template <typename T, typename _Alloc>
void BinTree<T, _Alloc>::deleteTree(BinTreeNode<T> *node) {

  if (node == nullNode)
    return;
  deleteTree(node->RHS);
  deleteTree(node->LHS);
  alloc_.destroy(node);
  alloc_.deallocate(node, 1);
}

// getter
template <typename T, typename _Alloc>
BinTreeNode<T> *BinTree<T, _Alloc>::getRoot() {
  return root;
}

//--------------------
// utility
//--------------------

// node must not nullNode
template <typename T, typename _Alloc> inline int BinTree<T, _Alloc>::bias(struct BinTreeNode<T> *node) {
  return node->LHS->height - node->RHS->height;
}

template <typename T, typename _Alloc>
inline void BinTree<T, _Alloc>::modHeight(struct BinTreeNode<T> *node) {
  int lHeight = node->LHS->height;
  int rHeight = node->RHS->height;
  node->height = 1 + (lHeight > rHeight ? lHeight : rHeight);
  node->bias = lHeight - rHeight;
}


// after要素について、beforeの親からafterへのポインタをはる
template <typename T, typename _Alloc>
void BinTree<T, _Alloc>::Replace(struct BinTreeNode<T> *before,
                         struct BinTreeNode<T> *after) {
  struct BinTreeNode<T> *parentNode = before->Parent;

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
// search
//--------------------
template <typename T, typename _Alloc> bool BinTree<T, _Alloc>::search(T data) {
  struct BinTreeNode<T> *result = searchNode(root, data);

  if (result == nullNode) {
    return false;
  }

  return true;
}

template <typename T, typename _Alloc>
BinTreeNode<T> *BinTree<T, _Alloc>::searchNode(struct BinTreeNode<T> *node, T data) {
  if (node == nullNode) {
    return node;
  }

  struct BinTreeNode<T> *tmp = node;

  while (tmp != nullNode && tmp->data.first != data.first) {
    tmp = data.first < tmp->data.first ? tmp->LHS : tmp->RHS;
  }
  return tmp;
}

//--------------------
// append
//--------------------
template <typename T, typename _Alloc> bool BinTree<T, _Alloc>::append(T data) {
  // initial append
  if (root == nullNode) {
    // struct BinTreeNode<T> *newNode = new struct BinTreeNode<T>;
    struct BinTreeNode<T> *newNode = alloc_.allocate(1);
    alloc_.construct(newNode, BinTreeNode<T>());
    newNode->data = data;
    newNode->Parent = nullNode;
    newNode->LHS = nullNode;
    newNode->RHS = nullNode;
    newNode->height = 1;
    newNode->bias = 0;

    root = newNode;
    return true;
  }

  struct BinTreeNode<T> *parent = searchParentNode(root, data);

  if (parent->data.first == data.first) {
    return false;
  }

  // 念の為のガード、ありえないパターン
  if (data.first < parent->data.first) {
    if (parent->LHS != nullNode) {
      return false;
    }
  } else {
    if (parent->RHS != nullNode) {
      return false;
    }
  }

  // struct BinTreeNode<T> *newNode = new struct BinTreeNode<T>;
  struct BinTreeNode<T> *newNode = alloc_.allocate(1);
  alloc_.construct(newNode, BinTreeNode<T>());  
  newNode->data = data;
  newNode->Parent = parent;
  newNode->LHS = nullNode;
  newNode->RHS = nullNode;
  newNode->height = 1;
  newNode->bias = 0;

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
template <typename T, typename _Alloc>
BinTreeNode<T> *BinTree<T, _Alloc>::searchParentNode(struct BinTreeNode<T> *node,
                                             T data) {
  // if node is root or nullNode,return themself.
  if (node->data.first == data.first || node == nullNode) {
    return node;
  }

  struct BinTreeNode<T> *parent = node;
  struct BinTreeNode<T> *canditate
    = data.first < node->data.first ? node->LHS : node->RHS;

  while (canditate != nullNode && canditate->data.first != data.first) {
    parent = canditate;
    canditate = data.first < canditate->data.first ? canditate->LHS : canditate->RHS;
  }

  return parent;
}

//--------------------
// erase
//--------------------
template <typename T, typename _Alloc> bool BinTree<T, _Alloc>::erase(T data) {
  struct BinTreeNode<T> *deleteNode = searchNode(root, data);

  if (deleteNode == nullNode) {
    return false;
  }

  if (deleteNode->LHS == nullNode) {
    Replace(deleteNode, deleteNode->RHS);
    BalanceE(deleteNode->RHS);
    // delete deleteNode;
    alloc_.destroy(deleteNode);
    alloc_.deallocate(deleteNode, 1);
  } else {
    struct BinTreeNode<T> *leftMaxNode = LeftMax(deleteNode);
    deleteNode->data = leftMaxNode->data;
    Replace(leftMaxNode, leftMaxNode->LHS);
    BalanceE(leftMaxNode->LHS);
    // delete leftMaxNode;
    alloc_.destroy(leftMaxNode);
    alloc_.deallocate(leftMaxNode, 1);
  }
  return true;
}

template <typename T, typename _Alloc>
struct BinTreeNode<T> *BinTree<T, _Alloc>::LeftMax(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *leftMaxNode = node->LHS;

  while (leftMaxNode->RHS != nullNode) {
    leftMaxNode = leftMaxNode->RHS;
  }
  return leftMaxNode;
}

//--------------------
// rotate
//--------------------

//      node            LHS
//   LHS    Z   -->    X   node
//  X   Y                 Y    Z
template <typename T, typename _Alloc>
struct BinTreeNode<T> *BinTree<T, _Alloc>::RotateR(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *LHS = node->LHS;
  struct BinTreeNode<T> *Y = node->LHS->RHS;

  struct BinTreeNode<T> *partitionRoot = LHS;

  node->LHS = Y;
  if (Y != nullNode) {
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
template <typename T, typename _Alloc>
struct BinTreeNode<T> *BinTree<T, _Alloc>::RotateRL(struct BinTreeNode<T> *node) {
  RotateR(node->RHS);
  return RotateL(node);
}

//   node                RHS
//  X    RHS   -->   node   Z
//     Y    Z       X    Y
template <typename T, typename _Alloc>
struct BinTreeNode<T> *BinTree<T, _Alloc>::RotateL(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *RHS = node->RHS;
  struct BinTreeNode<T> *Y = node->RHS->LHS;

  struct BinTreeNode<T> *partitionRoot = RHS;

  node->RHS = Y;
  if (Y != nullNode) {
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
template <typename T, typename _Alloc>
struct BinTreeNode<T> *BinTree<T, _Alloc>::RotateLR(struct BinTreeNode<T> *node) {
  RotateL(node->LHS);
  return RotateR(node);
}

//--------------------
// balance
//--------------------

template <typename T, typename _Alloc>
void BinTree<T, _Alloc>::BalanceA(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *targetNode = node;

  while (targetNode->Parent != nullNode) {
    struct BinTreeNode<T> *parentNode = targetNode->Parent;
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

template <typename T, typename _Alloc> void BinTree<T, _Alloc>::BalanceE(struct BinTreeNode<T> *node) {
  struct BinTreeNode<T> *targetNode = node;

  while (targetNode->Parent != nullNode) {
    struct BinTreeNode<T> *parentNode = targetNode->Parent;
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

template <typename T, typename _Alloc> void BinTree<T, _Alloc>::print() {
  printTree(root, 1);
}

template <typename T, typename _Alloc>
void BinTree<T, _Alloc>::printTree(BinTreeNode<T> *node, size_t depth) {

  if (node == nullNode)
    return;
  printTree(node->RHS, depth + 1);
  for (size_t i = 0; i < depth; i++) {
    std::cout << "";
  }
  std::cout << node->data.first << std::endl;
  printTree(node->LHS, depth + 1);
  ++depth;
}

template <typename T, typename _Alloc> void BinTree<T, _Alloc>::graph() {

  ToDot();
  system("rm bintree.dot");
  system("eog bintree.png");
  system("rm bintree.png");
}

template <typename T, typename _Alloc> void BinTree<T, _Alloc>::graphDebug() {
  std::ofstream ofs("bintree.dot");

  ofs << "digraph BinTree {" << std::endl;
  ofs << "graph [centering=\"false\",ranksep=0.2,ordering=out,nodesep=0.5];"
      << std::endl;
  ofs << "node [shape=circle,width = 0.2, height = 0.2, margin = "
         "0.01];"
      << std::endl;

  std::queue<struct BinTreeNode<T> *> queue;
  queue.push(root);

  int nullCount = 0;

  while (!queue.empty() && root != nullNode) {
    struct BinTreeNode<T> *front = queue.front();
    queue.pop();

    ofs << front->data << "[label=\"" << front->data << "("
        << front->Parent->data << "," << front->height << "," << bias(front)
        << ")\"];" << std::endl;
    if (front != root) {
      ofs << front->data << " -> " << front->Parent->data << ";" << std::endl;
    }

    if (front->LHS != nullNode) {
      ofs << front->data << " -> " << front->LHS->data << ";" << std::endl;
      queue.push(front->LHS);
    } else {
      ofs << "nullNode" << nullCount << "[label=\"0\",style=invis];"
          << std::endl;
      ofs << front->data << " -> "
          << "nullNode" << nullCount << ";" << std::endl;
      nullCount++;
    }

    if (front->RHS != nullNode) {
      ofs << front->data << " -> " << front->RHS->data << ";" << std::endl;
      queue.push(front->RHS);
    } else {
      ofs << "nullNode" << nullCount << "[label=\"0\",style=invis];"
          << std::endl;
      ofs << front->data << " -> "
          << "nullNode" << nullCount << ";" << std::endl;
      nullCount++;
    }
  }

  ofs << "}" << std::endl;

  system("dot -Kdot -Tpng bintree.dot -obintree.png");
  system("rm bintree.dot");
  system("eog bintree.png");
  system("rm bintree.png");
}

template <typename T, typename _Alloc> void BinTree<T, _Alloc>::ToDot() {
  std::ofstream ofs("bintree.dot");

  ofs << "digraph BinTree {" << std::endl;
  ofs << "graph [centering=\"false\",ranksep=0.2,ordering=out,nodesep=0.5];"
      << std::endl;
  ofs << "node [shape=circle,width = 0.2, height = 0.2, margin = "
         "0.01];"
      << std::endl;

  std::queue<struct BinTreeNode<T> *> queue;
  queue.push(root);

  int nullCount = 0;

  while (!queue.empty() && root != nullNode) {
    struct BinTreeNode<T> *front = queue.front();
    queue.pop();

    ofs << front->data << "[label=\"" << front->data << "\"];" << std::endl;

    if (front->LHS != nullNode) {
      ofs << front->data << " -> " << front->LHS->data << ";" << std::endl;
      queue.push(front->LHS);
    } else {
      ofs << "nullNode" << nullCount << "[label=\"0\",style=invis];"
          << std::endl;
      ofs << front->data << " -> "
          << "nullNode" << nullCount << "[style=invis];" << std::endl;
      nullCount++;
    }

    if (front->RHS != nullNode) {
      ofs << front->data << " -> " << front->RHS->data << ";" << std::endl;
      queue.push(front->RHS);
    } else {
      ofs << "nullNode" << nullCount << "[label=\"0\",style=invis];"
          << std::endl;
      ofs << front->data << " -> "
          << "nullNode" << nullCount << "[style=invis];" << std::endl;
      nullCount++;
    }
  }

  ofs << "}" << std::endl;

  system("dot -Kdot -Tpng bintree.dot -obintree.png");
}

template <typename T, typename _Alloc> void BinTree<T, _Alloc>::animation(std::string dir) {

  ToDot();
  system("rm bintree.dot");

  std::string moveQuery =
      "mv bintree.png " + dir + "/" + std::to_string(animationCount) + ".png";
  system(moveQuery.c_str());

  animationCount++;
}

// template <typename T, typename _Alloc> bool BinTree<T, _Alloc>::checkBin() {
//   if (root == nullNode) {
//     return true;
//   }

//   std::queue<struct BinTreeNode<T> *> queue;
//   queue.push(root);

//   while (!queue.empty()) {
//     struct BinTreeNode<T> *tmp = queue.front();
//     queue.pop();
//     T left = tmp->LHS == nullNode ? tmp->data - 1 : tmp->LHS->data;
//     T right = tmp->RHS == nullNode ? tmp->data + 1 : tmp->RHS->data;

//     if (tmp->data <= left || right <= tmp->data) {
//       DumpNode(tmp);
//       return false;
//     }

//     if (tmp->LHS != nullNode) {
//       queue.push(tmp->LHS);
//     }

//     if (tmp->RHS != nullNode) {
//       queue.push(tmp->RHS);
//     }
//   }
//   return true;
// }

template <typename T, typename _Alloc> bool BinTree<T, _Alloc>::checkAVL() {
  if (root == nullNode) {
    return true;
  }

  std::queue<struct BinTreeNode<T> *> queue;
  queue.push(root);

  while (!queue.empty()) {
    struct BinTreeNode<T> *tmp = queue.front();
    queue.pop();

    int tmpBias = bias(tmp);

    if (tmpBias <= -2 || 2 <= tmpBias) {
      DumpNode(tmp);
      return false;
    }

    if (tmp->LHS != nullNode) {
      queue.push(tmp->LHS);
    }

    if (tmp->RHS != nullNode) {
      queue.push(tmp->RHS);
    }
  }
  return true;
}

template <typename T, typename _Alloc> void BinTree<T, _Alloc>::DumpNode(struct BinTreeNode<T> *node) {
  if (node == nullNode) {
    std::cout << "nullNode" << std::endl;
    return;
  }
  std::cout << "data:" << node->data.first << ",height:" << node->height
            << ",bias:" << bias(node) << ",LHS:" << node->LHS->data.first
            << ",RHS:" << node->RHS->data.first << std::endl;

  if (node->LHS == nullNode) {
    std::cout << "LHS is nullNode" << std::endl;
  }
  if (node->RHS == nullNode) {
    std::cout << "RHS is nullNode" << std::endl;
  }
  if (node == root) {
    std::cout << "root node" << std::endl;
  }
}

}
