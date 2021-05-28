// #include "myVector.hpp"
#include <vector>

int main()
{
  // vector<int> v(1);
  std::vector<int> v;
  v.push_back(1);
  std::vector<int> v2;
  v2.push_back(200);
  v2.push_back(201);
  int i = 100;
  v.insert(v.begin(), i);
  v.insert(v.begin(), 2, i);
  v.insert(v.begin(), v2.begin(), v2.end());
  return 0;
}