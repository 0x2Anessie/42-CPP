# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acatusse <acatusse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 18:03:51 by acatusse          #+#    #+#              #
#    Updated: 2024/09/24 18:03:53 by acatusse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp
NAME = brain
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = -std=c++98 -Wall -Werror -Wextra
CXX = c++

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
