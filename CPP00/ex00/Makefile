NAME		=	megaphone
SRC		=	megaphone.cpp
CC			=	c++
CFLAGS		=	-std=c++98 -Wall -Werror -Wextra
RM			=	rm -f
OBJS		=	$(SRC:.cpp=.o)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME)	:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS)

clean	:
	@$(RM) $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re