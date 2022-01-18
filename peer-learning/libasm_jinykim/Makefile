CC			=   nasm	
CFLAGS		=   -f macho64 # -macosx_version_min 10.7.0 -no_pie 
NAME		=	libasm.a
SRCS		=	srcs/ft_strlen.s srcs/ft_strcpy.s  srcs/ft_strcmp.s srcs/ft_write.s srcs/ft_read.s srcs/ft_strdup.s
OBJS		=	$(SRCS:.s=.o)
AR			=	ar
ARFLAGS		=	-rc

.s.o : $(SRCS) 
	$(CC) $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

bonus : 

re : fclean all
