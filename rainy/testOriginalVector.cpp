#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
  std::vector<int> v1 = {1,2,3,4,5} ;
  std::vector<int> v2 = {1,2,3,4,5} ;
  v1.reserve(10);
  std::cout << v1.size() << std::endl;

  v1.insert(v1.begin() + 10, 10);
  std::cout << *v1.begin() << std::endl;
  std::cout << *(v1.end() - 1) << std::endl;

  std::cout << v1.size() << std::endl;

}