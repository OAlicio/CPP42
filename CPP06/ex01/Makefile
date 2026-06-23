NAME = serialize
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
HEADERS = Data.hpp Serializer.hpp
SRCS = Data.cpp \
	   Serializer.cpp \
	   main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS) : $(HEADERS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
