NAME = notsed
TEST = testsed
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = FileReplacer.hpp

M_SRC = main.cpp
SRC =  FileReplacer.cpp
T_SRC = Tests.cpp 

OBJ = $(SRC:.cpp=.o)
M_OBJ = $(M_SRC:.cpp=.o)
T_OBJ = $(T_SRC:.cpp=.o)

all: $(NAME)

test: $(TEST)

$(NAME): $(OBJ) $(M_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(M_OBJ) -o $(NAME)

$(TEST): $(OBJ) $(T_OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(T_OBJ) -o $(TEST)

$(OBJ): $(HEADER)
$(T_OBJ): $(HEADER)
$(M_OBJ): $(HEADER)

clean:
	rm -rf $(OBJ) $(T_OBJ) $(M_OBJ)

fclean: clean
	rm -rf $(NAME) $(TEST)

re: fclean all

.PHONY: all test clean fclean re
