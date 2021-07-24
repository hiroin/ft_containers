SRCS = main.cpp vector.cpp map.cpp stack.cpp tester.cpp
CC = clang++ -Wall -Wextra -Werror -std=c++98

ft:
	$(CC) -o ft_test $(SRCS) -std=c++98

std:
	$(CC) -o std_test $(SRCS) -std=c++98 -DTEST

clean:
	/bin/rm -f ft_test std_test a.out

fclean: clean
	/bin/rm -f *.txt

re : fclean all

.PHONY: all clean fclean re ft std