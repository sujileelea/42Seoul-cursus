SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = Weapon

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re