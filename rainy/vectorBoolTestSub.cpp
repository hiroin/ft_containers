#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include "test.hpp"
#include "vectorBool.hpp"

int main()
{
  std::vector<bool> std_vec(10);
  std::cout << "std: " << std_vec[0] << std::endl;
  std::cout << "std: " << std_vec[1] << std::endl;
  std::cout << "std: " << std_vec[2] << std::endl;

  ft::vector<bool> ft_vec(10);
  std::cout << "ft: " << ft_vec[0] << std::endl;
  std::cout << "ft: " << ft_vec[1] << std::endl;
  std::cout << "ft: " << ft_vec[2] << std::endl;


}