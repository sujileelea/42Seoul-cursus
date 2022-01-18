/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 05:28:05 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/05 17:29:10 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	parse_flag(char *str, int i, t_option *option)
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

static int	parse_width(char *str, int i, t_option *option, va_list ap)
{
	if (str[i] == '*')
	{
		option->width = va_arg(ap, int);
		if (option->width < 0)
		{
			option->width *= -1;
			option->minus = 1;
			option->zero = 0;
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

static int	parse_prec(char *str, int i, t_option *option, va_list ap)
{
	if (str[i] == '.')
	{
		option->dot = 1;
		i++;
		if (str[i] == '*')
			option->prec = va_arg(ap, int);
		while (str[i] >= '0' && str[i] <= '9')
		{
			option->prec = (option->prec * 10) + (str[i] - '0');
			i++;
		}
		if (option->prec < 0)
		{	
			option->prec = 0;
			option->dot = 0;
		}
	}
	return (i);
}

static int	parse_spec(char *str, int i, t_option *option)
{
	char c;

	c = str[i];
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || 
			c == 'p' || c == 's' || c == 'c')
		option->spec = c;
	i++;
	return (i);
}

void	parse_format(va_list ap, char *str, t_option *option)
{

	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++; // i = 1
			i = parse_flag(str, i, option); // i = 1
			i = parse_width(str, i, option, ap); // i = 2
			printf("width : %d\n", option->width);
			printf("%d\n", i);
			i = parse_prec(str, i, option, ap); //i = 4
			printf("prec : %d\n", option->prec);
			printf("%d\n", i);
			i = parse_spec(str, i, option); //i = 5
			printf("spec : %d\n", option->spec);
			printf("%d\n", i);
			print_format(ap, option);		
			init_option(option);
		}
		else
		{
			ft_putchar(str[i], option);
			i++;
			printf("size : %d\n", option->size);
		}
	}

}
