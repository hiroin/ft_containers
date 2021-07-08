#include <iostream>
#include <utility>
#include <string>
#include "ft_pair.hpp"

template <class T1, class T2>
void print(const std::string& name, const std::pair<T1, T2>& p)
{
  std::cout << name << " : (" << p.first << "," << p.second << ")" << std::endl;
}

template <class T1, class T2>
void ft_print(const std::string& name, const ft::pair<T1, T2>& p)
{
  std::cout << name << " : (" << p.first << "," << p.second << ")" << std::endl;
}

int main()
{
  std::pair<int, std::string> p1(1, "aaa");
  std::pair<int, std::string> p2(2, "bbb");
  print("p1", p1);
  print("p2", p2);
  std::pair<int, char> p5 = std::make_pair(1, 'a');
  print("p5", p5);

  ft::pair<int, std::string> p3(1, "aaa");
  ft::pair<int, std::string> p4(2, "bbb");
  ft_print("p3", p3);
  ft_print("p4", p4);
  ft::pair<int, char> p6 = ft::make_pair(1, 'a');
  ft_print("p6", p6);

}