#include "BinTree.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include "ft_pair.hpp"
#include "map.hpp"

#define FILENAME "rand.csv"

bool genRand(int node_n) {
  std::ofstream ofs(FILENAME);
  if (ofs.fail()) {
    return false;
  }

  srand((unsigned int)time(NULL));

  for (int i = 0; i < node_n; i++) {
    ofs << rand() << std::endl;
  }

  return true;
}

int main(int argc, char const *argv[]) {

  // ft::pair<int, int> p1;
  // p1 = ft::make_pair(1, 1);
  // ft::BinTreeNode<ft::pair<int, int> > bt1(p1);
  // return 0;

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

  ft::BinTree<int, int> bt;

  {
    // int search;
    // ft::pair<int, int> p;
    // for (int i = 0; i < node_n; i++) {
    //   // search = rand[i];
    //   search = 30 - i * 4;
    //   std::cout << "append: " << search << std::endl;
    //   p = ft::make_pair(search, search);
    //   bt.append(p);
    // }
    // bt.append(ft::make_pair(28, 28));
    // bt.append(ft::make_pair(32, 32));
    // bt.append(ft::make_pair(25, 25));
    // bt.append(ft::make_pair(26, 26));
    // bt.append(ft::make_pair(24, 24));
    // std::cout << "------------------------" << std::endl;

    // bt.print();
    // bt.printMaximumNode();

    // p = ft::make_pair(26, 26);
    // bt.erase(p);

    // for (int i = 0; i < node_n; i++) {
    //   // search = rand[i];
    //   search = 10 - i;
    //   p = ft::make_pair(search, search);
    //   // bt.erase(p);
    // }
    // std::cout << "------------------------" << std::endl;
    // bt.print();
  }

  // {
  //   int search;
  //   ft::pair<int, int> p;
  //   for (int i = 0; i < node_n; i++) {
  //     search = rand[i];
  //     std::cout << "append: " << search << std::endl;
  //     p = ft::make_pair(search, search);
  //     bt.append(p);
  //   }
  //   std::cout << "------------------------" << std::endl;
  //   bt.print();
  //   for (int i = 0; i < node_n; i++) {
  //     search = rand[i];
  //     p = ft::make_pair(search, search);
  //     bt.erase(p);
  //   }
  //   std::cout << "------------------------" << std::endl;
  //   bt.print();
  // }

  {
    // std::cout << "std---------------------" << std::endl;
    // std::pair<int,int> std_pair;
    // std_pair = std::make_pair(1,1);
    // std::map<int, int> std_map;
    // std_map.insert(std_pair);
    // std::map<int,int>::iterator std_itr;
    // std_itr = std_map.begin();
    // std::cout << (*std_itr).first << std::endl;
    // std_itr++;
    // std::cout << (*std_itr).first << std::endl;
    // std::cout << "------------------------" << std::endl;
  
    // int search;
    // ft::pair<int, int> p;
    // for (int i = 0; i < node_n; i++) {
    //   search = 10 - i;
    //   std::cout << "append: " << search << std::endl;
    //   p = ft::make_pair(search, search);
    //   bt.append(p);
    // }
    // std::cout << "------------------------" << std::endl;
    // bt.print();
    // std::cout << "------------------------" << std::endl;

    // ft::BinTreeNode<ft::pair<const int, int> > *byn1 = bt.getRoot();
    // std::cout << "root: " << byn1->data->first << std::endl;
    // ft::_AVL_tree_iterator<ft::pair<const int, int> > itr(byn1);
    // ft::_AVL_tree_iterator<ft::pair<const int, int> > itr2(byn1);
    // std::cout << itr->first << std::endl;
    // std::cout << (*itr).first << std::endl;
    // ++itr2;
    // itr++;
    // std::cout << itr->first << std::endl;
    // if (itr2 == itr)
    //   std::cout << "itr2 == itr" << std::endl;
    // itr++;
    // if (itr2 != itr)
    //   std::cout << "itr2 != itr" << std::endl;
    // std::cout << itr->first << std::endl;
    // itr++;
    // std::cout << itr->first << std::endl;
    // itr++;
    // std::cout << itr->first << std::endl;
  }

  // {
  //   int search;
  //   ft::pair<int, int> p;
  //   for (int i = 0; i < node_n; i++) {
  //     search = 10 - i;
  //     std::cout << "append: " << search << std::endl;
  //     p = ft::make_pair(search, search);
  //     bt.append(p);
  //   }
  //   std::cout << "------------------------" << std::endl;
  //   bt.print();
  //   std::cout << "------------------------" << std::endl;

  //   ft::BinTreeNode<ft::pair<const int, int> > *byn1 = bt.getRoot();
  //   std::cout << "root: " << byn1->data->first << std::endl;
  //   ft::_AVL_tree_iterator<ft::pair<const int, int> > itr(byn1);
  //   std::cout << itr->first << std::endl;
  //   itr--;
  //   std::cout << itr->first << std::endl;
  //   itr--;
  //   std::cout << itr->first << std::endl;
  //   itr--;
  //   std::cout << itr->first << std::endl;
  //   itr--;
  //   std::cout << itr->first << std::endl;
  //   itr--;
  //   std::cout << itr->first << std::endl;
  //   itr--;
  //   std::cout << itr->first << std::endl;
  //   itr--;
  //   std::cout << itr->first << std::endl;
  // }

  // {
  //   int search;
  //   ft::pair<int, int> p;
  //   for (int i = 0; i < node_n; i++) {
  //     search = 10 - i;
  //     std::cout << "append: " << search << std::endl;
  //     p = ft::make_pair(search, search);
  //     bt.append(p);
  //   }
  //   std::cout << "------------------------" << std::endl;
  //   bt.print();
  //   std::cout << "------------------------" << std::endl;

  //   ft::BinTreeNode<ft::pair<const int, int> > *byn1 = bt.getRoot();
  //   std::cout << "root: " << byn1->data->first << std::endl;
  //   ft::_AVL_tree_iterator<ft::pair<const int, int> > itr(byn1);
  //   ft::_AVL_tree_const_iterator<ft::pair<const int, int> > citr(byn1);
  //   std::cout << itr->first << std::endl;
  //   std::cout << (*itr).first << std::endl;
  //   citr++;
  //   ++itr;
  //   std::cout << itr->first << std::endl;
  //   if (citr == itr)
  //     std::cout << "citr == itr" << std::endl;
  //   itr++;
  //   if (citr != itr)
  //     std::cout << "citr != itr" << std::endl;
  //   ++citr;
  //   std::cout << itr->first << std::endl;
  //   itr++;
  //   std::cout << itr->first << std::endl;
  //   itr++;
  //   std::cout << itr->first << std::endl;
  // }
  // {
  //   ft::map<int, std::string> ft_m;
  //   std::map<int, std::string> std_m;
  //   // std::cout << "ft  size():" << ft_m.size() << std::endl;
  //   // std::cout << "std size():" << std_m.size() << std::endl;
  //   // std::cout << "ft  empty():" << ft_m.empty() << std::endl;
  //   // std::cout << "std empty():" << std_m.empty() << std::endl;
  //   // std::cout << "ft  max_size() :" << ft_m.max_size() << std::endl;
  //   // std::cout << "std max_size() :" << std_m.max_size() << std::endl;

  //   // ft::pair<ft::map<int, std::string>::iterator, bool> result
  //   //   = ft_m.insert(ft::make_pair(7, "dnakano"));
  //   // std::cout << result.first->first << std::endl;
  //   // std::cout << result.second << std::endl;
  //   // std::cout << ft_m.size() << std::endl;
  //   // result = ft_m.insert(ft::make_pair(7, "dnakano"));    
  //   // std::cout << result.first->first << std::endl;
  //   // std::cout << result.second << std::endl;
  //   // std::cout << ft_m.size() << std::endl;

  //   std_m.insert(std::make_pair(100,"one"));
  //   std_m.insert(std::make_pair(200,"two"));
  //   std_m.insert(std::make_pair(300,"three"));
  //   std::map<int, std::string>::iterator itr = std_m.begin();
  //   std::cout << "begin(): 100 : " <<  itr->first << std::endl;
  //   ++itr;
  //   std::cout << "++itr  : 200 : " <<  itr->first << std::endl;
  //   ++itr;
  //   std::cout << "++itr  : 300 : " <<  itr->first << std::endl;
  //   ++itr;
  //   std::cout << "end()  : ?   : " <<  itr->first << std::endl;
  //   ++itr;
  //   std::cout << "++itr  : ?   : " <<  itr->first << std::endl;
  //   ++itr;
  //   std::cout << "++itr  : ?   : " <<  itr->first << std::endl;
  //   itr = std_m.end();
  //   std::cout << "end()  : ?   : " <<  itr->first << std::endl;
  //   --itr;
  //   std::cout << "--itr  : 300 : " <<  itr->first << std::endl;
  //   --itr;
  //   std::cout << "--itr  : 200 : " <<  itr->first << std::endl;
  //   --itr;
  //   std::cout << "--itr  : 100 : " <<  itr->first << std::endl;
  //   --itr;
  //   std::cout << "--itr  : ?   : " <<  itr->first << std::endl;
  //   ++itr;
  //   std::cout << "++itr  : ? : " <<  itr->first << std::endl;

  //   std::map<int, std::string>::iterator itr_null(NULL);
  //   std::map<int, std::string>::iterator itr_end = std_m.end();
  //   if (itr_null == itr_end)
  //     std::cout << "itr_null == itr_end" << std::endl;
  //   else
  //     std::cout << "itr_null != itr_end" << std::endl;
  //   ++itr_end;
  //   --itr_end;
  //   std::map<int, std::string>::iterator itr_end2 = std_m.end();
  //   if (itr_end == itr_end2)
  //     std::cout << "itr_end == itr_end2" << std::endl;
  //   else
  //     std::cout << "itr_end != itr_end2" << std::endl;
  // }

  {
    std::cout << "------------------------" << std::endl;
    ft::map<int, std::string> ft_m;
    ft_m.insert(ft::make_pair(100,"one"));
    ft_m.insert(ft::make_pair(200,"two"));
    ft_m.insert(ft::make_pair(300,"three"));
    // ft::map<int, std::string>::iterator itr = ft_m.begin();
    // std::cout << "begin(): 100 : " <<  itr->first << std::endl;
    // ++itr;
    // std::cout << "++itr  : 200 : " <<  itr->first << std::endl;
    // ++itr;
    // std::cout << "++itr  : 300 : " <<  itr->first << std::endl;
    // ++itr;
    // std::cout << "end()  : ?   : " <<  itr->first << std::endl;
    // --itr;
    // std::cout << "--itr  : 300 : " <<  itr->first << std::endl;
    // ++itr;
    // std::cout << "end()  : ?   : " <<  itr->first << std::endl;
    ft::map<int, std::string>::iterator itr_end = ft_m.end();
    // if (itr == itr_end)
    //   std::cout << "itr == itr_end" << std::endl;

    // ft::map<int, std::string>::iterator itr_null(NULL);
    // if (itr_null == itr_end)
    //   std::cout << "itr_null == itr_end" << std::endl;
    // else
    //   std::cout << "itr_null != itr_end" << std::endl;
    std::cout << ft_m.lower_bound(0)->first << std::endl;
    std::cout << ft_m.lower_bound(100)->first << std::endl;
    std::cout << ft_m.lower_bound(150)->first << std::endl;
    std::cout << ft_m.lower_bound(200)->first << std::endl;
    std::cout << ft_m.lower_bound(350)->first << std::endl;
    std::cout << ((ft_m.lower_bound(350)) == itr_end) << std::endl;

    std::cout << "ft_m[100]: " << ft_m[100] << std::endl;
    std::cout << "ft_m[200]: " << ft_m[200] << std::endl;
    std::cout << "ft_m[300]: " << ft_m[300] << std::endl;
    std::cout << "ft_m[400]: " << ft_m[400] << std::endl;
#ifdef DEBUG
    ft_m.print();
#endif
  }


  {
    ft::map<int, std::string> ft_m;
    ft::pair<int, std::string> ft_persons[10] = {
        ft::pair<int, std::string>(7, "dnakano"),
        ft::pair<int, std::string>(2, "nop"),
        ft::pair<int, std::string>(4, "bunjiro"),
        ft::pair<int, std::string>(0, "deedee"),
        ft::pair<int, std::string>(9, "sataharu"),
        ft::pair<int, std::string>(8, "marvin"),
        ft::pair<int, std::string>(5, "hoge"),
        ft::pair<int, std::string>(1, "fuga"),
        ft::pair<int, std::string>(6, "foobar"),
        ft::pair<int, std::string>(3, "norminette")};
    ft_m.insert(ft_persons[0]);
    ft_m.insert(ft_persons, ft_persons + 10);
    // ft::map<int, std::string> ft_persons_map(ft_persons, ft_persons + 10);
  }
  return 0;
}
