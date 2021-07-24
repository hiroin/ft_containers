#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <string>
#include <exception>
#include <sstream>
#include <fstream>

#include "tester.hpp"

static std::stringstream	os;
std::ofstream				logS;

#ifdef TEST
# define STACKFILE "stack_std.txt"
#else
# define STACKFILE "stack_ft.txt"
#endif

template <typename T>
int		TESTstack(NAME::stack<T> STK)
{
	os << "[contents]\n";
	os << "STK : size " << STK.size() << "\n";
	while (!STK.empty())
	{
		os << "STK.top(): " << STK.top()  <<  std::endl;
		STK.pop();
	} 
	return SUCCESS;
}
template <typename T, class C>
int		TESTstack(NAME::stack<T, C> STK)
{
	os << "[contents]\n";
	os << "STK : size " << STK.size() << "\n";
	while (!STK.empty())
	{
		os << "STK.top(): " << STK.top()  <<  std::endl;
		STK.pop();
	} 
	return SUCCESS;
}


int		stack_constructor()
{
	std::cout << "[Constructor] ";
	os        << "========  [Constructor] ========= \n";
	os << "1. default construct\n";
	NAME::stack<char> STK_1;
	if (TESTstack<char>(STK_1) == 0)
		return FAILED;

	os << "2. stack< vector >\n";
	NAME::vector<int>		vec(3, 42);
	NAME::stack<int, NAME::vector<int> >	STK_2(vec);
	if (TESTstack<int>(STK_2) == 0)

	os << "3. stack< list >\n";
	std::list<std::string>		lst(7, "***");
	NAME::stack<std::string, std::list<std::string> >	STK_3(lst);
	if (TESTstack<std::string>(STK_3) == 0)
		return FAILED;

	buffer_clean(logS, os);
	return SUCCESS;
}

int		stack_size()
{
	std::cout << "[size ] ";
	os        << "========  [size] ========= \n";
	std::list<char>		lst1(10000, 'A');

	NAME::stack<char, std::list<char> >	STK(lst1);
	os << "STK.size(): " << STK.size()  <<  std::endl;

	STK.pop();
	STK.pop();
	STK.pop();
	os << "STK.size(): " << STK.size()  <<  std::endl;

	STK.push('a');
	STK.push('a');
	os << "STK.size(): " << STK.size()  <<  std::endl;

	for (int i = 0 ; i < 242; i++) {
		STK.pop();
	}
	os << "STK.size(): " << STK.size()  <<  std::endl;

	buffer_clean(logS, os);
	return SUCCESS;
}

int		stack_empty()
{
	std::cout << "[empty] ";
	os        << "========  [empty] ========= \n";
	std::list<char>		lst1(42, 'A');

	NAME::stack<char, std::list<char> >	STK(lst1);
	
	os << "STK.empty(): " << STK.empty()  <<  std::endl;
	while (!STK.empty())
	{
		STK.pop();
	}
	os << "STK.empty(): " << STK.empty()  <<  std::endl;

	buffer_clean(logS, os);
	return SUCCESS;
}


int		stack_top  ()
{
	std::cout << "[top  ] ";
	os        << "========  [top  ] ========= \n";
	std::list<char>		lst;
	for (int i = 0; i < 10; i++) lst.push_back(i + 65);

	os << "------  const  top  --------\n";
	const NAME::stack<char, std::list<char> >	STK(lst);
	os << "STK.top(): " << STK.top()  <<  std::endl;
	if (TESTstack<char>(STK) == 0)
		return FAILED;
	
	os << "------    top    --------\n";
	NAME::stack<char, std::list<char> >	STK2(lst);
	os << "STK.top(): " << STK2.top()  <<  std::endl;
	if (TESTstack<char>(STK2) == 0)
		return FAILED;

	buffer_clean(logS, os);
	return SUCCESS;
}

int		stack_push  ()
{
	std::cout << "[push ] ";
	os        << "========  [push ] ========= \n";
	NAME::stack<int>	STK;

	os << "------    before    --------\n";
	if (TESTstack<int>(STK) == 0)
		return FAILED;

	for (int i = 0; i < 5; i++) STK.push(i + 1);
	os << "------    after    --------\n";
	os << "STK.top(): " << STK.top()  <<  std::endl;
	if (TESTstack<int>(STK) == 0)
		return FAILED;

	buffer_clean(logS, os);
	return SUCCESS;
}

int		stack_pop  ()
{
	std::cout << "[pop  ] ";
	os        << "========  [pop  ] ========= \n";
	NAME::stack<int>	STK;

	for (int i = 0; i < 5; i++) STK.push(i + 1);

	os << "[ before ]\n";
	if (TESTstack<int>(STK) == 0)
		return FAILED;

	while (!STK.empty())
	{
		STK.pop();
	} 
	os << "[ after ]\n";
	if (TESTstack<int>(STK) == 0)
		return FAILED;

	buffer_clean(logS, os);
	return SUCCESS;
}

int		stack_operator()
{
	std::cout << "[operator] ";
	os        << "========  [operator] ========= \n";

	NAME::stack<int>	a; 
	NAME::stack<int>	b;
	for (int i = 0; i < 5; i++) a.push(i + 1);
	for (int i = 0; i < 5; i++) b.push(i + 1);

	TESTstack(a);
	TESTstack(b);
	os << "------- start ------\n";
	os << "[a == b]: " << bool(a == b) << std::endl;

	a.pop();
	os << "------- a.pop -------\n";
	os << "[a != b]: " << bool(a != b) << std::endl;
	os << "[a < b]: " << bool(a < b) << std::endl;
	os << "[a <= b]: " << bool(a <= b) << std::endl;

	a.push(42);
	os << "------- a.push(42) -------\n";;
	os << "[a != b]: " << bool(a != b) << std::endl;
	os << "[a > b]: " << bool(a > b) << std::endl;
	os << "[a >= b]: " << bool(a >= b) << std::endl;

	buffer_clean(logS, os);
	return SUCCESS;
}

int		StackTest(void)
{
	std::cout << "=======  Stack  =======\n";
	logS.open(STACKFILE, std::ios_base::trunc);

	if (stack_constructor()) OK();
	else KO();
	if (stack_size()) OK();
	else KO();
	if (stack_empty()) OK();
	else KO();
	if (stack_top()) OK();
	else KO();
	if (stack_push()) OK();
	else KO();
	if (stack_pop()) OK();
	else KO();
	if (stack_operator()) OK();
	else KO();

	buffer_clean(logS, os);
	logS.close();
	std::cout << "check " << STACKFILE << "!\n";
	return (SUCCESS);
}

