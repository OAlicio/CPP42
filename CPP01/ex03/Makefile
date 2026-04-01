NAME = humans
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
HA_SRC = HumanA.cpp
HB_SRC = HumanB.cpp
W_SRC = Weapon.cpp
M_SRC = main.cpp

HA_HEAD = HumanA.hpp
HB_HEAD = HumanB.hpp
W_HEAD = Weapon.hpp

HA_OBJ = $(HA_SRC:.cpp=.o)
HB_OBJ = $(HB_SRC:.cpp=.o)
W_OBJ = $(W_SRC:.cpp=.o)
M_OBJ = $(M_SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(HA_OBJ) $(HB_OBJ) $(W_OBJ) $(M_OBJ)
	$(CXX) $(CXXFLAGS) $(HA_OBJ) $(HB_OBJ) $(W_OBJ) $(M_OBJ) -o $(NAME)

$(HA_OBJ): $(HA_HEAD)
$(HB_OBJ): $(HB_HEAD)
$(W_OBJ): $(W_HEAD)

clean:
	rm -rf $(HA_OBJ) $(HB_OBJ) $(W_OBJ) $(M_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
