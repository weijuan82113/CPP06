NAME = identifyRealType

# COMPILE FLAGS
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
SRCS		=	main.cpp \
				Base.cpp \
				BaseA.cpp \
				BaseB.cpp \
				BaseC.cpp \
				Identify.cpp \


OBJS		= $(SRCS:%.cpp=%.o)


all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re