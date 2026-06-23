NAME = easyfind
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = easyfind.hpp easyfind.tpp
SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(HEADERS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
