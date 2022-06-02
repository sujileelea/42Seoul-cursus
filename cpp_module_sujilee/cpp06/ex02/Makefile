# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 16:23:20 by sujilee           #+#    #+#              #
#    Updated: 2022/06/02 18:46:06 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Base
CFLAGS := -Wall -Wextra -Werror -std=c++98
CC := c++
RM := rm -rf

SRC := main.cpp A.cpp B.cpp C.cpp Base.cpp
OBJ := $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re%