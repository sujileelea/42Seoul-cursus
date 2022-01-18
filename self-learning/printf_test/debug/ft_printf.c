/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 21:18:05 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/05 17:29:16 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	init_option(t_option *option)
{
	option->minus = 0;
	option->zero = 0;
	option->width = 0;
	option->dot = 0;
	option->prec = 0;
	option->spec = 0;
	option->factor_len = 0;
	option->space_len = 0;
	option->zero_len = 0;
}

int		ft_printf(const char *str, ...)
{
	char *format;
	t_option option;
	va_list	ap;
	
	format = (char *)str;
	va_start(ap, str);
	init_option(&option);
	option.size = 0;
	parse_format(ap, format, &option);
	va_end(ap);
	return (option.size);
}

int	main(void)
{
	ft_printf("%5.4d\n", 17);
	return (0);
}

