NAME = harl
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Harl.cpp
M_SRC = main.cpp
HEADER = Harl.hpp

M_OBJ = $(M_SRC:.cpp=.o)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(M_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(M_OBJ) -o $(NAME)

$(OBJ): $(HEADER)
$(M_OBJ): $(HEADER)

clean:
	rm -rf $(OBJ) $(M_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

