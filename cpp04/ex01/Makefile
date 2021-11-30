NAME = brain

SOURCES_FILES = Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	WrongAnimal.cpp \
	WrongCat.cpp \
	Brain.cpp \
	main.cpp

HEADER_FILES = Animal.hpp \
	Cat.hpp \
	Dog.hpp \
	WrongAnimal.hpp \
	WrongCat.hpp \
	Brain.hpp

OBJS = $(SOURCES_FILES:.cpp=.o)

CPPFLAGS = -Wall -Werror -Wextra
CC = clang++ -std=c++98

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
