CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fixed
SRC = Fixed.cpp \
	  main.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Fixed.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(HEADER)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
