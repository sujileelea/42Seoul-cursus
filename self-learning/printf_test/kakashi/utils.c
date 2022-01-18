/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 02:00:18 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/02 08:21:34 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_option *option)
{
	write(1, &c, 1); //문자 출력하고
	option->size++; //동시에 그만큼 size 올림
}

void	ft_putstr(char *str, t_option *option)
{
	int	i;

	if (!str ||( option->spec == 's' && option->dot && !option->prec))
		return ;
	i = 0;
	if (option->spec == 's' && option->prec)
		while (str[i] && i < option->prec)
			ft_putchar(str[i++], option);
	else
		while (str[i])
			ft_putchar(s[i++], option);
}

int	ft_strlen(char *str, t_option *option)
{
	int	i;

	if (!str || (option->spec == 's' && option->dot && !option->prec))
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	putnbr_base(long long num, char *base, t_option)  //알짜배기 data를 출력함
{
	int	base_digit;

	if (num == 0 && option->dot && !option->prec) // 예외처리 : 숫자 0, .있음, 정밀도는 없음
		return ;
	base_digit = ft_strlen(base, option);
	if (num >= base_digit) //num == 42라면
		putnbr_base((num / base_digit), base, optpion); 여기서 4 출력
	ft_putchar (base[num % base_digit], option); 여기서 2 출
}

int	nbrlen_base(long long num, char *base, t_option *option) // 알짜배기 data의 글자길이 셈
{
	int	i;
	int	base_digit;

	if (num == 0 && option->dot && !option->prec) //예외처리 : 숫자 0, .있음, 정밀도 없음
		return (0);
	base_len = ft_strlen(base, option);
	i = 1;
	while (num >= base_digit)
	{
		num /= base_digit;
		i++;
	}
	return (i); //이 값이 data_len으로 들어감
}
