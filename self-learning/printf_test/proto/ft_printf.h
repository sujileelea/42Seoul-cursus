#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../42seoul-libft/libft/libft.h"

//#define TYPE "csdiupxX%"

typedef struct s_option  //결과값을 0과 1로 함 - 불리안
{ 
	int	zero;
	int	minus;
	int	star;
	int	width;
	int	prec;
	int	spec;
	
}		t_option;

int	ft_putchar(char c);
void	 init_option(t_option *option);
int	specifier_yes(char c);
int	handle_specifier(const char *str, t_option option, va_list ap);
void	handle_minus(t_option *option);
void	handle_width(char c, t_option *option);
void	handle_star(t_option *option, va_list ap);
int	handle_dot(const char *str, t_option *option, va_list ap);
int	parse_option(const char *str, t_option *option, va_list ap);
int	parse_format(const char *str, va_list ap);
int	ft_printf(const char *format, ...);
char	*ft_strjoin_custo(char *str1, char *str2);
int	hanle_specifier(const char *str, t_option option, va_list ap);
int	find_max(int a, int b);
char	*make_sting(int count, char c);
char	*get_affix(t_option option);
int	handle_integer(int num, t_option option, va_list ap);

#endif
