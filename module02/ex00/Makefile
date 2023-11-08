# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wchen <wchen@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 20:47:41 by wchen             #+#    #+#              #
#    Updated: 2023/11/04 17:01:02 by wchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  Fixed

# COMPILE FLAGS
CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
SRCS	= Fixed.cpp main.cpp
OBJS	= $(SRCS:%.cpp=%.o)

all		: $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean 	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re

