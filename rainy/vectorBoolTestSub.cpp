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

  ft::Bit_type_ bit = 1;
  ft::Bit_type_ index = 0;
  ft::BitReference_ br(&bit, index);
  if (br)
    std::cout << "true" << std::endl; // here
  else
    std::cout << "false" << std::endl;
  br = false;
  if (br)
    std::cout << "true" << std::endl;
  else
    std::cout << "false" << std::endl; // here
  br = true;
  if (br)
    std::cout << "br  = true" << std::endl; // here
  else
    std::cout << "br  = false" << std::endl;

  ft::Bit_type_ bit2 = 0;
  ft::Bit_type_ index2 = 0;
  ft::BitReference_ br2(&bit2, index2);
  if (br2)
    std::cout << "br2 = true" << std::endl;
  else
    std::cout << "br2 = false" << std::endl; // here

  br = br2;
  if (br)
    std::cout << "br  = true" << std::endl;
  else
    std::cout << "br  = false" << std::endl; // here
  std::cout << (br == br2) << std::endl; // 1
  br.flip();
  if (br)
    std::cout << "br  = true" << std::endl; // here
  else
    std::cout << "br  = false" << std::endl;
  if (br2)
    std::cout << "br2 = true" << std::endl;
  else
    std::cout << "br2 = false" << std::endl; // here
  std::cout << (br == br2) << std::endl; // 0

  // ft::_Bit_type x = 0;
  // ft::_Bit_type y = 0;
  // ft::_Bit_reference br(&x, y);
  // std::cout << *br._M_p << std::endl;
  // std::cout << br._M_mask << std::endl;
  // std::cout << sizeof(size_t) << std::endl;


}