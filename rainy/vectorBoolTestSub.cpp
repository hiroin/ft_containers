#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include "test.hpp"
#include "vector.hpp"

int main()
{
  typedef std::allocator<size_t> Allocator ;
  typedef Allocator allocator_type;
  allocator_type alloc_;
  
  ft::_Bit_type x = 0;
  ft::_Bit_type y = 0;
  ft::_Bit_reference br(&x, y);
  std::cout << *br._M_p << std::endl;
  std::cout << br._M_mask << std::endl;

  std::cout << sizeof(size_t) << std::endl;


}