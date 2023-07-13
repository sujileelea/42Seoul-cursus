NAME	=	minishell
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRCS	=	srcs/main.c \
			srcs/signal.c \
			srcs/term.c \
			srcs/cmd_utils.c \
			srcs/cmd1.c \
			srcs/utils.c \
			srcs/input.c \
			srcs/pipe.c \
			srcs/execute.c \
			srcs/execute_utils.c \
			srcs/execute_check.c \
			srcs/quote.c \
			srcs/quote2.c \
			srcs/dollar.c \
			srcs/ft_pwd.c \
			srcs/ft_echo.c \
			srcs/ft_cd.c \
			srcs/ft_env.c \
			srcs/ft_exit.c \
			srcs/ft_export.c \
			srcs/ft_unset.c \
			srcs/utils_string.c \
			srcs/execute_utils2.c \
			srcs/ft_pipe_split.c \
			srcs/heredoc.c
			
INCS	=	-I includes -I libft
OBJS	=	$(SRCS:.c=.o)
LIBFT	=	libft/libft.a
LFT		=	-L libft -lft -lncurses

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFT) $(INCS)

$(LIBFT) :
	@make bonus -C libft/

.c.o :
	$(CC) -c $< -o $@ $(INCS)

clean :
	@make clean -C libft/
	rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft/
	rm -rf $(NAME)

re : fclean all
