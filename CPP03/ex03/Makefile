CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
NAME = diamondtrap

C_SRC = ClapTrap.cpp
S_SRC = ScavTrap.cpp
F_SRC = FragTrap.cpp
D_SRC = DiamondTrap.cpp
SRC = main.cpp

C_H = ClapTrap.hpp
S_H = ScavTrap.hpp
F_H = FragTrap.hpp
D_H = DiamondTrap.hpp

C_OBJ = $(C_SRC:.cpp=.o)
S_OBJ = $(S_SRC:.cpp=.o)
F_OBJ = $(F_SRC:.cpp=.o)
D_OBJ = $(D_SRC:.cpp=.o)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(D_OBJ) $(F_OBJ) $(S_OBJ) $(C_OBJ) $(OBJ) -o $(NAME)

$(OBJ): $(D_OBJ) $(C_OBJ) $(S_OBJ) $(F_OBJ)

$(C_OBJ): $(C_H)
$(S_OBJ): $(S_H)
$(F_OBJ): $(F_H)
$(D_OBJ): $(D_H)

clean:
	rm -rf $(D_OBJ) $(F_OBJ) $(S_OBJ) $(C_OBJ) $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
