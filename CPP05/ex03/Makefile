NAME = interns
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = AForm.cpp \
	  Bureaucrat.cpp \
	  PresidentialPardonForm.cpp \
	  RobotomyRequestForm.cpp \
	  ShrubberyCreationForm.cpp \
	  Intern.cpp \
	  main.cpp
HEADER = Bureaucrat.hpp \
		 AForm.hpp \
		 PresidentialPardonForm.hpp \
		 RobotomyRequestForm.hpp \
		 Intern.hpp \
		 ShrubberyCreationForm.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(HEADER)

clean:
	rm -rf *_shrubbery
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
