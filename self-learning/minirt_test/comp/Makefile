# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/11 00:08:51 by joockim           #+#    #+#              #
#    Updated: 2021/05/27 19:42:22 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = gcc

CFLAGS = -Wall -Werror -Wextra # -g -fsanitize=address

UTILS = utils/

LIBFT_FLAGS = -L ${UTILS}libft -lft -L ${UTILS}vec -lvec

MLX_FLAGS = -I minilibx -L ./minilibX -lmlx -framework OpenGL -framework AppKit

SRCS = $(addprefix ./srcs/, \
	   get_next_line.c \
	   error_check.c \
	   parse.c \
	   parse2.c \
	   parse3.c \
	   parse_utils.c \
	   parse_utils2.c\
	   sample_pixel.c \
	   camera_calc.c \
	   ray_tracing.c \
	   sphere.c \
	   pl_sq_tr.c \
	   cylinder.c \
	   light_calc.c \
	   color_calc.c \
	   make_bmpfile.c \
	   make_bmpfile_utils.c \
	   mlx_function.c \
	   minirt.c)

OBJS = ${SRCS:.c=.o}

FLAGS = ${CFLAGS} ${LIBFT_FLAGS} ${MLX_FLAGS}

.PHONY : all clean fclean re

${NAME} : ${OBJS}
	make -C ${UTILS}libft
	make -C ${UTILS}vec
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean :
	make clean -C ${UTILS}libft
	make clean -C ${UTILS}vec
	rm -f ${OBJS}

fclean : clean
	make fclean -C ${UTILS}libft
	make fclean -C ${UTILS}vec
	rm -f ${NAME}

re : fclean all
