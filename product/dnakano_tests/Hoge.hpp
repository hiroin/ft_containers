/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hoge.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:20:56 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/14 20:36:54 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOGE_HPP
#define HOGE_HPP

#include <ostream>

class Hoge {
 public:
  const int idx_;
  int* num_;

  Hoge();
  Hoge(int idx, int num);
  Hoge(const Hoge& ref);
  ~Hoge();
  Hoge& operator=(const Hoge& rhs);
};

bool operator==(const Hoge& lhs, const Hoge& rhs);
bool operator!=(const Hoge& lhs, const Hoge& rhs);
bool operator<(const Hoge& lhs, const Hoge& rhs);
bool operator<=(const Hoge& lhs, const Hoge& rhs);
bool operator>(const Hoge& lhs, const Hoge& rhs);
bool operator>=(const Hoge& lhs, const Hoge& rhs);

std::ostream& operator<<(std::ostream& out, const Hoge& rhs);

bool compareNum(const Hoge& hoge1, const Hoge& hoge2);

#endif /* HOGE_HPP */
