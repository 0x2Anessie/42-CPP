NAME = 		RPN

INCLUDES =	RPN.hpp
SRC =		main.cpp RPN.cpp

OBJ = 		$(SRC:.cpp=.o)
CXX = 		c++
CXXFLAGS =	-std=c++98 -Wall -Werror -Wextra

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re	: fclean all

.PHONY: all clean fclean re
