CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fragtrap

C_SRC = ClapTrap.cpp
S_SRC = ScavTrap.cpp
F_SRC = FragTrap.cpp
SRC = main.cpp

C_H = ClapTrap.hpp
S_H = ScavTrap.hpp
F_H = FragTrap.hpp

C_OBJ = $(C_SRC:.cpp=.o)
S_OBJ = $(S_SRC:.cpp=.o)
F_OBJ = $(F_SRC:.cpp=.o)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(F_OBJ) $(S_OBJ) $(C_OBJ) $(OBJ) -o $(NAME)

$(OBJ): $(C_OBJ) $(S_OBJ) $(F_OBJ)

$(C_OBJ): $(C_H)
$(S_OBJ): $(S_H)
$(F_OBJ): $(F_H)

clean:
	rm -rf $(F_OBJ) $(S_OBJ) $(C_OBJ) $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
