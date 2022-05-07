# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 16:23:20 by sujilee           #+#    #+#              #
#    Updated: 2022/05/07 13:09:37 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME := DiamondTrap
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
RM := rm -rf

SRC := main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
OBJ := $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re