CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = animals

A_SRC = Animal.cpp
B_SRC = Brain.cpp
C_SRC = Cat.cpp
D_SRC = Dog.cpp
WA_SRC = WrongAnimal.cpp
WC_SRC = WrongCat.cpp
SRC = main.cpp

A_HEADER = Animal.hpp
B_HEADER = Brain.hpp
C_HEADER = Cat.hpp
D_HEADER = Dog.hpp
WC_HEADER = WrongCat.hpp
WA_HEADER = WrongAnimal.hpp

A_OBJ = $(A_SRC:.cpp=.o)
B_OBJ = $(B_SRC:.cpp=.o)
C_OBJ = $(C_SRC:.cpp=.o)
D_OBJ = $(D_SRC:.cpp=.o)
WA_OBJ = $(WA_SRC:.cpp=.o)
WC_OBJ = $(WC_SRC:.cpp=.o)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(A_OBJ) $(B_OBJ) $(C_OBJ) $(D_OBJ) $(WA_OBJ) $(WC_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(A_OBJ) $(B_OBJ) $(C_OBJ) $(D_OBJ) $(WA_OBJ) $(WC_OBJ) -o $(NAME)

$(OBJ): $(A_OBJ) $(B_OBJ) $(C_OBJ) $(D_OBJ) $(WA_OBJ) $(WC_OBJ)

$(A_OBJ): $(A_HEADER)
$(B_OBJ): $(B_HEADER)
$(C_OBJ): $(C_HEADER)
$(D_OBJ): $(D_HEADER)
$(WA_OBJ): $(WA_HEADER)
$(WC_OBJ): $(WC_HEADER)

clean:
	rm -rf $(OBJ) $(A_OBJ) $(B_OBJ) $(C_OBJ) $(D_OBJ) $(WA_OBJ) $(WC_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
