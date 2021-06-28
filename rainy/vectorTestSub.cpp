#include "vector.hpp"
#include <vector>
#include <list>
// #include <forward_list>
#include <string.h>
#include "Hoge.hpp"

void putTestInfo(int& test_no, const std::string& outline)
{
  std::cout << "TEST No." << test_no++ << ": " << outline << std::flush;
}

int main()
{
  bool flg = 0;
  int test_no = 1;

  std::cout << "=== TEST VECTOR ===" << std::endl;

  Hoge hoge[10] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2), Hoge(3, 3), Hoge(4, 4),
                   Hoge(5, 5), Hoge(6, 6), Hoge(7, 7), Hoge(8, 8), Hoge(9, 9)};
  std::vector<Hoge> hoge_vec(hoge, &hoge[10]);
  std::list<Hoge> hoge_lst(hoge, &hoge[10]);

  putTestInfo(test_no, "construct using ft::iterator");
  try {
    int n;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std::vector<int>::iterator std_itr;
    ft::vector<int>::iterator ft_itr;
    std::vector<int>::reverse_iterator std_ritr;
    ft::vector<int>::reverse_iterator ft_ritr;
    std::vector<int>::const_iterator std_citr;
    ft::vector<int>::const_iterator ft_citr;
    std::vector<int>::const_reverse_iterator std_critr;
    ft::vector<int>::const_reverse_iterator ft_critr;

    for (int i = 0; i < 1000; i++) {
      n = rand() % 1000;
      std_vec.push_back(n);
      ft_vec.push_back(n);
    }

    for (std_itr = std_vec.begin(), ft_itr = ft_vec.begin();
         std_itr != std_vec.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_itr != ft_vec.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_ritr = std_vec.rbegin(), ft_ritr = ft_vec.rbegin();
         std_ritr != std_vec.rend(); ++std_ritr, ++ft_ritr) {
      if (*std_ritr != *ft_ritr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_ritr != ft_vec.rend()) {
      throw std::runtime_error("rev iterator");
    }

    for (std_citr = std_vec.begin(), ft_citr = ft_vec.begin();
         std_citr != std_vec.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_citr != ft_vec.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_critr = std_vec.rbegin(), ft_critr = ft_vec.rbegin();
         std_critr != std_vec.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_critr != ft_vec.rend()) {
      throw std::runtime_error("rev iterator");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return 0;
}