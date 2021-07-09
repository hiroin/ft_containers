#include "BinTree.hpp"
#include <cassert>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include "ft_pair.hpp"

#define FILENAME "rand.csv"

bool genRand(int node_n) {
  std::ofstream ofs(FILENAME);
  if (ofs.fail()) {
    return false;
  }

  std::random_device rand;

  for (int i = 0; i < node_n; i++) {
    ofs << rand() << std::endl;
  }

  return true;
}

int main(int argc, char const *argv[]) {
  if (argc < 1) {
    std::cout << "./a.out Node_N" << std::endl;
    exit(1);
  }
  int node_n = atoi(argv[1]);

  std::cout << "node_n is " << node_n << std::endl;

  if (genRand(node_n) == false) {
    std::cerr << "cannot generate rand" << std::endl;
    exit(1);
  }

  std::vector<int> rand;

  char buf[256];

  std::ifstream ifs(FILENAME);
  if (ifs.fail()) {
    std::cerr << "cannot open file" << std::endl;
    exit(1);
  }
  while (ifs.getline(buf, 256 - 1)) {
    rand.push_back(atoi(buf));
  }

  std::cout << rand.size() << std::endl;

  ft::BinTree<ft::pair<int, int>> bt;

  int search;
  ft::pair<int, int> p;
  for (int i = 0; i < node_n; i++) {
    search = rand[i];
    p = ft::make_pair(search, search);
    bt.append(p);
  }

  assert(bt.checkAVL());
  // assert(bt.checkBin());

  // bt.graphDebug();
  bt.print();

  // for (int i = 0; i < node_n; i++) {
  //   search = rand[i];
  //   p = ft::make_pair(search, search);
  //   bt.erase(p);
  // }

  assert(bt.checkAVL());
  // assert(bt.checkBin());

  return 0;
}
