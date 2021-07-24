/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hoge.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 15:21:44 by dnakano           #+#    #+#             */
/*   Updated: 2021/02/14 09:11:10 by dnakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hoge.hpp"

Hoge::Hoge() : idx_(-1) { num_ = new int(-1); }

Hoge::Hoge(int idx, int num) : idx_(idx) { num_ = new int(num); }

Hoge::Hoge(const Hoge& ref) : idx_(ref.idx_) { num_ = new int(*ref.num_); }

Hoge::~Hoge() { delete num_; }

Hoge& Hoge::operator=(const Hoge& rhs) {
  *num_ = *rhs.num_;
  return *this;
}

bool operator==(const Hoge& lhs, const Hoge& rhs) {
  return (lhs.idx_ == rhs.idx_ && *lhs.num_ == *rhs.num_);
}

bool operator!=(const Hoge& lhs, const Hoge& rhs) {
  return !operator==(lhs, rhs);
}

bool operator<(const Hoge& lhs, const Hoge& rhs) {
  return (*lhs.num_ < *rhs.num_);
}

bool operator>(const Hoge& lhs, const Hoge& rhs) {
  return (*lhs.num_ > *rhs.num_);
}

bool operator<=(const Hoge& lhs, const Hoge& rhs) { return !(lhs > rhs); }
bool operator>=(const Hoge& lhs, const Hoge& rhs) { return !(lhs < rhs); }

std::ostream& operator<<(std::ostream& out, const Hoge& rhs) {
  out << rhs.idx_ << ": " << *rhs.num_;
  return out;
}

bool compareNum(const Hoge& hoge1, const Hoge& hoge2) {
  return *hoge1.num_ == *hoge2.num_;
}
