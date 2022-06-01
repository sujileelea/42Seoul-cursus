SRCS = main.cpp Bureaucrat.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra -std=c++98

NAME = Bureaucrat

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re