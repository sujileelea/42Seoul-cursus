/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 20:15:54 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/11 21:25:23 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_space(long long factor, t_option *option)
{
	if (option->spec == 's' || option->spec == 'c' || option->spec == '%')
	{
		if (option->zero && !option->minus && !option->dot && !option->prec)
			return ;
		if (option->prec && option->prec < option->factor_len)
			option->space_len = option->width - option->prec;
		else
			option->space_len = option->width - option->factor_len;
		if (option->spec == '%' && option->zero && !option->minus
				&& option->width && option->dot)
			return ;
	}
	else
	{
		if (option->prec > option->factor_len)
			option->space_len = option->width - option->prec;
		else
			option->space_len = option->width - option->factor_len;
		print_exception(factor, option);
		if (option->zero && !option->dot && !option->prec)
			option->space_len -= option->width - option->factor_len;
	}
	while (option->space_len-- > 0)
		ft_putchar(' ', option);
}

void	print_zero(long long factor, t_option *option)
{
	if (option->spec == 's' || option->spec == 'c' || option->spec == '%')
	{
		if (option->zero && !option->minus)
			option->zero_len = option->width - option->factor_len;
	}
	else
	{
		if (option->zero && !option->dot && !option->prec)
		{
			option->zero_len = option->width - option->factor_len;
			if (factor < 0)
				option->zero_len--;
		}
		else
			option->zero_len = option->prec - option->factor_len;
	}
	while (option->zero_len-- > 0)
		ft_putchar('0', option);
}

void	print_dtop(va_list ap, t_option *option)
{
	char		*base;
	long long	factor;

	if (option->spec == 'd' || option->spec == 'i')
		factor = va_arg(ap, int);
	else if (option->spec == 'u' || option->spec == 'x' || option->spec == 'X')
		factor = va_arg(ap, unsigned int);
	else
		factor = va_arg(ap, long long);
	base = set_base(base, option);
	get_dtoplen(factor, base, option);
	if (!option->minus)
		print_space(factor, option);
	if (factor < 0)
		ft_putchar('-', option);
	if (option->spec == 'p')
		ft_putstr("0x", option);
	print_zero(factor, option);
	if (factor < 0)
		putnbr_base(factor * -1, base, option);
	else
		putnbr_base(factor, base, option);
	if (option->minus)
		print_space(factor, option);
}

void	print_ctos(va_list ap, t_option *option)
{
	char	*s_factor;
	int		c_factor;

	c_factor = 0;
	s_factor = 0;
	if (option->spec == 's')
		s_factor = va_arg(ap, char *);
	else if (option->spec == 'c')
		c_factor = va_arg(ap, int);
	else
		c_factor = '%';
	if (s_factor == NULL)
		s_factor = "(null)";
	get_ctoslen(c_factor, s_factor, option);
	if (!option->minus)
		print_space(0, option);
	print_zero(0, option);
	if (option->spec == 's')
		ft_putstr(s_factor, option);
	else
		ft_putchar(c_factor, option);
	if (option->minus)
		print_space(0, option);
}

void	print_format(va_list ap, t_option *option)
{
	if (option->spec == 'd' || option->spec == 'i' || option->spec == 'u'
			|| option->spec == 'x' || option->spec == 'X'
			|| option->spec == 'p')
		print_dtop(ap, option);
	else if (option->spec == 'c' || option->spec == 's' || option->spec == '%')
		print_ctos(ap, option);
}
