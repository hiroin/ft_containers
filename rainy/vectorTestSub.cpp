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

  putTestInfo(test_no, "assign(42, 21) to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.assign(42, 21);
    ft_vec.assign(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << idx << std::endl;
        std::cout << std_vec[idx] << std::endl;
        std::cout << ft_vec[idx] << std::endl;
        throw std::runtime_error("failed1");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return 0;
}