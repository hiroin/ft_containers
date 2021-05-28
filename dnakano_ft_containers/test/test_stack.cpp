/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:26:10 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/17 17:37:56 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include "list.hpp"
#include "stack.hpp"
#include "test.hpp"
#include "vector.hpp"

void test_stack(int& test_no) {
  int num[10] = {0, 1, 2, 3, 42, 5, 6, 7, 8, 9};
  Hoge hoge[10] = {Hoge(0, 0), Hoge(1, 1), Hoge(2, 2), Hoge(3, 3), Hoge(4, 4),
                   Hoge(5, 5), Hoge(6, 6), Hoge(7, 7), Hoge(8, 8), Hoge(9, 9)};

  std::cout << "=== TEST STACK ===" << std::endl;

  // vector int
  putTestInfo(test_no, "stack<int, vector>: push 10 times");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, vector>: push 10 times, pop 10 times");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    if (std_stk.empty() != ft_stk.empty() ||
        std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, vector>: 20push 9pop 4push 10pop 50push");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 20; i++) {
      std_stk.push(num[i % 10]);
      ft_stk.push(num[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 9; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    for (int i = 0; i < 4; i++) {
      std_stk.push(num[i % 10]);
      ft_stk.push(num[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 9; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    for (int i = 0; i < 50; i++) {
      std_stk.push(num[i % 10]);
      ft_stk.push(num[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    if (std_stk.empty() != ft_stk.empty() ||
        std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, vector>: comp 0 and 0");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    std::stack<int, std::vector<int> > std_stk2;
    ft::stack<int, ft::vector<int> > ft_stk2;
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, vector>: comp 0 and 10");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    std::stack<int, std::vector<int> > std_stk2;
    ft::stack<int, ft::vector<int> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, vector>: comp 10 and 0");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    std::stack<int, std::vector<int> > std_stk2;
    ft::stack<int, ft::vector<int> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk2.push(num[i]);
      ft_stk2.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, vector>: comp 5 and 10");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    std::stack<int, std::vector<int> > std_stk2;
    ft::stack<int, ft::vector<int> > ft_stk2;
    for (int i = 0; i < 5; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
    }
    for (int i = 0; i < 10; i++) {
      std_stk2.push(num[i]);
      ft_stk2.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, vector>: comp 10 and 5");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    std::stack<int, std::vector<int> > std_stk2;
    ft::stack<int, ft::vector<int> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
    }
    for (int i = 0; i < 5; i++) {
      std_stk2.push(num[i]);
      ft_stk2.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, vector>: comp 10 and 10");
  try {
    std::stack<int, std::vector<int> > std_stk;
    ft::stack<int, ft::vector<int> > ft_stk;
    std::stack<int, std::vector<int> > std_stk2;
    ft::stack<int, ft::vector<int> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
    }
    for (int i = 0; i < 10; i++) {
      std_stk2.push(num[i]);
      ft_stk2.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }

  // list int
  putTestInfo(test_no, "stack<int, list>: push 10 times");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, list>: push 10 times, pop 10 times");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    if (std_stk.empty() != ft_stk.empty() ||
        std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, list>: 20push 9pop 4push 10pop 50push");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 20; i++) {
      std_stk.push(num[i % 10]);
      ft_stk.push(num[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 9; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    for (int i = 0; i < 4; i++) {
      std_stk.push(num[i % 10]);
      ft_stk.push(num[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 9; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    for (int i = 0; i < 50; i++) {
      std_stk.push(num[i % 10]);
      ft_stk.push(num[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    if (std_stk.empty() != ft_stk.empty() ||
        std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, list>: comp 0 and 0");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    std::stack<int, std::list<int> > std_stk2;
    ft::stack<int, ft::list<int> > ft_stk2;
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, list>: comp 0 and 10");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    std::stack<int, std::list<int> > std_stk2;
    ft::stack<int, ft::list<int> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, list>: comp 10 and 0");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    std::stack<int, std::list<int> > std_stk2;
    ft::stack<int, ft::list<int> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk2.push(num[i]);
      ft_stk2.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, list>: comp 5 and 10");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    std::stack<int, std::list<int> > std_stk2;
    ft::stack<int, ft::list<int> > ft_stk2;
    for (int i = 0; i < 5; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
    }
    for (int i = 0; i < 10; i++) {
      std_stk2.push(num[i]);
      ft_stk2.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, list>: comp 10 and 5");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    std::stack<int, std::list<int> > std_stk2;
    ft::stack<int, ft::list<int> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
    }
    for (int i = 0; i < 5; i++) {
      std_stk2.push(num[i]);
      ft_stk2.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<int, list>: comp 10 and 10");
  try {
    std::stack<int, std::list<int> > std_stk;
    ft::stack<int, ft::list<int> > ft_stk;
    std::stack<int, std::list<int> > std_stk2;
    ft::stack<int, ft::list<int> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(num[i]);
      ft_stk.push(num[i]);
    }
    for (int i = 0; i < 10; i++) {
      std_stk2.push(num[i]);
      ft_stk2.push(num[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  // vector Hoge
  putTestInfo(test_no, "stack<Hoge, vector>: push 10 times");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, vector>: push 10 times, pop 10 times");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    if (std_stk.empty() != ft_stk.empty() ||
        std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, vector>: 20push 9pop 4push 10pop 50push");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 20; i++) {
      std_stk.push(hoge[i % 10]);
      ft_stk.push(hoge[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 9; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    for (int i = 0; i < 4; i++) {
      std_stk.push(hoge[i % 10]);
      ft_stk.push(hoge[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 9; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    for (int i = 0; i < 50; i++) {
      std_stk.push(hoge[i % 10]);
      ft_stk.push(hoge[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    if (std_stk.empty() != ft_stk.empty() ||
        std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, vector>: comp 0 and 0");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    std::stack<Hoge, std::vector<Hoge> > std_stk2;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk2;
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, vector>: comp 0 and 10");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    std::stack<Hoge, std::vector<Hoge> > std_stk2;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, vector>: comp 10 and 0");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    std::stack<Hoge, std::vector<Hoge> > std_stk2;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk2.push(hoge[i]);
      ft_stk2.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, vector>: comp 5 and 10");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    std::stack<Hoge, std::vector<Hoge> > std_stk2;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk2;
    for (int i = 0; i < 5; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
    }
    for (int i = 0; i < 10; i++) {
      std_stk2.push(hoge[i]);
      ft_stk2.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, vector>: comp 10 and 5");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    std::stack<Hoge, std::vector<Hoge> > std_stk2;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
    }
    for (int i = 0; i < 5; i++) {
      std_stk2.push(hoge[i]);
      ft_stk2.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, vector>: comp 10 and 10");
  try {
    std::stack<Hoge, std::vector<Hoge> > std_stk;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk;
    std::stack<Hoge, std::vector<Hoge> > std_stk2;
    ft::stack<Hoge, ft::vector<Hoge> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
    }
    for (int i = 0; i < 10; i++) {
      std_stk2.push(hoge[i]);
      ft_stk2.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }

  // list Hoge
  putTestInfo(test_no, "stack<Hoge, list>: push 10 times");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, list>: push 10 times, pop 10 times");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    if (std_stk.empty() != ft_stk.empty() ||
        std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, list>: 20push 9pop 4push 10pop 50push");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    if (std_stk.empty() != ft_stk.empty() || std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
    for (int i = 0; i < 20; i++) {
      std_stk.push(hoge[i % 10]);
      ft_stk.push(hoge[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 9; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    for (int i = 0; i < 4; i++) {
      std_stk.push(hoge[i % 10]);
      ft_stk.push(hoge[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    for (int i = 0; i < 9; i++) {
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
      std_stk.pop();
      ft_stk.pop();
    }
    for (int i = 0; i < 50; i++) {
      std_stk.push(hoge[i % 10]);
      ft_stk.push(hoge[i % 10]);
      if (std_stk.top() != std_stk.top()) {
        std::runtime_error("top");
      }
      if (std_stk.empty() != ft_stk.empty() ||
          std_stk.size() != ft_stk.size()) {
        std::runtime_error("size");
      }
    }
    if (std_stk.empty() != ft_stk.empty() ||
        std_stk.size() != ft_stk.size()) {
      std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, list>: comp 0 and 0");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    std::stack<Hoge, std::list<Hoge> > std_stk2;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk2;
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, list>: comp 0 and 10");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    std::stack<Hoge, std::list<Hoge> > std_stk2;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, list>: comp 10 and 0");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    std::stack<Hoge, std::list<Hoge> > std_stk2;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk2.push(hoge[i]);
      ft_stk2.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, list>: comp 5 and 10");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    std::stack<Hoge, std::list<Hoge> > std_stk2;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk2;
    for (int i = 0; i < 5; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
    }
    for (int i = 0; i < 10; i++) {
      std_stk2.push(hoge[i]);
      ft_stk2.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, list>: comp 10 and 5");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    std::stack<Hoge, std::list<Hoge> > std_stk2;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
    }
    for (int i = 0; i < 5; i++) {
      std_stk2.push(hoge[i]);
      ft_stk2.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "stack<Hoge, list>: comp 10 and 10");
  try {
    std::stack<Hoge, std::list<Hoge> > std_stk;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk;
    std::stack<Hoge, std::list<Hoge> > std_stk2;
    ft::stack<Hoge, ft::list<Hoge> > ft_stk2;
    for (int i = 0; i < 10; i++) {
      std_stk.push(hoge[i]);
      ft_stk.push(hoge[i]);
    }
    for (int i = 0; i < 10; i++) {
      std_stk2.push(hoge[i]);
      ft_stk2.push(hoge[i]);
    }
    if ((std_stk == std_stk2) != (ft_stk == ft_stk2) ||
    (std_stk != std_stk2) != (ft_stk != ft_stk2) ||
    (std_stk <= std_stk2) != (ft_stk <= ft_stk2) ||
    (std_stk < std_stk2) != (ft_stk < ft_stk2) ||
    (std_stk > std_stk2) != (ft_stk > ft_stk2) ||
    (std_stk >= std_stk2) != (ft_stk >= ft_stk2)) {
      throw std::runtime_error("relational");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;
  return;
}
