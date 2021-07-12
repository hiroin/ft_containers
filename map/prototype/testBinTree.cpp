#include "testBinTree.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "ft_pair.hpp"

int main(int argc, char const *argv[]) {

  ft::BinTree<int, int> bt;
  ft::pair<int, int> p;
  p = ft::make_pair(10, 10);
  bt.append(p);
  std::cout << "main() bt.root->data->first: " << bt.root->data->first << std::endl;

  return 0;
}
