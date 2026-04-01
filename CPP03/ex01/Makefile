CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = scavtrap

C_SRC = ClapTrap.cpp
S_SRC = ScavTrap.cpp
SRC = main.cpp

C_H = ClapTrap.hpp
S_H = ScavTrap.hpp

C_OBJ = $(C_SRC:.cpp=.o)
S_OBJ = $(S_SRC:.cpp=.o)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(S_OBJ) $(C_OBJ) $(OBJ) -o $(NAME)

$(OBJ): $(C_OBJ) $(S_OBJ)

$(C_OBJ): $(C_H)
$(S_OBJ): $(S_H)

clean:
	rm -rf $(S_OBJ) $(C_OBJ) $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
