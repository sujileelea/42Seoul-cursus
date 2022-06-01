SRCS = megaphone.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = megaphone

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re
