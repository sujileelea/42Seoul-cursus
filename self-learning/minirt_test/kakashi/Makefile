# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/16 16:31:52 by sujilee           #+#    #+#              #
#    Updated: 2021/05/16 18:38:56 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

BONUS_NAME = miniRT_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

UTILS = utils/

LIBFT_FLAGS = -L ${UTILS}libft -lft -L ${UTILS}vec -lvec

MLX_FLAGS = -I minilibx -L ./minilibx -lmlx -framework OpenGL -framework Appkit

SRCS = $(addprefix ./srcs/. \
	   

BONUS_SRCS = $(addprefix ./srcs_bonus/, \
		camera_calc.c \
		color_calc.c \
		cylinder.c \
		error_checking.c \
		get_next_line.c \
		light_calc.c \
		make_bmpfile_utils.c \
		make_bmpfile.c \
		minirt.c \
		mlx_function.c \
		multithread.c \
		parse_utils1.c \
		parse_utils2.c \
		pares.c \
		parse1.c \
		parse2.c \
		parse3.c \
		parse4.c \
		pl_sq_tr.c \
		py_cu_.c \
		ray_trace.c \
		sample_pixel.c \
		sphere.c \
		supersample_utils.c \
		supersample.c \
		texture.c)

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

FLAGS = ${CFLAGS} ${LIBFT_FLAGS} ${MLX_FLAGS}

.PHONY : all clean fclean re

${NAME} : ${OBJS}
	make -C ${UTILS}libft
	make -C ${UTILS}vec
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

${BONUS_NAME} : ${BONUS_OBJS}
	make -C ${UTILS}libft
	make -C ${UTILS}vec
	${CC} ${FLAGS} ${BONUS_OBJS} -o ${BONUS_NAME}

bonus : ${BONUS_NAME}

clean : 
	make clean -C ${UTILS}libft
	make clean -C ${UTILS}vec
	rm -f ${OBJS}
	rm -f ${BONUS_OBJS}

fclean : clean
	make fclean -C ${UTILS}libft
	make fclean -C ${UTILS}vec
	rm -f ${NAME}
	rm -f ${BONUS_NAME}

re : fclean all