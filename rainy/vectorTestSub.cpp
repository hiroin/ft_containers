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

  putTestInfo(test_no, "insert(begin(), 43, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(4, 2);
    ft::vector<int> ft_vec(4, 2);
    std_vec.insert(std_vec.begin(), 5, 4);
    ft_vec.insert(ft_vec.begin(), 5, 4);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
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