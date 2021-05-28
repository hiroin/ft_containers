/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 21:11:44 by dnakano           #+#    #+#             */
/*   Updated: 2021/03/03 13:15:19 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include "Hoge.hpp"

void putTestInfo(int& test_no, const std::string& outline);

void test_vector(int& test_no);
void test_list(int& test_no);
void test_map(int& test_no);
void test_stack(int& test_no);
void test_queue(int& test_no);
void test_vector_bool(int& test_no);

template <typename T>
void divByTwo(T& n) {
  n = n / 2;
}

bool is_even(const int& value);

struct is_odd {
  bool operator()(const int& value) { return (value % 2) == 1; }
};

template<typename T>
bool lesser_than_rhs(T const &nbr1, T const &nbr2) {
	return (nbr1 <= nbr2);
}

#endif /* TEST_HPP */
