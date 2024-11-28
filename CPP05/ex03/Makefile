NAME = 		Intern
INCLUDES =	Bureaucrat.hpp Intern.hpp AForm.hpp ShrubberyCreationForm.hpp \
			RobotomyRequestForm.hpp PresidentialPardonForm.hpp
SRC =		main.cpp Bureaucrat.cpp Intern.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp

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
