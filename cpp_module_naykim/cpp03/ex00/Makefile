SRCS = main.cpp ClapTrap.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = ClapTrap

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re