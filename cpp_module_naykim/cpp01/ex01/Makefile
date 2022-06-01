SRCS = Zombie.cpp zombieHorde.cpp main.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = ZombieHorde

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re