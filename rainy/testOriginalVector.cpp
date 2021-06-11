#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> v1 = {1,2,3,4,5} ;
    std::vector<int> v2 = {1,2,3,4,5} ;

    auto x = std::begin(v1) ;
    auto y = std::begin(v2) ;

    // x, yは0番目の要素を指す

    bool b1 = (x == y) ; // true
    bool b2 = (x != y) ; // false
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

}