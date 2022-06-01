SRCS = Contact.cpp PhoneBook.cpp main.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra

NAME = PhoneBook

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re
