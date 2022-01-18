/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:05:47 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/11 18:28:47 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_option *option)
{
	write(1, &c, 1);
	option->size++;
}

void	ft_putstr(char *str, t_option *option)
{
	int	i;

	i = 0;
	if (!str || (option->spec == 's' && option->dot && !option->prec))
		return ;
	if (option->spec == 's' && option->prec)
	{
		while (str[i] && i < option->prec)
		{
			ft_putchar(str[i], option);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			ft_putchar(str[i], option);
			i++;
		}
	}
}

int		ft_strlen(char *str, t_option *option)
{
	int	i;

	i = 0;
	if (!str || (option->spec == 's' && option->dot && !option->prec))
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		nbrlen_base(long long n, char *base, t_option *option)
{
	int	i;
	int	digit;

	if (n == 0 && option->dot && !option->prec)
		return (0);
	digit = ft_strlen(base, option);
	i = 1;
	while (n >= digit)
	{
		n /= digit;
		i++;
	}
	return (i);
}

void	putnbr_base(long long n, char *base, t_option *option)
{
	int	digit;

	if (n == 0 && option->dot && !option->prec)
		return ;
	digit = ft_strlen(base, option);
	if (n >= digit)
		putnbr_base((n / digit), base, option);
	ft_putchar(base[n % digit], option);
}
