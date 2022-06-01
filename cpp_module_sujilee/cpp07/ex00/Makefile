SRCS = main.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra -std=c++98

NAME = Whatever

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re