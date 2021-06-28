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

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 1, ary[5]) to vec(1) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(4);
    ft_vec.reserve(4);
    std_vec.insert(std_vec.begin(), 1, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      std::cout << "--------------------" << std::endl;
      std::cout << std_vec.at(idx) << std::endl;
      std::cout << ft_vec.at(idx) << std::endl;
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return 0;
}