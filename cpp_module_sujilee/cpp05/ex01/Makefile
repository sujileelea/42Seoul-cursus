SRCS = main.cpp Bureaucrat.cpp Form.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra -std=c++98

NAME = Form

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re