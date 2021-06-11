#include "test.hpp"
#include "vector.hpp"
#include <algorithm>
#include <iostream>

int main()
{
  func(1);
  func("a");

  ft::vector<int> v4(2, 1);
  std::cout << v4[0] << std::endl;
  std::cout << v4[1] << std::endl;

  ft::vector<int> v5(v4.begin(), v4.end());

  // ft::vector<int> v3(10);
  // v3[0] = 0;
  // v3[9] = 9;
  // try
  // {
  //   v3.at(10) = 10;
  // }
  // catch(const std::exception& e)
  // {
  //   std::cerr << e.what() << '\n';
  // }
  // std::cout << v3[0] << std::endl;

  // ft::vector<int> v1;
  // ft::vector<int> v2;
  // v1.push_back(1);
  // v1.push_back(2);
  // v2.push_back(1);
  // v2.push_back(2);

  // std::cout << std::equal(v1.begin(), v1.end(), v2.begin()) << std::endl;
  return 0;
}