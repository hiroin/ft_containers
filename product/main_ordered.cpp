#include <iostream>
#include <string>
#include "includes/map.hpp"
#include "includes/stack.hpp"
#include "includes/vector.hpp"
#include <stdlib.h>

int main()
{
	std::cout << "Check that the container is ordered." << std::endl;
	{
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 10; ++i)
		{
			ft_map[i * 2] = static_cast<char>(i + 'A');
			// std::cout << "   ft_map[" << i * 2 << "]: " << ft_map[i * 2] << std::endl;
  		// ft_map.print();
			// std::cout << std::endl;
		}
		ft_map.print();
		std::cout << std::endl;
		std::cout << "   ft_map.insert(ft::make_pair(7,\"Z\"))" << std::endl;
		ft_map.insert(ft::make_pair(7,"Z"));
		ft_map.print();
	}
	return (0);
}