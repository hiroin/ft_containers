#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include "test.hpp"
#include "vectorBool.hpp"

int main()
{
  typedef std::allocator<size_t> Allocator ;
  typedef Allocator allocator_type;
  allocator_type alloc_;

  {
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
  }
  std::cout << "--------------------------------------" << std::endl;
  {
    ft::Bit_type_ bit1 = 1;
    ft::BitReference_ br1(&bit1, 0);  
    ft::Bit_type_ bit0 = 0;
    ft::BitReference_ br0(&bit0, 0);  
    std::cout << (br1 < br0) << std::endl;
    std::cout << (br0 < br1) << std::endl;
  }
  std::cout << "--------------------------------------" << std::endl;
  {
    ft::Bit_type_ bit3 = 87;
    ft::bitIterator bitr(&bit3, 0);
    std::cout << "*bitr   : " << *bitr << std::endl;
    std::cout << "*++bitr : " << *++bitr << std::endl;
    std::cout << "*++bitr : " << *++bitr << std::endl;
    std::cout << "*++bitr : " << *++bitr << std::endl;
    std::cout << "*++bitr : " << *++bitr << std::endl;
    std::cout << "*++bitr : " << *++bitr << std::endl;
    std::cout << "*++bitr : " << *++bitr << std::endl;
    std::cout << "*++bitr : " << *++bitr << std::endl;
    std::cout << std::endl;
    std::cout << "*--bitr : " << *--bitr << std::endl;
    std::cout << "*--bitr : " << *--bitr << std::endl;
    std::cout << "*--bitr : " << *--bitr << std::endl;
  }
  std::cout << "--------------------------------------" << std::endl;
  {
    ft::Bit_type_ bit3 = 87;
    ft::bitIterator bitr(&bit3, 0);
    std::cout << "*bitr   : " << *bitr << std::endl;
    std::cout << "*bitr++ : " << *bitr++ << std::endl;
    std::cout << "*bitr++ : " << *bitr++ << std::endl;
    std::cout << "*bitr++ : " << *bitr++ << std::endl;
    std::cout << "*bitr++ : " << *bitr++ << std::endl;
    std::cout << "*bitr++ : " << *bitr++ << std::endl;
    std::cout << "*bitr++ : " << *bitr++ << std::endl;
    std::cout << "*bitr++ : " << *bitr++ << std::endl;
    std::cout << std::endl;
    std::cout << "*bitr-- : " << *bitr-- << std::endl;
    std::cout << std::endl;
  }
  std::cout << "--------------------------------------" << std::endl;
  {
    ft::Bit_type_ bit3 = 16;
    ft::bitIterator bitr(&bit3, 0);
    bitr += 4;
    std::cout << "*bitr   : " << *bitr << std::endl;
    bitr += 4;
    bitr -= 4;
    std::cout << "*bitr   : " << *bitr << std::endl;
    bitr -= 4;
    std::cout << "bitr[4] : " << bitr[4] << std::endl;
    bitr = bitr + 4;
    std::cout << "*bitr   : " << *bitr << std::endl;
    bitr = bitr - 4;
    bitr = bitr + 4;
    std::cout << "*bitr   : " << *bitr << std::endl;
    bitr = -4 + bitr;
    bitr = 4 + bitr;
    std::cout << "*bitr   : " << *bitr << std::endl;
  }
  std::cout << "--------------------------------------" << std::endl;
  {
    ft::Bit_type_ bit10000 = 16;
    ft::bitIterator bitr10000(&bit10000, 0);
    ft::Bit_type_ bit10000_2 = 16;
    ft::bitIterator bitr10000_2(&bit10000, 0);
    ft::Bit_type_ bit11000 = 24;
    ft::bitIterator bitr11000(&bit11000, 0);
    std::cout << "(bitr11000 == bitr10000)   : " << (bitr11000 == bitr10000) << std::endl;
    std::cout << "(bitr11000 != bitr10000)   : " << (bitr11000 != bitr10000) << std::endl;
    std::cout << "(bitr10000 == bitr10000_2) : " << (bitr10000 == bitr10000_2) << std::endl;
    std::cout << "(bitr10000 < bitr11000)    : " << (bitr10000 < bitr11000) << std::endl;
    std::cout << "(bitr10000 > bitr11000)    : " << (bitr10000 > bitr11000) << std::endl;
    std::cout << "(bitr10000 <= bitr10000_2) : " << (bitr10000 <= bitr10000_2) << std::endl;
    std::cout << "(bitr10000 >= bitr10000_2) : " << (bitr10000 >= bitr10000_2) << std::endl;
    std::cout << "(bitr10000 <= bitr11000)   : " << (bitr10000 <= bitr11000) << std::endl;
    std::cout << "(bitr10000 >= bitr11000)   : " << (bitr10000 >= bitr11000) << std::endl;
  }





}