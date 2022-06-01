SRCS = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = Zombie

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re