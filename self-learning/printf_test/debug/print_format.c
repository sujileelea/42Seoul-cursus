/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 07:22:57 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/05 17:22:18 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	find_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

static void	print_space(long long factor, t_option *option)
{	
	int	max;

	max = find_max(option->factor_len, 
			find_max(option->width, option->prec));
	if (option->spec == 'd' || option->spec == 'i' || option->spec == 'u')
	{
		if (max == option->width)
		{
			if (option->factor_len >= option->prec)
				option->space_len = option->width - option->factor_len;
			else
				option->space_len = option->width - option->prec;
		}
		if (option->zero && !option->dot && !option->prec)
			option->width = 0;
	}
	printf("space_len : %d\n", option->space_len);
	while (option->space_len--)
	{
		ft_putchar(' ', option);
		printf("tratrash: %d\n", option->space_len);
		printf("size : %d\n", option->size);
	}
}

static void	print_zero(long long factor, t_option *option)
{
	if (option->spec == 'd' || option->spec == 'i' ||
			option->spec == 'u')
	{
		if (option->zero && !option->dot && !option->prec)
		{
			option->zero = option->width - option->factor_len;
			if (factor < 0)
				option->zero -= 1;
		}
		else if (option->dot && option->prec)
			option->zero_len = option->prec - option->factor_len;
	}
	printf("zero_len : %d\n", option->zero_len);
	while (option->zero_len--)
		ft_putchar('0', option);
}

void		print_diu(va_list ap, t_option *option)
{
	long long	factor;

	if (option->spec == 'd' || option->spec == 'i')
		factor = va_arg(ap, int);
	else if (option->spec == 'u')
		factor = va_arg(ap, unsigned int);
	printf("factor : %lld\n", factor);
	if (factor < 0)
		option->factor_len = nbrlen_base(factor * -1, option);
	else
		option->factor_len = nbrlen_base(factor, option);
	printf("factor_len : %d\n", option->factor_len);
	if (option->minus == 0)
		print_space(factor, option);
	if (factor < 0)
		ft_putchar('-', option);
	print_zero(factor, option);
	if (factor < 0)
		putnbr_base(factor * -1, option);
	else
		putnbr_base(factor, option);
	if (option->minus == '1')
		print_space(factor, option);
}

void	print_format(va_list ap, t_option *option)
{
	if (option->spec == 'd' || option->spec == 'i' 
			|| option->spec == 'u')
		print_diu(ap, option);
	printf("size : %d\n", option->size);
}
