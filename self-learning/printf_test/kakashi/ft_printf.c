/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:19:48 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/02 09:24:52 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	init_info(t_option *option)
{
	option->minus = 0;
	option->zero = 0;
	option->width = 0;
	option->dot = 0;
	option->prec = 0;
	option->spec = 0;
	option->data_len = 0;
	option->space_len = 0;
	option->zero_len = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_option option;
	//char	*format;

	//format = (char *)str;
	init_option(&option); //구조체의 주소값을 넣음
	option.size = 0;
	va_start(ap, str);
	parse_format(ap, (char *)str, &option); //(ap, format, &opt)
	va_end(ap);
	return (option.size);
}
