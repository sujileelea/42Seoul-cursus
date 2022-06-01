SRCS = main.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = replace
NEW_FILE = *.replace

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME) $(NEW_FILE)

re: clean all

.PHONY: all clean re