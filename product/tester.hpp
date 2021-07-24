#ifndef TESTER_HPP
# define TESTER_HPP

# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

# define OK() std::cout << GREEN << "\t\tOK" << RESET << std::endl
# define KO() std::cout << RED << "\t\tKO" << RESET << std::endl

# define SUCCESS 1
# define FAILED 0

#ifdef TEST
# define NAME std
#else
# define NAME ft
#endif

#include <sstream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <fstream>

#include "includes/vector.hpp"
#include "includes/stack.hpp"
#include "includes/map.hpp"

int		buffer_clean(std::ofstream &_Log, std::stringstream &_Os);
int		failed(std::ofstream &_Log, std::stringstream &_Os);
int		success(std::ofstream &_Log, std::stringstream &_Os);

int		VectorTest(void);
int		StackTest(void);
int		MapTest(void);

#endif

