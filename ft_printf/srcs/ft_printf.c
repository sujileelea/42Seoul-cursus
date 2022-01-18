/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:34:24 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/11 18:17:37 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	option->error = 0;
}

int		ft_printf(const char *str, ...)
{
	t_option	option;
	char		*format;
	va_list		ap;

	format = (char *)str;
	va_start(ap, str);
	init_option(&option);
	option.size = 0;
	parse_format(format, &option, ap);
	va_end(ap);
	return (option.size);
}
