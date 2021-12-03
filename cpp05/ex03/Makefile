NAME = intern

SOURCES_FILES = Bureaucrat.cpp \
	Form.cpp \
	Intern.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	main.cpp

HEADER_FILES = Bureaucrat.hpp \
	Form.hpp \
	Intern.hpp \
	ShrubberyCreationForm.hpp \
	RobotomyRequestForm.hpp \
	PresidentialPardonForm.hpp

OBJS = $(SOURCES_FILES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra
CC = c++ -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HEADER_FILES)
	@$(CC) $(CPPFLAGS) $(SOURCES_FILES) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
