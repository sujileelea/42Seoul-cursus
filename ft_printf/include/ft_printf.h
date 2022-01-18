/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:27:12 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/11 21:22:39 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_option
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			prec;
	int			spec;
	int			factor_len;
	int			space_len;
	int			zero_len;
	int			size;
	int			error;
}				t_option;

int				ft_printf(const char *str, ...);
void			init_option(t_option *option);
int				parse_flag(char *str, int i, t_option *option);
int				parse_width(char *str, int i, t_option *option, va_list ap);
int				parse_prec(char *str, int i, t_option *option, va_list ap);
int				parse_spec(char *str, int i, t_option *option);
void			parse_format(char *str, t_option *option, va_list ap);
void			print_format(va_list ap, t_option *option);
void			print_space(long long factor, t_option *option);
void			print_zero(long long factor, t_option *option);
void			print_dtop(va_list ap, t_option *option);
void			print_ctos(va_list ap, t_option *option);
void			ft_putchar(char c, t_option *option);
void			ft_putstr(char *str, t_option *option);
int				ft_strlen(char *str, t_option *option);
int				nbrlen_base(long long n, char *base, t_option *option);
void			putnbr_base(long long n, char *base, t_option *option);
char			*set_base(char *base, t_option *option);
void			get_ctoslen(int c_factor, char *s_factor, t_option *option);
void			get_dtoplen(long long factor, char *base, t_option *option);
void			print_exceptional(long long factor, t_option *option);

#endif
