#include "vector.hpp"
#include <vector>
#include <list>
// #include <forward_list>
#include <string.h>

void putTestInfo(int& test_no, const std::string& outline)
{
  std::cout << "TEST No." << test_no++ << ": " << outline << std::flush;
}

int main()
{
  bool flg = 0;
  int test_no = 1;

  std::cout << "=== TEST VECTOR ===" << std::endl;

  putTestInfo(test_no, "vector: erase begin() from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin());
    ft_vec.erase(ft_vec.begin());
    std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return 0;
}