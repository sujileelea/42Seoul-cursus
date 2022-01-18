/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:01:38 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/05 17:26:04 by sujilee          ###   ########.fr       */
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
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str, t_option *option)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	putnbr_base(long long num, t_option *option) 
{
	char	*number;


	if (num == 0 && option->dot && !option->prec)
		return ;
	number = ft_itoa((int)num);
	ft_putstr(number, option);
	option->size += ft_strlen(number, option);
}

int	nbrlen_base(long long num, t_option *option)
{
	int	i;

	i = 1;
	if (num == 0 && option->dot && !option->prec)
		return (0);
	while (num >= 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}
