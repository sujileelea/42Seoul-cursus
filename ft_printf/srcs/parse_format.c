/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 18:53:06 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/11 18:20:58 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_flag(char *str, int i, t_option *option)
{
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			option->minus = 1;
		if (str[i] == '0')
			option->zero = 1;
		i++;
	}
	if (option->minus && option->zero)
		option->zero = 0;
	return (i);
}

int		parse_width(char *str, int i, t_option *option, va_list ap)
{
	if (str[i] == '*')
	{
		option->width = va_arg(ap, int);
		if (option->width < 0)
		{
			if (option->zero)
				option->zero = 0;
			option->width *= -1;
			option->minus = 1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		option->width = (option->width * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int		parse_prec(char *str, int i, t_option *option, va_list ap)
{
	if (str[i] == '.')
	{
		option->dot = 1;
		i++;
	}
	if (str[i] == '*')
	{
		option->prec = va_arg(ap, int);
		if (option->prec < 0)
		{
			option->prec = 0;
			option->dot = 0;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		option->prec = (option->prec * 10) + str[i] - '0';
		i++;
	}
	return (i);
}

int		parse_spec(char *str, int i, t_option *option)
{
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'u' || str[i] == 'x'
			|| str[i] == 'X' || str[i] == 'p' || str[i] == 'c'
			|| str[i] == 's' || str[i] == '%')
		option->spec = str[i];
	else
		return (-1);
	i++;
	return (i);
}

void	parse_format(char *str, t_option *option, va_list ap)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			i = parse_flag(str, i, option);
			i = parse_width(str, i, option, ap);
			i = parse_prec(str, i, option, ap);
			i = parse_spec(str, i, option);
			print_format(ap, option);
			init_option(option);
		}
		else
		{
			ft_putchar(str[i], option);
			i++;
		}
	}
}
