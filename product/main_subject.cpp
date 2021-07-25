#include <iostream>
#include <string>
#include <deque>
#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "includes/map.hpp"
	#include "includes/stack.hpp"
	#include "includes/vector.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }
	
	// for (int i = 0; i < COUNT; ++i)
	// {
	// 	map_int.insert(ft::make_pair(rand(), rand()));
	// }

	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }

	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
	std::cout << std::endl;
	std::cout << "vector<bool> test" << std::endl;
	std::cout << " constructor" << std::endl;
	{
		std::cout << "  default" << std::endl;
		ft::vector<bool> ft_vec;
		std::cout << "   empty(): " << ft_vec.empty() << std::endl;
		std::cout << "   size(): " << ft_vec.size() << std::endl;
		std::cout << "   capacity(): " << ft_vec.capacity() << std::endl;
		std::cout << "   max_size(): " << ft_vec.max_size() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "  ft_vec(10)" << std::endl;
		ft::vector<bool> ft_vec(10);
		std::cout << "   empty(): " << ft_vec.empty() << std::endl;
		std::cout << "   size(): " << ft_vec.size() << std::endl;
		std::cout << "   ft_vec[0]: " << ft_vec[0] << std::endl;
		std::cout << "   ft_vec[9]: " << ft_vec[9] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "  ft_vec(10, false)" << std::endl;
		ft::vector<bool> ft_vec(10, false);
		std::cout << "   empty(): " << ft_vec.empty() << std::endl;
		std::cout << "   size(): " << ft_vec.size() << std::endl;
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "  ft_vec(10, true)" << std::endl;
		ft::vector<bool> ft_vec(10, true);
		std::cout << "   empty(): " << ft_vec.empty() << std::endl;
		std::cout << "   size(): " << ft_vec.size() << std::endl;
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;

		std::cout << " operator=" << std::endl;
		std::cout << "  ft_vec2 = ft_vec" << std::endl;
		ft::vector<bool> ft_vec2;
		ft_vec2 = ft_vec;
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec2[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " assign" << std::endl;
		ft::vector<bool> ft_vec(10);
		std::cout << "  assign(10, true)" << std::endl;
		ft_vec.assign(10, true);
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
		std::cout << "  assign(10, false)" << std::endl;
		ft_vec.assign(10, false);
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;

		std::cout << " get_allocator" << std::endl;
		std::cout << "  no outout" << std::endl;
		ft_vec.get_allocator();
		std::cout << std::endl;
	}
	{
		ft::vector<bool> ft_vec(10);
		ft_vec[0] = true;
		ft_vec[2] = true;
		ft_vec[4] = true;
		ft_vec[5] = true;
		ft_vec[6] = true;
		try
		{
			std::cout << " at" << std::endl;
			std::cout << "  0,1,2,3,4,5,6,7,8,9" << std::endl;
			std::cout << "  -------------------" << std::endl;
			std::cout << "  1,0,1,0,1,1,1,0,0,0" << std::endl;
			for (size_t i = 0; i < 11; ++i)
				std::cout << "   ft_vec.at(" << i << "): " << ft_vec.at(i) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "catch exception" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "  front" << std::endl;
		std::cout << "   " << ft_vec.front() << std::endl;
		std::cout << "  back" << std::endl;
		std::cout << "   " << ft_vec.back() << std::endl;
		std::cout << std::endl;

		std::cout << " Iterators" << std::endl;
		std::cout << "  ft_vec.begin()  : " << *ft_vec.begin() << std::endl;
		std::cout << "  ft_vec.end() - 1: " << *(ft_vec.end() - 1) << std::endl;
		std::cout << "  ft_vec.rbegin() : " << *ft_vec.rbegin() << std::endl;
		std::cout << "  ft_vec.rend() -1: " << *(ft_vec.rend() - 1) << std::endl;
		ft::vector<bool>::const_iterator citr = ft_vec.begin();
		std::cout << "  ft_vec.begin() const   : " << *citr << std::endl;
		citr = ft_vec.end() - 1;
		std::cout << "  ft_vec.end() - 1 const : " << *citr << std::endl;
		ft::vector<bool>::const_reverse_iterator critr = ft_vec.rbegin();
		std::cout << "  ft_vec.rbegin() const  : " << *critr << std::endl;
		critr = ft_vec.rend() - 1;
		std::cout << "  ft_vec.rend() - 1 const: " << *critr << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " reserve / capacity" << std::endl;
		std::cout << "  ft_vec(10)" << std::endl;
		ft::vector<bool> ft_vec(10);
		std::cout << "   capacity(): " << ft_vec.capacity() << std::endl;
		std::cout << "  ft_vec.reserve(100)" << std::endl;
		ft_vec.reserve(100);
		std::cout << "   capacity(): " << ft_vec.capacity() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " clear" << std::endl;
		std::cout << "  ft_vec(10, true)" << std::endl;
		ft::vector<bool> ft_vec(10, true);
		std::cout << "  ft_vec.size(): " << ft_vec.size() << std::endl;
		try
		{
			ft_vec.at(0);
			std::cout << "  ft_vec.at(0) : " << ft_vec.at(0) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "catch exception" << std::endl;
		}
		std::cout << "  ft_vec.clear()" << std::endl;
		ft_vec.clear();
		std::cout << "  ft_vec.size(): " << ft_vec.size() << std::endl;
		try
		{
			ft_vec.at(0);
			std::cout << "  ft_vec.at(0) : " << ft_vec.at(0) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "  ft_vec.at(0) : catch exception" << std::endl;
		}
		std::cout << std::endl;
	}
	{
		std::cout << " insert" << std::endl;
		std::cout << "  ft_vec(10, true)" << std::endl;
		ft::vector<bool> ft_vec(10, true);
		std::cout << "  ft_vec.insert(ft_vec.begin() + 1, false)" << std::endl;
		ft_vec.insert(ft_vec.begin() + 1, false);
		for (size_t i = 0; i < 11; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
		std::cout << "  ft_vec.insert(ft_vec.begin() + 2, 5, false)" << std::endl;
		ft_vec.insert(ft_vec.begin() + 2, 5, false);
		for (size_t i = 0; i < 16; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "  ft_vec(10, true)" << std::endl;
		ft::vector<bool> ft_vec(10, true);
		std::cout << "  ft_vec2(10, false)" << std::endl;
		ft::vector<bool> ft_vec2(10, false);
		std::cout << "  ft_vec.insert(ft_vec.begin() + 2, ft_vec2.begin(), ft_vec2.end())" << std::endl;
		ft_vec.insert(ft_vec.begin() + 2, ft_vec2.begin(), ft_vec2.end());
		for (size_t i = 0; i < 20; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
		std::cout << " erase" << std::endl;
		std::cout << "  ft_vec.erase(ft_vec.begin())" << std::endl;
		ft_vec.erase(ft_vec.begin());
		for (size_t i = 0; i < 19; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
		std::cout << "  ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 1)" << std::endl;
		ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 1);
		for (size_t i = 0; i < 17; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " push_back" << std::endl;
		std::cout << "  ft::vector<bool> ft_vec" << std::endl;
		ft::vector<bool> ft_vec;
		std::cout << "  ft_vec.push_back(true)" << std::endl;
		ft_vec.push_back(true);
		std::cout << "  ft_vec[0]: " << ft_vec[0] << std::endl;
		std::cout << std::endl;

		std::cout << " pop_back" << std::endl;
		std::cout << "  ft_vec.pop_back()" << std::endl;
		ft_vec.pop_back();
		std::cout << "  ft_vec.size(): " << ft_vec.size() << std::endl;
		std::cout << std::endl;

		std::cout << " resize" << std::endl;
		std::cout << "  ft_vec.resize(10)" << std::endl;
		ft_vec.resize(10);
		std::cout << "  ft_vec.size(): " << ft_vec.size() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " swap" << std::endl;
		std::cout << "  ft_vec(10, true)" << std::endl;
		ft::vector<bool> ft_vec(10, true);
		std::cout << "  ft_vec2(10, false)" << std::endl;
		ft::vector<bool> ft_vec2(10, false);
		std::cout << "  ft_vec.swap(ft_vec2)" << std::endl;
		ft_vec.swap(ft_vec2);
		std::cout << "  ft_vec[0]: " << ft_vec[0] << std::endl;
		std::cout << "  ft_vec2[0]: " << ft_vec2[0] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " flip" << std::endl;
		std::cout << "  ft_vec(10, true)" << std::endl;
		ft::vector<bool> ft_vec(10, true);
		for (size_t i = 0; i < 10; i = i + 2)
		{
			std::cout << "  ft_vec[" << i << "] = false" << std::endl;
			ft_vec[i] = false;
		}
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
		std::cout << "  flip" << std::endl;
		ft_vec.flip();
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
		std::cout << " swap" << std::endl;
		ft_vec.swap(ft_vec[0], ft_vec[1]);
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
	}
	std::cout << " Non-member functions" << std::endl;
	{
		std::cout << "  ft_vec(10, true)" << std::endl;
		ft::vector<bool> ft_vec(10, true);
		std::cout << "  ft_vec2(10, false)" << std::endl;
		ft::vector<bool> ft_vec2(10, true);
		std::cout << "  ft_vec == ft_vec2: " << (ft_vec == ft_vec2) << std::endl;
		std::cout << "  ft_vec != ft_vec2: " << (ft_vec != ft_vec2) << std::endl;
		std::cout << "  ft_vec <  ft_vec2: " << (ft_vec <  ft_vec2) << std::endl;
		std::cout << "  ft_vec <= ft_vec2: " << (ft_vec <= ft_vec2) << std::endl;
		std::cout << "  ft_vec >  ft_vec2: " << (ft_vec > ft_vec2) << std::endl;
		std::cout << "  ft_vec >= ft_vec2: " << (ft_vec >= ft_vec2) << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_vec2[0] = false" << std::endl;
		ft_vec2[0] = false;
		std::cout << "  ft_vec == ft_vec2: " << (ft_vec == ft_vec2) << std::endl;
		std::cout << "  ft_vec != ft_vec2: " << (ft_vec != ft_vec2) << std::endl;
		std::cout << "  ft_vec <  ft_vec2: " << (ft_vec <  ft_vec2) << std::endl;
		std::cout << "  ft_vec <= ft_vec2: " << (ft_vec <= ft_vec2) << std::endl;
		std::cout << "  ft_vec >  ft_vec2: " << (ft_vec > ft_vec2) << std::endl;
		std::cout << "  ft_vec >= ft_vec2: " << (ft_vec >= ft_vec2) << std::endl;
		std::cout << std::endl;

		std::cout << "  swap(ft_vec, ft_vec2)" << std::endl;
		ft::swap(ft_vec, ft_vec2);
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec2[" << i << "]: " << ft_vec2[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " const_iterator and iterators should be comparable." << std::endl;
		ft::vector<bool> ft_vec(10, false);
		ft_vec[0] = true;
		ft_vec[2] = true;
		ft_vec[4] = true;
		ft_vec[5] = true;
		ft_vec[6] = true;
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec.at(" << i << "): " << ft_vec.at(i) << std::endl;

		std::cout << "  ft::vector<bool>::iterator itr = ft_vec.begin()" << std::endl;
		ft::vector<bool>::iterator itr = ft_vec.begin();
		std::cout << "  ft::vector<bool>::const_iterator citr = ft_vec.begin()" << std::endl;
		ft::vector<bool>::const_iterator citr = ft_vec.begin();
		if (itr == citr)
			std::cout << "  ft::vector<bool>::iterator == ft::vector<bool>::const_iterator" << std::endl;
		std::cout << std::endl;
	}

	{
		std::cout << " Test the swap function." << std::endl;
		ft::vector<bool> ft_vec(6, false);
		ft_vec[3] = true;
		ft_vec[4] = true;
		ft_vec[5] = true;
		ft::vector<bool> ft_vec2(6, false);
		ft_vec2[0] = true;
		ft_vec2[1] = true;
		ft_vec2[2] = true;
		for (size_t i = 0; i < 6; ++i)
			std::cout << "   ft_vec.at(" << i << "): " << ft_vec.at(i) << std::endl;
		for (size_t i = 0; i < 6; ++i)
			std::cout << "   ft_vec2.at(" << i << "): " << ft_vec2.at(i) << std::endl;
		std::cout << std::endl;
		
		std::cout << "  ft::vector<bool> *ft_vec_pointer = &ft_vec" << std::endl;
		ft::vector<bool> *ft_vec_pointer = &ft_vec;
		std::cout << "  ft::vector<bool>& ft_vec_reference = ft_vec" << std::endl;
		ft::vector<bool>& ft_vec_reference = ft_vec;

		std::cout << "  ft::vector<bool>::iterator itr = ft_vec.begin()" << std::endl;
		ft::vector<bool>::iterator itr = ft_vec.begin();
		std::cout << "   *itr: " << *itr << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_vec.swap(ft_vec2);" << std::endl;
		ft_vec.swap(ft_vec2);
		std::cout << std::endl;

		std::cout << "   *itr: " << *itr << std::endl;
		std::cout << std::endl;
		for (size_t i = 0; i < 6; ++i)
			std::cout << "   ft_vec_pointer->at(" << i << "): " << ft_vec_pointer->at(i) << std::endl;
		for (size_t i = 0; i < 6; ++i)
			std::cout << "   ft_vec_reference.at(" << i << "): " << ft_vec_reference.at(i) << std::endl;


	}



	return (0);
}