#include "vector.hpp"
#include <algorithm>
#include <iostream>

int main()
{
  ft::vector<int> v1;
  ft::vector<int> v2;
  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(1);
  v2.push_back(2);

  // std::cout << std::equal(v1.begin(), v1.end(), v2.begin()) << std::endl;
  std::cout << v1[0] << std::endl;
  v1[0] = 2;
  return 0;
}