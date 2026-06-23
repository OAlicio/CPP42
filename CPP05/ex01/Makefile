NAME = bureaucrats
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Form.cpp \
	  Bureaucrat.cpp \
	  main.cpp
HEADER = Bureaucrat.hpp Form.hpp
OBJ = $(SRC:.cpp=.o)

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
