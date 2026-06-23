NAME = bases
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Base.cpp \
	   A.cpp \
	   B.cpp \
	   C.cpp \
	   TypeManager.cpp \
	   main.cpp

HEADERS = Base.hpp \
		  A.hpp \
	   	  B.hpp \
	   	  C.hpp \
	   	  TypeManager.h

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(HEADERS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
