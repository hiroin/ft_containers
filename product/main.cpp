#include "tester.hpp"

int main()
{
  VectorTest();
  MapTest();
  StackTest();
#ifdef LEAK
		std::system("leaks test");
#endif
	return 0;
}
