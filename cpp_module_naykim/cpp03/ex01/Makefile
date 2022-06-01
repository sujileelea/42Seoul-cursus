SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = ScavTrap

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re