/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:40:41 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/11 21:22:07 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_base(char *base, t_option *option)
{
	if (option->spec == 'd' || option->spec == 'i' || option->spec == 'u')
		base = "0123456789";
	else if (option->spec == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (base);
}

void	get_ctoslen(int c_factor, char *s_factor, t_option *option)
{
	if (option->spec == 's')
		option->factor_len = ft_strlen(s_factor, option);
	else
		option->factor_len = 1;
}

void	get_dtoplen(long long factor, char *base, t_option *option)
{
	if (factor < 0)
		option->factor_len = nbrlen_base(factor * -1, base, option);
	else
		option->factor_len = nbrlen_base(factor, base, option);
}

void	print_exception(long long factor, t_option *option)
{
	if (factor < 0)
		option->space_len--;
	if (option->spec == 'p')
		option->space_len -= 2;
}
