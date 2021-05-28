/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:37:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/03/03 18:39:11 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

#include "../map.hpp"
#include "Hoge.hpp"
#include "test.hpp"

void test_map(int& test_no) {
  std::cout << "=== TEST MAP ===" << std::endl;
  std::pair<int, std::string> persons[10] = {
      std::pair<int, std::string>(7, "dnakano"),
      std::pair<int, std::string>(2, "nop"),
      std::pair<int, std::string>(4, "bunjiro"),
      std::pair<int, std::string>(0, "deedee"),
      std::pair<int, std::string>(9, "sataharu"),
      std::pair<int, std::string>(8, "marvin"),
      std::pair<int, std::string>(5, "hoge"),
      std::pair<int, std::string>(1, "fuga"),
      std::pair<int, std::string>(6, "foobar"),
      std::pair<int, std::string>(3, "norminette")};
  std::map<int, std::string> persons_map(persons, persons + 10);

  std::pair<int, std::string> persons_sorted[10] = {
      std::pair<int, std::string>(0, "dnakano"),
      std::pair<int, std::string>(1, "nop"),
      std::pair<int, std::string>(2, "bunjiro"),
      std::pair<int, std::string>(3, "deedee"),
      std::pair<int, std::string>(4, "sataharu"),
      std::pair<int, std::string>(5, "marvin"),
      std::pair<int, std::string>(6, "hoge"),
      std::pair<int, std::string>(7, "fuga"),
      std::pair<int, std::string>(8, "foobar"),
      std::pair<int, std::string>(9, "norminette")};
  std::map<int, std::string> persons_sorted_map(persons_sorted,
                                                persons_sorted + 10);

  std::pair<int, std::string> persons_revsorted[10] = {
      std::pair<int, std::string>(9, "dnakano"),
      std::pair<int, std::string>(8, "nop"),
      std::pair<int, std::string>(7, "bunjiro"),
      std::pair<int, std::string>(6, "deedee"),
      std::pair<int, std::string>(5, "sataharu"),
      std::pair<int, std::string>(4, "marvin"),
      std::pair<int, std::string>(3, "hoge"),
      std::pair<int, std::string>(2, "fuga"),
      std::pair<int, std::string>(1, "foobar"),
      std::pair<int, std::string>(0, "norminette")};
  std::map<int, std::string> persons_revsorted_map(persons_revsorted,
                                                   persons_revsorted + 10);

  std::pair<Hoge, Hoge> hoges[10] = {
      std::pair<Hoge, Hoge>(Hoge(0, 7), Hoge(0, 0)),
      std::pair<Hoge, Hoge>(Hoge(1, 2), Hoge(1, 1)),
      std::pair<Hoge, Hoge>(Hoge(2, 4), Hoge(2, 2)),
      std::pair<Hoge, Hoge>(Hoge(3, 0), Hoge(3, 3)),
      std::pair<Hoge, Hoge>(Hoge(4, 9), Hoge(4, 4)),
      std::pair<Hoge, Hoge>(Hoge(5, 8), Hoge(5, 5)),
      std::pair<Hoge, Hoge>(Hoge(6, 5), Hoge(6, 6)),
      std::pair<Hoge, Hoge>(Hoge(7, 1), Hoge(7, 7)),
      std::pair<Hoge, Hoge>(Hoge(8, 6), Hoge(8, 8)),
      std::pair<Hoge, Hoge>(Hoge(9, 3), Hoge(9, 9))};
  std::map<Hoge, Hoge> hoges_map(hoges, hoges + 10);

  std::pair<Hoge, Hoge> fugas[10] = {
      std::pair<Hoge, Hoge>(Hoge(0, 0), Hoge(0, 5)),
      std::pair<Hoge, Hoge>(Hoge(1, 1), Hoge(1, 1)),
      std::pair<Hoge, Hoge>(Hoge(2, 2), Hoge(2, 5)),
      std::pair<Hoge, Hoge>(Hoge(3, 3), Hoge(3, 589)),
      std::pair<Hoge, Hoge>(Hoge(4, 4), Hoge(4, 4)),
      std::pair<Hoge, Hoge>(Hoge(5, 5), Hoge(5, 43)),
      std::pair<Hoge, Hoge>(Hoge(6, 6), Hoge(6, 6)),
      std::pair<Hoge, Hoge>(Hoge(7, 7), Hoge(7, 45)),
      std::pair<Hoge, Hoge>(Hoge(8, 8), Hoge(8, 8)),
      std::pair<Hoge, Hoge>(Hoge(9, 9), Hoge(9, 24))};
  std::map<Hoge, Hoge> fugas_map(fugas, fugas + 10);

  putTestInfo(test_no, "map<int, string>: default construction");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error("failed");
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons[0]);
    ft_map.insert(persons[0]);
    if (std_map[7] != ft_map[7]) {
      throw std::runtime_error("value");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 2 to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons[0]);
    ft_map.insert(persons[0]);
    std_map.insert(persons[1]);
    ft_map.insert(persons[1]);
    if (std_map[7] != ft_map[7]) {
      throw std::runtime_error("value");
    }
    if (std_map[2] != ft_map[2]) {
      throw std::runtime_error("value");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_res = std_map.insert(persons[i]);
      ft_res = ft_map.insert(persons[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 sorted to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_res = std_map.insert(persons_sorted[i]);
      ft_res = ft_map.insert(persons_sorted[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 reverse_sorted to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_res = std_map.insert(persons_revsorted[i]);
      ft_res = ft_map.insert(persons_revsorted[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert 10 and sorted to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_res = std_map.insert(persons[i]);
      ft_res = ft_map.insert(persons[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
      std_res = std_map.insert(persons_sorted[i]);
      ft_res = ft_map.insert(persons_sorted[i]);
      if (*std_res.first != *ft_res.first || std_res.second != ft_res.second) {
        throw std::runtime_error("return value");
      }
    }
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert 10 to map(0)");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    std::pair<std::map<Hoge, Hoge>::iterator, bool> std_res;
    std::pair<ft::map<Hoge, Hoge>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map.insert(hoges[i]);
      ft_map.insert(hoges[i]);
      std_map.insert(fugas[i]);
      ft_map.insert(fugas[i]);
    }
    std_map[Hoge(42, 42)];
    ft_map[Hoge(42, 42)];
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[Hoge(42, 42)] != ft_map[Hoge(42, 42)] ||
        std_map[Hoge(-42, -42)] != ft_map[Hoge(-42, -42)]) {
      throw std::runtime_error("value");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert 10 and 10 to map(0)");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    std::pair<std::map<Hoge, Hoge>::iterator, bool> std_res;
    std::pair<ft::map<Hoge, Hoge>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map.insert(hoges[i]);
      ft_map.insert(hoges[i]);
    }
    std_map[Hoge(42, 42)];
    ft_map[Hoge(42, 42)];
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[Hoge(42, 42)] != ft_map[Hoge(42, 42)] ||
        std_map[Hoge(-42, -42)] != ft_map[Hoge(-42, -42)]) {
      throw std::runtime_error("value");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: operator[0..9] to map(0)");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map[persons[i].first] = persons[i].second;
      ft_map[persons[i].first] = persons[i].second;
    }
    std_map[42];
    ft_map[42];
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[42] != ft_map[42] || std_map[-42] != ft_map[-42]) {
      throw std::runtime_error("value");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: operator[0..9] to map(0) case 2");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;
    std::pair<std::map<int, std::string>::iterator, bool> std_res;
    std::pair<ft::map<int, std::string>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map[persons[i].first] = persons[i].second;
      ft_map[persons[i].first] = persons[i].second;
      std_map[persons_sorted[i].first] = persons_sorted[i].second;
      ft_map[persons_sorted[i].first] = persons_sorted[i].second;
    }
    std_map[42];
    ft_map[42];
    for (int i = 0; i < 10; i++) {
      if (std_map[i] != ft_map[i]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[42] != ft_map[42] || std_map[-42] != ft_map[-42]) {
      throw std::runtime_error("value");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: operator[0..9] to map(0)");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    std::pair<std::map<Hoge, Hoge>::iterator, bool> std_res;
    std::pair<ft::map<Hoge, Hoge>::iterator, bool> ft_res;

    for (int i = 0; i < 10; i++) {
      std_map[hoges[i].first] = hoges[i].second;
      ft_map[hoges[i].first] = hoges[i].second;
      std_map[fugas[i].first] = fugas[i].second;
      ft_map[fugas[i].first] = fugas[i].second;
    }
    std_map[Hoge(42, 42)];
    ft_map[Hoge(42, 42)];
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map[Hoge(42, 42)] != ft_map[Hoge(42, 42)] ||
        std_map[Hoge(-42, -42)] != ft_map[Hoge(-42, -42)]) {
      throw std::runtime_error("value");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // insert(range)
  putTestInfo(test_no, "map<int, string>: insert(0 ~ 10) with array");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons, persons + 10);
    ft_map.insert(persons, persons + 10);
    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert(0 ~ 10) twice with array");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons_sorted, persons_sorted + 10);
    ft_map.insert(persons_sorted, persons_sorted + 10);
    std_map.insert(persons, persons + 10);
    ft_map.insert(persons, persons + 10);
    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert(0 ~ 10) with map itr");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons_map.begin(), persons_map.end());
    ft_map.insert(persons_map.begin(), persons_map.end());
    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: insert(0 ~ 10) with map itr");
  try {
    std::map<int, std::string> std_map;
    ft::map<int, std::string> ft_map;

    std_map.insert(persons_map.begin(), persons_map.end());
    ft_map.insert(persons_map.begin(), persons_map.end());
    std_map.insert(persons_sorted_map.begin(), persons_sorted_map.end());
    ft_map.insert(persons_sorted_map.begin(), persons_sorted_map.end());
    std_map.insert(persons_revsorted_map.begin(), persons_revsorted_map.end());
    ft_map.insert(persons_revsorted_map.begin(), persons_revsorted_map.end());
    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert(0 ~ 10) with array");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;

    std_map.insert(hoges, hoges + 10);
    ft_map.insert(hoges, hoges + 10);
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert(0 ~ 10) with map itr");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;

    std_map.insert(hoges_map.begin(), hoges_map.end());
    ft_map.insert(hoges_map.begin(), hoges_map.end());
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: insert(0 ~ 10) with map itr");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;

    std_map.insert(hoges_map.begin(), hoges_map.end());
    ft_map.insert(hoges_map.begin(), hoges_map.end());
    std_map.insert(fugas_map.begin(), fugas_map.end());
    ft_map.insert(fugas_map.begin(), fugas_map.end());
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  // fill constructor
  putTestInfo(test_no, "map<int, string>: map(0 ~ 10) with array");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);

    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: map(0 ~ 10) with itr");
  try {
    std::map<int, std::string> std_map(persons_revsorted_map.begin(),
                                       persons_revsorted_map.end());
    ft::map<int, std::string> ft_map(persons_revsorted_map.begin(),
                                     persons_revsorted_map.end());

    for (int i = 0; i < 10; i++) {
      if (std_map[persons[i].first] != ft_map[persons[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: range construction with array");
  try {
    std::map<Hoge, Hoge> std_map(fugas, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(fugas, fugas + 10);

    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: range construction with mapitr");
  try {
    std::map<Hoge, Hoge> std_map(fugas_map.begin(), fugas_map.end());
    ft::map<Hoge, Hoge> ft_map(fugas_map.begin(), fugas_map.end());

    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(10) = map(10) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    std::map<Hoge, Hoge> std_map2(fugas, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map2(fugas, fugas + 10);

    for (int i = 0; i < 10; i++) {
      // std::cout << "std[" << hoges[i].first << "] = " <<
      // std_map[hoges[i].first]
      //           << " ft[" << hoges[i].first << "] = " <<
      //           ft_map[hoges[i].first]
      //           << std::endl;
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    std_map = std_map2;
    ft_map = ft_map2;
    for (int i = 0; i < 10; i++) {
      // std::cout << "std[" << hoges[i].first << "] = " <<
      // std_map[hoges[i].first]
      //           << " ft[" << hoges[i].first << "] = " <<
      //           ft_map[hoges[i].first]
      //           << std::endl;
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(10) = map(5) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    std::map<Hoge, Hoge> std_map2(fugas, fugas + 5);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map2(fugas, fugas + 5);

    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    std_map = std_map2;
    ft_map = ft_map2;
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5) = map(10) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 5);
    std::map<Hoge, Hoge> std_map2(fugas, fugas + 10);
    std::map<Hoge, Hoge> ft_map(hoges, hoges + 5);
    std::map<Hoge, Hoge> ft_map2(fugas, fugas + 10);

    for (int i = 0; i < 5; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    std_map = std_map2;
    ft_map = ft_map2;
    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(10) = map(10) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);

    for (int i = 0; i < 10; i++) {
      if (std_map[hoges[i].first] != ft_map[hoges[i].first]) {
        throw std::runtime_error("value");
      }
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, int>: value_comp");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);
    std::map<int, std::string>::value_compare comp_std = std_map.value_comp();
    ft::map<int, std::string>::value_compare comp_ft = ft_map.value_comp();

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (comp_std(persons[i], persons[j]) !=
                comp_ft(persons[i], persons[j]) ||
            comp_std(persons[j], persons[i]) != comp_ft(persons[j], persons[i]))
          throw std::runtime_error("comp");
      }
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, int>: value_comp to ref");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);
    const std::map<int, std::string>::value_compare& comp_std =
        std_map.value_comp();
    const ft::map<int, std::string>::value_compare& comp_ft =
        ft_map.value_comp();

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (comp_std(persons[i], persons[j]) !=
                comp_ft(persons[i], persons[j]) ||
            comp_std(persons[j], persons[i]) != comp_ft(persons[j], persons[i]))
          throw std::runtime_error("comp");
      }
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge>: value_comp");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    std::map<Hoge, Hoge>::value_compare comp_std = std_map.value_comp();
    ft::map<Hoge, Hoge>::value_compare comp_ft = ft_map.value_comp();

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (comp_std(hoges[i], hoges[j]) != comp_ft(hoges[i], hoges[j]) ||
            comp_std(hoges[j], hoges[i]) != comp_ft(hoges[j], hoges[i]))
          throw std::runtime_error("comp");
      }
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge>: value_comp");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    const std::map<Hoge, Hoge>::value_compare& comp_std = std_map.value_comp();
    ft::map<Hoge, Hoge>::value_compare comp_ft = ft_map.value_comp();

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (comp_std(hoges[i], hoges[j]) != comp_ft(hoges[i], hoges[j]) ||
            comp_std(hoges[j], hoges[i]) != comp_ft(hoges[j], hoges[i]))
          throw std::runtime_error("comp");
      }
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  // check iterator
  putTestInfo(test_no, "map<int, string>: map(0 ~ 10) and check by iter");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);
    std::map<int, std::string>::iterator std_itr;
    ft::map<int, std::string>::iterator ft_itr;

    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, string>: map(0 ~ 10) and check by iter");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);
    std::map<int, std::string>::iterator std_itr;
    ft::map<int, std::string>::iterator ft_itr;

    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); std_itr++, ft_itr++) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw e;
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "map<int, string>: map(0 ~ 10) and check by iter fron end to begin");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);
    std::map<int, std::string>::iterator std_itr;
    ft::map<int, std::string>::iterator ft_itr;

    for (std_itr = --std_map.end(), ft_itr = --ft_map.end();
         std_itr != std_map.begin(); --ft_itr, --std_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.begin()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(
      test_no,
      "map<int, string>: map(0 ~ 10) and check by iter fron end to begin");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);
    std::map<int, std::string>::iterator std_itr;
    ft::map<int, std::string>::iterator ft_itr;

    for (std_itr = --std_map.end(), ft_itr = --ft_map.end();
         std_itr != std_map.begin(); ft_itr--, std_itr--) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.begin()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no,
              "map<int, string>: map(0 ~ 10) and find all and nonexists");
  try {
    std::map<int, std::string> std_map(persons, persons + 10);
    ft::map<int, std::string> ft_map(persons, persons + 10);
    std::map<int, std::string>::iterator std_itr;
    ft::map<int, std::string>::iterator ft_itr;

    for (int i = 0; i < 10; i++) {
      std_itr = std_map.find(i);
      ft_itr = ft_map.find(i);
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("find");
      }
    }
    if (ft_map.find(42) != ft_map.end() || ft_map.find(-42) != ft_map.end()) {
      throw std::runtime_error("find");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  for (int i = 0; i < 10; i++) {
    std::stringstream sout;
    sout << "map<int, string>: map(0 ~ 10) and erase [" << i << "]";
    putTestInfo(test_no, sout.str());
    try {
      std::map<int, std::string> std_map(persons, persons + 10);
      ft::map<int, std::string> ft_map(persons, persons + 10);
      std::map<int, std::string>::iterator std_itr;
      ft::map<int, std::string>::iterator ft_itr;

      std_map.erase(std_map.find(i));
      ft_map.erase(ft_map.find(i));
      for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
           std_itr != std_map.end(); std_itr++, ft_itr++) {
        if (*std_itr != *ft_itr) {
          throw std::runtime_error("value");
        }
      }
      if (ft_itr != ft_map.end()) {
        throw std::runtime_error("itr");
      }
      if (std_map.size() != ft_map.size() ||
          std_map.empty() != ft_map.empty() ||
          std_map.max_size() != ft_map.max_size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = 0; i < 10; i++) {
    std::stringstream sout;
    sout << "map<int, string>: map(0 ~ 10) and erase [" << i << "]";
    putTestInfo(test_no, sout.str());
    try {
      std::map<int, std::string> std_map(persons, persons + 10);
      ft::map<int, std::string> ft_map(persons, persons + 10);
      std::map<int, std::string>::iterator std_itr;
      ft::map<int, std::string>::iterator ft_itr;

      std_map.erase(std_map.find(i));
      ft_map.erase(ft_map.find(i));
      for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
           std_itr != std_map.end(); std_itr++, ft_itr++) {
        if (*std_itr != *ft_itr) {
          throw std::runtime_error("value");
        }
      }
      if (ft_itr != ft_map.end()) {
        throw std::runtime_error("itr");
      }
      if (std_map.size() != ft_map.size() ||
          std_map.empty() != ft_map.empty() ||
          std_map.max_size() != ft_map.max_size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  for (int i = -2; i < 12; i++) {
    std::stringstream sout;
    sout << "map<int, string>: map(0 ~ 10) and erase [" << i << "] by key";
    putTestInfo(test_no, sout.str());
    try {
      std::map<int, std::string> std_map(persons, persons + 10);
      ft::map<int, std::string> ft_map(persons, persons + 10);
      std::map<int, std::string>::iterator std_itr;
      ft::map<int, std::string>::iterator ft_itr;

      if (std_map.erase(i) != ft_map.erase(i)) {
        throw std::runtime_error("return value");
      }
      for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
           std_itr != std_map.end(); std_itr++, ft_itr++) {
        if (*std_itr != *ft_itr) {
          throw std::runtime_error("value");
        }
      }
      if (ft_itr != ft_map.end()) {
        throw std::runtime_error("itr");
      }
      if (std_map.size() != ft_map.size() ||
          std_map.empty() != ft_map.empty() ||
          std_map.max_size() != ft_map.max_size()) {
        throw std::runtime_error("size");
      }
    } catch (std::exception& e) {
      throw std::runtime_error(e.what());
    }
    std::cout << " => OK :)" << std::endl;
  }

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5).swap(map(5)) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 5);
    std::map<Hoge, Hoge> std_map2(fugas + 5, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 5);
    ft::map<Hoge, Hoge> ft_map2(fugas + 5, fugas + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std_map.swap(std_map2);
    ft_map.swap(ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5).swap(map(10)) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges + 5, hoges + 10);
    std::map<Hoge, Hoge> std_map2(fugas, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(hoges + 5, hoges + 10);
    ft::map<Hoge, Hoge> ft_map2(fugas, fugas + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std_map.swap(std_map2);
    ft_map.swap(ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(10).swap(map(5)) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    std::map<Hoge, Hoge> std_map2(fugas + 5, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map2(fugas + 5, fugas + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std_map.swap(std_map2);
    ft_map.swap(ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5).swap(map(0)) with array");
  try {
    std::map<Hoge, Hoge> std_map;
    std::map<Hoge, Hoge> std_map2(fugas + 5, fugas + 10);
    ft::map<Hoge, Hoge> ft_map;
    ft::map<Hoge, Hoge> ft_map2(fugas + 5, fugas + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std_map.swap(std_map2);
    ft_map.swap(ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      std::cout << "\nhoge" << std::endl;
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(0).swap(map(5)) with array");
  try {
    std::map<Hoge, Hoge> std_map;
    std::map<Hoge, Hoge> std_map2(hoges, hoges + 5);
    ft::map<Hoge, Hoge> ft_map;
    ft::map<Hoge, Hoge> ft_map2(hoges, hoges + 5);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std_map.swap(std_map2);
    ft_map.swap(ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: swap(map(5), map(5)) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 5);
    std::map<Hoge, Hoge> std_map2(fugas + 5, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 5);
    ft::map<Hoge, Hoge> ft_map2(fugas + 5, fugas + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std::swap(std_map, std_map2);
    ft::swap(ft_map, ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5).swap(map(10)) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges + 5, hoges + 10);
    std::map<Hoge, Hoge> std_map2(fugas, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(hoges + 5, hoges + 10);
    ft::map<Hoge, Hoge> ft_map2(fugas, fugas + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std::swap(std_map, std_map2);
    ft::swap(ft_map, ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(10).swap(map(5)) with array");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    std::map<Hoge, Hoge> std_map2(fugas + 5, fugas + 10);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map2(fugas + 5, fugas + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std::swap(std_map, std_map2);
    ft::swap(ft_map, ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5).swap(map(0)) with array");
  try {
    std::map<Hoge, Hoge> std_map;
    std::map<Hoge, Hoge> std_map2(fugas + 5, fugas + 10);
    ft::map<Hoge, Hoge> ft_map;
    ft::map<Hoge, Hoge> ft_map2(fugas + 5, fugas + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std::swap(std_map, std_map2);
    ft::swap(ft_map, ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(0).swap(map(5)) with array");
  try {
    std::map<Hoge, Hoge> std_map;
    std::map<Hoge, Hoge> std_map2(hoges, hoges + 5);
    ft::map<Hoge, Hoge> ft_map;
    ft::map<Hoge, Hoge> ft_map2(hoges, hoges + 5);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std::swap(std_map, std_map2);
    ft::swap(ft_map, ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(0).swap(map(5)) with array");
  try {
    std::map<Hoge, Hoge> std_map;
    std::map<Hoge, Hoge> std_map2(hoges, hoges + 5);
    ft::map<Hoge, Hoge> ft_map;
    ft::map<Hoge, Hoge> ft_map2(hoges, hoges + 5);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std::swap(std_map, std_map2);
    ft::swap(ft_map, ft_map2);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
    for (std_itr = std_map2.begin(), ft_itr = ft_map2.begin();
         std_itr != std_map2.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map2.size() != ft_map2.size() ||
        std_map2.empty() != ft_map2.empty() ||
        std_map2.max_size() != ft_map2.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: iterator after map::swap");
  try {
    std::map<Hoge, Hoge> std_map(fugas, fugas + 10);
    std::map<Hoge, Hoge> std_map2(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map(fugas, fugas + 10);
    ft::map<Hoge, Hoge> ft_map2(hoges, hoges + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;
    std::map<Hoge, Hoge>::iterator std_itr2;
    ft::map<Hoge, Hoge>::iterator ft_itr2;

    std_itr = std_map.begin();
    ft_itr = ft_map.begin();
    std_itr2 = std_map2.begin();
    ft_itr2 = ft_map2.begin();
    for (int i = 0; i < 5; i++) {
      if (*std_itr != *ft_itr || *ft_itr2 != *std_itr2) {
        throw std::runtime_error("value");
      }
      std_itr++;
      std_itr2++;
      ft_itr++;
      ft_itr2++;
    }
    std_map.swap(std_map2);
    ft_map.swap(ft_map2);
    while (std_itr2 != std_map.end()) {
      if (*std_itr2 != *ft_itr2) {
        throw std::runtime_error("value");
      }
      std_itr2++;
      ft_itr2++;
    }
    if (ft_itr2 != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    while (std_itr != std_map2.end()) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
      std_itr++;
      ft_itr++;
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: iterator after swap");
  try {
    std::map<Hoge, Hoge> std_map(fugas, fugas + 10);
    std::map<Hoge, Hoge> std_map2(hoges, hoges + 10);
    ft::map<Hoge, Hoge> ft_map(fugas, fugas + 10);
    ft::map<Hoge, Hoge> ft_map2(hoges, hoges + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;
    std::map<Hoge, Hoge>::iterator std_itr2;
    ft::map<Hoge, Hoge>::iterator ft_itr2;

    std_itr = std_map.begin();
    ft_itr = ft_map.begin();
    std_itr2 = std_map2.begin();
    ft_itr2 = ft_map2.begin();
    for (int i = 0; i < 5; i++) {
      if (*std_itr != *ft_itr || *ft_itr2 != *std_itr2) {
        throw std::runtime_error("value");
      }
      std_itr++;
      std_itr2++;
      ft_itr++;
      ft_itr2++;
    }
    std::swap(std_map, std_map2);
    ft::swap(ft_map, ft_map2);
    while (std_itr2 != std_map.end()) {
      if (*std_itr2 != *ft_itr2) {
        throw std::runtime_error("value");
      }
      std_itr2++;
      ft_itr2++;
    }
    if (ft_itr2 != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    while (std_itr != std_map2.end()) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
      std_itr++;
      ft_itr++;
    }
    if (ft_itr != ft_map2.end()) {
      throw std::runtime_error("itr");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map.clear");
  try {
    std::map<Hoge, Hoge> std_map;
    ft::map<Hoge, Hoge> ft_map;
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std_map.clear();
    ft_map.clear();
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5).clear");
  try {
    std::map<Hoge, Hoge> std_map(hoges + 5, hoges + 10);
    ft::map<Hoge, Hoge> ft_map(hoges + 5, hoges + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std_map.clear();
    ft_map.clear();
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(5).clear and insert");
  try {
    std::map<Hoge, Hoge> std_map(hoges + 5, hoges + 10);
    ft::map<Hoge, Hoge> ft_map(hoges + 5, hoges + 10);
    std::map<Hoge, Hoge>::iterator std_itr;
    ft::map<Hoge, Hoge>::iterator ft_itr;

    std_map.clear();
    ft_map.clear();
    std_map.insert(hoges, hoges + 10);
    ft_map.insert(hoges, hoges + 10);
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("itr");
    }
    if (std_map.size() != ft_map.size() || std_map.empty() != ft_map.empty() ||
        std_map.max_size() != ft_map.max_size()) {
      throw std::runtime_error("size");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, int>: add nothing and count for 100");
  try {
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    for (int i = 0; i < 50; i++) {
      if (std_map.count(i) != ft_map.count(i)) {
        throw std::runtime_error("count");
      }
    }
    // ichiou check
    std::map<int, int>::iterator std_itr;
    ft::map<int, int>::iterator ft_itr;
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, int>: add 50 random and count for 100");
  try {
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    int tmp;

    for (int i = 0; i < 50; i++) {
      tmp = rand();
      std_map[tmp % 100] = tmp;
      ft_map[tmp % 100] = tmp;
    }
    for (int i = 0; i < 50; i++) {
      if (std_map.count(i) != ft_map.count(i)) {
        throw std::runtime_error("count");
      }
    }
    // ichiou check
    std::map<int, int>::iterator std_itr;
    ft::map<int, int>::iterator ft_itr;
    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("value");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, int>: map(0).lower_bound(-9~10)");
  try {
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    std::map<int, int>::iterator std_itr;
    ft::map<int, int>::iterator ft_itr;

    for (int i = -9; i <= 10; i++) {
      std_itr = std_map.lower_bound(i);
      ft_itr = ft_map.lower_bound(i);
      if (std_itr != std_map.end() && *std_itr != *ft_itr) {
        throw std::runtime_error("lower_bound");
      }
      if (std_itr == std_map.end() && ft_itr != ft_map.end()) {
        throw std::runtime_error("lower_bound");
      }
      std_itr = std_map.upper_bound(i);
      ft_itr = ft_map.upper_bound(i);
      if (std_itr != std_map.end() && *std_itr != *ft_itr) {
        throw std::runtime_error("upper_bound");
      }
      if (std_itr == std_map.end() && ft_itr != ft_map.end()) {
        throw std::runtime_error("upper_bound");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, int>: map(0, 2, ... 100).lower_bound(-9~110)");
  try {
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    std::map<int, int>::iterator std_itr;
    ft::map<int, int>::iterator ft_itr;

    for (int i = 0; i <= 50; i++) {
      std_map[i * 2] = i * 2;
      ft_map[i * 2] = i * 2;
    }
    for (int i = -9; i <= 110; i++) {
      std_itr = std_map.lower_bound(i);
      ft_itr = ft_map.lower_bound(i);
      if (std_itr != std_map.end() && *std_itr != *ft_itr) {
        throw std::runtime_error("lower_bound");
      }
      if (std_itr == std_map.end() && ft_itr != ft_map.end()) {
        throw std::runtime_error("lower_bound");
      }
      std_itr = std_map.upper_bound(i);
      ft_itr = ft_map.upper_bound(i);
      if (std_itr != std_map.end() && *std_itr != *ft_itr) {
        throw std::runtime_error("upper_bound");
      }
      if (std_itr == std_map.end() && ft_itr != ft_map.end()) {
        throw std::runtime_error("upper_bound");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, int>: map(0).equal_range(-9~10)");
  try {
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator>
        std_res;
    std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ft_res;

    for (int i = -9; i <= 10; i++) {
      std_res = std_map.equal_range(i);
      ft_res = ft_map.equal_range(i);
      if (std_res.first != std_map.end() && *std_res.first != *ft_res.first) {
        throw std::runtime_error("lower_bound");
      }
      if (std_res.first == std_map.end() && ft_res.first != ft_map.end()) {
        throw std::runtime_error("lower_bound");
      }
      if (std_res.second != std_map.end() &&
          *std_res.second != *ft_res.second) {
        throw std::runtime_error("lower_bound");
      }
      if (std_res.second == std_map.end() && ft_res.second != ft_map.end()) {
        throw std::runtime_error("lower_bound");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int, int>: map(0, 2, ... 100).equal_range(-9~110)");
  try {
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator>
        std_res;
    std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> ft_res;

    for (int i = 0; i <= 50; i++) {
      std_map[i * 2] = i * 2;
      ft_map[i * 2] = i * 2;
    }
    for (int i = -9; i <= 110; i++) {
      std_res = std_map.equal_range(i);
      ft_res = ft_map.equal_range(i);
      if (std_res.first != std_map.end() && *std_res.first != *ft_res.first) {
        throw std::runtime_error("lower_bound");
      }
      if (std_res.first == std_map.end() && ft_res.first != ft_map.end()) {
        throw std::runtime_error("lower_bound");
      }
      if (std_res.second != std_map.end() &&
          *std_res.second != *ft_res.second) {
        throw std::runtime_error("lower_bound");
      }
      if (std_res.second == std_map.end() && ft_res.second != ft_map.end()) {
        throw std::runtime_error("lower_bound");
      }
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  for (int i = 0; i <= 20; i++) {
    for (int j = 0; j <= 10; j++) {
      std::stringstream sout;
      sout << "map<int, int>: map(0,2..20).insert to " << i << " with hint "
           << j * 2;
      putTestInfo(test_no, sout.str());
      try {
        std::map<int, int> std_map;
        ft::map<int, int> ft_map;
        std::map<int, int>::iterator std_itr;
        ft::map<int, int>::iterator ft_itr;

        for (int k = 0; k <= 10; k++) {
          std_map[k * 2] = k * 2;
          ft_map[k * 2] = k * 2;
        }
        std_itr =
            std_map.insert(std_map.find(j * 2), std::pair<int, int>(i, 42));
        ft_itr = ft_map.insert(ft_map.find(j * 2), std::pair<int, int>(i, 42));
        if (*std_itr != *ft_itr) {
          throw std::runtime_error("return value");
        }
        for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
             std_itr != std_map.end(); ++std_itr, ++ft_itr) {
          if (*std_itr != *ft_itr) {
            throw std::runtime_error("value");
          }
        }
      } catch (std::exception& e) {
        throw std::runtime_error(e.what());
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  putTestInfo(test_no, "map<Hoge, Hoge>: map(1).erase(1)");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 1);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 1);

    std_map.erase(std_map.begin(), std_map.end());
    ft_map.erase(ft_map.begin(), ft_map.end());
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<Hoge, Hoge>: map(1~2).erase(all)");
  try {
    std::map<Hoge, Hoge> std_map(hoges, hoges + 2);
    ft::map<Hoge, Hoge> ft_map(hoges, hoges + 2);

    std_map.erase(std_map.begin(), std_map.end());
    ft_map.erase(ft_map.begin(), ft_map.end());
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  for (int i = 0; i <= 10; i++) {
    for (int j = i; j <= 10; j++) {
      std::stringstream sout;
      sout << "map<Hoge, Hoge>: map(0,10).erase(" << i << " ~ " << j << ")";
      putTestInfo(test_no, sout.str());
      try {
        std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
        ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);

        std::map<Hoge, Hoge>::iterator std_first = std_map.begin();
        ft::map<Hoge, Hoge>::iterator ft_first = ft_map.begin();
        for (int k = 0; k < i; k++) {
          ++std_first;
          ++ft_first;
        }

        std::map<Hoge, Hoge>::iterator std_last = std_first;
        ft::map<Hoge, Hoge>::iterator ft_last = ft_first;
        for (int k = i; k < j; k++) {
          ++std_last;
          ++ft_last;
        }
        std_map.erase(std_first, std_last);
        ft_map.erase(ft_first, ft_last);
        for (std_first = std_map.begin(), ft_first = ft_map.begin();
             std_first != std_map.end(); ++std_first, ++ft_first) {
          if (*std_first != *ft_first) {
            throw std::runtime_error("value");
          }
        }
      } catch (std::exception& e) {
        throw std::runtime_error(e.what());
      }
      std::cout << " => OK :)" << std::endl;
    }
  }

  putTestInfo(test_no, "map<int,int>: check iterators");
  try {
    int key;
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
    std::map<int, int>::iterator std_itr;
    ft::map<int, int>::iterator ft_itr;
    std::map<int, int>::reverse_iterator std_ritr;
    ft::map<int, int>::reverse_iterator ft_ritr;
    std::map<int, int>::const_iterator std_citr;
    ft::map<int, int>::const_iterator ft_citr;
    std::map<int, int>::const_reverse_iterator std_critr;
    ft::map<int, int>::const_reverse_iterator ft_critr;

    for (int i = 0; i < 1000; i++) {
      key = rand() % 1000;
      std_map[key] = i;
      ft_map[key] = i;
    }

    for (std_itr = std_map.begin(), ft_itr = ft_map.begin();
         std_itr != std_map.end(); ++std_itr, ++ft_itr) {
      if (*std_itr != *ft_itr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_itr != ft_map.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_ritr = std_map.rbegin(), ft_ritr = ft_map.rbegin();
         std_ritr != std_map.rend(); ++std_ritr, ++ft_ritr) {
      if (*std_ritr != *ft_ritr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_ritr != ft_map.rend()) {
      throw std::runtime_error("rev iterator");
    }

    for (std_citr = std_map.begin(), ft_citr = ft_map.begin();
         std_citr != std_map.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_citr != ft_map.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_critr = std_map.rbegin(), ft_critr = ft_map.rbegin();
         std_critr != std_map.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_critr != ft_map.rend()) {
      throw std::runtime_error("rev iterator");
    }

  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  putTestInfo(test_no, "map<int,int>: check const");
  try {
    const std::map<Hoge, Hoge> std_map(hoges, hoges + 10);
    const ft::map<Hoge, Hoge> ft_map(hoges, hoges + 10);
    std::map<Hoge, Hoge>::const_iterator std_citr;
    ft::map<Hoge, Hoge>::const_iterator ft_citr;
    std::map<Hoge, Hoge>::const_reverse_iterator std_critr;
    ft::map<Hoge, Hoge>::const_reverse_iterator ft_critr;

    for (std_citr = std_map.begin(), ft_citr = ft_map.begin();
         std_citr != std_map.end(); ++std_citr, ++ft_citr) {
      if (*std_citr != *ft_citr) {
        throw std::runtime_error("iterator");
      }
    }
    if (ft_citr != ft_map.end()) {
      throw std::runtime_error("iterator");
    }

    for (std_critr = std_map.rbegin(), ft_critr = ft_map.rbegin();
         std_critr != std_map.rend(); ++std_critr, ++ft_critr) {
      if (*std_critr != *ft_critr) {
        throw std::runtime_error("rev iterator");
      }
    }
    if (ft_critr != ft_map.rend()) {
      throw std::runtime_error("rev iterator");
    }
  } catch (std::exception& e) {
    throw std::runtime_error(e.what());
  }
  std::cout << " => OK :)" << std::endl;

  return;
}
