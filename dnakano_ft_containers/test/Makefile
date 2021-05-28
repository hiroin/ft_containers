# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dnakano <dnakano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 17:34:06 by dnakano           #+#    #+#              #
#    Updated: 2021/02/23 09:01:09 by dnakano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:=	main.cpp test_util.cpp test_vector.cpp test_list.cpp \
				test_map.cpp test_stack.cpp test_queue.cpp \
				test_vector_bool.cpp Hoge.cpp
OBJS		:=	$(SRCS:%.cpp=%.o)
HEADERS		:=	vector.hpp list.hpp map.hpp stack.hpp
HEADERDIR	:=	..
NAME		:=	test.out
OUTDIR		:=	.

CXX			:=	clang++
CPPFLAGS	:=	-Wall -Wextra -Werror -std=c++98 -I$(HEADERDIR)

.PHONY:		all
all:		test

$(NAME):	$(OBJS) $(addprefix $(HEADERDIR)/,$(HEADERS))
			$(CXX) $(CPPFLAGS) $(OBJS) -o $(NAME)

.PHONY:		test
test:		$(NAME)
			$(OUTDIR)/$(NAME)

.PHONY:		clean
clean:
			rm -f $(OBJS)

.PHONY:		fclean
fclean:		clean
			rm -f $(NAME)

.PHONY:		re
re:			fclean all
