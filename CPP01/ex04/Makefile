# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/30 11:50:10 by acatusse          #+#    #+#              #
#    Updated: 2024/09/30 14:51:43 by acatusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = Replace.hpp
SRC = main.cpp Replace.cpp
NAME = replace
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra
CXX = c++

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME)	: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

filename:
	echo "coucou coucou coucou ca va ?" > filename

filename.replace:
	echo "hello" > filename.replace

all	: $(NAME) filename filename.replace

clean	:
	rm -rf $(OBJ) filename filename.replace

fclean	: clean
	rm -rf $(NAME)

re	: fclean all

.PHONY: all clean fclean re filename filename.replace
