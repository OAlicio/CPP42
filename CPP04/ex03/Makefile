CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = arena

SRC = main.cpp Test.cpp
A_SRC = AMateria.cpp
C_SRC = Character.cpp
CM_SRC = Cure.cpp
IM_SRC = Ice.cpp
MS_SRC = MateriaSource.cpp
MM_SRC = MateriaManager.cpp

A_HEADER = AMateria.hpp
C_HEADER = Character.hpp
IC_HEADER = ICharacter.hpp
CM_HEADER = Cure.hpp
IM_HEADER = Ice.hpp
MS_HEADER = MateriaSource.hpp
MM_HEADER = MateriaManager.hpp
IMS_HEADER = IMateriaSource.hpp

OBJ = $(SRC:.cpp=.o)
A_OBJ = $(A_SRC:.cpp=.o)
C_OBJ = $(C_SRC:.cpp=.o)
CM_OBJ = $(CM_SRC:.cpp=.o)
IM_OBJ = $(IM_SRC:.cpp=.o)
MS_OBJ = $(MS_SRC:.cpp=.o)
MM_OBJ = $(MM_SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(A_OBJ) $(C_OBJ) $(CM_OBJ) $(IM_OBJ) $(MS_OBJ) $(MM_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(A_OBJ) $(C_OBJ) $(CM_OBJ) $(IM_OBJ) $(MS_OBJ) $(MM_OBJ) -o $(NAME)

$(OBJ): $(A_OBJ) $(C_OBJ) $(CM_OBJ) $(IM_OBJ) $(MS_OBJ) $(MM_OBJ)

$(A_OBJ): $(A_HEADER)
$(C_OBJ): $(C_HEADER) $(IC_HEADER)
$(MS_OBJ): $(MS_HEADER) $(IMS_HEADER)
$(CM_OBJ): $(CM_HEADER)
$(IM_OBJ): $(IM_HEADER)
$(MM_OBJ): $(MM_HEADER)

clean:
	rm -rf $(OBJ) $(A_OBJ) $(C_OBJ) $(CM_OBJ) $(IM_OBJ) $(MS_OBJ) $(MM_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
