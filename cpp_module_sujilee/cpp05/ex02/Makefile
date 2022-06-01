SRCS = main.cpp Bureaucrat.cpp Form.cpp\
	ShrubberyCreationForm.cpp\
	RobotomyRequestForm.cpp\
	PresidentialPardonForm.cpp

CPP = c++
FLAG = -Werror -Wall -Wextra -std=c++98

NAME = Forms

$(NAME): $(SRCS)
	$(CPP) $(FLAG) -o $(NAME) $(SRCS)

all: $(NAME)

clean:
	rm -f $(NAME) $(wildcard *_shrubbery)

re: clean all

.PHONY: all clean re