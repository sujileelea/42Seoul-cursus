/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:44:27 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/05 17:20:20 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_option
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	prec;
	int	spec;
	int	factor_len;
	int	space_len;
	int	zero_len;
	int	size;
}		t_option;

void	init_option(t_option *option);
int	ft_printf(const char *str, ...);
void	parse_format(va_list ap, char *str, t_option *option);
void	print_format(va_list ap, t_option *option);
void	print_diu(va_list ap, t_option *option);
void	ft_putchar(char c, t_option *option);
void	ft_putstr(char *str, t_option *option);
void	putnbr_base(long long num, t_option *option);
int	nbrlen_base(long long num, t_option *option);
char	*ft_itoa(int n);

#endif
