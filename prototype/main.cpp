// #include <vector>
#include "vector.hpp"

int main()
{
  std::allocator<int> a;
  vector<int> v1(10, 1, a);
  vector<int> v2(10, 1);
  vector<int> v3(0, 1);

  return 0;
}