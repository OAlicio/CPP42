CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = animals
D_SRC = Dog.cpp
C_SRC = Cat.cpp
A_SRC = Animal.cpp
WC_SRC = WrongCat.cpp
WA_SRC = WrongAnimal.cpp
SRC = main.cpp

D_HEADER = Dog.hpp
C_HEADER = Cat.hpp
A_HEADER = Animal.hpp
WC_HEADER = WrongCat.hpp
WA_HEADER = WrongAnimal.hpp

D_OBJ = $(D_SRC:.cpp=.o)
C_OBJ = $(C_SRC:.cpp=.o)
A_OBJ = $(A_SRC:.cpp=.o)
WC_OBJ = $(WC_SRC:.cpp=.o)
WA_OBJ = $(WA_SRC:.cpp=.o)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(D_OBJ) $(C_OBJ) $(A_OBJ) $(WC_OBJ) $(WA_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(D_OBJ) $(C_OBJ) $(A_OBJ) $(WC_OBJ) $(WA_OBJ) -o $(NAME)

$(OBJ): $(D_OBJ) $(C_OBJ) $(A_OBJ) $(WC_OBJ) $(WA_OBJ)

$(D_OBJ): $(D_HEADER)
$(C_OBJ): $(C_HEADER)
$(A_OBJ): $(A_HEADER)
$(WC_OBJ): $(WC_HEADER)
$(WA_OBJ): $(WA_HEADER)

clean:
	rm -rf $(OBJ) $(D_OBJ) $(C_OBJ) $(A_OBJ) $(WC_OBJ) $(WA_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
