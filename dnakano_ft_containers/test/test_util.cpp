/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_util.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:58:31 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/13 12:38:40 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void putTestInfo(int& test_no, const std::string& outline) {
  std::cout << "TEST No." << test_no++ << ": " << outline << std::flush;
}

bool is_even(const int& value) { return !(value % 2); }
