#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
  std::vector<int> v1;
  std::vector<int> v2;
  std::vector<int> v3;
  std::cout << INT32_MAX << std::endl;
  v3.reserve(214748364);
  v1.push_back(1);
  v1.push_back(2);
  v2.push_back(1);
  v2.push_back(2);

  std::cout << std::equal(v1.begin(), v1.end(), v2.begin()) << std::endl;

  return 0;
}