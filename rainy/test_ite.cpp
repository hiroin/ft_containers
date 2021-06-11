#include "test.hpp"
#include "vector.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

struct Test
{
  int value;
};

int main()
{
  std::stringstream ss;
  {
    int i[3] = {1, 2, 3};
    ft::vectorIterator<int> ft_itr(i);
    std::vector<int>::iterator original_itr(i);

    // *a 読み込み
    std::cout << std::left << std::setw(30) << "*ft_itr : ";
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // *a 書き込み
    *ft_itr = 2;
    *original_itr = 2;

    std::cout << std::left << std::setw(30) << "*ft_itr = 2 : ";
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a++
    std::cout << std::left << std::setw(30) << "ft_itr++ : ";
    if (*ft_itr++ == *original_itr++)
      ss << "OK";
    else
      ss << "NG";
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // ++a
    std::cout << std::left << std::setw(30) << "++ft_itr : ";
    if (*++ft_itr == *++original_itr)
      ss << "OK";
    else
      ss << "NG";
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a--
    std::cout << std::left << std::setw(30) << "ft_itr-- : ";
    if (*ft_itr-- == *original_itr--)
      ss << "OK";
    else
      ss << "NG";
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // --a
    std::cout << std::left << std::setw(30) << "--ft_itr : ";
    if (*--ft_itr == *--original_itr)
      ss << "OK";
    else
      ss << "NG";
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a[n] 読み込み
    std::cout << std::left << std::setw(30) << "ft_itr[0] : ";
    if (ft_itr[0] == original_itr[0])
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a[n] 書き込み
    std::cout << std::left << std::setw(30) << "ft_itr[0] : ";
    ft_itr[0] = 100;
    original_itr[0] = 100;
    if (ft_itr[0] == original_itr[0])
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a += 1
    std::cout << std::left << std::setw(30) << "ft_itr += 1 : ";
    ft_itr += 1;
    original_itr += 1;
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a + 1
    std::cout << std::left << std::setw(30) << "ft_itr + 1 : ";
    if (*(ft_itr + 1) == *(original_itr + 1))
      ss << "OK";
    else
      ss << "NG";
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a -= 1
    std::cout << std::left << std::setw(30) << "ft_itr -= 1 : ";
    ft_itr -= 1;
    original_itr -= 1;
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a - 1
    std::cout << std::left << std::setw(30) << "ft_itr - 1 : ";
    if (*(ft_itr - 1) == *(original_itr - 1))
      ss << "OK";
    else
      ss << "NG";
    if (*ft_itr == *original_itr)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

  }
  {
    int i[3] = {1, 2, 3};
    ft::vectorIterator<int> ft_itr1(i);
    ft::vectorIterator<int> ft_itr2(i);
    std::vector<int>::iterator original_itr1(i);
    std::vector<int>::iterator original_itr2(i);

    std::cout << std::left << std::setw(30) << "== : ";
    if ((ft_itr1 == ft_itr2) == (original_itr1 == original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ft_itr1++;
    original_itr1++;
    if ((ft_itr1 == ft_itr2) == (original_itr1 == original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    std::cout << std::left << std::setw(30) << "!= : ";
    if ((ft_itr1 == ft_itr2) == (original_itr1 == original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ft_itr2++;
    original_itr2++;
    if ((ft_itr1 == ft_itr2) == (original_itr1 == original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    std::cout << std::left << std::setw(30) << "< : ";
    if ((ft_itr1 < ft_itr2) == (original_itr1 < original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ft_itr1--;
    original_itr1--;
    if ((ft_itr1 < ft_itr2) == (original_itr1 < original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    std::cout << std::left << std::setw(30) << "> : ";
    if ((ft_itr1 > ft_itr2) == (original_itr1 > original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ft_itr1++;
    original_itr1++;
    if ((ft_itr1 > ft_itr2) == (original_itr1 > original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    std::cout << std::left << std::setw(30) << "<= : ";
    if ((ft_itr1 <= ft_itr2) == (original_itr1 <= original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ft_itr2--;
    original_itr2--;
    if ((ft_itr1 <= ft_itr2) == (original_itr1 <= original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ft_itr2++++;
    original_itr2++++;
    if ((ft_itr1 <= ft_itr2) == (original_itr1 <= original_itr2))
      ss << "OK";
    else
      ss << "NG"; 
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    std::cout << std::left << std::setw(30) << ">= : ";
    if ((ft_itr1 >= ft_itr2) == (original_itr1 >= original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ft_itr1--;
    original_itr1--;
    if ((ft_itr1 >= ft_itr2) == (original_itr1 >= original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ft_itr1++;
    original_itr1++;
    ft_itr1++;
    original_itr1++;
    if ((ft_itr1 >= ft_itr2) == (original_itr1 >= original_itr2))
      ss << "OK";
    else
      ss << "NG"; 
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");


    std::cout << std::left << std::setw(30) << "itr - itr";
    if ((ft_itr1 - ft_itr2) == (original_itr1 - original_itr2))
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

  }
  {
    Test t[3];
    t[0].value = 0;
    t[1].value = 1;
    t[2].value = 2;

    ft::vectorIterator<Test> ft_itr(t);
    std::vector<Test>::iterator original_itr(t);

    // a->m 読み込み
    std::cout << std::left << std::setw(30) << "ft_itr->value : ";
    if (ft_itr->value == original_itr->value)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
    ss.str("");

    // a->m 書き込み
    std::cout << std::left << std::setw(30) << "ft_itr->value = 10 : ";
    ft_itr->value = 10;
    original_itr->value = 10;
    if (ft_itr->value == original_itr->value)
      ss << "OK";
    else
      ss << "NG";
    ss << std::endl;
    std::cout << ss.str();
  }


  return 0;
}