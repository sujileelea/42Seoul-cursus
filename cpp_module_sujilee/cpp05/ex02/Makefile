# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 16:23:20 by sujilee           #+#    #+#              #
#    Updated: 2022/06/01 16:33:38 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := EXECUTE
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
RM := rm -rf

SRC := main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
OBJ := $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ) $(wildcard *_shrubbery)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re