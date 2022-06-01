SRCS = AMateria.cpp Cure.cpp Ice.cpp\
		Character.cpp\
		MateriaSource.cpp\
		main.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra -std=c++98

NAME = Materia

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re