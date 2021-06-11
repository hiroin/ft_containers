#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class Iterator {
 private:
  const char* p;

 public:
  const char& operator*() { return *p; }
  Iterator& operator++() { ++p; return *this; }
  bool operator!=(const Iterator& v) { return p != v.p; }

  Iterator(const char* s) : p(s)
  {}
};

struct String {
  const char* s;
  Iterator begin() { return {s}; }
  Iterator end()   { return {s + strlen(s)}; }
};

int main()
{
  String s = {"abc"};
  for (Iterator ite = s.begin(), end = s.end(); ite != end; ++ite)
    printf("%c,", *ite); // 出力: "a,b,c,"
  for (Iterator ite = std::begin(s), end = std::end(s); ite != end; ++ite)
    printf("%c,", *ite); // 出力: "a,b,c,"
}