#include <iostream>
#include <string>
#include <deque>
#include <list>
#if STD //CREATE A REAL STL EXAMPLE
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

int main()
{
	std::cout << "vector test" << std::endl;
	std::cout << " constructor" << std::endl;
	{
		std::cout << "  default" << std::endl;
		ft::vector<int> ft_vec;
		std::cout << "   empty(): " << ft_vec.empty() << std::endl;
		std::cout << "   size(): " << ft_vec.size() << std::endl;
		std::cout << "   capacity(): " << ft_vec.capacity() << std::endl;
		std::cout << "   max_size(): " << ft_vec.max_size() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "  ft_vec(10)" << std::endl;
		ft::vector<int> ft_vec(10);
		std::cout << "   empty(): " << ft_vec.empty() << std::endl;
		std::cout << "   size(): " << ft_vec.size() << std::endl;
		std::cout << "   ft_vec[0]: " << ft_vec[0] << std::endl;
		std::cout << "   ft_vec[9]: " << ft_vec[9] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "  ft_vec(10, 42)" << std::endl;
		ft::vector<int> ft_vec(10, 42);
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_vec2(ft_vec.begin(), ft_vec.end()" << std::endl;
		ft::vector<int> ft_vec2(ft_vec.begin(), ft_vec.end());
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec2[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " operator=" << std::endl;
		std::cout << "  ft_vec(10, 42)" << std::endl;
		ft::vector<int> ft_vec(10, 42);
		std::cout << "   empty(): " << ft_vec.empty() << std::endl;
		std::cout << "   size(): " << ft_vec.size() << std::endl;
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
		std::cout << "  ft_vec2 = ft_vec" << std::endl;
		ft::vector<int> ft_vec2;
		ft_vec2 = ft_vec;
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec2[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
	}	
	{
		std::cout << " assign" << std::endl;
		ft::vector<int> ft_vec(10);
		std::cout << "  ft_vec.assign(10, 42)" << std::endl;
		ft_vec.assign(10, 42);
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_vec2.assign(ft_vec.begin(), ft_vec.end())" << std::endl;
		ft::vector<int> ft_vec2;
		ft_vec2.assign(ft_vec.begin(), ft_vec.end());
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec2[" << i << "]: " << ft_vec2[i] << std::endl;
		std::cout << std::endl;

		std::cout << " get_allocator" << std::endl;
		std::cout << "  no outout" << std::endl;
		ft_vec.get_allocator();
		std::cout << std::endl;
	}
	{
		std::cout << " at" << std::endl;
		ft::vector<int> ft_vec(10);
		for (size_t i = 0; i < 10; ++i)
		{
			ft_vec[i] = i;
			std::cout << "  ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		}
		try
		{
			for (size_t i = 0; i < 11; ++i)
				std::cout << "   ft_vec.at(" << i << "): " << ft_vec.at(i) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "catch exception" << std::endl;
		}
		std::cout << std::endl;
		std::cout << "  front: " << ft_vec.front() << std::endl;
		std::cout << "  back : " << ft_vec.back() << std::endl;
		std::cout << std::endl;

		std::cout << " Iterators" << std::endl;
		std::cout << "  ft_vec.begin()  : " << *ft_vec.begin() << std::endl;
		std::cout << "  ft_vec.end() - 1: " << *(ft_vec.end() - 1) << std::endl;
		std::cout << "  ft_vec.rbegin() : " << *ft_vec.rbegin() << std::endl;
		std::cout << "  ft_vec.rend() -1: " << *(ft_vec.rend() - 1) << std::endl;
		ft::vector<int>::const_iterator citr = ft_vec.begin();
		std::cout << "  ft_vec.begin() const   : " << *citr << std::endl;
		citr = ft_vec.end() - 1;
		std::cout << "  ft_vec.end() - 1 const : " << *citr << std::endl;
		ft::vector<int>::const_reverse_iterator critr = ft_vec.rbegin();
		std::cout << "  ft_vec.rbegin() const  : " << *critr << std::endl;
		critr = ft_vec.rend() - 1;
		std::cout << "  ft_vec.rend() - 1 const: " << *critr << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " reserve / capacity" << std::endl;
		std::cout << "  ft_vec(10)" << std::endl;
		ft::vector<int> ft_vec(10);
		std::cout << "   capacity(): " << ft_vec.capacity() << std::endl;
		std::cout << "  ft_vec.reserve(100)" << std::endl;
		ft_vec.reserve(100);
		std::cout << "   capacity(): " << ft_vec.capacity() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " clear" << std::endl;
		std::cout << "  ft_vec(10, 42)" << std::endl;
		ft::vector<bool> ft_vec(10, 42);
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
		std::cout << "  ft_vec(10, 42)" << std::endl;
		ft::vector<int> ft_vec(10, 42);
		std::cout << "  ft_vec.insert(ft_vec.begin() + 1, false)" << std::endl;
		ft_vec.insert(ft_vec.begin() + 1, 88);
		for (size_t i = 0; i < 11; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
		std::cout << "  ft_vec.insert(ft_vec.begin() + 2, 5, 77)" << std::endl;
		ft_vec.insert(ft_vec.begin() + 2, 5, 77);
		for (size_t i = 0; i < 16; ++i)
			std::cout << "   ft_vec[" << i << "]: " << ft_vec[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "  ft_vec(10, 42)" << std::endl;
		ft::vector<int> ft_vec(10, 42);
		std::cout << "  ft_vec2(10, 88)" << std::endl;
		ft::vector<int> ft_vec2(10, 88);
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
		std::cout << "  ft::vector<int> ft_vec" << std::endl;
		ft::vector<int> ft_vec;
		std::cout << "  ft_vec.push_back(42)" << std::endl;
		ft_vec.push_back(42);
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
		std::cout << "  ft_vec(10, 42)" << std::endl;
		ft::vector<int> ft_vec(10, 42);
		std::cout << "  ft_vec2(10, 88)" << std::endl;
		ft::vector<int> ft_vec2(10, 88);
		std::cout << "  ft_vec.swap(ft_vec2)" << std::endl;
		ft_vec.swap(ft_vec2);
		std::cout << "  ft_vec[0]: " << ft_vec[0] << std::endl;
		std::cout << "  ft_vec2[0]: " << ft_vec2[0] << std::endl;
		std::cout << std::endl;
	}
	std::cout << " Non-member functions" << std::endl;
	{
		std::cout << "  ft_vec(10, 42)" << std::endl;
		ft::vector<int> ft_vec(10, 42);
		std::cout << "  ft_vec2(10, 42)" << std::endl;
		ft::vector<int> ft_vec2(10, 42);
		std::cout << "  ft_vec == ft_vec2: " << (ft_vec == ft_vec2) << std::endl;
		std::cout << "  ft_vec != ft_vec2: " << (ft_vec != ft_vec2) << std::endl;
		std::cout << "  ft_vec <  ft_vec2: " << (ft_vec <  ft_vec2) << std::endl;
		std::cout << "  ft_vec <= ft_vec2: " << (ft_vec <= ft_vec2) << std::endl;
		std::cout << "  ft_vec >  ft_vec2: " << (ft_vec > ft_vec2) << std::endl;
		std::cout << "  ft_vec >= ft_vec2: " << (ft_vec >= ft_vec2) << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_vec2[0] = 88" << std::endl;
		ft_vec2[0] = 88;
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
		ft::vector<int> ft_vec(10, 42);
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_vec.at(" << i << "): " << ft_vec.at(i) << std::endl;

		std::cout << "  ft::vector<int>::iterator itr = ft_vec.begin()" << std::endl;
		ft::vector<int>::iterator itr = ft_vec.begin();
		std::cout << "  ft::vector<int>::const_iterator citr = ft_vec.begin()" << std::endl;
		ft::vector<int>::const_iterator citr = ft_vec.begin();
		if (itr == citr)
			std::cout << "  ft::vector<int>::iterator == ft::vector<int>::const_iterator" << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " Test the swap function." << std::endl;
		ft::vector<int> ft_vec(6, 42);
		ft_vec[3] = 88;
		ft_vec[4] = 88;
		ft_vec[5] = 88;
		ft::vector<int> ft_vec2(6, 42);
		ft_vec2[0] = 88;
		ft_vec2[1] = 88;
		ft_vec2[2] = 88;
		for (size_t i = 0; i < 6; ++i)
			std::cout << "   ft_vec.at(" << i << "): " << ft_vec.at(i) << std::endl;
		for (size_t i = 0; i < 6; ++i)
			std::cout << "   ft_vec2.at(" << i << "): " << ft_vec2.at(i) << std::endl;
		std::cout << std::endl;
		
		std::cout << "  ft::vector<int> *ft_vec_pointer = &ft_vec" << std::endl;
		ft::vector<int> *ft_vec_pointer = &ft_vec;
		std::cout << "  ft::vector<int>& ft_vec_reference = ft_vec" << std::endl;
		ft::vector<int>& ft_vec_reference = ft_vec;

		std::cout << "  ft::vector<int>::iterator itr = ft_vec.begin()" << std::endl;
		ft::vector<int>::iterator itr = ft_vec.begin();
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
	std::cout << "----------------------------------------------" << std::endl;
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

	std::cout << std::endl;
	std::cout << "----------------------------------------------" << std::endl;  
	std::cout << "map test" << std::endl;
	std::cout << " constructor" << std::endl;
	{
		std::cout << "  default" << std::endl;
		ft::map<int, std::string> ft_map;
		std::cout << "   empty(): " << ft_map.empty() << std::endl;
		std::cout << "   size(): " << ft_map.size() << std::endl;
		std::cout << "   max_size(): " << ft_map.max_size() << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "  ft_map2(ft_map.begin(), ft_map.end()" << std::endl;
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 10; ++i)
    {
      ft_map[i] = static_cast<char>(i + 'A');
			std::cout << "   ft_map[" << i << "]: " << ft_map[i] << std::endl;
    }
		std::cout << std::endl;
		ft::map<int, std::string> ft_map2(ft_map.begin(), ft_map.end());
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_map2[" << i << "]: " << ft_map[i] << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " operator=" << std::endl;
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 10; ++i)
    {
      ft_map[i] = static_cast<char>(i + 'A');
			std::cout << "   ft_map[" << i << "]: " << ft_map[i] << std::endl;
    }
		std::cout << std::endl;
		std::cout << "  ft_map2 = ft_map" << std::endl;
		ft::map<int, std::string> ft_map2;
		ft_map2 = ft_map;
		for (size_t i = 0; i < 10; ++i)
			std::cout << "   ft_map2[" << i << "]: " << ft_map[i] << std::endl;
		std::cout << std::endl;

		std::cout << " get_allocator" << std::endl;
		std::cout << "  no outout" << std::endl;
		ft_map.get_allocator();
		std::cout << std::endl;
	}
	{
		std::cout << " Iterators" << std::endl;
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 10; ++i)
    {
      ft_map[i] = static_cast<char>(i + 'A');
			std::cout << "   ft_map[" << i << "]: " << ft_map[i] << std::endl;
    }
		std::cout << "  ft_map.begin()  : " << ft_map.begin()->first << std::endl;
		std::cout << "  ft_map.end() - 1: " << (--ft_map.end())->first << std::endl;
		std::cout << "  ft_map.rbegin() : " << ft_map.rbegin()->first << std::endl;
		std::cout << "  ft_map.rend() -1: " << (--ft_map.rend())->first << std::endl;
		ft::map<int, std::string>::const_iterator citr = ft_map.begin();
		std::cout << "  ft_map.begin() const   : " << citr->first << std::endl;
		citr = --ft_map.end();
		std::cout << "  ft_map.end() - 1 const : " << citr->first << std::endl;
		ft::map<int, std::string>::const_reverse_iterator critr = ft_map.rbegin();
		std::cout << "  ft_map.rbegin() const  : " << critr->first << std::endl;
		critr = --ft_map.rend();
		std::cout << "  ft_map.rend() - 1 const: " << critr->first << std::endl;
		std::cout << std::endl;

		std::cout << " clear" << std::endl;
		std::cout << "  ft_map.size(): " << ft_map.size() << std::endl;
		std::cout << "  ft_map.clear()" << std::endl;
		ft_map.clear();
		std::cout << "  ft_map.size(): " << ft_map.size() << std::endl;
    std::cout << std::endl;
	}
	{
		std::cout << " insert" << std::endl;
		ft::map<int, std::string> ft_map;
		std::cout << "  ft_map.insert(ft::make_pair(2, \"B\")" << std::endl;
		ft_map.insert(ft::make_pair(2, "B"));
  	std::cout << "   ft_map[2]: " << ft_map[2] << std::endl;
    std::cout << std::endl;

		std::cout << "  ft_map.insert(ft_map.begin() ,ft::make_pair(1, \"A\")" << std::endl;
		ft_map.insert(ft_map.begin() ,ft::make_pair(1, "A"));
  	std::cout << "   ft_map[1]: " << ft_map[1] << std::endl;
  	std::cout << "   ft_map[2]: " << ft_map[2] << std::endl;
    std::cout << std::endl;

    ft::pair<int, std::string> data[10] = {
      ft::pair<int, std::string>(3, "C"),
      ft::pair<int, std::string>(4, "D"),
      ft::pair<int, std::string>(5, "E")
    };
    std::cout << "  ft_map.insert(data ,data + 3)" << std::endl;
		ft_map.insert(data ,data + 3);
		for (size_t i = 1; i < 5; ++i)
			std::cout << "   ft_map[" << i << "]: " << ft_map[i] << std::endl;
		std::cout << std::endl;

    std::cout << " erase / find / count" << std::endl;
    std::cout << "  ft_map.size()  : " << ft_map.size() << std::endl;
    std::cout << "  ft_map.count(1): " << ft_map.count(1) << std::endl;
    std::cout << "  ft_map.find(1) : " << ft_map.find(1)->first << std::endl;
    std::cout << "  ft_map.erase(ft_map.begin())" << std::endl;
    ft_map.erase(ft_map.begin());
    std::cout << "  ft_map.size()  : " << ft_map.size() << std::endl;
    std::cout << "  ft_map.count(1): " << ft_map.count(1) << std::endl;
    std::cout << "  ft_map.erase(3)" << std::endl;
    ft_map.erase(3);
    std::cout << "  ft_map.size()  : " << ft_map.size() << std::endl;
    std::cout << "  ft_map.count(3): " << ft_map.count(3) << std::endl;

    std::cout << "  ft_map.erase(ft_map.begin(), ft_map.end())" << std::endl;
    ft_map.erase(ft_map.begin(), ft_map.end());
    std::cout << "  ft_map.size()  : " << ft_map.size() << std::endl;
    std::cout << std::endl;
	}
	{
		std::cout << " swap" << std::endl;
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 5; ++i)
    {
      ft_map[i] = static_cast<char>(i + 'A');
			std::cout << "   ft_map[" << i << "]: " << ft_map[i] << std::endl;
    }
		ft::map<int, std::string> ft_map2;
		for (size_t i = 5; i < 10; ++i)
    {
      ft_map2[i] = static_cast<char>(i + 'A');
			std::cout << "   ft_map2[" << i << "]: " << ft_map2[i] << std::endl;
    }
		std::cout << "  ft_map.swap(ft_map2)" << std::endl;
		ft_map.swap(ft_map2);
		std::cout << "  ft_map.begin()->first : " << ft_map.begin()->first << std::endl;
		std::cout << "  ft_map2.begin()->first: " << ft_map2.begin()->first << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " equal_range" << std::endl;
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 5; ++i)
		{
			ft_map[i * 2] = static_cast<char>(i + 'A');
			std::cout << "   ft_map[" << i * 2 << "]: " << ft_map[i * 2] << std::endl;
		}
		ft::map<int, std::string> ft_map2;
		for (size_t i = 5; i < 10; ++i)
		{
			ft_map2[i * 2] = static_cast<char>(i + 'A');
			std::cout << "   ft_map2[" << i * 2 << "]: " << ft_map2[i * 2] << std::endl;
		}
		std::cout << "  ft_map.equal_range(2).first->first: " << ft_map.equal_range(2).first->first << std::endl;
		std::cout << "  ft_map.lower_bound(3).first->first: " << ft_map.lower_bound(3)->first << std::endl;
		std::cout << "  ft_map.lower_bound(4).first->first: " << ft_map.lower_bound(4)->first << std::endl;
		std::cout << "  ft_map.upper_bound(4).first->first: " << ft_map.upper_bound(4)->first << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " key_comp" << std::endl;
		ft::map<int, std::string> ft_map;
		std::cout << "  ft_map.key_comp()(1, 2) is if(1 < 2): " << ft_map.key_comp()(1, 2) << std::endl;
		std::cout << std::endl;
  }
	{
		std::cout << " value_comp" << std::endl;
		ft::map<int, char> c;
		const ft::map<int, char>::value_compare& comp = c.value_comp();
		ft::pair<int, char> p1 = ft::make_pair(1,'a');
		ft::pair<int, char> p2 = ft::make_pair(2,'b');
		ft::pair<int, char> p3 = ft::make_pair(3,'c');
		std::cout << "  comp(p1, p2) is if(1 < 2): " << comp(p1, p2) << std::endl;
		std::cout << "  comp(p3, p2) is if(3 < 2): " << comp(p3, p2) << std::endl;
		std::cout << std::endl;
	}
	std::cout << " Non-member functions" << std::endl;
	{
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 5; ++i)
		{
			ft_map[i] = static_cast<char>(i + 'A');
			std::cout << "   ft_map[" << i << "]: " << ft_map[i] << std::endl;
		}
		ft::map<int, std::string> ft_map2;
		for (size_t i = 0; i < 5; ++i)
		{
			ft_map2[i] = static_cast<char>(i + 'A');
			std::cout << "   ft_map2[" << i << "]: " << ft_map2[i] << std::endl;
		}
		std::cout << std::endl;
		std::cout << "  ft_map == ft_map2: " << (ft_map == ft_map2) << std::endl;
		std::cout << "  ft_map != ft_map2: " << (ft_map != ft_map2) << std::endl;
		std::cout << "  ft_map <  ft_map2: " << (ft_map <  ft_map2) << std::endl;
		std::cout << "  ft_map <= ft_map2: " << (ft_map <= ft_map2) << std::endl;
		std::cout << "  ft_map >  ft_map2: " << (ft_map > ft_map2) << std::endl;
		std::cout << "  ft_map >= ft_map2: " << (ft_map >= ft_map2) << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_map2[1] = \"A\"" << std::endl;
		ft_map2[1] = "A";
		std::cout << std::endl;
		std::cout << "  ft_map == ft_map2: " << (ft_map == ft_map2) << std::endl;
		std::cout << "  ft_map != ft_map2: " << (ft_map != ft_map2) << std::endl;
		std::cout << "  ft_map <  ft_map2: " << (ft_map <  ft_map2) << std::endl;
		std::cout << "  ft_map <= ft_map2: " << (ft_map <= ft_map2) << std::endl;
		std::cout << "  ft_map >  ft_map2: " << (ft_map > ft_map2) << std::endl;
		std::cout << "  ft_map >= ft_map2: " << (ft_map >= ft_map2) << std::endl;
		std::cout << std::endl;

		std::cout << "  swap(ft_map, ft_map2)" << std::endl;
		ft::swap(ft_map, ft_map2);
		for (size_t i = 0; i < 5; ++i)
			std::cout << "   ft_map[" << i << "]: " << ft_map[i] << std::endl;
		for (size_t i = 0; i < 5; ++i)
			std::cout << "   ft_map2[" << i << "]: " << ft_map2[i] << std::endl;
		std::cout << std::endl;
	}

	std::cout << " There are never two of the same Key in one map." << std::endl;
	{
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 5; ++i)
		{
			ft_map[i] = static_cast<char>(i + 'A');
			std::cout << "   ft_map[" << i << "]: " << ft_map[i] << std::endl;
		}
		ft::pair<ft::map<int, std::string>::iterator, bool> result = ft_map.insert(ft::make_pair(0, "A"));
		std::cout << "  ft_map.insert(ft::make_pair(0, \"A\"): " << result.second << std::endl;
		std::cout << std::endl;
	}

	std::cout << " Check that insert or delete do not invalidate iterators." << std::endl;
	{
		ft::map<int, std::string> ft_map;
		for (size_t i = 0; i < 5; ++i)
		{
			ft_map[i * 2] = static_cast<char>(i + 'A');
			std::cout << "   ft_map[" << i * 2 << "]: " << ft_map[i * 2] << std::endl;
		}
		std::cout << "  itr = ft_map.begin()" << std::endl;
		ft::map<int, std::string>::iterator itr = ft_map.begin();
		std::cout << "  ft_map[1] = \"ONE\"" << std::endl;
		ft_map[1] = "ONE";
		std::cout << "  (++itr)->first: " << (++itr)->first << std::endl;
		std::cout << "  itr = ft_map.begin()" << std::endl;
		itr = ft_map.begin();
		std::cout << "  ft_map.erase(1)" << std::endl;
		ft_map.erase(1);
		std::cout << "  (++itr)->first: " << (++itr)->first << std::endl;
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << "stack test" << std::endl;
	{
		std::cout << " constructor" << std::endl;
		std::cout << " ft::stack<int> ft_sta" << std::endl;
		ft::stack<int> ft_sta;
		std::cout << "  empty(): " << ft_sta.empty() << std::endl;
		std::cout << "  size(): " << ft_sta.size() << std::endl;
		std::cout << std::endl;

		std::cout << " operator= / push / top / pop" << std::endl;
		std::cout << "  ft_sta.push(1)" << std::endl;
		ft_sta.push(1);
		std::cout << "  empty(): " << ft_sta.empty() << std::endl;
		std::cout << "  size(): " << ft_sta.size() << std::endl;
		std::cout << "  ft_sta.top(): " << ft_sta.top() << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_sta.push(2)" << std::endl;
		ft_sta.push(2);
		std::cout << "  size(): " << ft_sta.size() << std::endl;
		std::cout << "  ft_sta.top(): " << ft_sta.top() << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_sta.pop()" << std::endl;
		ft_sta.pop();
		std::cout << "  size(): " << ft_sta.size() << std::endl;
		std::cout << "  ft_sta.top(): " << ft_sta.top() << std::endl;
		std::cout << std::endl;

		std::cout << "  ft_sta2 = ft_sta" << std::endl;
		ft::stack<int> ft_sta2;
		ft_sta2 = ft_sta;
		std::cout << "  size(): " << ft_sta2.size() << std::endl;
		std::cout << "  ft_sta.top(): " << ft_sta2.top() << std::endl;
		std::cout << std::endl;

		std::cout << " Non-member functions" << std::endl;
		std::cout << "  ft_sta == ft_sta2: " << (ft_sta == ft_sta2) << std::endl;
		std::cout << "  ft_sta != ft_sta2: " << (ft_sta != ft_sta2) << std::endl;
		std::cout << "  ft_sta <  ft_sta2: " << (ft_sta <  ft_sta2) << std::endl;
		std::cout << "  ft_sta <= ft_sta2: " << (ft_sta <= ft_sta2) << std::endl;
		std::cout << "  ft_sta >  ft_sta2: " << (ft_sta > ft_sta2) << std::endl;
		std::cout << "  ft_sta >= ft_sta2: " << (ft_sta >= ft_sta2) << std::endl;
		std::cout << std::endl;
		std::cout << "  ft_sta.push(5)" << std::endl;
		ft_sta.push(5);
		std::cout << "  ft_sta == ft_sta2: " << (ft_sta == ft_sta2) << std::endl;
		std::cout << "  ft_sta != ft_sta2: " << (ft_sta != ft_sta2) << std::endl;
		std::cout << "  ft_sta <  ft_sta2: " << (ft_sta <  ft_sta2) << std::endl;
		std::cout << "  ft_sta <= ft_sta2: " << (ft_sta <= ft_sta2) << std::endl;
		std::cout << "  ft_sta >  ft_sta2: " << (ft_sta > ft_sta2) << std::endl;
		std::cout << "  ft_sta >= ft_sta2: " << (ft_sta >= ft_sta2) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << " The standard container classes vector, deque and list are compatible as underlying container." << std::endl;
		std::cout << "  ft::stack<int, std::list> ft_sta" << std::endl;
		ft::stack<int, std::list<int> > ft_sta_list;
		std::cout << "  ft::stack<int, std::deque> ft_sta" << std::endl;
		ft::stack<int, std::deque<int> > ft_sta_deque;
	}
	std::cout << "----------------------------------------------" << std::endl;
#ifdef LEAK
		std::system("leaks a.out");
#endif
	return (0);
}