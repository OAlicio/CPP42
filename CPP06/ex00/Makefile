NAME = scalarconverter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = ScalarConverter.cpp \
	  helper.cpp \
	  main.cpp
HEADERS = ScalarConverter.hpp helper.h

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(HEADERS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
