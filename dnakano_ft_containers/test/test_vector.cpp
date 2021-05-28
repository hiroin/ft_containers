/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:50:10 by dnakano           #+#    #+#             */
/*   Updated: 2021/03/04 09:20:10 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ALLOW_USE_CPP03

#include <exception>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
#ifdef ALLOW_USE_CPP03
#include <algorithm>
#endif /* ALLOW_USE_CPP03 */

#include "test.hpp"
#include "vector.hpp"

void test_vector(int& test_no) {
  bool flg = 0;

  std::cout << "=== TEST VECTOR ===" << std::endl;

  putTestInfo(test_no, "Vector: default construction");
  try {
    ft::vector<int> vec;
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: fill construction with 42, 42");
  try {
    ft::vector<int> vec(42, 42);
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: copy construction with default");
  try {
    std::vector<int> vec_std1;
    std::vector<int> vec_std2(vec_std1);
    ft::vector<int> vec_ft1;
    ft::vector<int> vec_ft2(vec_ft1);
    if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
        vec_ft2.size() != vec_std2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: copy construction with vec(42,42)");
  try {
    std::vector<int> vec_std1(42, 42);
    std::vector<int> vec_std2(vec_std1);
    ft::vector<int> vec_ft1(42, 42);
    ft::vector<int> vec_ft2(vec_ft1);
    std::vector<int>::iterator itr_std;
    ft::vector<int>::iterator itr_ft;
    for (itr_std = vec_std2.begin(), itr_ft = vec_ft2.begin();
    itr_std != vec_std2.end(); ++itr_std, ++itr_ft) {
      if (*itr_std != *itr_ft) {
        throw std::runtime_error("failed");
      }
    }
    std::vector<int>::const_iterator citr_std;
    ft::vector<int>::const_iterator citr_ft;
    for (citr_std = vec_std2.begin(), citr_ft = vec_ft2.begin();
    citr_std != vec_std2.end(); ++citr_std, ++citr_ft) {
      if (*citr_std != *citr_ft) {
        throw std::runtime_error("failed");
      }
    }
    std::vector<int>::reverse_iterator ritr_std;
    ft::vector<int>::reverse_iterator ritr_ft;
    for (ritr_std = vec_std2.rbegin(), ritr_ft = vec_ft2.rbegin();
    ritr_std != vec_std2.rend(); ++ritr_std, ++ritr_ft) {
      if (*ritr_std != *ritr_ft) {
        throw std::runtime_error("failed");
      }
    }
    std::vector<int>::const_reverse_iterator rcitr_std;
    ft::vector<int>::const_reverse_iterator rcitr_ft;
    for (rcitr_std = vec_std2.rbegin(), rcitr_ft = vec_ft2.rbegin();
    rcitr_std != vec_std2.rend(); ++rcitr_std, ++rcitr_ft) {
      if (*rcitr_std != *rcitr_ft) {
        throw std::runtime_error("failed");
      }
    }
    if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
        vec_ft2.size() != vec_std2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of vec(42,42)");
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(src.begin(), src.end());
    ft::vector<int> ft_vec(src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of lst(42,21)");
  try {
    std::list<int> src(42, 21);
    std::vector<int> std_vec(src.begin(), src.end());
    ft::vector<int> ft_vec(src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of flst(42,21)");
  try {
    std::forward_list<int> src(42, 21);
    std::vector<int> std_vec(src.begin(), src.end());
    ft::vector<int> ft_vec(src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of flst(42,21)");
  try {
    int src[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of vec(42,42) (between "
              "begin() + 20 and end()");
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(src.begin() + 20, src.end());
    ft::vector<int> ft_vec(src.begin() + 20, src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: range construction with iterator of vec(42,42) (between "
              "begin() + 10 and end() - 10");
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(src.begin() + 10, src.end() - 10);
    ft::vector<int> ft_vec(src.begin() + 10, src.end() - 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: copy construction with vec(42,42) with cap(84)");
  try {
    std::vector<int> vec_std1(42, 42);
    vec_std1.reserve(84);
    std::vector<int> vec_std2(vec_std1);
    ft::vector<int> vec_ft1(42, 42);
    vec_ft1.reserve(84);
    ft::vector<int> vec_ft2(vec_ft1);
    for (size_t idx = 0; idx < vec_std2.size(); idx++) {
      if (vec_std2[idx] != vec_ft2[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (vec_ft1 != vec_ft2 || vec_ft2.capacity() != vec_std2.capacity() ||
        vec_ft2.size() != vec_std2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1 == vec2 (default construction");
  try {
    ft::vector<int> vec1;
    ft::vector<int> vec2;
    if (!(vec1 == vec2)) {
      throw std::runtime_error("should be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1(42,42) == vec2(42,42)");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2(42, 42);
    if (!(vec1 == vec2)) {
      throw std::runtime_error("should be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1(42,42) == vec2(21,42)");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2(21, 42);
    if (vec1 == vec2) {
      throw std::runtime_error("should not be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1(42,42) == vec2(42,21)");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2(42, 21);
    if (vec1 == vec2) {
      throw std::runtime_error("should not be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: vec1(42,42) == vec2(42,42) but capacity diffs");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2(42, 42);
    vec2.reserve(84);
    // std::cout << "\nvec1.capacity() = " << vec1.capacity() << std::endl;
    // std::cout << "vec2.capacity() = " << vec2.capacity() << std::endl;
    // std::cout << "vec1 == vec2: " << (vec1 == vec2) << std::endl;
    if (vec1 != vec2) {
      throw std::runtime_error("should be true");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // case different allocator

  putTestInfo(test_no, "vector: check vec1 = vec2(42,42)");
  try {
    ft::vector<int> vec1;
    ft::vector<int> vec2(42, 42);
    vec1 = vec2;
    if (vec1 != vec2) {
      throw std::runtime_error("should not be equal");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1 = vec2(42,42) with 84 capacity");
  try {
    ft::vector<int> vec1;
    ft::vector<int> vec2(42, 42);
    vec2.reserve(84);
    vec1 = vec2;
    // std::cout << "\nvec1.capacity() = " << vec1.capacity() << std::endl;
    // std::cout << "vec2.capacity() = " << vec2.capacity() << std::endl;
    if (vec1 != vec2) {
      throw std::runtime_error("should not be equal");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: check vec1(42, 42) = vec2");
  try {
    ft::vector<int> vec1(42, 42);
    ft::vector<int> vec2;
    vec1 = vec2;
    if (!(vec1 == vec2)) {
      throw std::runtime_error("should be equal");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: size() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.size() != ft_vec.size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: size() of fill construction with 42, 42");
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.size() != ft_vec.size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: max_size() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: max_size() of fill construction with 42, 42");
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: capacity() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: capacity() of fill construction with 42, 42");
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std_vec.capacity() << std::endl;
      throw std::exception();
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector: empty() of empty vector construct with default");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: empty() of fill construction with 42, 42");
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: vec[0] (int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    int std_res = std_vec[0];
    int ft_res = ft_vec[0];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[21] (int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    int std_res = std_vec[21];
    int ft_res = ft_vec[21];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[40] (int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    int std_res = std_vec[40];
    int ft_res = ft_vec[40];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::out_of_range& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: assign vec[i] = i with constructed with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    for (int i = 0; i < 42; i++) {
      std_vec[i] = i;
      ft_vec[i] = i;
      if (std_vec[i] != ft_vec[i]) {
        throw std::runtime_error("failed");
      }
    }
  } catch (std::out_of_range& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[0] (const int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    const int std_res = std_vec[0];
    const int ft_res = ft_vec[0];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[21] (const int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    const int std_res = std_vec[21];
    const int ft_res = ft_vec[21];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: vec[40] (const int) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    const int std_res = std_vec[40];
    const int ft_res = ft_vec[40];
    if (std_res != ft_res) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(0) of default constructed vector");
  flg = 0;
  try {
    ft::vector<int> vec;
    std::cout << vec.at(0) << std::endl;
  } catch (std::out_of_range& e) {
    if (std::string(e.what()) == "vector") {
      flg = true;
    }
  }
  if (!flg) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(0) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.at(0) != ft_vec.at(0)) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(21) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.at(21) != ft_vec.at(21)) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: at(41) of fill construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    if (std_vec.at(41) != ft_vec.at(41)) {
      throw std::runtime_error("failed");
    }
  } catch (std::out_of_range& e) {
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(42) for default construction");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21]) {
      std::cout << "21: " << std_vec[21] << ", " << ft_vec[21] << std::endl;
      std::cout << "24: " << std_vec[24] << ", " << ft_vec[24] << std::endl;
      std::cout << "41: " << std_vec[41] << ", " << ft_vec[41] << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(42) for construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21]) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(84) for construction with 42, 42");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    std_vec[83] = 83;
    ft_vec[83] = 83;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21] || std_vec[83] != ft_vec[83]) {
      // std::cout << "24: " << std_vec[24] << ", " << ft_vec[24] << std::endl;
      // std::cout << "41: " << std_vec[41] << ", " << ft_vec[41] << std::endl;
      // std::cout << "80: " << std_vec[83] << ", " << ft_vec[83] << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: reserve(INT_MAX) for default construction");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.reserve(INT32_MAX);
    ft_vec.reserve(INT32_MAX);
    std_vec[21] = 21;
    ft_vec[21] = 21;
    std_vec[41] = 41;
    ft_vec[41] = 41;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size() ||
        std_vec.max_size() != ft_vec.max_size() || std_vec[41] != ft_vec[41] ||
        std_vec[21] != ft_vec[21]) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: reserve(max_size() + 1) for default construction");
  flg = 0;
  try {
    ft::vector<int> ft_vec;
    ft_vec.reserve(42);
    try {
      ft_vec.reserve(ft_vec.max_size() + 1);
    } catch (std::length_error& e) {
      if (!strcmp(
              e.what(),
              "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported "
              "size")) {
        flg = 1;
      }
    }
    if (!flg) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(42, 21) for default construction");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    if (std_vec[0] != ft_vec[0] || std_vec[41] != ft_vec[41] ||
        std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(42, 21) for vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    if (std_vec[0] != ft_vec[0] || std_vec[41] != ft_vec[41] ||
        std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(42, 21) for vec(21, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    for (size_t idx = 0; idx < std_vec.capacity(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(21, 42) for vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.resize(21, 42);
    ft_vec.resize(21, 42);
    for (size_t idx = 0; idx < std_vec.capacity(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: resize(42, 21) for vec() after reserve(84)");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: resize(42, 21) for vec(21, 42) after reserve(84)");
  flg = 0;
  try {
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: resize(42, 21) for vec(42, 21) after reserve(84)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec.resize(42, 21);
    ft_vec.resize(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "Vector: resize(21, 42) for vec(42, 21) after reserve(84)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.reserve(84);
    ft_vec.reserve(84);
    std_vec.resize(21, 42);
    ft_vec.resize(21, 42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // case segv
  // putTestInfo(test_no, "Vector: front() for default construction");

  putTestInfo(test_no, "Vector: front() of vec(1, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: front() = 21 of vec(1, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    std_vec.front() = 21;
    ft_vec.front() = 21;
    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: front() of vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: front() = 21 of vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.front() = 21;
    ft_vec.front() = 21;
    if (std_vec.front() != ft_vec.front()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // segv
  // putTestInfo(test_no, "Vector: front() of vec()");

  putTestInfo(test_no, "Vector: back() of vec(1, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: back() = 21 of vec(1, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    std_vec.back() = 21;
    ft_vec.back() = 21;
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: back() of vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: back() of vec(42, 42) (rewrite vec[41]");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);

    std_vec[41] = 21;
    ft_vec[41] = 21;
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "Vector: back() = 21 of vec(42, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.back() = 21;
    ft_vec.back() = 21;
    if (std_vec.back() != ft_vec.back()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec(21, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(21, 21);
    ft::vector<int> ft_vec(21, 21);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }

  putTestInfo(test_no, "push_back(42) to vec(1, 1)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 1);
    ft::vector<int> ft_vec(1, 1);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec(2, 2)");
  flg = 0;
  try {
    std::vector<int> std_vec(2, 2);
    ft::vector<int> ft_vec(2, 2);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec(4242, 4242)");
  flg = 0;
  try {
    std::vector<int> std_vec(4242, 4242);
    ft::vector<int> ft_vec(4242, 4242);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      std::cout << std::endl
                << std_vec.size() << ": " << ft_vec.size() << std::endl;
      std::cout << std::endl
                << std_vec.capacity() << ": " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // was ok but takes a few minutes
  // putTestInfo(test_no, "push_back(42) to vec(1234567890, 12345)");

  putTestInfo(test_no, "push_back(42) to vec(12345, 12345)");
  flg = 0;
  try {
    std::vector<int> std_vec(12345, 12345);
    ft::vector<int> ft_vec(12345, 12345);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "push_back(42) to vec(1, 1) after reserve(21)");
  flg = 0;
  try {
    std::vector<int> std_vec(4242, 4242);
    ft::vector<int> ft_vec(4242, 4242);
    std_vec.reserve(21);
    ft_vec.reserve(21);
    std_vec.push_back(42);
    ft_vec.push_back(42);
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "pop_back() to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.pop_back();
    ft_vec.pop_back();
    // don't refer (causing segv)
    // for (size_t idx = 0; idx < std_vec.size(); idx++) {
    //   if (std_vec[idx] != ft_vec[idx]) {
    //     throw std::runtime_error("failed");
    //   }
    // }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "pop_back() to vec(21, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(21, 21);
    ft::vector<int> ft_vec(21, 21);
    std_vec.pop_back();
    ft_vec.pop_back();
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "pop_back() to vec() after resize(1, 1)");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.resize(1, 1);
    ft_vec.resize(1, 1);
    std_vec.pop_back();
    ft_vec.pop_back();
    for (size_t idx = 0; idx < std_vec.size(); idx++) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;
  /**/
  putTestInfo(test_no, "swap vec() and vec(21, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec1;
    std::vector<int> std_vec2(21, 21);
    ft::vector<int> ft_vec1;
    ft::vector<int> ft_vec2(21, 21);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); idx++) {
      if (std_vec1[idx] != ft_vec1[idx]) {
        throw std::runtime_error("value1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); idx++) {
      if (std_vec2[idx] != ft_vec2[idx]) {
        throw std::runtime_error("value2");
      }
    }
    if (std_vec1.capacity() != ft_vec1.capacity() ||
        std_vec1.size() != ft_vec1.size() ||
        std_vec2.capacity() != ft_vec2.capacity() ||
        std_vec2.size() != ft_vec2.size()) {
      std::cout << std::endl;
      std::cout << "std1: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft1: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      std::cout << "std2: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft2: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "swap vec(21, 21) and vec()");
  flg = 0;
  try {
    std::vector<int> std_vec1(21, 21);
    std::vector<int> std_vec2;
    ft::vector<int> ft_vec1(21, 21);
    ft::vector<int> ft_vec2;
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); idx++) {
      if (std_vec1[idx] != ft_vec1[idx]) {
        throw std::runtime_error("failed");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); idx++) {
      if (std_vec2[idx] != ft_vec2[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec1.capacity() != ft_vec1.capacity() ||
        std_vec1.size() != ft_vec1.size() ||
        std_vec2.capacity() != ft_vec2.capacity() ||
        std_vec2.size() != ft_vec2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "swap vec(42, 42) and vec(21, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec1(42, 42);
    std::vector<int> std_vec2(21, 21);
    ft::vector<int> ft_vec1(42, 42);
    ft::vector<int> ft_vec2(21, 21);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); idx++) {
      if (std_vec1[idx] != ft_vec1[idx]) {
        throw std::runtime_error("failed");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); idx++) {
      if (std_vec2[idx] != ft_vec2[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec1.capacity() != ft_vec1.capacity() ||
        std_vec1.size() != ft_vec1.size() ||
        std_vec2.capacity() != ft_vec2.capacity() ||
        std_vec2.size() != ft_vec2.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;
  /* */
  putTestInfo(test_no, "clear with vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.clear();
    ft_vec.clear();
    // std::cout << std::endl;
    // std::cout << "size = " << std_vec.size() << std::endl;
    // std::cout << "capacity = " << std_vec.capacity() << std::endl;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "clear with vec(42,42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std_vec.clear();
    ft_vec.clear();
    // std::cout << std::endl;
    // std::cout << "size = " << std_vec.size() << std::endl;
    // std::cout << "capacity = " << std_vec.capacity() << std::endl;
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "clear with vec(1,42)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 42);
    ft::vector<int> ft_vec(1, 42);
    std_vec.clear();
    ft_vec.clear();
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // this case passed but takes minutes of time
  // putTestInfo(test_no, "clear with vec(1234567890,42)");

  putTestInfo(test_no, "clear with vec(12345, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(12345, 42);
    ft::vector<int> ft_vec(12345, 42);
    std_vec.clear();
    ft_vec.clear();
    if (std_vec.capacity() != ft_vec.capacity() ||
        std_vec.size() != ft_vec.size()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(42,42)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter = std_vec.begin();
    ft::vector<int>::iterator ft_iter = ft_vec.begin();
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      ++std_iter;
      ++ft_iter;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(), cmp with std");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std::vector<int>::iterator std_iter = std_vec.begin();
    ft::vector<int>::iterator ft_iter = ft_vec.begin();
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      ++std_iter;
      ++ft_iter;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(42,42), set seq and cmp with std");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter = std_vec.begin();
    ft::vector<int>::iterator ft_iter = ft_vec.begin();
    int i = 0;
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      *std_iter = i;
      *ft_iter = i;
      std_iter++;
      ft_iter++;
      i++;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
    std_iter = std_vec.begin();
    ft_iter = ft_vec.begin();
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      ++std_iter;
      ++ft_iter;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "itarator of vec(42,42), cmp with std (use operator+ and -)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter;
    ft::vector<int>::iterator ft_iter;
    if (ft_vec.end() - ft_vec.begin() != std_vec.end() - std_vec.begin()) {
      throw std::runtime_error("error operator- iter2 - iter1");
    }
    std_iter = std_vec.begin();
    ft_iter = ft_vec.begin();
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      std_iter = std_iter + 2;
      ft_iter = ft_iter + 2;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "itarator of vec(42,42), cmp with std (use operator+ and -)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter;
    ft::vector<int>::iterator ft_iter;
    if (ft_vec.begin() - ft_vec.end() != std_vec.begin() - std_vec.end()) {
      throw std::runtime_error("error operator- iter2 - iter1");
    }
    std_iter = std_vec.begin();
    ft_iter = ft_vec.begin();
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      std_iter = 2 + std_iter;
      ft_iter = 2 + ft_iter;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(42,42), cmp with std (use operator+=)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter;
    ft::vector<int>::iterator ft_iter;
    std_iter = std_vec.begin();
    ft_iter = ft_vec.begin();
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      std_iter += 2;
      ft_iter += 2;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(42,42), cmp with std (use operator-)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter;
    ft::vector<int>::iterator ft_iter;
    std_iter = std_vec.end();
    ft_iter = ft_vec.end();
    while (ft_iter != ft_vec.begin()) {
      if (*(std_iter - 1) != *(ft_iter - 1)) {
        throw std::runtime_error("iter.begin not match");
      }
      std_iter = std_iter - 2;
      ft_iter = ft_iter - 2;
    }
    if (std_iter != std_vec.begin()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(42,42), cmp with std (use operator-=)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter;
    ft::vector<int>::iterator ft_iter;
    std_iter = std_vec.end();
    ft_iter = ft_vec.end();
    while (ft_iter != ft_vec.begin()) {
      if (*(std_iter - 1) != *(ft_iter - 1)) {
        throw std::runtime_error("iter.begin not match");
      }
      std_iter -= 2;
      ft_iter -= 2;
    }
    if (std_iter != std_vec.begin()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

#ifdef ALLOW_USE_CPP03
  putTestInfo(test_no,
              "itarator of vec(42,42), set 21 using for_each algorithm and "
              "cmp with std");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::for_each(std_vec.begin(), std_vec.end(), divByTwo<int>);
    std::for_each(ft_vec.begin(), ft_vec.end(), divByTwo<int>);
    std::vector<int>::iterator std_iter = std_vec.begin();
    ft::vector<int>::iterator ft_iter = ft_vec.begin();
    std_iter = std_vec.begin();
    ft_iter = ft_vec.begin();
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      ++std_iter;
      ++ft_iter;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;
#endif /* ALLOW_USE_CPP03 */

  putTestInfo(test_no, "reverse itarator of vec(42,42), cmp with std");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::reverse_iterator std_riter = std_vec.rbegin();
    ft::vector<int>::reverse_iterator ft_riter = ft_vec.rbegin();
    while (ft_riter != ft_vec.rend()) {
      if (*std_riter != *ft_riter) {
        throw std::runtime_error("riter.begin not match");
      }
      ++std_riter;
      ++ft_riter;
    }
    if (std_riter != std_vec.rend()) {
      throw std::runtime_error("riter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "reverse itarator of vec(), cmp with std");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std::vector<int>::reverse_iterator std_riter = std_vec.rbegin();
    ft::vector<int>::reverse_iterator ft_riter = ft_vec.rbegin();
    while (ft_riter != ft_vec.rend()) {
      if (*std_riter != *ft_riter) {
        throw std::runtime_error("riter.begin not match");
      }
      ++std_riter;
      ++ft_riter;
    }
    if (std_riter != std_vec.rend()) {
      throw std::runtime_error("riter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "reverse itarator of vec(42,42), set inverse, cmp with std");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter = std_vec.begin();
    ft::vector<int>::iterator ft_iter = ft_vec.begin();
    std::vector<int>::reverse_iterator std_riter = std_vec.rbegin();
    ft::vector<int>::reverse_iterator ft_riter = ft_vec.rbegin();
    int i = 0;
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      *std_iter = i;
      *ft_iter = i;
      std_iter++;
      ft_iter++;
      i++;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
    while (ft_riter != ft_vec.rend()) {
      if (*std_riter != *ft_riter) {
        throw std::runtime_error("riter.begin not match");
      }
      ++std_riter;
      ++ft_riter;
    }
    if (std_riter != std_vec.rend()) {
      throw std::runtime_error("riter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "reverse itarator of vec(42,42), set inverse seq, cmp with std");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::reverse_iterator std_riter = std_vec.rbegin();
    ft::vector<int>::reverse_iterator ft_riter = ft_vec.rbegin();
    int i = 0;
    while (ft_riter != ft_vec.rend()) {
      if (*std_riter != *ft_riter) {
        throw std::runtime_error("iter.begin not match");
      }
      *std_riter = i;
      *ft_riter = i;
      std_riter++;
      ft_riter++;
      i++;
    }
    if (std_riter != std_vec.rend()) {
      throw std::runtime_error("riter.end not match");
    }
    while (ft_riter != ft_vec.rend()) {
      if (*std_riter != *ft_riter) {
        throw std::runtime_error("riter.begin not match");
      }
      ++std_riter;
      ++ft_riter;
    }
    if (std_riter != std_vec.rend()) {
      throw std::runtime_error("riter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

#ifdef ALLOW_USE_CPP03
  putTestInfo(test_no,
              "reverse itarator of vec(42,42), set 21 using for_each algorithm "
              "and cmp with std");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::iterator std_iter = std_vec.begin();
    ft::vector<int>::iterator ft_iter = ft_vec.begin();
    while (ft_iter != ft_vec.end()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.begin not match");
      }
      ++std_iter;
      ++ft_iter;
    }
    if (std_iter != std_vec.end()) {
      throw std::runtime_error("iter.end not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;
#endif /* ALLOW_USE_CPP03 */

  putTestInfo(
      test_no,
      "reverse itarator of vec(42,42), cmp with std (use operator+ and -)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::reverse_iterator std_iter;
    ft::vector<int>::reverse_iterator ft_iter;
    if (ft_vec.rend() - ft_vec.rbegin() != std_vec.rend() - std_vec.rbegin()) {
      throw std::runtime_error("error operator- iter2 - iter1");
    }
    std_iter = std_vec.rbegin();
    ft_iter = ft_vec.rbegin();
    while (ft_iter != ft_vec.rend()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.rbegin not match");
      }
      std_iter = std_iter + 2;
      ft_iter = ft_iter + 2;
    }
    if (std_iter != std_vec.rend()) {
      throw std::runtime_error("iter.rend not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "itarator of vec(42,42), cmp with std (use operator+ and -)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::reverse_iterator std_iter;
    ft::vector<int>::reverse_iterator ft_iter;
    if (ft_vec.rbegin() - ft_vec.rend() != std_vec.rbegin() - std_vec.rend()) {
      throw std::runtime_error("error operator- iter2 - iter1");
    }
    std_iter = std_vec.rbegin();
    ft_iter = ft_vec.rbegin();
    while (ft_iter != ft_vec.rend()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.rbegin not match");
      }
      std_iter = 2 + std_iter;
      ft_iter = 2 + ft_iter;
    }
    if (std_iter != std_vec.rend()) {
      throw std::runtime_error("iter.rend not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(42,42), cmp with std (use operator+=)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::reverse_iterator std_iter;
    ft::vector<int>::reverse_iterator ft_iter;
    std_iter = std_vec.rbegin();
    ft_iter = ft_vec.rbegin();
    while (ft_iter != ft_vec.rend()) {
      if (*std_iter != *ft_iter) {
        throw std::runtime_error("iter.rbegin not match");
      }
      std_iter += 2;
      ft_iter += 2;
    }
    if (std_iter != std_vec.rend()) {
      throw std::runtime_error("iter.rend not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(42,42), cmp with std (use operator-)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::reverse_iterator std_iter;
    ft::vector<int>::reverse_iterator ft_iter;
    std_iter = std_vec.rend();
    ft_iter = ft_vec.rend();
    while (ft_iter != ft_vec.rbegin()) {
      if (*(std_iter - 1) != *(ft_iter - 1)) {
        throw std::runtime_error("iter.rbegin not match");
      }
      std_iter = std_iter - 2;
      ft_iter = ft_iter - 2;
    }
    if (std_iter != std_vec.rbegin()) {
      throw std::runtime_error("iter.rend not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "itarator of vec(42,42), cmp with std (use operator-=)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 42);
    ft::vector<int> ft_vec(42, 42);
    std::vector<int>::reverse_iterator std_iter;
    ft::vector<int>::reverse_iterator ft_iter;
    std_iter = std_vec.rend();
    ft_iter = ft_vec.rend();
    while (ft_iter != ft_vec.rbegin()) {
      if (*(std_iter - 1) != *(ft_iter - 1)) {
        throw std::runtime_error("iter.rbegin not match");
      }
      std_iter -= 2;
      ft_iter -= 2;
    }
    if (std_iter != std_vec.rbegin()) {
      throw std::runtime_error("iter.rend not match");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign(42, 21) to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.assign(42, 21);
    ft_vec.assign(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign(84, 42) to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.assign(84, 42);
    ft_vec.assign(84, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign(42, 21) to vec(84, 42)");
  flg = 0;
  try {
    std::vector<int> std_vec(84, 42);
    ft::vector<int> ft_vec(84, 42);
    std_vec.assign(42, 21);
    ft_vec.assign(42, 21);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << "\ncapacity = " << std_vec.capacity() << std::endl;
      std::cout << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign vec(42, 21) to vec() by iter");
  flg = 0;
  try {
    std::vector<int> src_vec(42, 21);
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.assign(src_vec.begin(), src_vec.end());
    ft_vec.assign(src_vec.begin(), src_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << "\ncapacity = " << std_vec.capacity() << std::endl;
      std::cout << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign vec(42, 21) to vec() by list_iter");
  flg = 0;
  try {
    std::list<int> src_lst(42, 21);
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.assign(src_lst.begin(), src_lst.end());
    ft_vec.assign(src_lst.begin(), src_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << "\ncapacity = " << std_vec.capacity() << std::endl;
      std::cout << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign vec(42, 21) to vec() by list_iter");
  flg = 0;
  try {
    std::list<int> src_lst(42, 21);
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.assign(src_lst.end(), src_lst.begin());
    ft_vec.assign(src_lst.end(), src_lst.begin());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << "\ncapacity = " << std_vec.capacity() << std::endl;
      std::cout << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign vec(42, 21) to vec() by forwardlist_iter");
  flg = 0;
  try {
    std::forward_list<int> src_lst(42, 21);
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.assign(src_lst.begin(), src_lst.end());
    ft_vec.assign(src_lst.begin(), src_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << "\ncapacity = " << std_vec.capacity() << std::endl;
      std::cout << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign vec(42, 21) to vec() by int array pointer");
  flg = 0;
  try {
    int array[42] = {21};
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.assign(&array[0], &array[41]);
    ft_vec.assign(&array[0], &array[41]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << "\ncapacity = " << std_vec.capacity() << std::endl;
      std::cout << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 42), to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (*std_vec.insert(std_vec.begin(), 42) !=
        *ft_vec.insert(ft_vec.begin(), 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(end(), 42), to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    if (*std_vec.insert(std_vec.end(), 42) !=
        *ft_vec.insert(ft_vec.end(), 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 42), to vec(1, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 24);
    ft::vector<int> ft_vec(1, 24);
    if (*std_vec.insert(std_vec.begin(), 42) !=
        *ft_vec.insert(ft_vec.begin(), 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(end(), 42), to vec(1, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(1, 24);
    ft::vector<int> ft_vec(1, 24);
    if (*std_vec.insert(std_vec.end(), 42) !=
        *ft_vec.insert(ft_vec.end(), 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 42), to vec(2, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(2, 24);
    ft::vector<int> ft_vec(2, 24);
    if (*std_vec.insert(std_vec.begin(), 42) !=
        *ft_vec.insert(ft_vec.begin(), 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin() + 1, 42), to vec(2, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(2, 24);
    ft::vector<int> ft_vec(2, 24);
    if (*std_vec.insert(std_vec.begin() + 1, 42) !=
        *ft_vec.insert(ft_vec.begin() + 1, 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(end(), 42), to vec(2, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(2, 24);
    ft::vector<int> ft_vec(2, 24);
    if (*std_vec.insert(std_vec.end(), 42) !=
        *ft_vec.insert(ft_vec.end(), 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 42), to vec(42, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 24);
    ft::vector<int> ft_vec(42, 24);
    if (*std_vec.insert(std_vec.begin(), 42) !=
        *ft_vec.insert(ft_vec.begin(), 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin() + 1, 42), to vec(42, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 24);
    ft::vector<int> ft_vec(42, 24);
    if (*std_vec.insert(std_vec.begin() + 1, 42) !=
        *ft_vec.insert(ft_vec.begin() + 1, 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin() + 20, 42), to vec(42, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 24);
    ft::vector<int> ft_vec(42, 24);
    if (*std_vec.insert(std_vec.begin() + 20, 42) !=
        *ft_vec.insert(ft_vec.begin() + 20, 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin() + 41, 42), to vec(42, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 24);
    ft::vector<int> ft_vec(42, 24);
    if (*std_vec.insert(std_vec.begin() + 41, 42) !=
        *ft_vec.insert(ft_vec.begin() + 41, 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin() + 42, 42), to vec(42, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 24);
    ft::vector<int> ft_vec(42, 24);
    if (*std_vec.insert(std_vec.begin() + 42, 42) !=
        *ft_vec.insert(ft_vec.begin() + 42, 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << "size: " << std_vec.size() << ": " << ft_vec.size()
                << std::endl;
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(end(), 42), to vec(2, 24)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 24);
    ft::vector<int> ft_vec(42, 24);
    if (*std_vec.insert(std_vec.end(), 42) !=
        *ft_vec.insert(ft_vec.end(), 42)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ", val = " << ft_vec[idx] << ", "
                  << std_vec[idx] << std::endl;
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 21, 42), to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.insert(std_vec.begin(), 21, 42);
    ft_vec.insert(ft_vec.begin(), 21, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(end(), 21, 42), to vec()");
  flg = 0;
  try {
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.insert(std_vec.end(), 21, 42);
    ft_vec.insert(ft_vec.end(), 21, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("failed");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("failed");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 21, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.begin(), 21, 42);
    ft_vec.insert(ft_vec.begin(), 21, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 42, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.begin(), 42, 42);
    ft_vec.insert(ft_vec.begin(), 42, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 43, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.begin(), 43, 42);
    ft_vec.insert(ft_vec.begin(), 43, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 100, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.begin(), 100, 42);
    ft_vec.insert(ft_vec.begin(), 100, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 1000, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.begin(), 1000, 42);
    ft_vec.insert(ft_vec.begin(), 1000, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin(), 0, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.begin(), 0, 42);
    ft_vec.insert(ft_vec.begin(), 0, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin() + 20, 21, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.begin() + 20, 21, 42);
    ft_vec.insert(ft_vec.begin() + 20, 21, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(begin() + 42, 21, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.begin() + 42, 21, 42);
    ft_vec.insert(ft_vec.begin() + 42, 21, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert(end(), 21, 42), to vec(42, 21)");
  flg = 0;
  try {
    std::vector<int> std_vec(42, 21);
    ft::vector<int> ft_vec(42, 21);
    std_vec.insert(std_vec.end(), 21, 42);
    ft_vec.insert(ft_vec.end(), 21, 42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert vec() by iter at begin() of vec()");
  flg = 0;
  try {
    std::vector<int> src;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.insert(std_vec.begin(), src.begin(), src.end());
    ft_vec.insert(ft_vec.begin(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert vec(42, 21) by iter at begin() of vec()");
  flg = 0;
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.insert(std_vec.begin(), src.begin(), src.end());
    ft_vec.insert(ft_vec.begin(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert vec(42, 21) by iter at end() of vec()");
  flg = 0;
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std_vec.insert(std_vec.end(), src.begin(), src.end());
    ft_vec.insert(ft_vec.end(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // とりあえずこのエラー処理はあとまわし
  // putTestInfo(test_no, "insert(end(), begin(), end()), to vec()");
  // flg = 0;
  // try {
  //   std::vector<int> src(42, 21);
  //   std::vector<int> std_vec;
  //   ft::vector<int> ft_vec;
  //   std_vec.insert(std_vec.end(), src.end(), src.begin());
  //   ft_vec.insert(ft_vec.end(), src.end(), src.begin());
  //   std::cout << std::endl;
  //   std::cout << std_vec.size() << ": " << ft_vec.size() << std::endl;
  //   for (size_t idx = 0; idx < std_vec.size(); ++idx) {
  //     if (std_vec[idx] != ft_vec[idx]) {
  //       std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": " <<
  //       ft_vec[idx] << std::endl; throw std::runtime_error("value");
  //     }
  //   }
  //   if (std_vec.size() != ft_vec.size() ||
  //       std_vec.capacity() != ft_vec.capacity()) {
  //     throw std::runtime_error("size or capacity");
  //   }
  // } catch (std::exception& e) {
  //   throw std::runtime_error(e.what());
  // }
  // std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert vec(42, 21) by iter at begin() of vec(21, 42)");
  flg = 0;
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.begin(), src.begin(), src.end());
    ft_vec.insert(ft_vec.begin(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert vec(42, 21) by iter at end() of vec(21, 42)");
  flg = 0;
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.end(), src.begin(), src.end());
    ft_vec.insert(ft_vec.end(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "insert vec(42, 21) by iter at begin() + 20 of vec(21, 42)");
  flg = 0;
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.begin() + 20, src.begin(), src.end());
    ft_vec.insert(ft_vec.begin() + 20, src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "insert partial vec(42, 21) by iter at begin() + 20 of vec(21, 42)");
  flg = 0;
  try {
    std::vector<int> src(42, 21);
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.begin() + 20, src.begin() + 10, src.end() - 10);
    ft_vec.insert(ft_vec.begin() + 20, src.begin() + 10, src.end() - 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert lst(42, 21) by iter at begin() of vec(21, 42)");
  flg = 0;
  try {
    std::list<int> src(42, 21);
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.begin(), src.begin(), src.end());
    ft_vec.insert(ft_vec.begin(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert lst(42, 21) by iter at end() of vec(21, 42)");
  flg = 0;
  try {
    std::list<int> src(42, 21);
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.end(), src.begin(), src.end());
    ft_vec.insert(ft_vec.end(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert flst(42, 21) by iter at begin() of vec(21, 42)");
  flg = 0;
  try {
    std::forward_list<int> src(42, 21);
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.begin(), src.begin(), src.end());
    ft_vec.insert(ft_vec.begin(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert flst(42, 21) by iter at end() of vec(21, 42)");
  flg = 0;
  try {
    std::forward_list<int> src(42, 21);
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.end(), src.begin(), src.end());
    ft_vec.insert(ft_vec.end(), src.begin(), src.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert ary[10] by iter at end() of vec(21, 42)");
  flg = 0;
  try {
    int src[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.end(), src, &src[10]);
    ft_vec.insert(ft_vec.end(), src, &src[10]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "insert empty by iter at end() of vec(21, 42)");
  flg = 0;
  try {
    int src[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(21, 42);
    ft::vector<int> ft_vec(21, 42);
    std_vec.insert(std_vec.end(), src + 3, src + 3);
    ft_vec.insert(ft_vec.end(), src + 3, src + 3);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        std::cout << "\nidx = " << idx << ": " << std_vec[idx] << ": "
                  << ft_vec[idx] << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase begin() from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin());
    ft_vec.erase(ft_vec.begin());
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase begin() + 1 from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin() + 1);
    ft_vec.erase(ft_vec.begin() + 1);
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase begin() + 5 from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin() + 5);
    ft_vec.erase(ft_vec.begin() + 5);
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase begin() + 9 from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin() + 9);
    ft_vec.erase(ft_vec.begin() + 9);
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase 2 ~ 8 from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin() + 2, std_vec.begin() + 8);
    ft_vec.erase(ft_vec.begin() + 2, ft_vec.begin() + 8);
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase begin ~ 8 from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin(), std_vec.begin() + 8);
    ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 8);
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase begin ~ end from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin(), std_vec.end());
    ft_vec.erase(ft_vec.begin(), ft_vec.end());
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase begin ~ begin from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin(), std_vec.begin());
    ft_vec.erase(ft_vec.begin(), ft_vec.begin());
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: erase end ~ end from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.end(), std_vec.end());
    ft_vec.erase(ft_vec.end(), ft_vec.end());
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: begin + 1 ~ begin + 2 from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    src[1] = 42;
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin() + 1, std_vec.begin() + 2);
    ft_vec.erase(ft_vec.begin() + 1, ft_vec.begin() + 2);
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector: begin + 1 ~ begin + 1 from vec({0..9}");
  try {
    int src[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> std_vec(src, src + 10);
    ft::vector<int> ft_vec(src, src + 10);
    std_vec.erase(std_vec.begin() + 1, std_vec.begin() + 2);
    ft_vec.erase(ft_vec.begin() + 1, ft_vec.begin() + 2);
    // std::cout << std::endl;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      // std::cout << std_vec[idx] << ": " << ft_vec[idx] << std::endl;
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // case segv
  // putTestInfo(test_no, "vector: erase begin() + 10 from vec({0..9}");

  /*** test using hoge ***/
  Hoge hoge[10] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2), Hoge(3, 3), Hoge(4, 4),
                   Hoge(5, 5), Hoge(6, 6), Hoge(7, 7), Hoge(8, 8), Hoge(9, 9)};
  std::vector<Hoge> hoge_vec(hoge, &hoge[10]);
  std::list<Hoge> hoge_lst(hoge, &hoge[10]);
  std::forward_list<Hoge> hoge_flst(hoge, &hoge[10]);

  putTestInfo(test_no, "vector<Hoge>: default construction");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: construct vec(0)");
  try {
    std::vector<Hoge> std_vec(0);
    ft::vector<Hoge> ft_vec(0);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: construct vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: construct vec(42)");
  try {
    std::vector<Hoge> std_vec(42);
    ft::vector<Hoge> ft_vec(42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: construct vec(0, Hoge(42,42))");
  try {
    std::vector<Hoge> std_vec(0, Hoge(42, 42));
    ft::vector<Hoge> ft_vec(0, Hoge(42, 42));
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: construct vec(1, Hoge(42,42))");
  try {
    std::vector<Hoge> std_vec(1, Hoge(42, 42));
    ft::vector<Hoge> ft_vec(1, Hoge(42, 42));
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: construct vec(42, Hoge(42,42))");
  try {
    std::vector<Hoge> std_vec(1, Hoge(42, 42));
    ft::vector<Hoge> ft_vec(1, Hoge(42, 42));
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: fill construct with array");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: fill construct with vector");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: fill construct with list");
  try {
    std::vector<Hoge> std_vec(hoge_lst.begin(), hoge_lst.end());
    ft::vector<Hoge> ft_vec(hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: fill construct with flist");
  try {
    std::vector<Hoge> std_vec(hoge_flst.begin(), hoge_flst.end());
    ft::vector<Hoge> ft_vec(hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.empty() != ft_vec.empty()) {
      throw std::runtime_error("empty");
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: copy construct empty one");
  try {
    std::vector<Hoge> std_vec_src;
    ft::vector<Hoge> ft_vec_src;
    std::vector<Hoge> std_vec(std_vec_src);
    ft::vector<Hoge> ft_vec(ft_vec_src);
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: copy construct with filled with one");
  try {
    std::vector<Hoge> std_vec_src(1, hoge[0]);
    ft::vector<Hoge> ft_vec_src(1, hoge[0]);
    std::vector<Hoge> std_vec(std_vec_src);
    ft::vector<Hoge> ft_vec(ft_vec_src);
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: copy construct with filled one");
  try {
    std::vector<Hoge> std_vec_src(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec_src(hoge_vec.begin(), hoge_vec.end());
    std::vector<Hoge> std_vec(std_vec_src);
    ft::vector<Hoge> ft_vec(ft_vec_src);
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec() = vec()");
  try {
    std::vector<Hoge> std_vec_src;
    ft::vector<Hoge> ft_vec_src;
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(filled with one) = vec()");
  try {
    std::vector<Hoge> std_vec_src;
    ft::vector<Hoge> ft_vec_src;
    std::vector<Hoge> std_vec(1, hoge[2]);
    ft::vector<Hoge> ft_vec(1, hoge[2]);
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(filled with 10) = vec()");
  try {
    std::vector<Hoge> std_vec_src;
    ft::vector<Hoge> ft_vec_src;
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(1) = vec(1)");
  try {
    std::vector<Hoge> std_vec_src(1, hoge[2]);
    ft::vector<Hoge> ft_vec_src(1, hoge[2]);
    std::vector<Hoge> std_vec(1, hoge[2]);
    ft::vector<Hoge> ft_vec(1, hoge[2]);
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) = vec(1)");
  try {
    std::vector<Hoge> std_vec_src(1, hoge[2]);
    ft::vector<Hoge> ft_vec_src(1, hoge[2]);
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(1) = vec(10)");
  try {
    std::vector<Hoge> std_vec_src(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec_src(hoge_vec.begin(), hoge_vec.end());
    std::vector<Hoge> std_vec(1, hoge[2]);
    ft::vector<Hoge> ft_vec(1, hoge[2]);
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    if ((ft_vec != ft_vec_src || !(ft_vec == ft_vec_src)) !=
        (std_vec != std_vec_src || !(std_vec == std_vec_src))) {
      throw std::runtime_error("assignation");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) = vec(10)");
  try {
    std::vector<Hoge> std_vec_src(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec_src(hoge_vec.begin(), hoge_vec.end());
    std::vector<Hoge> std_vec(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec(hoge_vec.rbegin(), hoge_vec.rend());
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) = vec(5)");
  try {
    std::vector<Hoge> std_vec_src(hoge_vec.begin() + 5, hoge_vec.end());
    ft::vector<Hoge> ft_vec_src(hoge_vec.begin() + 5, hoge_vec.end());
    std::vector<Hoge> std_vec(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec(hoge_vec.rbegin(), hoge_vec.rend());
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) = vec(10)");
  try {
    std::vector<Hoge> std_vec_src(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec_src(hoge_vec.begin(), hoge_vec.end());
    std::vector<Hoge> std_vec(hoge_vec.rbegin() + 5, hoge_vec.rend());
    ft::vector<Hoge> ft_vec(hoge_vec.rbegin() + 5, hoge_vec.rend());
    std_vec = std_vec_src;
    ft_vec = ft_vec_src;
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec() -> reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) -> reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge + 4, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 4, hoge + 9);
    std::cout << std::endl << "hoge" << std::endl;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) -> reserve(0)");
  try {
    std::vector<Hoge> std_vec(hoge + 4, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 4, hoge + 9);
    std::cout << std::endl << "hoge" << std::endl;
    std_vec.reserve(0);
    ft_vec.reserve(0);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) -> reserve(4)");
  try {
    std::vector<Hoge> std_vec(hoge + 4, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 4, hoge + 9);
    std::cout << std::endl << "hoge" << std::endl;
    std_vec.reserve(4);
    ft_vec.reserve(4);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) -> reserve(5)");
  try {
    std::vector<Hoge> std_vec(hoge + 4, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 4, hoge + 9);
    std::cout << std::endl << "hoge" << std::endl;
    std_vec.reserve(5);
    ft_vec.reserve(5);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) -> reserve(7)");
  try {
    std::vector<Hoge> std_vec(hoge + 4, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 4, hoge + 9);
    std::cout << std::endl << "hoge" << std::endl;
    std_vec.reserve(7);
    ft_vec.reserve(7);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) -> reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    std::cout << std::endl << "hoge" << std::endl;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(24) -> reserve(42)");
  try {
    std::vector<Hoge> std_vec(24);
    ft::vector<Hoge> ft_vec(24);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec() -> resize(0)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.resize(0);
    ft_vec.resize(0);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec() -> resize(5)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.resize(5);
    ft_vec.resize(5);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec() -> reserve(3) -> resize(4)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(3);
    ft_vec.reserve(3);
    std_vec.resize(4);
    ft_vec.resize(4);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec() -> reserve(3) -> resize(10)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(3);
    ft_vec.reserve(3);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec() -> reserve(15) -> resize(10)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(15);
    ft_vec.reserve(15);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec() -> reserve(42) -> resize(10)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(1) -> reserve(3) -> resize(10)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(3);
    ft_vec.reserve(3);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(1) -> reserve(15) -> resize(10)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(15);
    ft_vec.reserve(15);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(1) -> reserve(42) -> resize(10)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(7) -> reserve(3) -> resize(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 7);
    ft::vector<Hoge> ft_vec(hoge, hoge + 7);
    std_vec.reserve(3);
    ft_vec.reserve(3);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(7) -> reserve(15) -> resize(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 7);
    ft::vector<Hoge> ft_vec(hoge, hoge + 7);
    std_vec.reserve(15);
    ft_vec.reserve(15);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(7) -> reserve(42) -> resize(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 7);
    ft::vector<Hoge> ft_vec(hoge, hoge + 7);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(42) -> reserve(3) -> resize(4)");
  try {
    std::vector<Hoge> std_vec(42);
    ft::vector<Hoge> ft_vec(42);
    std_vec.reserve(3);
    ft_vec.reserve(3);
    std_vec.resize(4);
    ft_vec.resize(4);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(42) -> reserve(3) -> resize(10)");
  try {
    std::vector<Hoge> std_vec(42);
    ft::vector<Hoge> ft_vec(42);
    std_vec.reserve(3);
    ft_vec.reserve(3);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(42) -> reserve(15) -> resize(10)");
  try {
    std::vector<Hoge> std_vec(42);
    ft::vector<Hoge> ft_vec(42);
    std_vec.reserve(15);
    ft_vec.reserve(15);
    std_vec.resize(10);
    ft_vec.resize(10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec[idx] != ft_vec[idx]) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) at(0 - 10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.begin(), hoge_lst.end());
    ft::vector<Hoge> ft_vec(hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) at(42)");
  flg = 0;
  try {
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    try {
      (void)ft_vec.at(42);
    } catch (std::exception& e) {
      flg = 1;
    }
    if (!flg) {
      throw std::runtime_error("caught no exception");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) at(10)");
  flg = 0;
  try {
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    try {
      (void)ft_vec.at(10);
    } catch (std::exception& e) {
      flg = 1;
    }
    if (!flg) {
      throw std::runtime_error("caught no exception");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) at(-1)");
  flg = 0;
  try {
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    try {
      (void)ft_vec.at(-1);
    } catch (std::exception& e) {
      flg = 1;
    }
    if (!flg) {
      throw std::runtime_error("caught no exception");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) assign(2)");
  try {
    std::vector<Hoge> std_vec(hoge + 5, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 5, hoge + 9);
    std_vec.assign(hoge + 8, hoge + 9);
    ft_vec.assign(hoge + 8, hoge + 9);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) assign(7)");
  try {
    std::vector<Hoge> std_vec(hoge + 5, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 5, hoge + 9);
    std_vec.assign(hoge + 2, hoge + 9);
    ft_vec.assign(hoge + 2, hoge + 9);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(10) assign(7)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    std_vec.assign(hoge + 2, hoge + 9);
    ft_vec.assign(hoge + 2, hoge + 9);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector, <Hoge>: vec(42) assign(7)");
  try {
    std::vector<Hoge> std_vec(42, hoge[9], std::vector<int>::allocator_type());
    ft::vector<Hoge> ft_vec(42, hoge[9], std::vector<int>::allocator_type());
    std_vec.assign(hoge + 2, hoge + 9);
    ft_vec.assign(hoge + 2, hoge + 9);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector, <Hoge>: vec(42) assign(10) vec");
  try {
    std::vector<Hoge> std_vec(42, hoge[9], std::vector<int>::allocator_type());
    ft::vector<Hoge> ft_vec(42, hoge[9], std::vector<int>::allocator_type());
    std_vec.assign(hoge_vec.begin(), hoge_vec.end());
    ft_vec.assign(hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector, <Hoge>: vec(42) assign(10) lst");
  try {
    std::vector<Hoge> std_vec(42, hoge[9], std::vector<int>::allocator_type());
    ft::vector<Hoge> ft_vec(42, hoge[9], std::vector<int>::allocator_type());
    std_vec.assign(hoge_lst.begin(), hoge_lst.end());
    ft_vec.assign(hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector, <Hoge>: vec(42) assign(10) flst");
  try {
    std::vector<Hoge> std_vec(42, hoge[9], std::vector<int>::allocator_type());
    ft::vector<Hoge> ft_vec(42, hoge[9], std::vector<int>::allocator_type());
    std_vec.assign(hoge_flst.begin(), hoge_flst.end());
    ft_vec.assign(hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector, <Hoge>: vec(42) assign(0)");
  try {
    std::vector<Hoge> std_vec(42, hoge[0]);
    ft::vector<Hoge> ft_vec(42, hoge[0]);
    std_vec.assign(hoge + 2, hoge + 2);
    ft_vec.assign(hoge + 2, hoge + 2);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(5) assign(2)");
  try {
    std::vector<Hoge> std_vec(hoge + 5, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 5, hoge + 9);
    std_vec.assign(2, hoge[1]);
    ft_vec.assign(2, hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(2) assign(5)");
  try {
    std::vector<Hoge> std_vec(hoge + 8, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 8, hoge + 9);
    std_vec.assign(5, hoge[1]);
    ft_vec.assign(5, hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(2) assign(42)");
  try {
    std::vector<Hoge> std_vec(hoge + 8, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge + 8, hoge + 9);
    std_vec.assign(42, hoge[1]);
    ft_vec.assign(42, hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(42) assign(42)");
  try {
    std::vector<Hoge> std_vec(42, hoge[2], ft::vector<int>::allocator_type());
    ft::vector<Hoge> ft_vec(42, hoge[2], ft::vector<int>::allocator_type());
    std_vec.assign(42, hoge[1]);
    ft_vec.assign(42, hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(24) assign(42)");
  try {
    std::vector<Hoge> std_vec(24, hoge[2], ft::vector<int>::allocator_type());
    ft::vector<Hoge> ft_vec(24, hoge[2], ft::vector<int>::allocator_type());
    std_vec.assign(42, hoge[1]);
    ft_vec.assign(42, hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vec(42) assign(0)");
  try {
    std::vector<Hoge> std_vec(42, hoge[2], ft::vector<int>::allocator_type());
    ft::vector<Hoge> ft_vec(42, hoge[2], ft::vector<int>::allocator_type());
    std_vec.assign(0, hoge[1]);
    ft_vec.assign(0, hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: push_back to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.push_back(hoge[1]);
    ft_vec.push_back(hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: push_back to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.push_back(hoge[1]);
    ft_vec.push_back(hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: push_back to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.push_back(hoge[1]);
    ft_vec.push_back(hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: push_back to vec() after reserve(20)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(20);
    ft_vec.reserve(20);
    std_vec.push_back(hoge[1]);
    ft_vec.push_back(hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: push_back to vec(10) after reserve(20)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.reserve(20);
    ft_vec.reserve(20);
    std_vec.push_back(hoge[1]);
    ft_vec.push_back(hoge[1]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // pop_back
  putTestInfo(test_no, "vector<Hoge>: pop_back to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.pop_back();
    ft_vec.pop_back();
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: pop_back to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec(hoge_vec.rbegin(), hoge_vec.rend());
    std_vec.pop_back();
    ft_vec.pop_back();
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1]) to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    if (*std_vec.insert(std_vec.begin(), hoge[1]) !=
        *ft_vec.insert(ft_vec.begin(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    if (*std_vec.insert(std_vec.end(), hoge[1]) !=
        *ft_vec.insert(ft_vec.end(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    if (*std_vec.insert(std_vec.begin(), hoge[1]) !=
        *ft_vec.insert(ft_vec.begin(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    if (*std_vec.insert(std_vec.end(), hoge[1]) !=
        *ft_vec.insert(ft_vec.end(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    if (*std_vec.insert(std_vec.begin(), hoge[1]) !=
        *ft_vec.insert(ft_vec.begin(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin + 5, hoge[1]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    if (*std_vec.insert(std_vec.begin() + 5, hoge[1]) !=
        *ft_vec.insert(ft_vec.begin() + 5, hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    if (*std_vec.insert(std_vec.end(), hoge[1]) !=
        *ft_vec.insert(ft_vec.end(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin, hoge[1]) to vec(10) reserve(11)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.reserve(11);
    ft_vec.reserve(11);
    if (*std_vec.insert(std_vec.begin(), hoge[1]) !=
        *ft_vec.insert(ft_vec.begin(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin + 5, hoge[1]) to vec(10) reserve(11)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.reserve(11);
    ft_vec.reserve(11);
    if (*std_vec.insert(std_vec.begin() + 5, hoge[1]) !=
        *ft_vec.insert(ft_vec.begin() + 5, hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(end, hoge[5]) to vec(10) reserve(11)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.begin(), hoge_lst.end());
    ft::vector<Hoge> ft_vec(hoge_lst.begin(), hoge_lst.end());
    std_vec.reserve(11);
    ft_vec.reserve(11);
    if (*std_vec.insert(std_vec.end(), hoge[1]) !=
        *ft_vec.insert(ft_vec.end(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        std::cout << idx << std::endl;
        std::cout << std_vec[idx].idx_ << ":" << *std_vec[idx].num_
                  << std::endl;
        std::cout << ft_vec[idx].idx_ << ":" << *ft_vec[idx].num_ << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin, hoge[1]) to vec(10) reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    if (*std_vec.insert(std_vec.begin(), hoge[1]) !=
        *ft_vec.insert(ft_vec.begin(), hoge[1])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin + 5, hoge[1]) to vec(10) reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    if (*std_vec.insert(std_vec.begin(), hoge[5]) !=
        *ft_vec.insert(ft_vec.begin(), hoge[5])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(end, hoge[5]) to vec(10) reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.begin(), hoge_lst.end());
    ft::vector<Hoge> ft_vec(hoge_lst.begin(), hoge_lst.end());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    if (*std_vec.insert(std_vec.end(), hoge[5]) !=
        *ft_vec.insert(ft_vec.end(), hoge[5])) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        std::cout << idx << std::endl;
        std::cout << std_vec[idx].idx_ << ":" << *std_vec[idx].num_
                  << std::endl;
        std::cout << ft_vec[idx].idx_ << ":" << *ft_vec[idx].num_ << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10ary] to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10ary]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10ary]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10ary]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10ary]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, hoge[1~10ary]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin() + 5, hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin() + 5, hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10ary]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.end(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.end(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, hoge[1~10ary] to vec after reserve(10)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(10);
    ft_vec.reserve(10);
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10ary]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10ary]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10ary]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10ary]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, hoge[1~10ary]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin() + 5, hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.begin() + 5, hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10ary]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.end(), hoge + 1, hoge + 10);
    ft_vec.insert(ft_vec.end(), hoge + 1, hoge + 10);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, hoge[1~10ary]) to vec(10) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), hoge, hoge + 9);
    ft_vec.insert(ft_vec.end(), hoge, hoge + 9);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, hoge[1~10flst]) to vec() after reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), hoge + 2, hoge + 5);
    ft_vec.insert(ft_vec.end(), hoge + 2, hoge + 5);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10flst] to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10flst]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.end(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.end(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10flst]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10flst]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.end(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.end(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin, hoge[1~10flst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, hoge[1~10flst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin() + 5, hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin() + 5, hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10flst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.end(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.end(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, hoge[1~10flst] to vec after reserve(10)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(10);
    ft_vec.reserve(10);
    std_vec.insert(std_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10flst]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10flst]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10flst]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin, hoge[1~10flst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, hoge[1~10flst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin() + 5, hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.begin() + 5, hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10flst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.end(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.end(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, hoge[1~10flst]) to vec(10) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.end(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, hoge[1~10flst]) to vec() after reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), hoge_flst.begin(), hoge_flst.end());
    ft_vec.insert(ft_vec.end(), hoge_flst.begin(), hoge_flst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10lst] to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10lst]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.end(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.end(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10lst]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10lst]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.end(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.end(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10lst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, hoge[1~10lst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin() + 5, hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin() + 5, hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10lst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.end(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.end(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, hoge[1~10lst] to vec after reserve(10)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(10);
    ft_vec.reserve(10);
    std_vec.insert(std_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10lst]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10lst]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10lst]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10lst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, hoge[1~10lst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin() + 5, hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.begin() + 5, hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10lst]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.end(), hoge_lst.begin(), hoge_lst.end());
    ft_vec.insert(ft_vec.end(), hoge_lst.begin(), hoge_lst.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10vec] to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10vec]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.end(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.end(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10vec]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10vec]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.end(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.end(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10vec]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, hoge[1~10vec]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin() + 5, hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin() + 5, hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10vec]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.end(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.end(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, hoge[1~10vec] to vec after reserve(10)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(10);
    ft_vec.reserve(10);
    std_vec.insert(std_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10vec]) to vec()");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10vec]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10vec]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, hoge[1~10vec]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, hoge[1~10vec]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.begin() + 5, hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.begin() + 5, hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, hoge[1~10vec]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.insert(std_vec.end(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.end(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 9, hoge[1~10vec]) to vec(10) after "
              "reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_lst.rbegin(), hoge_lst.rend());
    ft::vector<Hoge> ft_vec(hoge_lst.rbegin(), hoge_lst.rend());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), hoge_vec.begin(), hoge_vec.end());
    ft_vec.insert(ft_vec.end(), hoge_vec.begin(), hoge_vec.end());
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  /// case vec
  putTestInfo(test_no, "vector<Hoge>: insert(begin, 0, ary[5]) to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), 0, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 0, ary[5]) to vec after reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin(), 0, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 0, ary[5]) to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.end(), 0, hoge[5]);
    ft_vec.insert(ft_vec.end(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(end, 0, ary[5]) to vec after reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 0, hoge[5]);
    ft_vec.insert(ft_vec.end(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, 1, ary[5]) to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), 1, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 1, ary[5]) to vec after reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin(), 1, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 1, ary[5]) to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.end(), 1, hoge[5]);
    ft_vec.insert(ft_vec.end(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(end, 1, ary[5]) to vec after reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 1, hoge[5]);
    ft_vec.insert(ft_vec.end(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, 10, ary[5]) to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.begin(), 10, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 1, ary[5]) to vec after reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin(), 10, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 1, ary[5]) to vec");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.insert(std_vec.end(), 10, hoge[5]);
    ft_vec.insert(ft_vec.end(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(end, 1, ary[5]) to vec after reserve(42)");
  try {
    std::vector<Hoge> std_vec;
    ft::vector<Hoge> ft_vec;
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 10, hoge[5]);
    ft_vec.insert(ft_vec.end(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  /// case vec(1)
  putTestInfo(test_no, "vector<Hoge>: insert(begin, 0, ary[5]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), 0, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 0, ary[5]) to vec(1) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin(), 0, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 0, ary[5]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.end(), 0, hoge[5]);
    ft_vec.insert(ft_vec.end(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, 0, ary[5]) to vec(1) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 0, hoge[5]);
    ft_vec.insert(ft_vec.end(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, 1, ary[5]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), 1, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 1, ary[5]) to vec(1) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin(), 1, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 1, ary[5]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.end(), 1, hoge[5]);
    ft_vec.insert(ft_vec.end(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, 1, ary[5]) to vec(1) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 1, hoge[5]);
    ft_vec.insert(ft_vec.end(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        std::cout << "idx = " << idx << std::endl;
        std::cout << std_vec[idx].idx_ << ":" << *std_vec[idx].num_
                  << std::endl;
        std::cout << ft_vec[idx].idx_ << ":" << *ft_vec[idx].num_ << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, 10, ary[5]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.begin(), 10, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 10, ary[5]) to vec(1) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin(), 10, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 10, ary[5]) to vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.insert(std_vec.end(), 10, hoge[5]);
    ft_vec.insert(ft_vec.end(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, 10, ary[5]) to vec(1) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 10, hoge[5]);
    ft_vec.insert(ft_vec.end(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  /// case vec(10)
  putTestInfo(test_no, "vector<Hoge>: insert(begin, 0, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.begin(), 0, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 0, ary[5]) to vec(10) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin(), 0, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin + 5, 0, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.begin() + 5, 0, hoge[5]);
    ft_vec.insert(ft_vec.begin() + 5, 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, 0, ary[5]) to vec(10) after "
              "reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin() + 5, 0, hoge[5]);
    ft_vec.insert(ft_vec.begin() + 5, 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 0, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.end(), 0, hoge[5]);
    ft_vec.insert(ft_vec.end(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, 0, ary[5]) to vec(10) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 0, hoge[5]);
    ft_vec.insert(ft_vec.end(), 0, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, 1, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.begin(), 1, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 1, ary[5]) to vec(10) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.begin(), 1, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin + 5, 1, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.begin() + 5, 1, hoge[5]);
    ft_vec.insert(ft_vec.begin() + 5, 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, 1, ary[5]) to vec(10) after "
              "reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.begin() + 5, 1, hoge[5]);
    ft_vec.insert(ft_vec.begin() + 5, 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 1, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.end(), 1, hoge[5]);
    ft_vec.insert(ft_vec.end(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, 1, ary[5]) to vec(10) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 1, hoge[5]);
    ft_vec.insert(ft_vec.end(), 1, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        std::cout << "idx = " << idx << std::endl;
        std::cout << std_vec[idx].idx_ << ":" << *std_vec[idx].num_
                  << std::endl;
        std::cout << ft_vec[idx].idx_ << ":" << *ft_vec[idx].num_ << std::endl;
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(begin, 10, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.begin(), 10, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(begin, 10, ary[5]) to vec(10) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin(), 10, hoge[5]);
    ft_vec.insert(ft_vec.begin(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, 10, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.begin() + 5, 10, hoge[5]);
    ft_vec.insert(ft_vec.begin() + 5, 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: insert(begin + 5, 10, ary[5]) to vec(10) after "
              "reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.begin() + 5, 10, hoge[5]);
    ft_vec.insert(ft_vec.begin() + 5, 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: insert(end, 10, ary[5]) to vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.insert(std_vec.end(), 10, hoge[5]);
    ft_vec.insert(ft_vec.end(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
    if (std_vec.max_size() != std_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "vector<Hoge>: insert(end, 10, ary[5]) to vec(10) after reserve(42)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    std_vec.reserve(42);
    ft_vec.reserve(42);
    std_vec.insert(std_vec.end(), 10, hoge[5]);
    ft_vec.insert(ft_vec.end(), 10, hoge[5]);
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // erase
  putTestInfo(test_no, "vector<Hoge>: erase(begin) from vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    if (std_vec.erase(std_vec.begin()) != std_vec.end() ||
        ft_vec.erase(ft_vec.begin()) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    if (*std_vec.erase(std_vec.begin()) != *ft_vec.erase(ft_vec.begin())) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin + 5) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    if (*std_vec.erase(std_vec.begin() + 5) !=
        *ft_vec.erase(ft_vec.begin() + 5)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin + 9) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> ft_vec(hoge_vec.begin(), hoge_vec.end());
    if (std_vec.erase(std_vec.begin() + 9) != std_vec.end() ||
        ft_vec.erase(ft_vec.begin() + 9) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin, end) from vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    if (std_vec.erase(std_vec.begin(), std_vec.end()) != std_vec.end() ||
        ft_vec.erase(ft_vec.begin(), ft_vec.end()) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin, begin) from vec(1)");
  try {
    std::vector<Hoge> std_vec(1);
    ft::vector<Hoge> ft_vec(1);
    if (*std_vec.erase(std_vec.begin(), std_vec.begin()) !=
        *ft_vec.erase(ft_vec.begin(), ft_vec.begin())) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin, begin) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    if (*std_vec.erase(std_vec.begin(), std_vec.begin()) !=
        *ft_vec.erase(ft_vec.begin(), ft_vec.begin())) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin, begin + 1) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    if (*std_vec.erase(std_vec.begin(), std_vec.begin() + 1) !=
        *ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 1)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin, begin + 5) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec(hoge, hoge + 9);
    if (*std_vec.erase(std_vec.begin(), std_vec.begin() + 5) !=
        *ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 5)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin, begin + 9) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (std_vec.erase(std_vec.begin(), std_vec.begin() + 10) != std_vec.end() ||
        ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 10) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin, end) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (std_vec.erase(std_vec.begin(), std_vec.end()) != std_vec.end() ||
        ft_vec.erase(ft_vec.begin(), ft_vec.end()) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: erase(begin + 1, begin + 1) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (*std_vec.erase(std_vec.begin() + 1, std_vec.begin() + 1) !=
        *ft_vec.erase(ft_vec.begin() + 1, ft_vec.begin() + 1)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
    if (std_vec.max_size() != std_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: erase(begin + 1, begin + 5) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (*std_vec.erase(std_vec.begin() + 1, std_vec.begin() + 5) !=
        *ft_vec.erase(ft_vec.begin() + 1, ft_vec.begin() + 5)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
    if (std_vec.max_size() != ft_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: erase(begin + 1, begin + 10) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (std_vec.erase(std_vec.begin() + 1, std_vec.begin() + 10) !=
            std_vec.end() ||
        ft_vec.erase(ft_vec.begin() + 1, ft_vec.begin() + 10) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin + 1, end) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (std_vec.erase(std_vec.begin() + 1, std_vec.end()) != std_vec.end() ||
        ft_vec.erase(ft_vec.begin() + 1, ft_vec.end()) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
    if (std_vec.max_size() != std_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  ///
  putTestInfo(test_no,
              "vector<Hoge>: erase(begin + 5, begin + 5) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (*std_vec.erase(std_vec.begin() + 5, std_vec.begin() + 5) !=
        *ft_vec.erase(ft_vec.begin() + 5, ft_vec.begin() + 5)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
    if (std_vec.max_size() != std_vec.max_size()) {
      throw std::runtime_error("max_size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: erase(begin + 5, begin + 9) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (*std_vec.erase(std_vec.begin() + 5, std_vec.begin() + 9) !=
        *ft_vec.erase(ft_vec.begin() + 5, ft_vec.begin() + 9)) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin + 5, end) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (std_vec.erase(std_vec.begin() + 5, std_vec.end()) != std_vec.end() ||
        ft_vec.erase(ft_vec.begin() + 5, ft_vec.end()) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: erase(begin + 9, end) from vec(10)");
  try {
    std::vector<Hoge> std_vec(hoge, hoge + 10);
    ft::vector<Hoge> ft_vec(hoge, hoge + 10);
    if (std_vec.erase(std_vec.begin() + 9, std_vec.end()) != std_vec.end() ||
        ft_vec.erase(ft_vec.begin() + 9, ft_vec.end()) != ft_vec.end()) {
      throw std::runtime_error("return value");
    }
    for (size_t idx = 0; idx < std_vec.size(); ++idx) {
      if (std_vec.at(idx) != ft_vec.at(idx)) {
        throw std::runtime_error("value");
      }
    }
    if (std_vec.size() != ft_vec.size() ||
        std_vec.capacity() != ft_vec.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec.size() << ", "
                << "capacity = " << std_vec.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec.size() << ", "
                << "capacity = " << ft_vec.capacity() << std::endl;
      throw std::runtime_error("size or capacity");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // swap (member)
  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector())");
  try {
    std::vector<Hoge> std_vec1, std_vec2;
    ft::vector<Hoge> ft_vec1, ft_vec2;
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(1).swap(vector(1))");
  try {
    std::vector<Hoge> std_vec1(1, hoge[0]), std_vec2(1, hoge[1]);
    ft::vector<Hoge> ft_vec1(1, hoge[0]), ft_vec2(1, hoge[1]);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector(1))");
  try {
    std::vector<Hoge> std_vec1, std_vec2(1, hoge[1]);
    ft::vector<Hoge> ft_vec1, ft_vec2(1, hoge[1]);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(1).swap(vector())");
  try {
    std::vector<Hoge> std_vec1(1, hoge[0]), std_vec2;
    ft::vector<Hoge> ft_vec1(1, hoge[0]), ft_vec2;
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "hoge" << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector(10))");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector(5))");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend() - 5);
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend() - 5);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector(1))");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()), std_vec2(1);
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()), ft_vec2(1);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector())");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()), std_vec2;
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()), ft_vec2;
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(5).swap(vector(10))");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin() + 5, hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(hoge_vec.begin() + 5, hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(1).swap(vector(10))");
  try {
    std::vector<Hoge> std_vec1(1), std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(1), ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector(10))");
  try {
    std::vector<Hoge> std_vec1, std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1, ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // swap (non member)
  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector())");
  try {
    std::vector<Hoge> std_vec1, std_vec2;
    ft::vector<Hoge> ft_vec1, ft_vec2;
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(1).swap(vector(1))");
  try {
    std::vector<Hoge> std_vec1(1, hoge[0]), std_vec2(1, hoge[1]);
    ft::vector<Hoge> ft_vec1(1, hoge[0]), ft_vec2(1, hoge[1]);
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector(1))");
  try {
    std::vector<Hoge> std_vec1, std_vec2(1, hoge[1]);
    ft::vector<Hoge> ft_vec1, ft_vec2(1, hoge[1]);
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(1).swap(vector())");
  try {
    std::vector<Hoge> std_vec1(1, hoge[0]), std_vec2;
    ft::vector<Hoge> ft_vec1(1, hoge[0]), ft_vec2;
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector(10))");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector(5))");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend() - 5);
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend() - 5);
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector(1))");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()), std_vec2(1);
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()), ft_vec2(1);
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector())");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()), std_vec2;
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()), ft_vec2;
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(5).swap(vector(10))");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin() + 5, hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(hoge_vec.begin() + 5, hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(1).swap(vector(10))");
  try {
    std::vector<Hoge> std_vec1(1), std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(1), ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector(10))");
  try {
    std::vector<Hoge> std_vec1, std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1, ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    std::swap(std_vec1, std_vec2);
    ft::swap(ft_vec1, ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // swap (member with reserve)
  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector()) reserve1(10)");
  try {
    std::vector<Hoge> std_vec1, std_vec2;
    ft::vector<Hoge> ft_vec1, ft_vec2;
    std_vec1.reserve(10);
    ft_vec1.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector()) reserve2(10)");
  try {
    std::vector<Hoge> std_vec1, std_vec2;
    ft::vector<Hoge> ft_vec1, ft_vec2;
    std_vec2.reserve(10);
    ft_vec2.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector(1)) reserve1(10)");
  try {
    std::vector<Hoge> std_vec1, std_vec2(1);
    ft::vector<Hoge> ft_vec1, ft_vec2(1);
    std_vec1.reserve(10);
    ft_vec1.reserve(10);
    // std::cout << std::endl;
    // std::cout << "ptr1 = " << &*std_vec1.begin() << std::endl;
    // std::cout << "ptr2 = " << &*std_vec2.begin() << std::endl;
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    // std::cout << std::endl;
    // std::cout << "ptr1 = " << &*std_vec1.begin() << std::endl;
    // std::cout << "ptr2 = " << &*std_vec2.begin() << std::endl;
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector(1)) reserve2(10)");
  try {
    std::vector<Hoge> std_vec1, std_vec2(1);
    ft::vector<Hoge> ft_vec1, ft_vec2(1);
    std_vec2.reserve(10);
    ft_vec2.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(1).swap(vector(1)) reserve1(10)");
  try {
    std::vector<Hoge> std_vec1, std_vec2(1);
    ft::vector<Hoge> ft_vec1, ft_vec2(1);
    std_vec1.reserve(10);
    ft_vec1.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(1).swap(vector(1)) reserve2(10)");
  try {
    std::vector<Hoge> std_vec1, std_vec2(1);
    ft::vector<Hoge> ft_vec1, ft_vec2(1);
    std_vec2.reserve(10);
    ft_vec2.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector(5)) reserve1(10)");
  try {
    std::vector<Hoge> std_vec1, std_vec2(5);
    ft::vector<Hoge> ft_vec1, ft_vec2(5);
    std_vec1.reserve(10);
    ft_vec1.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector().swap(vector(5)) reserve2(10)");
  try {
    std::vector<Hoge> std_vec1, std_vec2(5);
    ft::vector<Hoge> ft_vec1, ft_vec2(5);
    std_vec2.reserve(10);
    ft_vec2.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(5).swap(vector(5)) reserve1(10)");
  try {
    std::vector<Hoge> std_vec1(5), std_vec2(5);
    ft::vector<Hoge> ft_vec1(5), ft_vec2(5);
    std_vec1.reserve(10);
    ft_vec1.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(5).swap(vector(5)) reserve2(10)");
  try {
    std::vector<Hoge> std_vec1(5), std_vec2(5);
    ft::vector<Hoge> ft_vec1(5), ft_vec2(5);
    std_vec2.reserve(10);
    ft_vec2.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(5).swap(vector(10)) reserve1(10)");
  try {
    std::vector<Hoge> std_vec1(5), std_vec2(10);
    ft::vector<Hoge> ft_vec1(5), ft_vec2(10);
    std_vec1.reserve(10);
    ft_vec1.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(5).swap(vector(10)) reserve2(10)");
  try {
    std::vector<Hoge> std_vec1(5), std_vec2(10);
    ft::vector<Hoge> ft_vec1(5), ft_vec2(10);
    std_vec2.reserve(10);
    ft_vec2.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector(5)) reserve1(10)");
  try {
    std::vector<Hoge> std_vec1(10), std_vec2(10);
    ft::vector<Hoge> ft_vec1(10), ft_vec2(10);
    std_vec1.reserve(10);
    ft_vec1.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: vector(10).swap(vector(5)) reserve2(10)");
  try {
    std::vector<Hoge> std_vec1(10), std_vec2(10);
    ft::vector<Hoge> ft_vec1(10), ft_vec2(10);
    std_vec2.reserve(10);
    ft_vec2.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: vector(10).swap(vector(10)) reserve1(10)");
  try {
    std::vector<Hoge> std_vec1(10), std_vec2(10);
    ft::vector<Hoge> ft_vec1(10), ft_vec2(10);
    std_vec1.reserve(10);
    ft_vec1.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: vector(10).swap(vector(10)) reserve2(10)");
  try {
    std::vector<Hoge> std_vec1(10), std_vec2(10);
    ft::vector<Hoge> ft_vec1(10), ft_vec2(10);
    std_vec2.reserve(10);
    ft_vec2.reserve(10);
    std_vec1.swap(std_vec2);
    ft_vec1.swap(ft_vec2);
    for (size_t idx = 0; idx < std_vec1.size(); ++idx) {
      if (std_vec1.at(idx) != ft_vec1.at(idx)) {
        throw std::runtime_error("value 1");
      }
    }
    for (size_t idx = 0; idx < std_vec2.size(); ++idx) {
      if (std_vec2.at(idx) != ft_vec2.at(idx)) {
        throw std::runtime_error("value 2");
      }
    }
    if (std_vec1.size() != ft_vec1.size() ||
        std_vec1.capacity() != ft_vec1.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec1.size() << ", "
                << "capacity = " << std_vec1.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec1.size() << ", "
                << "capacity = " << ft_vec1.capacity() << std::endl;
      throw std::runtime_error("size or capacity 1");
    }
    if (std_vec2.size() != ft_vec2.size() ||
        std_vec2.capacity() != ft_vec2.capacity()) {
      std::cout << std::endl;
      std::cout << "std: size = " << std_vec2.size() << ", "
                << "capacity = " << std_vec2.capacity() << std::endl;
      std::cout << "ft: size = " << ft_vec2.size() << ", "
                << "capacity = " << ft_vec2.capacity() << std::endl;
      throw std::runtime_error("size or capacity 2");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: compare by operators vec() with vec()");
  try {
    std::vector<Hoge> std_vec1, std_vec2;
    ft::vector<Hoge> ft_vec1, ft_vec2;
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: compare by operators vec() with vec(1)");
  try {
    std::vector<Hoge> std_vec1, std_vec2(1);
    ft::vector<Hoge> ft_vec1, ft_vec2(1);
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<Hoge>: compare by operators vec(1) with vec()");
  try {
    std::vector<Hoge> std_vec1(1), std_vec2;
    ft::vector<Hoge> ft_vec1(1), ft_vec2;
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: compare by operators vec(1, 1) with vec(1, 1)");
  try {
    std::vector<Hoge> std_vec1(1, hoge[1]), std_vec2(1, hoge[1]);
    ft::vector<Hoge> ft_vec1(1, hoge[1]), ft_vec2(1, hoge[1]);
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: compare by operators vec(1, 1) with vec(1, 2)");
  try {
    std::vector<Hoge> std_vec1(1, hoge[1]), std_vec2(1, hoge[2]);
    ft::vector<Hoge> ft_vec1(1, hoge[1]), ft_vec2(1, hoge[2]);
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: compare by operators vec(0~9) with vec(0~9)");
  try {
    std::vector<Hoge> std_vec1(hoge, hoge + 9), std_vec2(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec1(hoge, hoge + 9), ft_vec2(hoge, hoge + 9);
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: compare by operators vec(0~5) with vec(0~9)");
  try {
    std::vector<Hoge> std_vec1(hoge, hoge + 5), std_vec2(hoge, hoge + 9);
    ft::vector<Hoge> ft_vec1(hoge, hoge + 5), ft_vec2(hoge, hoge + 9);
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: compare by operators vec(0~9) with vec(0~5)");
  try {
    std::vector<Hoge> std_vec1(hoge, hoge + 9), std_vec2(hoge, hoge + 5);
    ft::vector<Hoge> ft_vec1(hoge, hoge + 9), ft_vec2(hoge, hoge + 5);
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: compare by operators vec(0~9) with vec(9~0)");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: compare by operators vec(0~4) with vec(9~0)");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin() + 4, hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(hoge_vec.begin() + 4, hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "vector<Hoge>: compare by operators vec(0~9) with vec(9~5)");
  try {
    std::vector<Hoge> std_vec1(hoge_vec.begin(), hoge_vec.end()),
        std_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    ft::vector<Hoge> ft_vec1(hoge_vec.begin(), hoge_vec.end()),
        ft_vec2(hoge_vec.rbegin(), hoge_vec.rend());
    if ((std_vec1 == std_vec2) != (ft_vec1 == ft_vec2)) {
      throw std::runtime_error("operator==");
    }
    if ((std_vec1 != std_vec2) != (ft_vec1 != ft_vec2)) {
      throw std::runtime_error("operator!=");
    }
    if ((std_vec1 > std_vec2) != (ft_vec1 > ft_vec2)) {
      throw std::runtime_error("operator>");
    }
    if ((std_vec1 < std_vec2) != (ft_vec1 < ft_vec2)) {
      throw std::runtime_error("operator<");
    }
    if ((std_vec1 >= std_vec2) != (ft_vec1 >= ft_vec2)) {
      throw std::runtime_error("operator>=");
    }
    if ((std_vec1 <= std_vec2) != (ft_vec1 <= ft_vec2)) {
      throw std::runtime_error("operator<=");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "assign using ft::iterator");
  try {
    ft::vector<Hoge> vec1(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> vec2;
    vec2.assign(vec1.begin(), vec1.end());
    ft::vector<Hoge>::iterator itr1;
    ft::vector<Hoge>::iterator itr2;
    for (itr1 = vec1.begin(), itr2 = vec2.begin(); itr1 != vec1.end();
         ++itr1, ++itr2) {
      if (*itr1 != *itr2) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "construct using ft::iterator");
  try {
    ft::vector<Hoge> vec1(hoge_vec.begin(), hoge_vec.end());
    ft::vector<Hoge> vec2;
    vec2.assign(vec1.begin(), vec1.end());
    ft::vector<Hoge>::iterator itr1;
    ft::vector<Hoge>::iterator itr2;
    for (itr1 = vec1.begin(), itr2 = vec2.begin(); itr1 != vec1.end();
         ++itr1, ++itr2) {
      if (*itr1 != *itr2) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "construct using ft::iterator");
  try {
    int n;
    std::vector<int> std_vec;
    ft::vector<int> ft_vec;
    std::vector<int>::iterator std_itr;
    ft::vector<int>::iterator ft_itr;
    std::vector<int>::reverse_iterator std_ritr;
    ft::vector<int>::reverse_iterator ft_ritr;
    std::vector<int>::const_iterator std_citr;
    ft::vector<int>::const_iterator ft_citr;
    std::vector<int>::const_reverse_iterator std_critr;
    ft::vector<int>::const_reverse_iterator ft_critr;

    for (int i = 0; i < 1000; i++) {
      n = rand() % 1000;
      std_vec.push_back(n);
      ft_vec.push_back(n);
    }

    for (std_itr = std_vec.begin(), ft_itr = ft_vec.begin();
         std_itr != std_vec.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_itr != ft_vec.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_ritr = std_vec.rbegin(), ft_ritr = ft_vec.rbegin();
         std_ritr != std_vec.rend(); ++std_ritr, ++ft_ritr) {
      if (*std_ritr != *ft_ritr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_ritr != ft_vec.rend()) {
      throw std::runtime_error("rev iterator");
    }

    for (std_citr = std_vec.begin(), ft_citr = ft_vec.begin();
         std_citr != std_vec.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_citr != ft_vec.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_critr = std_vec.rbegin(), ft_critr = ft_vec.rbegin();
         std_critr != std_vec.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_critr != ft_vec.rend()) {
      throw std::runtime_error("rev iterator");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "vector<int>: const");
  try {
    int num[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
    const std::vector<int> std_vec(num, num + 10);
    const ft::vector<int> ft_vec(num, num + 10);
    std::vector<int>::const_iterator std_citr;
    ft::vector<int>::const_iterator ft_citr;
    std::vector<int>::const_reverse_iterator std_critr;
    ft::vector<int>::const_reverse_iterator ft_critr;

    for (int i = 0; i < 10; i++) {
      if (std_vec[i] != ft_vec[i]) {
        throw std::runtime_error("reference");
      }
    }

    for (std_citr = std_vec.begin(), ft_citr = ft_vec.begin();
         std_citr != std_vec.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_citr != ft_vec.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_critr = std_vec.rbegin(), ft_critr = ft_vec.rbegin();
         std_critr != std_vec.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_critr != ft_vec.rend()) {
      throw std::runtime_error("rev iterator");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
