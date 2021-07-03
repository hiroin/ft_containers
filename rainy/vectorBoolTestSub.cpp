#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include "test.hpp"
#include "vectorBool.hpp"

static void test_value_assign(int& test_no, size_t size1, bool val1,
                              size_t size2, bool val2) {
  std::stringstream sout;
  sout << std::boolalpha << "Vector<bool>: vector(" << size1 << ", " << val1
       << ") and assign(" << size2 << ", " << val2 << ")";
  putTestInfo(test_no, sout.str());
  try {
    std::vector<bool> std_vec(size1, val1);
    ft::vector<bool> ft_vec(size1, val1);

    std_vec.assign(size2, val2);
    ft_vec.assign(size2, val2);
    for (size_t idx = 0; idx < size2; ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.capacity() << std::endl;
      std::cout << " ft: " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      // throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;
}

void test_vector_bool(int& test_no)
{
  std::cout << "=== TEST VECTOR<BOOL> ===" << std::endl;
  std::cout << std::boolalpha;
  size_t size = 0;
  size_t size_ary[] = {0,   1,   2,    63,   64,   65,   100, 127,
                       128, 129, 1023, 1024, 1025, 2000, 4000};
  bool flg = 0;
  std::stringstream sout;

  putTestInfo(test_no, "Vector<bool>: relational: vec(4242) and vec(4242)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);
    std::vector<bool> std_vec2(val, &val[size]);
    ft::vector<bool> ft_vec2(val, &val[size]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;
}

int main()
{
  int no = 1;
  test_vector_bool(no);

}