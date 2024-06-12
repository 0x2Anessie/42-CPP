NAME		=	phonebook
INCLUDES	=	Contact.hpp PhoneBook.hpp
SRCS			=	PhoneBook.cpp Contact.cpp main.cpp
CC			=	c++
FLAGS		=	-std=c++98 -Wall -Werror -Wextra
RM			=	rm -f
OBJ			=	$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean	:
	@$(RM) $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
