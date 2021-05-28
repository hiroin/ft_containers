/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_bool.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 08:32:48 by dnakano           #+#    #+#             */
/*   Updated: 2021/03/04 09:30:12 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ALLOW_USE_CPP03

#include <exception>
#include <forward_list>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#ifdef ALLOW_USE_CPP03
#include <algorithm>
#endif /* ALLOW_USE_CPP03 */

#include "test.hpp"
#include "vector.hpp"

static void test_value_assign(int& test_no, size_t size1, bool val1,
                              size_t size2, bool val2) {
  std::stringstream sout;
  sout << std::boolalpha << "Vector<bool>: vector(" << size1 << ", " << val1
       << ") and assign(" << size2 << ", " << val2 << ")";
  putTestInfo(test_no, sout.str());
  try {
    std::vector<bool> std_vec(size1, val1);
    ft::vector<bool> ft_vec(size1, val1);

    std_vec.assign(size2, val2);
    ft_vec.assign(size2, val2);
    for (size_t idx = 0; idx < size2; ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.capacity() << std::endl;
      std::cout << " ft: " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("value");
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;
}

void test_vector_bool(int& test_no) {
  std::cout << "=== TEST VECTOR<BOOL> ===" << std::endl;
  std::cout << std::boolalpha;
  size_t size = 0;
  size_t size_ary[] = {0,   1,   2,    63,   64,   65,   100, 127,
                       128, 129, 1023, 1024, 1025, 2000, 4000};
  bool flg = 0;

  putTestInfo(test_no, "Vector<bool>: size/capacity of default construction");
  try {
    std::vector<bool> std_vec;
    ft::vector<bool> ft_vec;

    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      std::cout << std::endl;
      std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
      std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  for (size = 0; size <= 150; size++) {
    std::stringstream sout;
    sout << "Vector<bool>: vector(" << size << ")";
    putTestInfo(test_no, sout.str());
    try {
      std::vector<bool> std_vec(size);
      ft::vector<bool> ft_vec(size);

      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size = 0; size <= 150; size++) {
    std::stringstream sout;
    sout << "Vector<bool>: vector(" << size << ", false)";
    putTestInfo(test_no, sout.str());
    try {
      std::vector<bool> std_vec(size, false);
      ft::vector<bool> ft_vec(size, false);

      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size = 0; size <= 150; size++) {
    std::stringstream sout;
    sout << "Vector<bool>: vector(" << size << ", true)";
    putTestInfo(test_no, sout.str());
    try {
      std::vector<bool> std_vec(size, false);
      ft::vector<bool> ft_vec(size, false);

      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  size = 420;
  putTestInfo(test_no, "Vector<bool>: assign random to vec(420)");
  try {
    bool val;
    std::vector<bool> std_vec(size);
    ft::vector<bool> ft_vec(size);

    for (size_t idx = 0; idx < size; ++idx) {
      val = rand() % 2;
      std_vec[idx] = val;
      ft_vec[idx] = val;
    }
    for (size_t idx = 0; idx < size; ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      std::cout << std::endl;
      std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
      std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  size = 420;
  putTestInfo(test_no, "Vector<bool>: assign random to vec(420) then flip");
  try {
    bool val;
    std::vector<bool> std_vec(size);
    ft::vector<bool> ft_vec(size);

    for (size_t idx = 0; idx < size; ++idx) {
      val = rand() % 2;
      std_vec[idx] = val;
      ft_vec[idx] = val;
    }
    std_vec.flip();
    ft_vec.flip();
    for (size_t idx = 0; idx < size; ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      std::cout << std::endl;
      std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
      std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j < 15; j++) {
      test_value_assign(test_no, size_ary[i], true, size_ary[j], false);
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j < 15; j++) {
      test_value_assign(test_no, size_ary[i], false, size_ary[j], true);
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j < 15; j++) {
      test_value_assign(test_no, size_ary[i], true, size_ary[j], true);
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j < 15; j++) {
      test_value_assign(test_no, size_ary[i], false, size_ary[j], false);
    }
  }

  for (size_t i = 0; i < 15; ++i) {
    size = size_ary[i];
    std::stringstream sout;
    sout << "Vector<bool>: range construct " << size << " by pointer";
    putTestInfo(test_no, sout.str());
    try {
      bool val[size];
      for (size_t idx = 0; idx < size; ++idx) {
        val[idx] = rand() % 2;
      }

      std::vector<bool> std_vec(val, val + size);
      ft::vector<bool> ft_vec(val, val + size);
      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        std::cout << std::endl;
        std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
        std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size_t i = 0; i < 15; ++i) {
    for (size_t j = 0; j < 15; ++j) {
      std::stringstream sout;
      sout << "Vector<bool>: assgin(" << size_ary[i] << ") by pointer to vec("
           << size_ary[j] << ")";
      putTestInfo(test_no, sout.str());
      try {
        bool val[size_ary[i]];
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          val[idx] = rand() % 2;
        }

        std::vector<bool> std_vec(size_ary[j]);
        ft::vector<bool> ft_vec(size_ary[j]);
        std_vec.assign(val, val + size_ary[i]);
        ft_vec.assign(val, val + size_ary[i]);
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; i++) {
    size = size_ary[i];
    std::stringstream sout;
    sout << "Vector<bool>: check iterator with " << size;
    putTestInfo(test_no, sout.str());
    try {
      bool val[size];
      for (size_t idx = 0; idx < size; ++idx) {
        val[idx] = rand() % 2;
      }

      std::vector<bool> std_vec(val, val + size);
      ft::vector<bool> ft_vec(val, val + size);
      std::vector<bool>::iterator std_itr;
      ft::vector<bool>::iterator ft_itr;
      for (std_itr = std_vec.begin(), ft_itr = ft_vec.begin();
           ft_itr != ft_vec.end(); ++std_itr, ++ft_itr) {
        if (*std_itr != *ft_itr) {
          std::cout << std::endl;
          std::cout << "std: " << *std_itr << std::endl;
          std::cout << " ft: " << *ft_itr << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (ft_itr != ft_vec.end()) {
        throw std::runtime_error("iterator");
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        std::cout << std::endl;
        std::cout << "std: " << std_vec.capacity() << std::endl;
        std::cout << " ft: " << ft_vec.capacity() << std::endl;
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        std::cout << std::endl;
        std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
        std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  size = 420;
  std::stringstream sout;
  sout << "Vector<bool>: vec(" << size << ").at(0~" << size * 2 << ")";
  putTestInfo(test_no, sout.str());
  try {
    bool val[size];
    for (size_t idx = 0; idx < size; ++idx) {
      val[idx] = rand() % 2;
    }

    std::vector<bool> std_vec(val, val + size);
    ft::vector<bool> ft_vec(val, val + size);
    for (size_t idx = 0; idx < size; ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        std::cout << std::endl;
        std::cout << "std: " << std_vec.at(idx) << std::endl;
        std::cout << " ft: " << ft_vec.at(idx) << std::endl;
        throw std::runtime_error("value");
      }
    }
    for (size_t idx = size; idx < size * 2; ++idx) {
      flg = false;
      try {
        ft_vec.at(420) = 1;
      } catch (std::out_of_range& e) {
        if (strcmp(e.what(), "vector")) {
          throw std::runtime_error(e.what());
        }
        flg = true;
      }
      if (!flg) {
        throw std::runtime_error("error");
      }
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  for (size_t i = 1; i < 15; i++) {
    size = size_ary[i];
    std::stringstream sout;
    sout << "Vector<bool>: check iterator with " << size;
    putTestInfo(test_no, sout.str());
    try {
      bool val[size];
      for (size_t idx = 0; idx < size; ++idx) {
        val[idx] = rand() % 2;
      }

      std::vector<bool> std_vec(val, val + size);
      ft::vector<bool> ft_vec(val, val + size);
      if (std_vec.front() != ft_vec.front()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.back() != ft_vec.back()) {
        throw std::runtime_error("size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size_t i = 0; i < 15; ++i) {
    for (size_t j = 0; j < 15; ++j) {
      std::stringstream sout;
      sout << "Vector<bool>: reserve(" << size_ary[i] << ") by pointer to vec("
           << size_ary[j] << ")";
      putTestInfo(test_no, sout.str());
      try {
        bool val[size_ary[j]];
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          val[idx] = rand() % 2;
        }

        std::vector<bool> std_vec(val, val + size_ary[j]);
        ft::vector<bool> ft_vec(val, val + size_ary[j]);
        std_vec.reserve(size_ary[i]);
        ft_vec.reserve(size_ary[i]);
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; ++i) {
    for (size_t j = 0; j < 15; ++j) {
      std::stringstream sout;
      sout << "Vector<bool>: resize(" << size_ary[i] << ", true) to vec("
           << size_ary[j] << ")";
      putTestInfo(test_no, sout.str());
      try {
        bool val[size_ary[j]];
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          val[idx] = rand() % 2;
          // val[idx] = true;
        }

        std::vector<bool> std_vec(val, val + size_ary[j]);
        ft::vector<bool> ft_vec(val, val + size_ary[j]);
        std_vec.resize(size_ary[i], true);
        ft_vec.resize(size_ary[i], true);
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; ++i) {
    for (size_t j = 0; j < 15; ++j) {
      std::stringstream sout;
      sout << "Vector<bool>: resize(" << size_ary[i] << ", false) to vec("
           << size_ary[j] << ")";
      putTestInfo(test_no, sout.str());
      try {
        bool val[size_ary[j]];
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          val[idx] = rand() % 2;
        }

        std::vector<bool> std_vec(val, val + size_ary[j]);
        ft::vector<bool> ft_vec(val, val + size_ary[j]);
        std_vec.resize(size_ary[i], false);
        ft_vec.resize(size_ary[i], false);
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; i++) {
    size = size_ary[i];
    std::stringstream sout;
    sout << "Vector<bool>: push_back(true) to vec(" << size << ")";
    putTestInfo(test_no, sout.str());
    try {
      bool val[size];
      for (size_t idx = 0; idx < size; ++idx) {
        val[idx] = rand() % 2;
      }
      std::vector<bool> std_vec(val, val + size);
      ft::vector<bool> ft_vec(val, val + size);
      std_vec.push_back(true);
      ft_vec.push_back(true);
      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        std::cout << std::endl;
        std::cout << "std: " << std_vec.capacity() << std::endl;
        std::cout << " ft: " << ft_vec.capacity() << std::endl;
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        std::cout << std::endl;
        std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
        std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size_t i = 0; i < 15; i++) {
    size = size_ary[i];
    std::stringstream sout;
    sout << "Vector<bool>: push_back(false) to vec(" << size << ")";
    putTestInfo(test_no, sout.str());
    try {
      bool val[size];
      for (size_t idx = 0; idx < size; ++idx) {
        val[idx] = rand() % 2;
      }
      std::vector<bool> std_vec(val, val + size);
      ft::vector<bool> ft_vec(val, val + size);
      std_vec.push_back(false);
      ft_vec.push_back(false);
      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        std::cout << std::endl;
        std::cout << "std: " << std_vec.capacity() << std::endl;
        std::cout << " ft: " << ft_vec.capacity() << std::endl;
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        std::cout << std::endl;
        std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
        std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size_t i = 1; i < 15; i++) {
    size = size_ary[i];
    std::stringstream sout;
    sout << "Vector<bool>: pop_back() to vec(" << size << ")";
    putTestInfo(test_no, sout.str());
    try {
      bool val[size];
      for (size_t idx = 0; idx < size; ++idx) {
        val[idx] = rand() % 2;
      }
      std::vector<bool> std_vec(val, val + size);
      ft::vector<bool> ft_vec(val, val + size);
      std_vec.pop_back();
      ft_vec.pop_back();
      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        std::cout << std::endl;
        std::cout << "std: " << std_vec.capacity() << std::endl;
        std::cout << " ft: " << ft_vec.capacity() << std::endl;
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        std::cout << std::endl;
        std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
        std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j <= i; j++) {
      size = size_ary[i];
      std::stringstream sout;
      sout << "Vector<bool>: insert(begin + " << size_ary[j]
           << ", true) to vec(" << size << ")";

      putTestInfo(test_no, sout.str());
      try {
        bool val[size];
        for (size_t idx = 0; idx < size; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec(val, val + size);
        ft::vector<bool> ft_vec(val, val + size);
        std::vector<bool>::iterator std_itr = std_vec.begin();
        ft::vector<bool>::iterator ft_itr = ft_vec.begin();
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          ++std_itr;
          ++ft_itr;
        }
        if (*std_vec.insert(std_itr, true) != *ft_vec.insert(ft_itr, true)) {
          throw std::runtime_error("return value");
        }
        for (size_t idx = 0; idx < std_vec.size(); ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.size() << std::endl;
          std::cout << " ft: " << ft_vec.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j <= i; j++) {
      size = size_ary[i];
      std::stringstream sout;
      sout << "Vector<bool>: insert(begin + " << size_ary[j]
           << ", true) to vec(" << size << ")";

      putTestInfo(test_no, sout.str());
      try {
        bool val[size];
        for (size_t idx = 0; idx < size; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec(val, val + size);
        ft::vector<bool> ft_vec(val, val + size);
        std::vector<bool>::iterator std_itr = std_vec.begin();
        ft::vector<bool>::iterator ft_itr = ft_vec.begin();
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          ++std_itr;
          ++ft_itr;
        }
        if (*std_vec.insert(std_itr, false) != *ft_vec.insert(ft_itr, false)) {
          throw std::runtime_error("return value");
        }
        for (size_t idx = 0; idx < std_vec.size(); ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.size() << std::endl;
          std::cout << " ft: " << ft_vec.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j <= i; j++) {
      size = size_ary[i];
      std::stringstream sout;
      sout << "Vector<bool>: insert(begin + " << size_ary[j]
           << ", true) to vec(" << size << ")";

      putTestInfo(test_no, sout.str());
      try {
        bool val[size];
        for (size_t idx = 0; idx < size; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec(val, val + size);
        ft::vector<bool> ft_vec(val, val + size);
        std::vector<bool>::iterator std_itr = std_vec.begin();
        ft::vector<bool>::iterator ft_itr = ft_vec.begin();
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          ++std_itr;
          ++ft_itr;
        }
        if (*std_vec.insert(std_itr, true) != *ft_vec.insert(ft_itr, true)) {
          throw std::runtime_error("return value");
        }
        for (size_t idx = 0; idx < std_vec.size(); ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.size() << std::endl;
          std::cout << " ft: " << ft_vec.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j <= i; j++) {
      for (size_t n = 0; n < 15; n++) {
        size = size_ary[i];
        std::stringstream sout;
        sout << "Vector<bool>: insert(begin + " << size_ary[j] << ", "
             << size_ary[n] << ", true) to vec(" << size << ")";

        putTestInfo(test_no, sout.str());
        try {
          bool val[size];
          for (size_t idx = 0; idx < size; ++idx) {
            val[idx] = rand() % 2;
          }
          std::vector<bool> std_vec(val, val + size);
          ft::vector<bool> ft_vec(val, val + size);
          std::vector<bool>::iterator std_itr = std_vec.begin();
          ft::vector<bool>::iterator ft_itr = ft_vec.begin();
          for (size_t idx = 0; idx < size_ary[j]; ++idx) {
            ++std_itr;
            ++ft_itr;
          }
          std_vec.insert(std_itr, size_ary[n], true);
          ft_vec.insert(ft_itr, size_ary[n], true);
          for (size_t idx = 0; idx < std_vec.size(); ++idx) {
            if (std_vec[idx] != ft_vec[idx]) {
              std::cout << std::endl << "idx = " << idx << std::endl;
              std::cout << "std: " << std_vec[idx] << std::endl;
              std::cout << " ft: " << ft_vec[idx] << std::endl;
              throw std::runtime_error("value");
            }
          }
          if (std_vec.empty() != ft_vec.empty()) {
            throw std::runtime_error("empty");
          }
          if (std_vec.size() != ft_vec.size()) {
            std::cout << std::endl;
            std::cout << "std: " << std_vec.size() << std::endl;
            std::cout << " ft: " << ft_vec.size() << std::endl;
            throw std::runtime_error("size");
          }
          if (std_vec.capacity() != ft_vec.capacity()) {
            std::cout << std::endl;
            std::cout << "std: " << std_vec.capacity() << std::endl;
            std::cout << " ft: " << ft_vec.capacity() << std::endl;
            throw std::runtime_error("capacity");
          }
          if (std_vec.max_size() != ft_vec.max_size()) {
            std::cout << std::endl;
            std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
            std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
            throw std::runtime_error("max_size");
          }
        } catch (std::runtime_error& e) {
          throw e;
        }
        std::cout << " => OK :)" << std::endl;
      }
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j <= i; j++) {
      for (size_t n = 0; n < 15; n++) {
        size = size_ary[i];
        std::stringstream sout;
        sout << "Vector<bool>: insert(begin + " << size_ary[j] << ", "
             << size_ary[n] << ", false) to vec(" << size << ")";

        putTestInfo(test_no, sout.str());
        try {
          bool val[size];
          for (size_t idx = 0; idx < size; ++idx) {
            val[idx] = rand() % 2;
          }
          std::vector<bool> std_vec(val, val + size);
          ft::vector<bool> ft_vec(val, val + size);
          std::vector<bool>::iterator std_itr = std_vec.begin();
          ft::vector<bool>::iterator ft_itr = ft_vec.begin();
          for (size_t idx = 0; idx < size_ary[j]; ++idx) {
            ++std_itr;
            ++ft_itr;
          }
          std_vec.insert(std_itr, size_ary[n], false);
          ft_vec.insert(ft_itr, size_ary[n], false);
          for (size_t idx = 0; idx < std_vec.size(); ++idx) {
            if (std_vec[idx] != ft_vec[idx]) {
              std::cout << std::endl << "idx = " << idx << std::endl;
              std::cout << "std: " << std_vec[idx] << std::endl;
              std::cout << " ft: " << ft_vec[idx] << std::endl;
              throw std::runtime_error("value");
            }
          }
          if (std_vec.empty() != ft_vec.empty()) {
            throw std::runtime_error("empty");
          }
          if (std_vec.size() != ft_vec.size()) {
            std::cout << std::endl;
            std::cout << "std: " << std_vec.size() << std::endl;
            std::cout << " ft: " << ft_vec.size() << std::endl;
            throw std::runtime_error("size");
          }
          if (std_vec.capacity() != ft_vec.capacity()) {
            std::cout << std::endl;
            std::cout << "std: " << std_vec.capacity() << std::endl;
            std::cout << " ft: " << ft_vec.capacity() << std::endl;
            throw std::runtime_error("capacity");
          }
          if (std_vec.max_size() != ft_vec.max_size()) {
            std::cout << std::endl;
            std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
            std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
            throw std::runtime_error("max_size");
          }
        } catch (std::runtime_error& e) {
          throw e;
        }
        std::cout << " => OK :)" << std::endl;
      }
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = 0; j <= i; j++) {
      for (size_t n = 0; n < 15; n++) {
        size = size_ary[i];
        std::stringstream sout;
        sout << "Vector<bool>: insert(begin + " << size_ary[j] << ", "
             << "first, last) (size = " << size_ary[n] << ") to vec(" << size
             << ")";

        putTestInfo(test_no, sout.str());
        try {
          bool val[size];
          for (size_t idx = 0; idx < size; ++idx) {
            val[idx] = rand() % 2;
          }
          bool val2[size_ary[n]];
          for (size_t idx = 0; idx < size_ary[n]; ++idx) {
            // val2[idx] = true;
            val2[idx] = rand() % 2;
          }
          std::vector<bool> std_vec(val, val + size);
          ft::vector<bool> ft_vec(val, val + size);
          std::vector<bool>::iterator std_itr = std_vec.begin();
          ft::vector<bool>::iterator ft_itr = ft_vec.begin();
          for (size_t idx = 0; idx < size_ary[j]; ++idx) {
            ++std_itr;
            ++ft_itr;
          }
          std_vec.insert(std_itr, val2, val2 + size_ary[n]);
          ft_vec.insert(ft_itr, val2, val2 + size_ary[n]);
          for (size_t idx = 0; idx < std_vec.size(); ++idx) {
            if (std_vec[idx] != ft_vec[idx]) {
              std::cout << std::endl << "idx = " << idx << std::endl;
              std::cout << "std: " << std_vec[idx] << std::endl;
              std::cout << " ft: " << ft_vec[idx] << std::endl;
              throw std::runtime_error("value");
            }
          }
          if (std_vec.empty() != ft_vec.empty()) {
            throw std::runtime_error("empty");
          }
          if (std_vec.size() != ft_vec.size()) {
            std::cout << std::endl;
            std::cout << "std: " << std_vec.size() << std::endl;
            std::cout << " ft: " << ft_vec.size() << std::endl;
            throw std::runtime_error("size");
          }
          if (std_vec.capacity() != ft_vec.capacity()) {
            std::cout << std::endl;
            std::cout << "std: " << std_vec.capacity() << std::endl;
            std::cout << " ft: " << ft_vec.capacity() << std::endl;
            throw std::runtime_error("capacity");
          }
          if (std_vec.max_size() != ft_vec.max_size()) {
            std::cout << std::endl;
            std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
            std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
            throw std::runtime_error("max_size");
          }
        } catch (std::runtime_error& e) {
          throw e;
        }
        std::cout << " => OK :)" << std::endl;
      }
    }
  }

  for (size_t i = 1; i < 15; i++) {
    for (size_t j = 0; j < i; j++) {
      size = size_ary[i];
      std::stringstream sout;
      sout << "Vector<bool>: erase(begin, begin + " << size_ary[j]
           << ") from vec(" << size << ")";

      putTestInfo(test_no, sout.str());
      try {
        bool val[size];
        for (size_t idx = 0; idx < size; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec(val, val + size);
        ft::vector<bool> ft_vec(val, val + size);
        std::vector<bool>::iterator std_itr = std_vec.begin();
        ft::vector<bool>::iterator ft_itr = ft_vec.begin();
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          ++std_itr;
          ++ft_itr;
        }
        std_itr = std_vec.erase(std_vec.begin(), std_itr);
        ft_itr = ft_vec.erase(ft_vec.begin(), ft_itr);
        if ((std_itr == std_vec.end() && ft_itr != ft_vec.end())) {
          throw std::runtime_error("return value");
        }
        if (std_itr != std_vec.end() && *std_itr != *ft_itr) {
          std::cout << "std = " << *std_itr << ", ft = " << *ft_itr
                    << std::endl;
          throw std::runtime_error("return value");
        }
        for (size_t idx = 0; idx < std_vec.size(); ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.size() << std::endl;
          std::cout << " ft: " << ft_vec.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 1; i < 15; i++) {
    for (size_t j = 0; j < i; j++) {
      size = size_ary[i];
      std::stringstream sout;
      sout << "Vector<bool>: erase(begin + " << size_ary[j]
           << ", end() - 1) from vec(" << size << ")";

      putTestInfo(test_no, sout.str());
      try {
        bool val[size];
        for (size_t idx = 0; idx < size; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec(val, val + size);
        ft::vector<bool> ft_vec(val, val + size);
        std::vector<bool>::iterator std_itr = std_vec.begin();
        ft::vector<bool>::iterator ft_itr = ft_vec.begin();
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          ++std_itr;
          ++ft_itr;
        }
        std_itr = std_vec.erase(std_itr, --std_vec.end());
        ft_itr = ft_vec.erase(ft_itr, --ft_vec.end());
        if ((std_itr == std_vec.end() && ft_itr != ft_vec.end())) {
          throw std::runtime_error("return value");
        }
        if (std_itr != std_vec.end() && *std_itr != *ft_itr) {
          std::cout << "std = " << *std_itr << ", ft = " << *ft_itr
                    << std::endl;
          throw std::runtime_error("return value");
        }
        for (size_t idx = 0; idx < std_vec.size(); ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.size() << std::endl;
          std::cout << " ft: " << ft_vec.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; i++) {
    for (size_t j = i; j < 15; j++) {
      size = 4000;
      std::stringstream sout;
      sout << "Vector<bool>: erase(begin + " << size_ary[i] << ", begin() + "
           << size_ary[j] << ") from vec(" << size << ")";

      putTestInfo(test_no, sout.str());
      try {
        bool val[size];
        for (size_t idx = 0; idx < size; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec(val, val + size);
        ft::vector<bool> ft_vec(val, val + size);
        std::vector<bool>::iterator std_itr = std_vec.begin();
        ft::vector<bool>::iterator ft_itr = ft_vec.begin();
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          ++std_itr;
          ++ft_itr;
        }
        std::vector<bool>::iterator std_itr2 = std_vec.begin();
        ft::vector<bool>::iterator ft_itr2 = ft_vec.begin();
        for (size_t idx = 0; idx < size_ary[j]; ++idx) {
          ++std_itr2;
          ++ft_itr2;
        }
        std_itr = std_vec.erase(std_itr, std_itr2);
        ft_itr = ft_vec.erase(ft_itr, ft_itr2);
        if ((std_itr == std_vec.end() && ft_itr != ft_vec.end())) {
          throw std::runtime_error("return value");
        }
        if (std_itr != std_vec.end() && *std_itr != *ft_itr) {
          std::cout << "std = " << *std_itr << ", ft = " << *ft_itr
                    << std::endl;
          throw std::runtime_error("return value");
        }
        for (size_t idx = 0; idx < std_vec.size(); ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.size() << std::endl;
          std::cout << " ft: " << ft_vec.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }
      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  for (size_t i = 0; i < 15; i++) {
    size = size_ary[i];
    std::stringstream sout;
    sout << "Vector<bool>: clear() vec(" << size << ")";
    putTestInfo(test_no, sout.str());
    try {
      bool val[size];
      for (size_t idx = 0; idx < size; ++idx) {
        val[idx] = rand() % 2;
      }
      std::vector<bool> std_vec(val, val + size);
      ft::vector<bool> ft_vec(val, val + size);
      std_vec.clear();
      ft_vec.clear();
      for (size_t idx = 0; idx < size; ++idx) {
        if (std_vec[idx] != ft_vec[idx]) {
          std::cout << std::endl << "idx = " << idx << std::endl;
          std::cout << "std: " << std_vec[idx] << std::endl;
          std::cout << " ft: " << ft_vec[idx] << std::endl;
          throw std::runtime_error("value");
        }
      }
      if (std_vec.empty() != ft_vec.empty()) {
        throw std::runtime_error("empty");
      }
      if (std_vec.size() != ft_vec.size()) {
        throw std::runtime_error("size");
      }
      if (std_vec.capacity() != ft_vec.capacity()) {
        std::cout << std::endl;
        std::cout << "std: " << std_vec.capacity() << std::endl;
        std::cout << " ft: " << ft_vec.capacity() << std::endl;
        throw std::runtime_error("capacity");
      }
      if (std_vec.max_size() != ft_vec.max_size()) {
        std::cout << std::endl;
        std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
        std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
        throw std::runtime_error("max_size");
      }
    } catch (std::runtime_error& e) {
      throw e;
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (size_t i = 1; i < 15; i++) {
    for (size_t j = 0; j < 15; j++) {
      std::stringstream sout;
      sout << "Vector<bool>: vec(" << size_ary[i] << ").swap(vec("
           << size_ary[j] << "))";

      putTestInfo(test_no, sout.str());
      try {
        bool val[std::max(size_ary[i], size_ary[j])];
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec(val, val + size_ary[i]);
        ft::vector<bool> ft_vec(val, val + size_ary[i]);
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec2(val, val + size_ary[i]);
        ft::vector<bool> ft_vec2(val, val + size_ary[i]);

        std_vec.swap(std_vec2);
        ft_vec.swap(ft_vec2);

        for (size_t idx = 0; idx < std_vec.size(); ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.size() << std::endl;
          std::cout << " ft: " << ft_vec.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }

        for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
          if (std_vec2[idx] != ft_vec2[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec2[idx] << std::endl;
            std::cout << " ft: " << ft_vec2[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec2.empty() != ft_vec2.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec2.size() != ft_vec2.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec2.size() << std::endl;
          std::cout << " ft: " << ft_vec2.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec2.capacity() != ft_vec2.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec2.capacity() << std::endl;
          std::cout << " ft: " << ft_vec2.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec2.max_size() != ft_vec2.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec2.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec2.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }

      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  putTestInfo(test_no, "Vector<bool>: swap reference");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);

    for (size_t i = 0; i < size; i++) {
      std_vec.swap(std_vec[i], std_vec[size - i - 1]);
      ft_vec.swap(ft_vec[i], ft_vec[size - i - 1]);
    }

    std::vector<bool>::iterator std_itr;
    ft::vector<bool>::iterator ft_itr;
    for (std_itr = std_vec.begin(), ft_itr = ft_vec.begin();
         std_itr != std_vec.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("nomal itr");
      }
    }
    if (ft_itr != ft_vec.end()) {
      throw std::runtime_error("nomal itr");
    }
    for (std_itr = --std_vec.end(), ft_itr = --ft_vec.end();
         std_itr != std_vec.begin(); --std_itr, --ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("nomal itr");
      }
    }
    if (ft_itr != ft_vec.begin()) {
      throw std::runtime_error("nomal itr");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  for (size_t i = 1; i < 15; i++) {
    for (size_t j = 0; j < 15; j++) {
      std::stringstream sout;
      sout << "Vector<bool>: swap(vec(" << size_ary[i] << "), vec("
           << size_ary[j] << "))";

      putTestInfo(test_no, sout.str());
      try {
        bool val[std::max(size_ary[i], size_ary[j])];
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec(val, val + size_ary[i]);
        ft::vector<bool> ft_vec(val, val + size_ary[i]);
        for (size_t idx = 0; idx < size_ary[i]; ++idx) {
          val[idx] = rand() % 2;
        }
        std::vector<bool> std_vec2(val, val + size_ary[i]);
        ft::vector<bool> ft_vec2(val, val + size_ary[i]);

        swap(std_vec, std_vec2);
        swap(ft_vec, ft_vec2);

        for (size_t idx = 0; idx < std_vec.size(); ++idx) {
          if (std_vec[idx] != ft_vec[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec[idx] << std::endl;
            std::cout << " ft: " << ft_vec[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec.empty() != ft_vec.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec.size() != ft_vec.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.size() << std::endl;
          std::cout << " ft: " << ft_vec.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec.capacity() != ft_vec.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec.capacity() << std::endl;
          std::cout << " ft: " << ft_vec.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec.max_size() != ft_vec.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }

        for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
          if (std_vec2[idx] != ft_vec2[idx]) {
            std::cout << std::endl << "idx = " << idx << std::endl;
            std::cout << "std: " << std_vec2[idx] << std::endl;
            std::cout << " ft: " << ft_vec2[idx] << std::endl;
            throw std::runtime_error("value");
          }
        }
        if (std_vec2.empty() != ft_vec2.empty()) {
          throw std::runtime_error("empty");
        }
        if (std_vec2.size() != ft_vec2.size()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec2.size() << std::endl;
          std::cout << " ft: " << ft_vec2.size() << std::endl;
          throw std::runtime_error("size");
        }
        if (std_vec2.capacity() != ft_vec2.capacity()) {
          std::cout << std::endl;
          std::cout << "std: " << std_vec2.capacity() << std::endl;
          std::cout << " ft: " << ft_vec2.capacity() << std::endl;
          throw std::runtime_error("capacity");
        }
        if (std_vec2.max_size() != ft_vec2.max_size()) {
          std::cout << std::endl;
          std::cout << "max_size(std) = " << std_vec2.max_size() << std::endl;
          std::cout << "max_size(ft)  = " << ft_vec2.max_size() << std::endl;
          throw std::runtime_error("max_size");
        }

      } catch (std::runtime_error& e) {
        throw e;
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  // test iterators
  putTestInfo(test_no, "Vector<bool>: check iterators");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);

    std::vector<bool>::iterator std_itr;
    ft::vector<bool>::iterator ft_itr;
    for (std_itr = std_vec.begin(), ft_itr = ft_vec.begin();
         std_itr != std_vec.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("nomal itr");
      }
    }
    if (ft_itr != ft_vec.end()) {
      throw std::runtime_error("nomal itr");
    }
    for (std_itr = --std_vec.end(), ft_itr = --ft_vec.end();
         std_itr != std_vec.begin(); --std_itr, --ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("nomal itr");
      }
    }
    if (ft_itr != ft_vec.begin()) {
      throw std::runtime_error("nomal itr");
    }

    std::vector<bool>::const_iterator std_citr;
    ft::vector<bool>::const_iterator ft_citr;
    for (std_citr = std_vec.begin(), ft_citr = ft_vec.begin();
         std_citr != std_vec.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("const itr");
      }
    }
    if (ft_citr != ft_vec.end()) {
      throw std::runtime_error("const itr");
    }
    for (std_citr = --std_vec.end(), ft_citr = --ft_vec.end();
         std_citr != std_vec.begin(); --std_citr, --ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("const itr");
      }
    }
    if (ft_citr != ft_vec.begin()) {
      throw std::runtime_error("const itr");
    }

    std::vector<bool>::reverse_iterator std_ritr;
    ft::vector<bool>::reverse_iterator ft_ritr;
    for (std_ritr = std_vec.rbegin(), ft_ritr = ft_vec.rbegin();
         std_ritr != std_vec.rend(); ++std_ritr, ++ft_ritr) {
      if (*std_ritr != *ft_ritr) {
        throw std::runtime_error("reverse itr");
      }
    }
    if (ft_ritr != ft_vec.rend()) {
      throw std::runtime_error("reverse itr");
    }
    for (std_ritr = --std_vec.rend(), ft_ritr = --ft_vec.rend();
         std_ritr != std_vec.rbegin(); --std_ritr, --ft_ritr) {
      if (*std_ritr != *ft_ritr) {
        throw std::runtime_error("reverse itr");
      }
    }
    if (ft_ritr != ft_vec.rbegin()) {
      throw std::runtime_error("reverse itr");
    }

    std::vector<bool>::const_reverse_iterator std_critr;
    ft::vector<bool>::const_reverse_iterator ft_critr;
    for (std_critr = std_vec.rbegin(), ft_critr = ft_vec.rbegin();
         std_critr != std_vec.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("const reverse itr");
      }
    }
    if (ft_critr != ft_vec.rend()) {
      throw std::runtime_error("const reverse itr");
    }
    for (std_critr = --std_vec.rend(), ft_critr = --ft_vec.rend();
         std_critr != std_vec.rbegin(); --std_critr, --ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("const reverse itr");
      }
    }
    if (ft_critr != ft_vec.rbegin()) {
      throw std::runtime_error("const reverse itr");
    }

  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  // test iterators
  putTestInfo(test_no, "Vector<bool>: const iterators");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    const std::vector<bool> std_vec(val, &val[size]);
    const ft::vector<bool> ft_vec(val, &val[size]);

    for (size_t i = 0; i < size; i++) {
      if (std_vec[i] != ft_vec[i]) {
        throw std::runtime_error("operator[]");
      }
      if (std_vec.at(i) != ft_vec.at(i)) {
        throw std::runtime_error("at");
      }
    }

    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("front");
    }

    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("back");
    }

    std::vector<bool>::const_iterator std_citr;
    ft::vector<bool>::const_iterator ft_citr;
    for (std_citr = std_vec.begin(), ft_citr = ft_vec.begin();
         std_citr != std_vec.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("nomal itr");
      }
    }
    if (ft_citr != ft_vec.end()) {
      throw std::runtime_error("nomal itr");
    }
    for (std_citr = --std_vec.end(), ft_citr = --ft_vec.end();
         std_citr != std_vec.begin(); --std_citr, --ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("nomal itr");
      }
    }
    if (ft_citr != ft_vec.begin()) {
      throw std::runtime_error("nomal itr");
    }

    std::vector<bool>::const_reverse_iterator std_critr;
    ft::vector<bool>::const_reverse_iterator ft_critr;
    for (std_critr = std_vec.rbegin(), ft_critr = ft_vec.rbegin();
         std_critr != std_vec.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("reverse itr");
      }
    }
    if (ft_critr != ft_vec.rend()) {
      throw std::runtime_error("reverse itr");
    }
    for (std_critr = --std_vec.rend(), ft_critr = --ft_vec.rend();
         std_critr != std_vec.rbegin(); --std_critr, --ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("reverse itr");
      }
    }
    if (ft_critr != ft_vec.rbegin()) {
      throw std::runtime_error("reverse itr");
    }

  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: vec(0) = vec(4242)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec;
    ft::vector<bool> ft_vec;
    std::vector<bool> std_vec2(val, &val[size]);
    ft::vector<bool> ft_vec2(val, &val[size]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.size() << std::endl;
      std::cout << " ft: " << ft_vec.size() << std::endl;
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.capacity() << std::endl;
      std::cout << " ft: " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      std::cout << std::endl;
      std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
      std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: vec(4242) = vec(0)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);
    std::vector<bool> std_vec2;
    ft::vector<bool> ft_vec2;

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.size() << std::endl;
      std::cout << " ft: " << ft_vec.size() << std::endl;
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.capacity() << std::endl;
      std::cout << " ft: " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      std::cout << std::endl;
      std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
      std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: vec(4242) = vec(2424)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);
    std::vector<bool> std_vec2(val, &val[2424]);
    ft::vector<bool> ft_vec2(val, &val[2424]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.size() << std::endl;
      std::cout << " ft: " << ft_vec.size() << std::endl;
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.capacity() << std::endl;
      std::cout << " ft: " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      std::cout << std::endl;
      std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
      std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: vec(2424) = vec(4242)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[2424]);
    ft::vector<bool> ft_vec(val, &val[2424]);
    std::vector<bool> std_vec2(val, &val[size]);
    ft::vector<bool> ft_vec2(val, &val[size]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << std::endl << "idx = " << idx << std::endl;
        std::cout << "std: " << std_vec[idx] << std::endl;
        std::cout << " ft: " << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.size() << std::endl;
      std::cout << " ft: " << ft_vec.size() << std::endl;
      throw std::runtime_error("size");
    }
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: " << std_vec.capacity() << std::endl;
      std::cout << " ft: " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      std::cout << std::endl;
      std::cout << "max_size(std) = " << std_vec.max_size() << std::endl;
      std::cout << "max_size(ft)  = " << ft_vec.max_size() << std::endl;
      throw std::runtime_error("max_size");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: relational: vec(4242) and vec(4242)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);
    std::vector<bool> std_vec2(val, &val[size]);
    ft::vector<bool> ft_vec2(val, &val[size]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector<bool>: relational: vec(4242) and vec(4242) diff");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }
    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }
    std::vector<bool> std_vec2(val, &val[size]);
    ft::vector<bool> ft_vec2(val, &val[size]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: relational: vec(4242) and vec(2424)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);
    std::vector<bool> std_vec2(val + 1212, &val[3636]);
    ft::vector<bool> ft_vec2(val + 1212, &val[3636]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: relational: vec(4242) and vec(2424)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);
    std::vector<bool> std_vec2(val, &val[2424]);
    ft::vector<bool> ft_vec2(val, &val[2424]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: relational: vec(2424) and vec(4242)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val + 1212, &val[3636]);
    ft::vector<bool> ft_vec(val + 1212, &val[3636]);
    std::vector<bool> std_vec2(val, &val[size]);
    ft::vector<bool> ft_vec2(val, &val[size]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: relational: vec(2424) and vec(4242)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[2424]);
    ft::vector<bool> ft_vec(val, &val[2424]);
    std::vector<bool> std_vec2(val, &val[size]);
    ft::vector<bool> ft_vec2(val, &val[size]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: relational: vec(4242) and vec()");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec(val, &val[size]);
    ft::vector<bool> ft_vec(val, &val[size]);
    std::vector<bool> std_vec2;
    ft::vector<bool> ft_vec2;

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector<bool>: relational: vec() and vec(4242)");
  try {
    const size_t size = 4242;
    bool val[size];
    for (size_t i = 0; i < size; i++) {
      val[i] = rand() % 2;
    }

    std::vector<bool> std_vec;
    ft::vector<bool> ft_vec;
    std::vector<bool> std_vec2(val, &val[size]);
    ft::vector<bool> ft_vec2(val, &val[size]);

    std_vec = std_vec2;
    ft_vec = ft_vec2;

    if ((std_vec == std_vec2) != (ft_vec == ft_vec2)) {
      throw std::runtime_error("==");
    }
    if ((std_vec != std_vec2) != (ft_vec != ft_vec2)) {
      throw std::runtime_error("!=");
    }
    if ((std_vec < std_vec2) != (ft_vec < ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec > std_vec2) != (ft_vec > ft_vec2)) {
      throw std::runtime_error("<");
    }
    if ((std_vec <= std_vec2) != (ft_vec <= ft_vec2)) {
      throw std::runtime_error("<=");
    }
    if ((std_vec >= std_vec2) != (ft_vec >= ft_vec2)) {
      throw std::runtime_error(">=");
    }
  } catch (std::runtime_error& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  std::cout << std::noboolalpha;
}
