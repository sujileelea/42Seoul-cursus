# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 17:57:27 by sujilee           #+#    #+#              #
#    Updated: 2021/11/18 18:28:36 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 := checker
NAME2 := push_swap

CC :== gcc
CFLAGS = -Wall -Wextra -Wextra -g
INCLUDE := -I./INCLUDE
RM := rm -rf

LIBFT := libft.a
LIBFT_DIR := ./libft

SRCS := checker.c push_swap.c parse.c sort.c sort_tool.c common_rules.c
command.c command2.c
OBJ_DIR := ./obj
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all : $(NAME1) $(NAME2)
	@echo "(つ ◕▽◕)つ checker, push_swap is complete! c(◕▽◕ c)"

$(NAME1) : $(OBJS1) $(LIBFT_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS1) $(INCLUDE) $(LIBFT_DIR)/$(LIBFT) -o $(NAME1)
	@echo "(つ >_<)つ    checker has been created!    c(>_< c)"

$(NAME2) : $(OBJS2) $(LIBFT_DIR)/$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS2) $(INCLUDE) $(LIBFT_DIR)/$(LIBFT) -o $(NAME2)
	@echo "(つ ^o^)つ   push_swap has been created!   c(^o^ c)"

$(OBJ_DIR)/%.o : ./%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) all -C $(LIBFT_DIR)
	@echo "(つ 0◇0)つ    libft.a has been created!    c(0◇0 c)"

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@$(RM) $(OBJ_DIR)/*.o

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@$(RM) $(NAME1) $(NAME2)

re : fclean all

.PHONY : all bonus clean fclean re