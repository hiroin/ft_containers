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
#include "tester.hpp"

static std::stringstream	os;
std::ofstream		logV;

#ifdef TEST
# define VECTORFILE "vector_std.txt"
#else
# define VECTORFILE "vector_ft.txt"
#endif


template <typename T>
void	print_vector(NAME::vector<T> const &vec)
{
	typename NAME::vector<T>::const_iterator it = vec.begin(), ite = vec.end();
	os << "[Contents]" << std::endl;
	for (; it != ite; ++it)
		os << "" << *it << " ";
	os << "\nSize     : " << vec.size() << '\n';
	os << "Capacity : " << vec.capacity() << '\n';
	os << std::endl;
}

template<typename T>
bool const_vector(NAME::vector<T> const &vec)
{
	typename NAME::vector<T>::const_iterator it = vec.begin(), ite = vec.end();
	while (it != ite)
	{
		os << "*it: " << *it  <<  std::endl;
		++it;
	}
	typename NAME::vector<T>::const_reverse_iterator itr = vec.rbegin(), itre = vec.rend();
	while (itr != itre)
	{
		os << "*it: " << *itr  <<  std::endl;
		++itr;
	}
	return (true);
}

template <typename T>
int		TESTvector(NAME::vector<T> const  &VEC)
{
	print_vector(VEC);
	return SUCCESS;
}

int		vector_construct()
{
	std::cout << "[Constructor] ";
	os        << "========  [Constructor] ========= \n";
	os << "1. default construct\n";
	NAME::vector<std::string>	a;
	if (!TESTvector(a))
		return FAILED;

	os << "2. fill construct\n";
	NAME::vector<std::string> b(10, "vector");
	if (TESTvector(b) == 0)
		return FAILED;

	os << "3. range construct\n";
	std::vector<std::string> STD(10, "vector");
	NAME::vector<std::string>	c(STD.begin(), STD.end() - 1);
	if (TESTvector(c) == 0)
		return FAILED;

	os << "4. copy construct\n";
	NAME::vector<std::string>	tmp = c;
	NAME::vector<std::string>	d(tmp);
	if (TESTvector(d) == 0)
		return FAILED;

	buffer_clean(logV, os);
	return SUCCESS;
}

int	vector_iterator()
{
	std::cout << "[begin, end] ";
	os        << "========  [begin, end] ========= \n";
	NAME::vector<char> VEC;

	os << "------------------- begin, end ------------------\n";
	for (int i=1; i<=10; i++) VEC.push_back(i + 64);
	NAME::vector<char>::iterator it = VEC.begin();
	NAME::vector<char>::iterator ite = VEC.end();
	while (it != ite)
	{
		os << "*it: " << *it  <<  std::endl;
		++it;
	}

	os << "------------------- rbegin, rend ------------------\n";
	NAME::vector<char>::reverse_iterator itr = VEC.rbegin();
	NAME::vector<char>::reverse_iterator itre = VEC.rend();
	while (itr != itre)
	{
		os << "*itr: " << *itr  <<  std::endl;
		++itr;
	}
	os << "------------------- const test ------------------\n";
	const_vector(VEC);
	os << "OK\n";
	return SUCCESS;
}

int		vector_resize(void)
{
	std::cout << "[resize] ";
	os        << "========  [resize] ========= \n";
	NAME::vector<int>		A(5, 42);

	A.push_back(21);
	if (TESTvector(A) == 0)
		return FAILED;

	os << "---  resize(14, 3)  ---\n";
	A.resize(14, 3);
	if (TESTvector(A) == 0)
		return FAILED;
	os << "---  resize(17, 7)  ---\n";
	A.resize(17, 7);
	if (TESTvector(A) == 0)
		return FAILED;
	os << "---  resize(5)  ---\n";
	A.resize(5);
	if (TESTvector(A) == 0)
		return FAILED;

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_empty()
{
	std::cout << "[empty] ";
	os << "========  [empty] ========= \n";
	NAME::vector<std::string> VEC(5, "***");

	if (TESTvector(VEC) == 0) return FAILED;	
	if (VEC.empty()) {
		return failed(logV, os);
	}
	VEC.clear();
	if (TESTvector(VEC) == 0) return FAILED;	
	if (!VEC.empty()) {
		return failed(logV, os);
	}
	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_max_size()
{
	std::cout << "[max_size] ";
	os << "========  [max_size] ========= \n";
	{
		NAME::vector<unsigned int> VEC;
		os << "VEC: " << VEC.max_size() << std::endl;
	}
	{
		NAME::vector<char> VEC;
		os << "VEC: " << VEC.max_size() << std::endl;
	}
	{
		NAME::vector<double> VEC;
		os << "VEC: " << VEC.max_size() << std::endl;
	}
	{
		NAME::vector<std::string> VEC;
		os << "VEC: " << VEC.max_size() << std::endl;
	}
	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_reserve()
{
	std::cout << "[reserve] ";
	os << "========  [reserve] ========= \n";
	NAME::vector<std::string> VEC(5, "***");

	if (TESTvector(VEC) == 0) return FAILED;	

	VEC.reserve(42);
	if (TESTvector(VEC) == 0) return FAILED;

	VEC.reserve(3);
	if (TESTvector(VEC) == 0) return FAILED;	

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_at()
{
	std::cout << "[access] ";
	os        << "========  [access] ========= \n";
	NAME::vector<int> VEC;
	for (int i=1; i<=10; i++) VEC.push_back(i);

	os << "------------------- START ------------------\n";
	if (TESTvector(VEC) == 0) return FAILED;

	os << "------------------- vector.at(), vector[i] ------------------\n";
	for (size_t i = 0; i < VEC.size(); i++)
	{
		os << "VEC.at("<<i<<"):  " << VEC.at(i)  <<  std::endl;
	}
	os << "------------------- vector.front() ------------------\n";
	os << "VEC.front():  " << VEC.front()  <<  std::endl;

	os << "------------------- vector.back() ------------------\n";
	os << "VEC.front():  " << VEC.back()  <<  std::endl;


	try {
		os << "STD: seception" << VEC.at(42);
		return FAILED;
	}
	catch (std::exception &e) {
		os << "Catch exception: " << e.what() << std::endl;
	}

	buffer_clean(logV, os);
	return SUCCESS;
}
int		vector_at_const()
{
	std::cout << "[access 2] ";
	os        << "========  [access 2] ========= \n";
	const NAME::vector<int> VEC(10, 42);

	os << "------------------- START ------------------\n";
	if (TESTvector(VEC) == 0) return FAILED;

	os << "------------------- vector.at(), vector[i] ------------------\n";
	for (size_t i = 0; i < VEC.size(); i++)
	{
		os << "VEC.at("<<i<<"):  " << VEC.at(i)  <<  std::endl;
	}
	os << "------------------- vector.front() ------------------\n";
	os << "VEC.front():  " << VEC.front()  <<  std::endl;

	os << "------------------- vector.back() ------------------\n";
	os << "VEC.front():  " << VEC.back()  <<  std::endl;

	try {
		os << "VEC: seception" << VEC.at(42);
		return FAILED;
	}
	catch (std::exception &e) {
		os << "Catch exception: " << e.what() << std::endl;
	}

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_assgin()
{
	std::cout << "[assign] ";
	os        << "========  [assign] ========= \n";
	std::vector<char>	vec(5, '*');
	std::list<char>	lst(5, '*');

	NAME::vector<char>	VEC(3);
	os << "1. assign(first, last) \n";
	VEC.assign(vec.begin() + 1, vec.end());
	if (TESTvector(VEC) == 0)
		return FAILED;

	os << "2. assign(lstfirst, lstlast)\n";
	VEC.assign(lst.begin(), lst.end());
	if (TESTvector(VEC) == 0)
		return FAILED;

	os << "3, assign(n, val)\n";
	VEC.assign(7, 99);
	if (TESTvector(VEC) == 0)
		return FAILED;
	os << "4, assign(0, val)\n";
	VEC.assign(0, 99);
	if (TESTvector(VEC) == 0)
		return FAILED;

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_push_pop()
{
	std::cout << "[push pop] ";
	os << "========  [push_back] ========= \n";
	NAME::vector<int> VEC;
	os << "--- push_back(i) \n";
	for (int i=1; i<=10; i++) 
		VEC.push_back(i);
	if (TESTvector(VEC) == 0) 
		return FAILED;

	os << "========  [pop_back] ========= \n";
	os << "--- pop_back() \n";
	for (int i=0; i < 3; i++) 
		VEC.pop_back();
	if (TESTvector(VEC) == 0) 
		return FAILED;
	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_insert1()
{
	std::cout << "[insert 1] ";
	os        << "========  [insert 1] ========= \n";
	NAME::vector<int> VEC;
	for (int i=1; i<=10; i++) VEC.push_back(i);

	NAME::vector<int>::iterator ite = VEC.begin() ;

	os << "------------------- START ------------------\n";
	if (TESTvector(VEC) == 0) return FAILED;
	
	os << "--- insert(begin() + 3, 42) ---\n";
	ite = VEC.insert(VEC.begin() + 3, 42);

	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "--- insert(begin() + 3, 12) ---\n";
	ite = VEC.insert(VEC.begin() + 3, 12);

	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "--- insert(end() - 1, 99) ---\n";
	ite = VEC.insert(VEC.end() - 1, 99);

	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "--- insert(end(), 99) ---\n";
	ite = VEC.insert(VEC.end() , 99);

	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "--- insert(end() - 7, 99) ---\n";
	ite = VEC.insert(VEC.end() - 7, 99);

	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_insert2()
{
	std::cout << "[insert 2] ";
	os        << "========  [insert 2] ========= \n";
	NAME::vector<int> VEC;
	for (int i=1; i<=10; i++) VEC.push_back(i );
	os << "------------------- START ------------------\n";
	if (TESTvector(VEC) == 0) return FAILED;
	
	os << "--- insert(begin() + 2, 6, 1) ---\n";
	VEC.insert(VEC.begin() + 2, 6, 1);
	if (TESTvector(VEC) == 0) return FAILED;

	os << "--- insert(begin() + 7, 0, 1) ---\n";
	VEC.insert(VEC.begin() + 7, 0, 1);
	if (TESTvector(VEC) == 0) return FAILED;

	os << "--- insert(begin() + 7, 1, 65) ---\n";
	VEC.insert(VEC.begin() + 7, 1, 65);
	if (TESTvector(VEC) == 0) return FAILED;

	os << "--- insert(begin() + 10, 16, 42) ---\n";
	VEC.insert(VEC.begin() + 10, 16, 42);
	if (TESTvector(VEC) == 0) return FAILED;

	os << "--- insert(begin() + 10, 200, 42) ---\n";
	VEC.insert(VEC.begin() + 10, 200, 7);
	if (TESTvector(VEC) == 0) return FAILED;

	os << "------------------- START ------------------\n";
	NAME::vector<int>	VEC2(5, 42);
	if (TESTvector(VEC2) == 0) return FAILED;

	os << "--- insert(begin(), 3, 77) ---\n";
	VEC2.insert(VEC2.begin(), 3, 77);
	if (TESTvector(VEC2) == 0) return FAILED;

	os << "--- insert(end(), 4, 99) ---\n";
	VEC2.insert(VEC2.end(), 4, 99);
	if (TESTvector(VEC2) == 0) return FAILED;

	os << "--- insert(end(), 13, 41) ---\n";
	VEC2.insert(VEC2.end(), 13, 41);
	if (TESTvector(VEC2) == 0) return FAILED;

	os << "--- insert(begin(), 15, 0) ---\n";
	VEC2.insert(VEC2.begin(), 15, 0);
	if (TESTvector(VEC2) == 0) return FAILED;

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_insert3()
{
	std::cout << "[insert 3] ";
	os        << "========  [insert 3] ========= \n";
	NAME::vector<int> VEC;
	for (int i=1; i<=10; i++) VEC.push_back(i);

	std::list<int> Input(6, 42);
	std::list<int>::iterator first = Input.begin();
	std::list<int>::iterator last = Input.end();
	os << "------------------- START ------------------\n";
	if (TESTvector(VEC) == 0) return FAILED;
	
	os << "--- insert(begin() + 2, first, last) ---\n";
	VEC.insert(VEC.begin() + 2, first, last);
	if (TESTvector(VEC) == 0) return FAILED;
	os << "--- insert(begin(), first, ++first) ---\n";
	VEC.insert(VEC.begin() , first, ++first);
	if (TESTvector(VEC) == 0) return FAILED;
	os << "--- insert(end() - 1, first, last) ---\n";
	VEC.insert(VEC.end() - 1, first, last);
	if (TESTvector(VEC) == 0) return FAILED;

	NAME::vector<int> VEC2;
	for (int i=1; i<=5; i++) VEC2.push_back(i);

	os << "------------------- START ------------------\n";
	if (TESTvector(VEC2) == 0) return FAILED;

	os << "--- insert(end() - 1, first, last) ---\n";
	VEC2.insert(VEC2.end() - 1, first, last);
	if (TESTvector(VEC2) == 0) return FAILED;

	VEC.clear();
	for (int i=-1; i>=-100; i--) VEC.push_back(i);
	os << "--- insert(end() - 3, STD.begin(), STD.begin()) ---\n";
	VEC2.insert(VEC2.end() - 3, VEC.begin(), VEC.end());
	if (TESTvector(VEC2) == 0) return FAILED;


	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_erase1()
{
	std::cout << "[erase 1] ";
	os        << "========  [erase 1] ========= \n";
	NAME::vector<int> VEC;
	for (int i=1; i<=10; i++) VEC.push_back(i);
	NAME::vector<int>::iterator ite = VEC.begin() + 3;

	os << "------------------- START ------------------\n";
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "------- erase(begin() + 3) --------\n";
	ite = VEC.erase(VEC.begin() + 3);
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "------- erase(end() - 1) --------\n";
	ite = VEC.erase(VEC.end() - 1);
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "------- erase(begin())    --------\n";
	ite = VEC.erase(VEC.begin());
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "------- erase(begin())    --------\n";
	ite = VEC.erase(VEC.begin());
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os <<"------- erase(end() - 1) --------\n";
	ite = VEC.erase(VEC.end() - 1);
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_erase2()
{
	std::cout << "[erase 2] ";
	os        << "========  [erase 2] ========= \n";
	NAME::vector<char> VEC;
	for (int i=1; i<=10; i++) VEC.push_back(i + 64);

	NAME::vector<char>::iterator ite = VEC.begin() + 3;

	os << "------------------- START ------------------\n";
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;
	
	os << "--- erase(begin() , begin()+3) ---\n";
	ite = VEC.erase(VEC.begin(), VEC.begin() + 3);
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "------- erase(begin() + 1 , begin()+3)  --------\n";
	ite = VEC.erase(VEC.begin() + 1, VEC.begin() + 3);
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "------- erase(begin() + 1, end())  --------\n";
	ite = VEC.erase(VEC.begin() + 1, VEC.end());
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	os << "------- erase(begin(), end())  --------\n";
	ite = VEC.erase(VEC.begin(), VEC.end());
	if (TESTvector(VEC) == 0) return FAILED;
	os << "return:  " << *ite <<  std::endl;

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_swap()
{
	std::cout << "[ swap] ";
	os << "========  [swap] ========= \n";
	NAME::vector<int> A(3, 21);
	NAME::vector<int> B(5, 42);
	NAME::vector<int>::const_iterator itr = A.begin();

	os << "-- before \n";
	if (TESTvector(A) == 0) return FAILED;
	if (TESTvector(B) == 0) return FAILED;

	os << "-- after \n";
	A.swap(B);
	if (TESTvector(A) == 0) return FAILED;
	if (TESTvector(B) == 0) return FAILED;

	os << "-- Aitr == B.begin() \n";
	os << (itr == B.begin()) << std::endl;
	if (itr != B.begin()) {
		return failed(logV, os);
	}

	os << "-- swap(x, y) \n";
	NAME::swap(A, B);
	if (TESTvector(A) == 0) return FAILED;
	if (TESTvector(B) == 0) return FAILED;
	if (itr != A.begin()) {
		return failed(logV, os);
	}

	buffer_clean(logV, os);
	return SUCCESS;
}

int		vector_clear()
{
	std::cout << "[clear] ";
	os << "========  [clear] ========= \n";
	NAME::vector<int> VEC(5, 42);

	os << "-- before \n";
	if (TESTvector(VEC) == 0) 
		return FAILED;
	VEC.clear();
	os << "-- after \n";
	if (TESTvector(VEC) == 0)
		return FAILED;
	buffer_clean(logV, os);
	return SUCCESS;
}

template<typename T>
int		operand_test(T const &lhs, T const &rhs)
{
	int ret = 0;
	os << "---- (a == b)  ";
	if (lhs == rhs)
	{
		ret += 1;
		os << "->TRUE\n";
	}
	else 
		os << "->FALSE\n";

	os << "---- (a != b)  ";
	if (lhs != rhs) 
	{
		ret += 2;
		os << "->TRUE\n";
	}
	else os << "->FALSE\n";


	os << "---- (a < b)   ";
	if (lhs < rhs) 
	{
		ret += 3;
		os << "->TRUE\n";
	}
	else os << "->FALSE\n";

	os << "---- (a <= b)  ";
	if (lhs <= rhs) 
	{
		ret += 4;
		os << "->TRUE\n";
	}
	else os << "->FALSE\n";

	os << "---- (a > b)   ";
	if (lhs > rhs) 
	{
		ret += 5;
		os << "->TRUE\n";
	}
	else os << "->FALSE\n";
	
	os << "---- (a >= b)  ";
	if (lhs >= rhs) 
	{
		ret += 6;
		os << "->TRUE\n";
	}
	else os << "->FALSE\n";
	os << std::endl;
	return ret;
}

int		vector_operator()
{
	std::cout << "[operator] ";
	os        << "========  [operator] ========= \n";
	NAME::vector<int> a;
	for (int i=1; i<=10; i++) a.push_back(i);
	NAME::vector<int> b = a;

	os << "a == b\n";
	TESTvector(a);
	TESTvector(b);
	operand_test(a, b);
	os << "a < b\n";
	*(b.end() - 3) = 42;
	TESTvector(b);
	operand_test(a, b);

	os << "a > b\n";
	*(b.end() - 3) = 0;
	TESTvector(a);
	TESTvector(b);
	operand_test(a, b);

	os << "a < b\n";
	a.resize(3);
	TESTvector(a);
	TESTvector(b);
	operand_test(a, b);
	buffer_clean(logV, os);
	return SUCCESS;
}

int		VectorTest(void)
{
	std::cout << "======= Vector =======\n";
	logV.open(VECTORFILE, std::ios_base::trunc);

	if (vector_construct()) OK();
	else KO();
	if (vector_iterator()) OK();
	else KO();

	if (vector_resize()) OK();
	else KO();
	if (vector_empty()) OK();
	else KO();
	if (vector_max_size()) OK();
	else KO();
	if (vector_reserve()) OK();
	else KO();

	if (vector_at()) OK();
	else KO();
	if (vector_at_const()) OK();
	else KO();

	if (vector_assgin()) OK();
	else KO();
	if (vector_push_pop()) OK();
	else KO();
	if (vector_insert1()) OK();
	else KO();
	if (vector_insert2()) OK();
	else KO();
	if (vector_insert3()) OK();
	else KO();
	if (vector_erase1()) OK();
	else KO();
	if (vector_erase2()) OK();
	else KO();
	if (vector_swap()) OK();
	else KO();
	if (vector_clear()) OK();
	else KO();

	if (vector_operator()) OK();
	else KO();

	buffer_clean(logV, os);
	logV.close();
	std::cout << "check " << VECTORFILE << "!\n";
	return SUCCESS;
}
