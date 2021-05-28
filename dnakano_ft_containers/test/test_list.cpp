/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 08:01:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/03/08 12:33:46 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <forward_list>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

#include "../list.hpp"
#include "../vector.hpp"
#include "Hoge.hpp"
#include "test.hpp"

void test_list(int& test_no) {
  Hoge hoge[10] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2), Hoge(3, 3), Hoge(4, 4),
                   Hoge(5, 5), Hoge(6, 6), Hoge(7, 7), Hoge(8, 8), Hoge(9, 9)};
  std::vector<Hoge> hoge_vec(hoge, &hoge[10]);
  std::list<Hoge> hoge_lst(hoge, &hoge[10]);
  std::forward_list<Hoge> hoge_flst(hoge, &hoge[10]);

  int num[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
  std::vector<int> num_vec(num, &num[10]);

  std::cout << "=== TEST LIST ===" << std::endl;

  // default constuction
  putTestInfo(test_no, "list<Hoge>: default construction");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  // default push_front(), front() and back()
  putTestInfo(test_no, "list<int>: push_front() and get it by front()");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;

    lst_std.push_front(4);
    lst_ft.push_front(4);
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: push_front() and get it by front()");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.push_front(hoge[4]);
    lst_ft.push_front(hoge[4]);
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: push_front() and get it by back()");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.push_front(hoge[4]);
    lst_ft.push_front(hoge[4]);
    if (lst_std.back() != lst_ft.back()) {
      throw std::runtime_error("value");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: push_front() twice and get it by front() and back()");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.push_front(hoge[4]);
    lst_ft.push_front(hoge[4]);
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("front");
    }
    if (lst_std.back() != lst_ft.back()) {
      throw std::runtime_error("back");
    }
    lst_std.push_front(hoge[2]);
    lst_ft.push_front(hoge[2]);
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("front");
    }
    if (lst_std.back() != lst_ft.back()) {
      throw std::runtime_error("back");
    }
    // try twice
    if (lst_std.front() != lst_ft.front()) {
      throw std::runtime_error("front");
    }
    if (lst_std.back() != lst_ft.back()) {
      throw std::runtime_error("back");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: push_front() 10 times and front/back/size/empty/max_size");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    if (lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size() ||
        lst_std.empty() != lst_ft.empty()) {
      throw std::runtime_error("size/empty/max_size");
    }
    if (lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("size");
    }
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: push_back() 10 times and front/back/size/empty/max_size");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    if (lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size() ||
        lst_std.empty() != lst_ft.empty()) {
      throw std::runtime_error("size/empty/max_size");
    }
    if (lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("size");
    }
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and "
              "front/back/size/empty/max_size");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    if (lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size() ||
        lst_std.empty() != lst_ft.empty()) {
      throw std::runtime_error("size/empty/max_size");
    }
    if (lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("size");
    }
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and pop_front until empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    while (!lst_std.empty()) {
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
      lst_std.pop_front();
      lst_ft.pop_front();
    }
    if (!lst_ft.empty()) {
      throw std::runtime_error("empty");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and pop_back until empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    while (!lst_std.empty()) {
      // std::cout << "size = " << lst_ft.size() << std::endl;
      // std::cout << "std = " << lst_std.front() << std::endl;
      // std::cout << "std = " << lst_std.back() << std::endl;
      // std::cout << "ft = " << lst_ft.front() << std::endl;
      // std::cout << "ft = " << lst_ft.back() << std::endl;
      if (lst_std.front() != lst_ft.front()) {
        throw std::runtime_error("front");
      }
      if (lst_std.back() != lst_ft.back()) {
        throw std::runtime_error("back");
      }
      if (lst_std.size() != lst_ft.size() ||
          lst_std.max_size() != lst_ft.max_size() ||
          lst_std.empty() != lst_ft.empty()) {
        throw std::runtime_error("size/empty/max_size");
      }
      lst_std.pop_back();
      lst_ft.pop_back();
    }
    if (!lst_ft.empty()) {
      throw std::runtime_error("empty");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and check value using "
              "iterator (increase by ++iter)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    for (itr_ft = lst_ft.begin(), itr_std = lst_std.begin();
         itr_ft != lst_ft.end(); ++itr_ft, ++itr_std) {
      if (*itr_ft != *itr_std) {
        std::cout << "std :: ft = " << *itr_std << " :: " << *itr_ft
                  << std::endl;
        throw std::runtime_error("iterator value");
      }
    }
    if (itr_std != lst_std.end()) {
      throw std::runtime_error("iteratation");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times and check value using "
              "iterator (increase by iter++)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    itr_ft = lst_ft.begin();
    itr_std = lst_std.begin();
    while (itr_ft != lst_ft.end()) {
      if (*itr_std++ != *itr_ft++) {
        throw std::runtime_error("iterator value");
      }
    }
    if (itr_std != lst_std.end()) {
      throw std::runtime_error("iteratation");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times, then rewrite all value to "
              "zero and check value using iterator");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    itr_ft = lst_ft.begin();
    itr_std = lst_std.begin();
    while (itr_ft != lst_ft.end()) {
      *itr_std++ = hoge[0];
      *itr_ft++ = hoge[0];
    }
    itr_ft = lst_ft.begin();
    itr_std = lst_std.begin();
    while (itr_ft != lst_ft.end()) {
      if (*itr_std++ != *itr_ft++) {
        throw std::runtime_error("iterator value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back 10 times and check value using "
              "iterator (increase by ++iter)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::reverse_iterator itr_std;
    ft::list<Hoge>::reverse_iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    for (itr_ft = lst_ft.rbegin(), itr_std = lst_std.rbegin();
         itr_ft != lst_ft.rend(); ++itr_ft, ++itr_std) {
      if (*itr_ft != *itr_std) {
        std::cout << "std :: ft = " << *itr_std << " :: " << *itr_ft
                  << std::endl;
        throw std::runtime_error("iterator value");
      }
    }
    if (itr_std != lst_std.rend()) {
      throw std::runtime_error("iteratation");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back 10 times and check value using "
              "iterator (increase by iter++)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::reverse_iterator itr_std;
    ft::list<Hoge>::reverse_iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    itr_ft = lst_ft.rbegin();
    itr_std = lst_std.rbegin();
    while (itr_ft != lst_ft.rend()) {
      if (*itr_std++ != *itr_ft++) {
        throw std::runtime_error("iterator value");
      }
    }
    if (itr_std != lst_std.rend()) {
      throw std::runtime_error("iteratation");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: push_back/front 10 times, then rewrite all value to "
              "zero and check value using iterator");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::reverse_iterator itr_std;
    ft::list<Hoge>::reverse_iterator itr_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    itr_ft = lst_ft.rbegin();
    itr_std = lst_std.rbegin();
    while (itr_ft != lst_ft.rend()) {
      *itr_std++ = hoge[0];
      *itr_ft++ = hoge[0];
    }
    itr_ft = lst_ft.rbegin();
    itr_std = lst_std.rbegin();
    while (itr_ft != lst_ft.rend()) {
      if (*itr_std++ != *itr_ft++) {
        throw std::runtime_error("iterator value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: clear() of default constucted");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.clear();
    lst_ft.clear();
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("error");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: clear() of 1 elem contained");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.push_front(hoge[1]);
    lst_ft.push_front(hoge[1]);
    lst_std.clear();
    lst_ft.clear();
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("error");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: push_front 10 times, then clear()");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    lst_std.clear();
    lst_ft.clear();
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("error");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: clear add clear add clear");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    lst_std.clear();
    lst_ft.clear();
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
      lst_std.push_back(*iter);
      lst_ft.push_back(*iter);
    }
    lst_std.clear();
    lst_ft.clear();
    lst_std.push_front(hoge[1]);
    lst_ft.push_front(hoge[1]);
    lst_std.clear();
    lst_ft.clear();
    for (std::vector<Hoge>::iterator iter = hoge_vec.begin();
         iter != hoge_vec.end(); ++iter) {
      lst_std.push_front(*iter);
      lst_ft.push_front(*iter);
    }
    lst_std.clear();
    lst_ft.clear();
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size() ||
        lst_std.max_size() != lst_ft.max_size()) {
      throw std::runtime_error("error");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(n, val) <int>
  putTestInfo(test_no, "list<int>: assign(0, 42) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(1, 42);
    lst_ft.assign(1, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(1, 42) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(1, 42);
    lst_ft.assign(1, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(42, 42) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(42, 42);
    lst_ft.assign(42, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign 42 -> 0 -> 1 -> 42 -> 1 to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(42, 42);
    lst_ft.assign(42, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(0, 42);
    lst_ft.assign(0, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(1, 42);
    lst_ft.assign(1, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(42, 42);
    lst_ft.assign(42, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(1, 42);
    lst_ft.assign(1, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(n, val) <Hoge>
  putTestInfo(test_no, "list<Hoge>: assign(0, hoge[4]) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(1, hoge[4]);
    lst_ft.assign(1, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(1, hoge[4]) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(1, hoge[4]);
    lst_ft.assign(1, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(42, hoge[4]) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(42, hoge[4]);
    lst_ft.assign(42, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign 42 -> 0 -> 1 -> 42 -> 1 to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(42, hoge[4]);
    lst_ft.assign(42, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(0, hoge[4]);
    lst_ft.assign(0, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(1, hoge[4]);
    lst_ft.assign(1, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(42, hoge[4]);
    lst_ft.assign(42, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(1, hoge[4]);
    lst_ft.assign(1, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(itr, itr) <int>
  putTestInfo(test_no, "list<int>: assign(begin, end) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.begin(), num_vec.end());
    lst_ft.assign(num_vec.begin(), num_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(rbegin, rend) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.rbegin(), num_vec.rend());
    lst_ft.assign(num_vec.rbegin(), num_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(begin, begin) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.begin(), num_vec.begin());
    lst_ft.assign(num_vec.begin(), num_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(end, end) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.end(), num_vec.end());
    lst_ft.assign(num_vec.end(), num_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign(begin, ++begin) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.begin(), ++num_vec.begin());
    lst_ft.assign(num_vec.begin(), ++num_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: assign(begin, end) -> (begin,begin)->(rbegin,rend) "
              "-> (begin,++begin) -> (begin,end) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(num_vec.begin(), num_vec.end());
    lst_ft.assign(num_vec.begin(), num_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(num_vec.begin(), num_vec.begin());
    lst_ft.assign(num_vec.begin(), num_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(num_vec.rbegin(), num_vec.rend());
    lst_ft.assign(num_vec.rbegin(), num_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(num_vec.begin(), num_vec.begin());
    lst_ft.assign(num_vec.begin(), num_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(num_vec.begin(), num_vec.end());
    lst_ft.assign(num_vec.begin(), num_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(ptr, ptr) <int>
  putTestInfo(test_no, "list<int>: assign([0], [9]) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(&num[0], &num[9]);
    lst_ft.assign(&num[0], &num[9]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign([0], [0]) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(&num[0], &num[0]);
    lst_ft.assign(&num[0], &num[0]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: assign([0], [0]) to empty");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.assign(&num[2], &num[4]);
    lst_ft.assign(&num[2], &num[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // assign(itr, itr) <Hoge>
  putTestInfo(test_no, "list<Hoge>: assign(begin, end) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.begin(), hoge_vec.end());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(rbegin, rend) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.assign(hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(begin, begin) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.begin(), hoge_vec.begin());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(end, end) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.end(), hoge_vec.end());
    lst_ft.assign(hoge_vec.end(), hoge_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: assign(begin, ++begin) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.begin(), ++hoge_vec.begin());
    lst_ft.assign(hoge_vec.begin(), ++hoge_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: assign(begin, end) -> (begin,begin)->(rbegin,rend) "
              "-> (begin,++begin) -> (begin,end) to empty");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.assign(hoge_vec.begin(), hoge_vec.end());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(hoge_vec.begin(), hoge_vec.begin());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.assign(hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(hoge_vec.begin(), hoge_vec.begin());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

    lst_std.assign(hoge_vec.begin(), hoge_vec.end());
    lst_ft.assign(hoge_vec.begin(), hoge_vec.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // fill constructor <int>
  putTestInfo(test_no, "list<int>: int(0)");
  try {
    std::list<int> lst_std(0);
    ft::list<int> lst_ft(0);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(0, 42)");
  try {
    std::list<int> lst_std(0, 42);
    ft::list<int> lst_ft(0, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(1)");
  try {
    std::list<int> lst_std(1);
    ft::list<int> lst_ft(1);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(1, 42)");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(24)");
  try {
    std::list<int> lst_std(24);
    ft::list<int> lst_ft(24);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: int(24, 42)");
  try {
    std::list<int> lst_std(24, 42);
    ft::list<int> lst_ft(24, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // fill constructor <Hoge>
  putTestInfo(test_no, "list<Hoge>: Hoge(0)");
  try {
    std::list<Hoge> lst_std(0);
    ft::list<Hoge> lst_ft(0);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(0, hoge[4])");
  try {
    std::list<Hoge> lst_std(0, hoge[4]);
    ft::list<Hoge> lst_ft(0, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(1)");
  try {
    std::list<Hoge> lst_std(1);
    ft::list<Hoge> lst_ft(1);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(24)");
  try {
    std::list<Hoge> lst_std(24);
    ft::list<Hoge> lst_ft(24);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: Hoge(24, hoge[4])");
  try {
    std::list<Hoge> lst_std(24, hoge[4]);
    ft::list<Hoge> lst_ft(24, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // range constuctor(itr, itr) <int>
  putTestInfo(test_no, "list<int>: list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list(begin, begin)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.begin());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.begin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list(rbegin, rend)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rend());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rend());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // range constuctor(ptr, ptr) <int>
  putTestInfo(test_no, "list<int>: list([0], [9])");
  try {
    std::list<int> lst_std(num, &num[9]);
    ft::list<int> lst_ft(num, &num[9]);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list([4], [4])");
  try {
    std::list<int> lst_std(&num[4], &num[4]);
    ft::list<int> lst_ft(&num[4], &num[4]);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // range constuctor(itr, itr) <Hoge>
  putTestInfo(test_no, "list<Hoge>: list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(begin, begin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.begin());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.begin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(rbegin, rend)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rend());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // copy constructor
  putTestInfo(test_no, "list<Hoge>: copy constructor");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std(lst_std_src);
    ft::list<Hoge> lst_ft(lst_ft_src);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: copy constructor from empty");
  try {
    std::list<Hoge> lst_std_src;
    ft::list<Hoge> lst_ft_src;
    std::list<Hoge> lst_std(lst_std_src);
    ft::list<Hoge> lst_ft(lst_ft_src);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // operator=
  putTestInfo(test_no, "list<Hoge>: lst = lst");
  try {
    std::list<Hoge> lst_std_src;
    ft::list<Hoge> lst_ft_src;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst = lst(begin, ++begin)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), ++hoge_vec.begin());
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst = lst(begin, end)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, ++begin) = lst");
  try {
    std::list<Hoge> lst_std_src;
    ft::list<Hoge> lst_ft_src;
    std::list<Hoge> lst_std(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), ++hoge_vec.begin());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, ++begin) = lst(begin, ++begin)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), ++hoge_vec.begin());
    std::list<Hoge> lst_std(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), ++hoge_vec.begin());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, ++begin) = lst(begin, end)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), ++hoge_vec.begin());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, end) = lst");
  try {
    std::list<Hoge> lst_std_src;
    ft::list<Hoge> lst_ft_src;
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, end) = lst(begin, ++begin)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), ++hoge_vec.begin());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), ++hoge_vec.begin());
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: lst(begin, end) = lst(begin, end)");
  try {
    std::list<Hoge> lst_std_src(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft_src(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    lst_std = lst_std_src;
    lst_ft = lst_ft_src;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, val) <int>
  putTestInfo(test_no, "list<int>: insert(begin, 42) to list(rbegin, rbegin)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rbegin());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rbegin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), 42);
    itr_ft = lst_ft.insert(lst_ft.begin(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(begin, 42) to list(rbegin,++rbegin)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), ++num_vec.rbegin());
    ft::list<int> lst_ft(num_vec.rbegin(), ++num_vec.rbegin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), 42);
    itr_ft = lst_ft.insert(lst_ft.begin(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(begin, 42) to list(rbegin, rend)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rend());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rend());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), 42);
    itr_ft = lst_ft.insert(lst_ft.begin(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 42) to list(rbegin, rbegin)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rbegin());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rbegin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), 42);
    itr_ft = lst_ft.insert(lst_ft.end(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 42) to list(rbegin,++rbegin)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), ++num_vec.rbegin());
    ft::list<int> lst_ft(num_vec.rbegin(), ++num_vec.rbegin());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), 42);
    itr_ft = lst_ft.insert(lst_ft.end(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 42) to list(rbegin, rend)");
  try {
    std::list<int> lst_std(num_vec.rbegin(), num_vec.rend());
    ft::list<int> lst_ft(num_vec.rbegin(), num_vec.rend());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), 42);
    itr_ft = lst_ft.insert(lst_ft.end(), 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(begin + 5, 42) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (int n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.insert(itr_std, 42);
    itr_ft = lst_ft.insert(itr_ft, 42);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, val) <Hoge>
  putTestInfo(test_no,
              "list<Hoge>: insert(begin, hoge[4]) to list(rbegin, rbegin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rbegin());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rbegin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.begin(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, hoge[4]) to list(rbegin,++rbegin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), ++hoge_vec.rbegin());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), ++hoge_vec.rbegin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.begin(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, hoge[4]) to list(rbegin, rend)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rend());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.begin(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.begin(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, hoge[4]) to list(rbegin, rbegin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rbegin());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rbegin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.end(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, hoge[4]) to list(rbegin,++rbegin)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), ++hoge_vec.rbegin());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), ++hoge_vec.rbegin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.end(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, hoge[4]) to list(rbegin, rend)");
  try {
    std::list<Hoge> lst_std(hoge_vec.rbegin(), hoge_vec.rend());
    ft::list<Hoge> lst_ft(hoge_vec.rbegin(), hoge_vec.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.insert(lst_std.end(), hoge[4]);
    itr_ft = lst_ft.insert(lst_ft.end(), hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin + 5, hoge[4]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.insert(itr_std, hoge[4]);
    itr_ft = lst_ft.insert(itr_ft, hoge[4]);
    if (*itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, n, val) <int>
  putTestInfo(test_no, "list<int>: insert(begin, 24, 42) to list");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(++begin, 24, 42) to list");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), 24, 42);
    lst_ft.insert(++lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 24, 42) to list");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(begin, 24, 42) to list(1, 42)");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(++begin, 24, 42) to list(1, 42)");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), 24, 42);
    lst_ft.insert(++lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 24, 42) to list(1,42)");
  try {
    std::list<int> lst_std(1, 42);
    ft::list<int> lst_ft(1, 42);
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(begin, 24, 42) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, 42);
    lst_ft.insert(lst_ft.begin(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: insert(end, 24, 42) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    lst_std.insert(lst_std.end(), 24, 42);
    lst_ft.insert(lst_ft.end(), 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<int>: insert(begin + 5, 24, 42) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    lst_std.insert(itr_std, 24, 42);
    lst_ft.insert(itr_ft, 24, 42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, n, val) <Hoge>
  putTestInfo(test_no, "list<Hoge>: insert(begin, 24, hoge[4]) to list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: insert(++begin, 24, hoge[4]) to list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(++lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: insert(end, 24, hoge[4]) to list");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, 24, hoge[4]) to list(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(++begin, 24, hoge[4]) to list(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(++lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, 24, hoge[4]) to list(1,hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, 24, hoge[4]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), 24, hoge[4]);
    lst_ft.insert(lst_ft.begin(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, 24, hoge[4]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.end(), 24, hoge[4]);
    lst_ft.insert(lst_ft.end(), 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin + 5, 24, hoge[4]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    lst_std.insert(itr_std, 24, hoge[4]);
    lst_ft.insert(itr_ft, 24, hoge[4]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, itr, itr) <int>
  putTestInfo(test_no,
              "list<int>: insert(begin + 5, rbegin, rend) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    lst_std.insert(itr_std, num_vec.rbegin(), num_vec.rend());
    lst_ft.insert(itr_ft, num_vec.rbegin(), num_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, ptr, ptr) <int>
  putTestInfo(test_no,
              "list<int>: insert(begin + 5, [5], [7]) to list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    lst_std.insert(itr_std, num_vec.rbegin(), num_vec.rend());
    lst_ft.insert(itr_ft, num_vec.rbegin(), num_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, n, val) <Hoge>
  putTestInfo(test_no, "list<Hoge>: insert(begin, rbegin, rend) to list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(lst_ft.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(++begin, hoge_vec.rbegin(), hoge_vec.rend()) "
              "to list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(++lst_ft.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: insert(end, hoge_vec.rbegin(), hoge_vec.rend()) to list");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(lst_ft.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, hoge_vec.rbegin(), hoge_vec.rend()) "
              "to list(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(lst_ft.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(++begin, hoge_vec.rbegin(), hoge_vec.rend()) "
              "to list(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(++lst_ft.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, hoge_vec.rbegin(), hoge_vec.rend()) to "
              "list(1,hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(lst_ft.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin, hoge_vec.rbegin(), hoge_vec.rend()) "
              "to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(lst_ft.begin(), hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, hoge_vec.rbegin(), hoge_vec.rend()) to "
              "list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.end(), hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(lst_ft.end(), hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(begin + 5, hoge_vec.rbegin(), "
              "hoge_vec.rend()) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    lst_std.insert(itr_std, hoge_vec.rbegin(), hoge_vec.rend());
    lst_ft.insert(itr_ft, hoge_vec.rbegin(), hoge_vec.rend());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(pos, [4], [8]) <Hoge>
  putTestInfo(test_no, "list<Hoge>: insert(begin, [4], [8]) to list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), &hoge[4], &hoge[8]);
    lst_ft.insert(lst_ft.begin(), &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(++begin, &hoge[4], &hoge[8]) to list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), &hoge[4], &hoge[8]);
    lst_ft.insert(++lst_ft.begin(), &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: insert(end, &hoge[4], &hoge[8]) to list");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), &hoge[4], &hoge[8]);
    lst_ft.insert(lst_ft.begin(), &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: insert(begin, &hoge[4], &hoge[8]) to list(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), &hoge[4], &hoge[8]);
    lst_ft.insert(lst_ft.begin(), &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: insert(++begin, &hoge[4], &hoge[8]) to list(1, hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(++lst_std.begin(), &hoge[4], &hoge[8]);
    lst_ft.insert(++lst_ft.begin(), &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: insert(end, &hoge[4], &hoge[8]) to list(1,hoge[4])");
  try {
    std::list<Hoge> lst_std(1, hoge[4]);
    ft::list<Hoge> lst_ft(1, hoge[4]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), &hoge[4], &hoge[8]);
    lst_ft.insert(lst_ft.begin(), &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: insert(begin, &hoge[4], &hoge[8]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.begin(), &hoge[4], &hoge[8]);
    lst_ft.insert(lst_ft.begin(), &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: insert(end, &hoge[4], &hoge[8]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.insert(lst_std.end(), &hoge[4], &hoge[8]);
    lst_ft.insert(lst_ft.end(), &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list<Hoge>: insert(begin + 5, &hoge[4], &hoge[8]) to list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t n = 0; n < 5; n++) {
      ++itr_std;
      ++itr_ft;
    }
    lst_std.insert(itr_std, &hoge[4], &hoge[8]);
    lst_ft.insert(itr_ft, &hoge[4], &hoge[8]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // erase(pos) int
  putTestInfo(test_no, "list<int>: erase(begin + 5) from list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(itr_std);
    itr_ft = lst_ft.erase(itr_ft);
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: erase(begin) from list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    while (lst_std.size() > 0) {
      itr_std = lst_std.erase(lst_std.begin());
      itr_ft = lst_ft.erase(lst_ft.begin());
      if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
          *itr_std != *itr_ft) {
        throw std::runtime_error("return value");
      }
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: erase(--end) from list(begin, end)");
  try {
    std::list<int> lst_std(num_vec.begin(), num_vec.end());
    ft::list<int> lst_ft(num_vec.begin(), num_vec.end());
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    while (lst_std.size() > 0) {
      itr_std = lst_std.erase(--lst_std.end());
      itr_ft = lst_ft.erase(--lst_ft.end());
      if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
          *itr_std != *itr_ft) {
        throw std::runtime_error("return value");
      }
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // erase(pos) Hoge
  putTestInfo(test_no, "list<Hoge>: erase(begin + 5) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(itr_std);
    itr_ft = lst_ft.erase(itr_ft);
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: erase(begin) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    while (lst_std.size() > 0) {
      itr_std = lst_std.erase(lst_std.begin());
      itr_ft = lst_ft.erase(lst_ft.begin());
      if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
          *itr_std != *itr_ft) {
        throw std::runtime_error("return value");
      }
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: erase(--end) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    while (lst_std.size() > 0) {
      itr_std = lst_std.erase(--lst_std.end());
      itr_ft = lst_ft.erase(--lst_ft.end());
      if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
          *itr_std != *itr_ft) {
        throw std::runtime_error("return value");
      }
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // erase(pos) Hoge
  putTestInfo(test_no,
              "list<Hoge>: erase(begin, begin + 5) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(lst_std.begin(), itr_std);
    itr_ft = lst_ft.erase(lst_ft.begin(), itr_ft);
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: erase(begin, end) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(lst_std.begin(), lst_std.end());
    itr_ft = lst_ft.erase(lst_ft.begin(), lst_ft.end());
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: erase(begin + 1, begin + 5) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(++lst_std.begin(), itr_std);
    itr_ft = lst_ft.erase(++lst_ft.begin(), itr_ft);
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: erase(begin + 5, begin + 7) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(itr_std++, ++itr_std);
    itr_ft = lst_ft.erase(itr_ft++, ++itr_ft);
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: erase(begin + 5, begin + 5) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(itr_std, itr_std);
    itr_ft = lst_ft.erase(itr_ft, itr_ft);
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: erase(begin + 5, end) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(itr_std, lst_std.end());
    itr_ft = lst_ft.erase(itr_ft, lst_ft.end());
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list<Hoge>: erase(begin + 5, end) from list(begin, end)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    itr_std = lst_std.begin();
    itr_ft = lst_ft.begin();
    for (size_t i = 0; i < 5; ++i) {
      ++itr_std;
      ++itr_ft;
    }
    itr_std = lst_std.erase(itr_std, lst_std.end());
    itr_ft = lst_ft.erase(itr_ft, lst_ft.end());
    if (itr_std != lst_std.end() && itr_ft != lst_ft.end() &&
        *itr_std != *itr_ft) {
      throw std::runtime_error("return value");
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // swap (member)
  putTestInfo(test_no, "list<Hoge> list(begin, end).swap(list(begin, end))");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std2(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft2(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.swap(lst_std2);
    lst_ft.swap(lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list(begin, end).swap(list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::list<Hoge> lst_ft2(hoge_vec.rbegin(), hoge_vec.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.swap(lst_std2);
    lst_ft.swap(lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list.swap(list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.swap(lst_std2);
    lst_ft.swap(lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list.swap(list(begin, end))");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft2(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.swap(lst_std2);
    lst_ft.swap(lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list(begin, end).swap(list)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.swap(lst_std2);
    lst_ft.swap(lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list([2], [4]).swap(list([1], [8]))");
  try {
    std::list<Hoge> lst_std(&hoge[2], &hoge[4]);
    ft::list<Hoge> lst_ft(&hoge[2], &hoge[4]);
    std::list<Hoge> lst_std2(&hoge[1], &hoge[8]);
    ft::list<Hoge> lst_ft2(&hoge[1], &hoge[8]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.swap(lst_std2);
    lst_ft.swap(lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list([1], [4]).swap(list([7], [8]))");
  try {
    std::list<Hoge> lst_std(&hoge[1], &hoge[4]);
    ft::list<Hoge> lst_ft(&hoge[1], &hoge[4]);
    std::list<Hoge> lst_std2(&hoge[7], &hoge[8]);
    ft::list<Hoge> lst_ft2(&hoge[7], &hoge[8]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.swap(lst_std2);
    lst_ft.swap(lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list(begin, end).swap(itself)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.swap(lst_std);
    lst_ft.swap(lst_ft);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // swap (non member)
  putTestInfo(test_no, "list<Hoge> list(begin, end).swap(list(begin, end))");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std2(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft2(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    std::swap(lst_std, lst_std2);
    ft::swap(lst_ft, lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list(begin, end).swap(list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::list<Hoge> lst_ft2(hoge_vec.rbegin(), hoge_vec.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    std::swap(lst_std, lst_std2);
    ft::swap(lst_ft, lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list.swap(list");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    std::swap(lst_std, lst_std2);
    ft::swap(lst_ft, lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list.swap(list(begin, end))");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft2(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    std::swap(lst_std, lst_std2);
    ft::swap(lst_ft, lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list(begin, end).swap(list)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    std::swap(lst_std, lst_std2);
    ft::swap(lst_ft, lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list([2], [4]).swap(list([1], [8]))");
  try {
    std::list<Hoge> lst_std(&hoge[2], &hoge[4]);
    ft::list<Hoge> lst_ft(&hoge[2], &hoge[4]);
    std::list<Hoge> lst_std2(&hoge[1], &hoge[8]);
    ft::list<Hoge> lst_ft2(&hoge[1], &hoge[8]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    std::swap(lst_std, lst_std2);
    ft::swap(lst_ft, lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list([1], [4]).swap(list([7], [8]))");
  try {
    std::list<Hoge> lst_std(&hoge[1], &hoge[4]);
    ft::list<Hoge> lst_ft(&hoge[1], &hoge[4]);
    std::list<Hoge> lst_std2(&hoge[7], &hoge[8]);
    ft::list<Hoge> lst_ft2(&hoge[7], &hoge[8]);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    std::swap(lst_std, lst_std2);
    ft::swap(lst_ft, lst_ft2);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge> list(begin, end).swap(itself)");
  try {
    std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
    ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    std::swap(lst_std, lst_std);
    ft::swap(lst_ft, lst_ft);
    // check lst1
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // resize
  putTestInfo(test_no, "list().resize(42)");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(42);
    lst_ft.resize(42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(21).resize(42)");
  try {
    std::list<Hoge> lst_std(21);
    ft::list<Hoge> lst_ft(21);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(42);
    lst_ft.resize(42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(64).resize(42)");
  try {
    std::list<Hoge> lst_std(64);
    ft::list<Hoge> lst_ft(64);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(42);
    lst_ft.resize(42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(0)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(0);
    lst_ft.resize(0);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(0, hoge[5])");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(0, hoge[5]);
    lst_ft.resize(0, hoge[5]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(1)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(1);
    lst_ft.resize(1);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(1, hoge[5])");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(1, hoge[5]);
    lst_ft.resize(1, hoge[5]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(5)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(5);
    lst_ft.resize(5);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(5, hoge[5])");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(5, hoge[5]);
    lst_ft.resize(5, hoge[5]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(9)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(9);
    lst_ft.resize(9);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(9, hoge[5])");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(9, hoge[5]);
    lst_ft.resize(9, hoge[5]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(10)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(10);
    lst_ft.resize(10);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(10, hoge[5])");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(10, hoge[5]);
    lst_ft.resize(10, hoge[5]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(11)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(11);
    lst_ft.resize(11);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(11, hoge[5])");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(11, hoge[5]);
    lst_ft.resize(11, hoge[5]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(42)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(42);
    lst_ft.resize(42);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).resize(42, hoge[5])");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.resize(42, hoge[5]);
    lst_ft.resize(42, hoge[5]);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // splice(pos, x)
  putTestInfo(test_no, "list(begin, end).splice(begin, list())");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2);
    lst_ft.splice(lst_ft.begin(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(begin, list(0))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(++hoge_flst.begin(), ++hoge_flst.begin());
    ft::list<Hoge> lst_ft2(++hoge_flst.begin(), ++hoge_flst.begin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2);
    lst_ft.splice(lst_ft.begin(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(begin, list(1))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_flst.begin(), ++hoge_flst.begin());
    ft::list<Hoge> lst_ft2(hoge_flst.begin(), ++hoge_flst.begin());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2);
    lst_ft.splice(lst_ft.begin(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(begin, list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2);
    lst_ft.splice(lst_ft.begin(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(++begin, list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++lst_std.begin(), lst_std2);
    lst_ft.splice(++lst_ft.begin(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(++++begin, list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++++lst_std.begin(), lst_std2);
    lst_ft.splice(++++lst_ft.begin(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(++++++begin, list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++++++lst_std.begin(), lst_std2);
    lst_ft.splice(++++++lst_ft.begin(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(end, list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.end(), lst_std2);
    lst_ft.splice(lst_ft.end(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(--end, list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(--lst_std.end(), lst_std2);
    lst_ft.splice(--lst_ft.end(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(----end, list(rbegin, rend))");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(----lst_std.end(), lst_std2);
    lst_ft.splice(----lst_ft.end(), lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // splice(pos, x, itr)
  putTestInfo(test_no,
              "list(begin, end).splice(begin, list(rbegin, rend), begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, list(rbegin, rend), ++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, ++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, ++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, list(rbegin, rend), ++++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, ++++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, ++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(++begin, list(rbegin, rend), begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++lst_std.begin(), lst_std2, lst_std2.begin());
    lst_ft.splice(++lst_ft.begin(), lst_ft2, lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(++begin, list(rbegin, rend), ++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++lst_std.begin(), lst_std2, ++lst_std2.begin());
    lst_ft.splice(++lst_ft.begin(), lst_ft2, ++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(++begin, list(rbegin, rend), ++++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++lst_std.begin(), lst_std2, ++++lst_std2.begin());
    lst_ft.splice(++lst_ft.begin(), lst_ft2, ++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(++++begin, list(rbegin, rend), begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++++lst_std.begin(), lst_std2, lst_std2.begin());
    lst_ft.splice(++++lst_ft.begin(), lst_ft2, lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(++++begin, list(rbegin, rend), ++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++++lst_std.begin(), lst_std2, ++lst_std2.begin());
    lst_ft.splice(++++lst_ft.begin(), lst_ft2, ++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list(begin, end).splice(++++begin, list(rbegin, rend), ++++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++++lst_std.begin(), lst_std2, ++++lst_std2.begin());
    lst_ft.splice(++++lst_ft.begin(), lst_ft2, ++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(end, list(rbegin, rend), begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++++lst_std.begin(), lst_std2, lst_std2.begin());
    lst_ft.splice(++++lst_ft.begin(), lst_ft2, lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(end, list(rbegin, rend), ++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(++++lst_std.begin(), lst_std2, ++lst_std2.begin());
    lst_ft.splice(++++lst_ft.begin(), lst_ft2, ++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(end, list(rbegin, rend), ++++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.end(), lst_std2, ++++lst_std2.begin());
    lst_ft.splice(lst_ft.end(), lst_ft2, ++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // splice(pos, x, itr)
  putTestInfo(test_no,
              "list(begin, end).splice(begin, list(rbegin, rend), --end");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, --lst_std2.end());
    lst_ft.splice(lst_ft.begin(), lst_ft2, --lst_ft2.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, list(rbegin, rend), ++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, --lst_std2.end());
    lst_ft.splice(lst_ft.begin(), lst_ft2, --lst_ft2.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, list(rbegin, rend), ++begin");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, --lst_std2.end());
    lst_ft.splice(lst_ft.begin(), lst_ft2, --lst_ft2.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(x.begin, x, x.begin, x.end)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, lst_std2.begin(), lst_std2.end());
    lst_ft.splice(lst_ft.begin(), lst_ft2, lst_ft2.begin(), lst_ft2.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(begin, x, x.begin, ++x.begin)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, lst_std2.begin(),
                   ++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, lst_ft2.begin(), ++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, x, x.begin, ++++x.begin)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, lst_std2.begin(),
                   ++++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, lst_ft2.begin(),
                  ++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, x, x.begin, ++++++x.begin)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, lst_std2.begin(),
                   ++++++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, lst_ft2.begin(),
                  ++++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, x, x.begin, ++++++++x.begin)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, lst_std2.begin(),
                   ++++++++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, lst_ft2.begin(),
                  ++++++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, x, ++x.begin, ++++++++x.begin)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, ++lst_std2.begin(),
                   ++++++++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, ++lst_ft2.begin(),
                  ++++++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "list(begin, end).splice(begin, x, ++++x.begin, ++++++++x.begin)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, ++++lst_std2.begin(),
                   ++++++++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, ++++lst_ft2.begin(),
                  ++++++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "list(begin, end).splice(begin, x, ++++x.begin, ++++x.begin)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, ++++lst_std2.begin(),
                   ++++lst_std2.begin());
    lst_ft.splice(lst_ft.begin(), lst_ft2, ++++lst_ft2.begin(),
                  ++++lst_ft2.begin());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list(begin, end).splice(begin, x, ++++x.begin, x.end)");
  try {
    std::list<Hoge> lst_std(hoge_flst.begin(), hoge_flst.end());
    ft::list<Hoge> lst_ft(hoge_flst.begin(), hoge_flst.end());
    std::list<Hoge> lst_std2(hoge_lst.rbegin(), hoge_lst.rend());
    ft::list<Hoge> lst_ft2(hoge_lst.rbegin(), hoge_lst.rend());
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.splice(lst_std.begin(), lst_std2, ++++lst_std2.begin(),
                   lst_std2.end());
    lst_ft.splice(lst_ft.begin(), lst_ft2, ++++lst_ft2.begin(), lst_ft2.end());
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check 2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  for (int i = 0; i < 10; i++) {
    std::stringstream sout;
    sout << "list<int>(0..9).remove(" << i << ")";
    putTestInfo(test_no, sout.str());
    try {
      std::list<int> lst_std(num, num + 9);
      ft::list<int> lst_ft(num, num + 9);
      std::list<int>::iterator itr_std;
      ft::list<int>::iterator itr_ft;

      lst_std.remove(i);
      lst_ft.remove(i);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = 0; i < 10; i++) {
    std::stringstream sout;
    sout << "list<int>(10, " << i << ").remove(" << i << ")";
    putTestInfo(test_no, sout.str());
    try {
      std::list<int> lst_std(10, i);
      ft::list<int> lst_ft(10, i);
      std::list<int>::iterator itr_std;
      ft::list<int>::iterator itr_ft;

      lst_std.remove(i);
      lst_ft.remove(i);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = 0; i < 10; i++) {
    std::stringstream sout;
    sout << "list<int>(" << i << ", 42).remove(42)";
    putTestInfo(test_no, sout.str());
    try {
      std::list<int> lst_std(10, 42);
      ft::list<int> lst_ft(10, 42);
      std::list<int>::iterator itr_std;
      ft::list<int>::iterator itr_ft;

      lst_std.remove(42);
      lst_ft.remove(42);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = 0; i < 10; i++) {
    std::stringstream sout;
    sout << "list<int>(" << i << ", 21).remove(42)";
    putTestInfo(test_no, sout.str());
    try {
      std::list<int> lst_std(i, 42);
      ft::list<int> lst_ft(i, 42);
      std::list<int>::iterator itr_std;
      ft::list<int>::iterator itr_ft;

      lst_std.remove(42);
      lst_ft.remove(42);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = 0; i < 10; i++) {
    std::stringstream sout;
    sout << "list<Hoge>(begin, end).remove(hoge[" << i << "])";
    putTestInfo(test_no, sout.str());
    try {
      std::list<Hoge> lst_std(hoge_vec.begin(), hoge_vec.end());
      ft::list<Hoge> lst_ft(hoge_vec.begin(), hoge_vec.end());
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.remove(hoge[i]);
      lst_ft.remove(hoge[i]);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  // merge(list)
  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6))");
  try {
    Hoge hog[6] = {Hoge(0, 2),  Hoge(1, 6),  Hoge(2, 42),
                   Hoge(3, 84), Hoge(4, 92), Hoge(5, 95)};
    Hoge hog2[6] = {Hoge(-1, 3),  Hoge(-2, 4),  Hoge(-3, 24),
                    Hoge(-4, 32), Hoge(-5, 89), Hoge(-6, 99)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6)) case2");
  try {
    Hoge hog[6] = {Hoge(0, 2), Hoge(1, 3),  Hoge(2, 3),
                   Hoge(3, 3), Hoge(4, 92), Hoge(5, 95)};
    Hoge hog2[6] = {Hoge(-1, 1),  Hoge(-2, 3),  Hoge(-3, 3),
                    Hoge(-4, 32), Hoge(-5, 89), Hoge(-6, 99)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6)) case3");
  try {
    Hoge hog[6] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2),
                   Hoge(3, 3), Hoge(4, 4), Hoge(5, 5)};
    Hoge hog2[6] = {Hoge(-1, 0), Hoge(-2, 1), Hoge(-3, 2),
                    Hoge(-4, 3), Hoge(-5, 4), Hoge(-6, 5)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6)) case4");
  try {
    Hoge hog[6] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2),
                   Hoge(3, 3), Hoge(4, 4), Hoge(5, 5)};
    Hoge hog2[6] = {Hoge(-1, 6), Hoge(-2, 7),  Hoge(-3, 8),
                    Hoge(-4, 9), Hoge(-5, 10), Hoge(-6, 11)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6)) case5");
  try {
    Hoge hog[6] = {Hoge(0, 6), Hoge(1, 7),  Hoge(2, 8),
                   Hoge(3, 9), Hoge(4, 10), Hoge(5, 11)};
    Hoge hog2[6] = {Hoge(-1, 0), Hoge(-2, 1), Hoge(-3, 2),
                    Hoge(-4, 3), Hoge(-5, 4), Hoge(-6, 5)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  for (int i = -1; i < 7; i++) {
    std::stringstream sout;
    sout << "list<Hoge>: list(1).marge(list(6)) case: " << i;
    putTestInfo(test_no, sout.str());
    try {
      Hoge hog[1] = {Hoge(0, i)};
      Hoge hog2[6] = {Hoge(-1, 0), Hoge(-2, 1), Hoge(-3, 2),
                      Hoge(-4, 3), Hoge(-5, 4), Hoge(-6, 5)};
      std::list<Hoge> lst_std(hog, hog + 1);
      ft::list<Hoge> lst_ft(hog, hog + 1);
      std::list<Hoge> lst_std2(hog2, hog2 + 6);
      ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.merge(lst_std2);
      lst_ft.merge(lst_ft2);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
      // check lst2
      for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
           itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft2.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std2.empty() != lst_ft2.empty() ||
          lst_std2.size() != lst_ft2.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = -1; i < 7; i++) {
    std::stringstream sout;
    sout << "list<Hoge>: list(6).marge(list(1)) case: " << i;
    putTestInfo(test_no, sout.str());
    try {
      Hoge hog[6] = {Hoge(1, 0), Hoge(2, 1), Hoge(3, 2),
                     Hoge(4, 3), Hoge(5, 4), Hoge(6, 5)};
      Hoge hog2[1] = {Hoge(0, i)};
      std::list<Hoge> lst_std(hog, hog + 6);
      ft::list<Hoge> lst_ft(hog, hog + 6);
      std::list<Hoge> lst_std2(hog2, hog2 + 1);
      ft::list<Hoge> lst_ft2(hog2, hog2 + 1);
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.merge(lst_std2);
      lst_ft.merge(lst_ft2);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
      // check lst2
      for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
           itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft2.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std2.empty() != lst_ft2.empty() ||
          lst_std2.size() != lst_ft2.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = -1; i < 3; i++) {
    std::stringstream sout;
    sout << "list<Hoge>: list(1)).marge(list(2)) case" << i;
    putTestInfo(test_no, sout.str());
    try {
      Hoge hog[1] = {Hoge(1, i)};
      Hoge hog2[2] = {Hoge(-1, 0), Hoge(-2, 1)};
      std::list<Hoge> lst_std(hog, hog + 1);
      ft::list<Hoge> lst_ft(hog, hog + 1);
      std::list<Hoge> lst_std2(hog2, hog2 + 2);
      ft::list<Hoge> lst_ft2(hog2, hog2 + 2);
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.merge(lst_std2);
      lst_ft.merge(lst_ft2);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
      // check lst2
      for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
           itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft2.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std2.empty() != lst_ft2.empty() ||
          lst_std2.size() != lst_ft2.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = -1; i < 3; i++) {
    std::stringstream sout;
    sout << "list<Hoge>: list(2)).marge(list(1)) case" << i;
    putTestInfo(test_no, sout.str());
    try {
      Hoge hog[2] = {Hoge(-1, 0), Hoge(-2, 1)};
      Hoge hog2[1] = {Hoge(1, i)};
      std::list<Hoge> lst_std(hog, hog + 2);
      ft::list<Hoge> lst_ft(hog, hog + 2);
      std::list<Hoge> lst_std2(hog2, hog2 + 1);
      ft::list<Hoge> lst_ft2(hog2, hog2 + 1);
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.merge(lst_std2);
      lst_ft.merge(lst_ft2);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
      // check lst2
      for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
           itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft2.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std2.empty() != lst_ft2.empty() ||
          lst_std2.size() != lst_ft2.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  putTestInfo(test_no, "list<Hoge>: list(0)).marge(list(6))");
  try {
    Hoge hog2[6] = {Hoge(-1, 6), Hoge(-2, 7),  Hoge(-3, 8),
                    Hoge(-4, 9), Hoge(-5, 10), Hoge(-6, 11)};
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(0))");
  try {
    Hoge hog[6] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2),
                   Hoge(3, 3), Hoge(4, 4), Hoge(5, 5)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(0)).marge(list(1))");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2(1);
    ft::list<Hoge> lst_ft2(1);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1).marge(list(0))");
  try {
    std::list<Hoge> lst_std(1);
    ft::list<Hoge> lst_ft(1);
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(0).marge(list(0))");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2);
    lst_ft.merge(lst_ft2);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 1");
  try {
    Hoge hog[6] = {Hoge(0, 4), Hoge(1, 1), Hoge(2, 0),
                   Hoge(3, 5), Hoge(4, 2), Hoge(5, 3)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 2");
  try {
    Hoge hog[6] = {Hoge(0, 4), Hoge(1, 0), Hoge(2, 5),
                   Hoge(3, 1), Hoge(4, 0), Hoge(5, 0)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 3");
  try {
    Hoge hog[6] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2),
                   Hoge(3, 3), Hoge(4, 4), Hoge(5, 5)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 4");
  try {
    Hoge hog[6] = {Hoge(0, 5), Hoge(1, 4), Hoge(2, 3),
                   Hoge(3, 2), Hoge(4, 1), Hoge(5, 0)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 5");
  try {
    Hoge hog[6] = {Hoge(0, 1), Hoge(1, 1), Hoge(2, 1),
                   Hoge(3, 1), Hoge(4, 1), Hoge(5, 1)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(0).sort");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1).sort");
  try {
    int n = 1;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(i, rand() % n);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(10).sort");
  try {
    int n = 10;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(i, rand() % n);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1000).sort");
  try {
    int n = 1000;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(i, rand() % n);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort();
    lst_ft.sort();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // merge(list)
  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6))");
  try {
    Hoge hog[6] = {Hoge(0, 2),  Hoge(1, 6),  Hoge(2, 42),
                   Hoge(3, 84), Hoge(4, 92), Hoge(5, 95)};
    Hoge hog2[6] = {Hoge(-1, 3),  Hoge(-2, 4),  Hoge(-3, 24),
                    Hoge(-4, 32), Hoge(-5, 89), Hoge(-6, 99)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6)) case2");
  try {
    Hoge hog[6] = {Hoge(0, 2), Hoge(1, 3),  Hoge(2, 3),
                   Hoge(3, 3), Hoge(4, 92), Hoge(5, 95)};
    Hoge hog2[6] = {Hoge(-1, 1),  Hoge(-2, 3),  Hoge(-3, 3),
                    Hoge(-4, 32), Hoge(-5, 89), Hoge(-6, 99)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6)) case3");
  try {
    Hoge hog[6] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2),
                   Hoge(3, 3), Hoge(4, 4), Hoge(5, 5)};
    Hoge hog2[6] = {Hoge(-1, 0), Hoge(-2, 1), Hoge(-3, 2),
                    Hoge(-4, 3), Hoge(-5, 4), Hoge(-6, 5)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6)) case4");
  try {
    Hoge hog[6] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2),
                   Hoge(3, 3), Hoge(4, 4), Hoge(5, 5)};
    Hoge hog2[6] = {Hoge(-1, 6), Hoge(-2, 7),  Hoge(-3, 8),
                    Hoge(-4, 9), Hoge(-5, 10), Hoge(-6, 11)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(6)) case5");
  try {
    Hoge hog[6] = {Hoge(0, 6), Hoge(1, 7),  Hoge(2, 8),
                   Hoge(3, 9), Hoge(4, 10), Hoge(5, 11)};
    Hoge hog2[6] = {Hoge(-1, 0), Hoge(-2, 1), Hoge(-3, 2),
                    Hoge(-4, 3), Hoge(-5, 4), Hoge(-6, 5)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  for (int i = -1; i < 7; i++) {
    std::stringstream sout;
    sout << "list<Hoge>: list(1).marge(list(6)) case: " << i;
    putTestInfo(test_no, sout.str());
    try {
      Hoge hog[1] = {Hoge(0, i)};
      Hoge hog2[6] = {Hoge(-1, 0), Hoge(-2, 1), Hoge(-3, 2),
                      Hoge(-4, 3), Hoge(-5, 4), Hoge(-6, 5)};
      std::list<Hoge> lst_std(hog, hog + 1);
      ft::list<Hoge> lst_ft(hog, hog + 1);
      std::list<Hoge> lst_std2(hog2, hog2 + 6);
      ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.merge(lst_std2, operator<);
      lst_ft.merge(lst_ft2, operator<);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
      // check lst2
      for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
           itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft2.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std2.empty() != lst_ft2.empty() ||
          lst_std2.size() != lst_ft2.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = -1; i < 7; i++) {
    std::stringstream sout;
    sout << "list<Hoge>: list(6).marge(list(1)) case: " << i;
    putTestInfo(test_no, sout.str());
    try {
      Hoge hog[6] = {Hoge(1, 0), Hoge(2, 1), Hoge(3, 2),
                     Hoge(4, 3), Hoge(5, 4), Hoge(6, 5)};
      Hoge hog2[1] = {Hoge(0, i)};
      std::list<Hoge> lst_std(hog, hog + 6);
      ft::list<Hoge> lst_ft(hog, hog + 6);
      std::list<Hoge> lst_std2(hog2, hog2 + 1);
      ft::list<Hoge> lst_ft2(hog2, hog2 + 1);
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.merge(lst_std2, operator<);
      lst_ft.merge(lst_ft2, operator<);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
      // check lst2
      for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
           itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft2.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std2.empty() != lst_ft2.empty() ||
          lst_std2.size() != lst_ft2.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = -1; i < 3; i++) {
    std::stringstream sout;
    sout << "list<Hoge>: list(1)).marge(list(2)) case" << i;
    putTestInfo(test_no, sout.str());
    try {
      Hoge hog[1] = {Hoge(1, i)};
      Hoge hog2[2] = {Hoge(-1, 0), Hoge(-2, 1)};
      std::list<Hoge> lst_std(hog, hog + 1);
      ft::list<Hoge> lst_ft(hog, hog + 1);
      std::list<Hoge> lst_std2(hog2, hog2 + 2);
      ft::list<Hoge> lst_ft2(hog2, hog2 + 2);
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.merge(lst_std2, operator<);
      lst_ft.merge(lst_ft2, operator<);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
      // check lst2
      for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
           itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft2.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std2.empty() != lst_ft2.empty() ||
          lst_std2.size() != lst_ft2.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = -1; i < 3; i++) {
    std::stringstream sout;
    sout << "list<Hoge>: list(2)).marge(list(1)) case" << i;
    putTestInfo(test_no, sout.str());
    try {
      Hoge hog[2] = {Hoge(-1, 0), Hoge(-2, 1)};
      Hoge hog2[1] = {Hoge(1, i)};
      std::list<Hoge> lst_std(hog, hog + 2);
      ft::list<Hoge> lst_ft(hog, hog + 2);
      std::list<Hoge> lst_std2(hog2, hog2 + 1);
      ft::list<Hoge> lst_ft2(hog2, hog2 + 1);
      std::list<Hoge>::iterator itr_std;
      ft::list<Hoge>::iterator itr_ft;

      lst_std.merge(lst_std2, operator<);
      lst_ft.merge(lst_ft2, operator<);
      for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
           itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std.empty() != lst_ft.empty() ||
          lst_std.size() != lst_ft.size()) {
        throw std::runtime_error("size");
      }
      // check lst2
      for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
           itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
        if (*itr_std != *itr_ft) {
          throw std::runtime_error("value");
        }
      }
      if (itr_ft != lst_ft2.end()) {
        throw std::runtime_error("iter");
      }
      if (lst_std2.empty() != lst_ft2.empty() ||
          lst_std2.size() != lst_ft2.size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  putTestInfo(test_no, "list<Hoge>: list(0)).marge(list(6))");
  try {
    Hoge hog2[6] = {Hoge(-1, 6), Hoge(-2, 7),  Hoge(-3, 8),
                    Hoge(-4, 9), Hoge(-5, 10), Hoge(-6, 11)};
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2(hog2, hog2 + 6);
    ft::list<Hoge> lst_ft2(hog2, hog2 + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).marge(list(0))");
  try {
    Hoge hog[6] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2),
                   Hoge(3, 3), Hoge(4, 4), Hoge(5, 5)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(0)).marge(list(1))");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2(1);
    ft::list<Hoge> lst_ft2(1);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1).marge(list(0))");
  try {
    std::list<Hoge> lst_std(1);
    ft::list<Hoge> lst_ft(1);
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(0).marge(list(0))");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge> lst_std2;
    ft::list<Hoge> lst_ft2;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.merge(lst_std2, operator<);
    lst_ft.merge(lst_ft2, operator<);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
    // check lst2
    for (itr_std = lst_std2.begin(), itr_ft = lst_ft2.begin();
         itr_std != lst_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft2.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std2.empty() != lst_ft2.empty() ||
        lst_std2.size() != lst_ft2.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 1");
  try {
    Hoge hog[6] = {Hoge(0, 4), Hoge(1, 1), Hoge(2, 0),
                   Hoge(3, 5), Hoge(4, 2), Hoge(5, 3)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 2");
  try {
    Hoge hog[6] = {Hoge(0, 4), Hoge(1, 0), Hoge(2, 5),
                   Hoge(3, 1), Hoge(4, 0), Hoge(5, 0)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 3");
  try {
    Hoge hog[6] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2),
                   Hoge(3, 3), Hoge(4, 4), Hoge(5, 5)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 4");
  try {
    Hoge hog[6] = {Hoge(0, 5), Hoge(1, 4), Hoge(2, 3),
                   Hoge(3, 2), Hoge(4, 1), Hoge(5, 0)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(6).sort case 5");
  try {
    Hoge hog[6] = {Hoge(0, 1), Hoge(1, 1), Hoge(2, 1),
                   Hoge(3, 1), Hoge(4, 1), Hoge(5, 1)};
    std::list<Hoge> lst_std(hog, hog + 6);
    ft::list<Hoge> lst_ft(hog, hog + 6);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(0).sort");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1).sort");
  try {
    int n = 1;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(i, rand() % n);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(10).sort");
  try {
    int n = 10;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(i, rand() % n);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1000).sort");
  try {
    int n = 1000;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(i, rand() % n);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort(operator>);
    lst_ft.sort(operator>);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list(1000).sort.unique");
  try {
    int n = 1000;
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      int num = rand() % 10;
      lst_std.push_back(num);
      lst_ft.push_back(num);
    }
    lst_std.sort();
    lst_ft.sort();
    lst_std.unique();
    lst_ft.unique();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1000).sort.unique");
  try {
    int n = 1000;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(rand() % 1000, rand() % 10);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort();
    lst_ft.sort();
    lst_std.unique(compareNum);
    lst_ft.unique(compareNum);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list(1).sort.unique");
  try {
    int n = 1;
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::const_iterator itr_std;
    ft::list<int>::const_iterator itr_ft;

    for (int i = 0; i < n; i++) {
      int num = rand() % 10;
      lst_std.push_back(num);
      lst_ft.push_back(num);
    }
    lst_std.sort();
    lst_ft.sort();
    lst_std.unique();
    lst_ft.unique();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  /*
  putTestInfo(test_no, "list<int>: list(1).sort.unique");
  try {
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::const_iterator itr_std;
    ft::list<int>::const_iterator itr_ft;

    lst_std.push_back(5);
    lst_std.push_back(42);
    lst_std.push_back(44);
    lst_std.push_back(43);
    lst_std.push_back(44);
    lst_std.push_back(5);
    lst_std.push_back(45);
    lst_ft.push_back(5);
    lst_ft.push_back(42);
    lst_ft.push_back(44);
    lst_ft.push_back(43);
    lst_ft.push_back(44);
    lst_ft.push_back(5);
    lst_ft.push_back(45);
    lst_std.unique(&lesser_than_rhs<int>);
    lst_ft.unique(&lesser_than_rhs<int>);
    for (itr_ft = lst_ft.begin(); itr_ft != lst_ft.end(); ++itr_ft) {
      std::cout << *itr_ft << std::endl;
    }
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;
  */

  putTestInfo(test_no, "list<Hoge>: list(1).sort.unique");
  try {
    int n = 1;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(rand() % 1000, rand() % 10);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort();
    lst_ft.sort();
    lst_std.unique(compareNum);
    lst_ft.unique(compareNum);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list(0).sort.unique");
  try {
    int n = 0;
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      int num = rand() % 10;
      lst_std.push_back(num);
      lst_ft.push_back(num);
    }
    lst_std.sort();
    lst_ft.sort();
    lst_std.unique();
    lst_ft.unique();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(0).sort.unique");
  try {
    int n = 1;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(rand() % 1000, rand() % 10);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort();
    lst_ft.sort();
    lst_std.unique(compareNum);
    lst_ft.unique(compareNum);
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: list(1000).sort.unique all same");
  try {
    int n = 1000;
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int>::iterator itr_std;
    ft::list<int>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      int num = 42;
      lst_std.push_back(num);
      lst_ft.push_back(num);
    }
    lst_std.sort();
    lst_ft.sort();
    lst_std.unique();
    lst_ft.unique();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1000).sort.unique all same");
  try {
    int n = 1000;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(rand() % 1000, 42);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.sort();
    lst_ft.sort();
    lst_std.unique(compareNum);
    lst_ft.unique(compareNum);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    std::list<Hoge>::const_iterator citr_std;
    ft::list<Hoge>::const_iterator citr_ft;
    for (citr_std = lst_std.begin(), citr_ft = lst_ft.begin();
         citr_std != lst_std.end(); ++citr_std, ++citr_ft) {
      if (*citr_std != *citr_ft) {
        throw std::runtime_error("value");
      }
    }
    std::list<Hoge>::reverse_iterator ritr_std;
    ft::list<Hoge>::reverse_iterator ritr_ft;
    for (ritr_std = lst_std.rbegin(), ritr_ft = lst_ft.rbegin();
         ritr_std != lst_std.rend(); ++ritr_std, ++ritr_ft) {
      if (*ritr_std != *ritr_ft) {
        throw std::runtime_error("value");
      }
    }
    std::list<Hoge>::const_reverse_iterator rcitr_std;
    ft::list<Hoge>::const_reverse_iterator rcitr_ft;
    for (rcitr_std = lst_std.rbegin(), rcitr_ft = lst_ft.rbegin();
         rcitr_std != lst_std.rend(); ++rcitr_std, ++rcitr_ft) {
      if (*rcitr_std != *rcitr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1000).reverse");
  try {
    int n = 1000;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(i, rand() % n);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.reverse();
    lst_ft.reverse();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(999).reverse");
  try {
    int n = 999;
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    for (int i = 0; i < n; i++) {
      Hoge h(i, rand() % n);
      lst_std.push_back(h);
      lst_ft.push_back(h);
    }
    lst_std.reverse();
    lst_ft.reverse();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(1).reverse");
  try {
    std::list<Hoge> lst_std(1);
    ft::list<Hoge> lst_ft(1);
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.reverse();
    lst_ft.reverse();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<Hoge>: list(0).reverse");
  try {
    std::list<Hoge> lst_std;
    ft::list<Hoge> lst_ft;
    std::list<Hoge>::iterator itr_std;
    ft::list<Hoge>::iterator itr_ft;

    lst_std.reverse();
    lst_ft.reverse();
    for (itr_std = lst_std.begin(), itr_ft = lst_ft.begin();
         itr_std != lst_std.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("value");
      }
    }
    if (itr_ft != lst_ft.end()) {
      throw std::runtime_error("iter");
    }
    if (lst_std.empty() != lst_ft.empty() || lst_std.size() != lst_ft.size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(6) case 1");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 1, 2, 3, 4, 5};
    std::list<int> lst_std(num1, num1 + 6);
    ft::list<int> lst_ft(num1, num1 + 6);
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(6) case 2");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {1, 1, 2, 3, 4, 5};
    std::list<int> lst_std(num1, num1 + 6);
    ft::list<int> lst_ft(num1, num1 + 6);
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(6) case 3");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 42, 2, 3, 4, 5};
    std::list<int> lst_std(num1, num1 + 6);
    ft::list<int> lst_ft(num1, num1 + 6);
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(6) case 4");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 1, 2, 3, 42, 5};
    std::list<int> lst_std(num1, num1 + 6);
    ft::list<int> lst_ft(num1, num1 + 6);
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(6) case 5");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 1, 2, 3, 4, 42};
    std::list<int> lst_std(num1, num1 + 6);
    ft::list<int> lst_ft(num1, num1 + 6);
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(6) case 6");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {-5, -6, -7, -8, -9, -0};
    std::list<int> lst_std(num1, num1 + 6);
    ft::list<int> lst_ft(num1, num1 + 6);
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(0) and list(6)");
  try {
    // int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 1, 2, 3, 4, 5};
    std::list<int> lst_std;
    ft::list<int> lst_ft;
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(1) and list(6)");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 1, 2, 3, 4, 5};
    std::list<int> lst_std(num1, num1 + 1);
    ft::list<int> lst_ft(num1, num1 + 1);
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(5) and list(6)");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 1, 2, 3, 4, 5};
    std::list<int> lst_std(num1, num1 + 5);
    ft::list<int> lst_ft(num1, num1 + 5);
    std::list<int> lst_std2(num2, num2 + 6);
    ft::list<int> lst_ft2(num2, num2 + 6);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(5)");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 1, 2, 3, 4, 5};
    std::list<int> lst_std(num1, num1 + 6);
    ft::list<int> lst_ft(num1, num1 + 6);
    std::list<int> lst_std2(num2, num2 + 5);
    ft::list<int> lst_ft2(num2, num2 + 5);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(1)");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    int num2[6] = {0, 1, 2, 3, 4, 5};
    std::list<int> lst_std(num1, num1 + 1);
    ft::list<int> lst_ft(num1, num1 + 1);
    std::list<int> lst_std2(num2, num2 + 1);
    ft::list<int> lst_ft2(num2, num2 + 1);

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: compare list(6) and list(0)");
  try {
    int num1[6] = {0, 1, 2, 3, 4, 5};
    std::list<int> lst_std(num1, num1 + 1);
    ft::list<int> lst_ft(num1, num1 + 1);
    std::list<int> lst_std2;
    ft::list<int> lst_ft2;

    // operator==
    if ((lst_std == lst_std2) != (lst_ft == lst_ft2)) {
      throw std::runtime_error("operator==");
    }
    // operator!=
    if ((lst_std != lst_std2) != (lst_ft != lst_ft2)) {
      throw std::runtime_error("operator!=");
    }
    // operator<
    if ((lst_std < lst_std2) != (lst_ft < lst_ft2)) {
      throw std::runtime_error("operator<");
    }
    // operator<=
    if ((lst_std <= lst_std2) != (lst_ft <= lst_ft2)) {
      throw std::runtime_error("operator<=");
    }
    // operator>
    if ((lst_std > lst_std2) != (lst_ft > lst_ft2)) {
      throw std::runtime_error("operator>");
    }
    // operator>=
    if ((lst_std >= lst_std2) != (lst_ft >= lst_ft2)) {
      throw std::runtime_error("operator>=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: test all itrs");
  try {
    int n;
    std::list<int> std_lst;
    ft::list<int> ft_lst;
    std::list<int>::iterator std_itr;
    ft::list<int>::iterator ft_itr;
    std::list<int>::reverse_iterator std_ritr;
    ft::list<int>::reverse_iterator ft_ritr;
    std::list<int>::const_iterator std_citr;
    ft::list<int>::const_iterator ft_citr;
    std::list<int>::const_reverse_iterator std_critr;
    ft::list<int>::const_reverse_iterator ft_critr;

    for (int i = 0; i < 1000; i++) {
      n = rand() % 1000;
      std_lst.push_back(n);
      ft_lst.push_back(n);
    }

    for (std_itr = std_lst.begin(), ft_itr = ft_lst.begin();
         std_itr != std_lst.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_itr != ft_lst.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_ritr = std_lst.rbegin(), ft_ritr = ft_lst.rbegin();
         std_ritr != std_lst.rend(); ++std_ritr, ++ft_ritr) {
      if (*std_ritr != *ft_ritr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_ritr != ft_lst.rend()) {
      throw std::runtime_error("rev iterator");
    }

    for (std_citr = std_lst.begin(), ft_citr = ft_lst.begin();
         std_citr != std_lst.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_citr != ft_lst.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_critr = std_lst.rbegin(), ft_critr = ft_lst.rbegin();
         std_critr != std_lst.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_critr != ft_lst.rend()) {
      throw std::runtime_error("rev iterator");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "list<int>: test const");
  try {
    const std::list<int> std_lst(num, num + 10);
    const ft::list<int> ft_lst(num, num + 10);
    std::list<int>::const_iterator std_citr;
    ft::list<int>::const_iterator ft_citr;
    std::list<int>::const_reverse_iterator std_critr;
    ft::list<int>::const_reverse_iterator ft_critr;

    for (std_citr = std_lst.begin(), ft_citr = ft_lst.begin();
         std_citr != std_lst.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_citr != ft_lst.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_critr = std_lst.rbegin(), ft_critr = ft_lst.rbegin();
         std_critr != std_lst.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_critr != ft_lst.rend()) {
      throw std::runtime_error("rev iterator");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
