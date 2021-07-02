#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include "test.hpp"
#include "vectorBool.hpp"

int main()
{
  std::vector<bool> std_vec(65);
  std::cout << "std: " << std_vec[65] << std::endl;

  ft::vector<bool> ft_vec(65);
  std::cout << "ft: " << ft_vec[65] << std::endl;

}