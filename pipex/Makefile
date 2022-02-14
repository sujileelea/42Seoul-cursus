# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 09:56:20 by sujilee           #+#    #+#              #
#    Updated: 2022/02/14 09:56:20 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	pipex

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	srcs/pipex.c\
			srcs/ft_split.c\
			srcs/ft_strdup.c\
			srcs/ft_strjoin.c\
			srcs/ft_strncmp.c\
			srcs/utils.c
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re:	fclean all

.PHONY: all clean fclean re