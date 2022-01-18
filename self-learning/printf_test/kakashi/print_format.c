/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 04:13:04 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/02 05:04:04 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_space(t_option *option, long long data)
{
	if (option->spec == 's' || option->spec == 'c'
			|| optpion->spec == '%')
	{
		if (option->zero && !option->minus && !option->dot &&
				!option->prec)
			return ;
		if (option->prec && option->prec < option->data_len)
			option->space_len = option->width - option->prec;
		else
			option->space_len = option->idth - option->data_len;
	}
	else // 'd' 'i' 'u' 'p' 'x' 'X'
	{
		if (option->data_len < option->prec)
			option->space_len = option->width - option->prec;
		else
			option->space_len = option->width - option->data_len; // 여기까지 공백 들어오는 경우
		option->spec == 'p' ? option->space_len -= 2 : 0; // 0x를 출력할 자리를 빼줌
		if (option->zero && !option->dot && !option->prec) // 정밀도 없이 0 플래그만 들어오면
			option->space_len -= option->width - option->data_len;
	} //여기까지 공백 개수 세줌
	while (option->space_len-- > 0) // 그렇게 센 공백을 출력
		ft_putchar(' ', option); 
}

static void	print_zero(t_option *option, long long data)
{
	if (option->spec == 's' || option->spec == 'c' || option->spec == '%')
	{
		if (option->zero && !option->minus)
			option->zero_len = option->width - option->data_len;
	}
	else // 'd' 'i' 'u' 'p' 'x' 'X'
	{
		if (option->zero && !option->dot && !option->prec) // 정밀도 없이 0 플래그만 들어오면
		{
			option->zero_len = option->width - option->data_len;
			data < 0 ? option->zero_len-- : 0; // data가 음수면 '-'자리 확보
		}
		else
			option->zero_len = option->prec - option->data_len; //이건 정밀도의 0임(위는 플래그)
	}
	while (option->zero_len-- > 0) //위에서 센 0의 개수만큼 출력
		ft_putchar('0', option);
}

static void	print_diuxXp(va_list ap, t_option *option)
{
	char		*base;
	long long 	data; //가변인자로 받아오는 데이터

	if (option->spec == 'd' || option->spec == 'i')
		data = va_arg(ap, int);
	else if (option->spec == 'u' || option->spec == 'x' ||
			option->spec == 'X')
		data = va_arg(ap, unsigned int);
	else
		data = va_arg(ap, unsigned long);
	if (option->spec == 'd' || option->spec == 'i'
			option->spec == 'u')
		base = "0123456789";
	else if (option->spec == 'x')
		base = "0123456789abcdef";
	else // 'X'
		base = "0123456789ABCDEF";
	option.data_len = data < 0 ? nbrlen_base(data * -1, base, option) : 
		nbrlen_base(data, base, option); //data_len을 구함(음양 기준)
	option->minus == 0 ? print_space(option, data) : 0; //minus플래그 없으면 여기서 공백 출력
	data < 0 ? ft_putchar('-', option) : 0; // data가 음수면 '-'부호 출력
	option->spec == 'p' ? ft_putstr("0x", option) : 0;//'p'의 경우는 앞에 0x 붙여서 출력
	print_zero(option, data); // 0 패딩 출력
	data < 0 ? putnbr_base(-1 * data, base, option) : 
		putnbr_base(data, base, option); // 알짜배기 숫자 출력
	option->minus == '1' ? print_space(option, data) : 0; //minus플래그 있으면 여기서 공백 출력
}
	
void	print_format(va_list ap, t_option *option)
{
	if (option->spec == 'd' || option->spec == 'i' || option->spec == 'u'
	|| option->spec == 'x' || option->spec == 'X' || option->spec == 'p')
		printf_diuxp(ap, option);
	else if (option->spec == 's' || option->spec == 'c'
			|| option->spec-> '%')
		print_sc(ap, option);
}
