SRCS = main.cpp Karen.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = karenFilter

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re