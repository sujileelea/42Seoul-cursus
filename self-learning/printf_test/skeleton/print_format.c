/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 07:22:57 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/04 17:48:58 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_space(t_option *option, long long data) //long long data is changable
{
	s c % 의 경우

	d i u p x X의 경우
	공백이 들어오는 갯수 세줌
	p의 경우 0x를 출력할 자리만큼 개수 뺌
	경우 처리 : 정밀도 없이 0플래그만 들어오는 경우 공백개수
	그렇게 센 공백을 출력
}

static void		print_zero(t_option *option, long long data) //long long data is changable
{
		s c %의 경우

		d i u x X p의 경우
		정밀도 없이 0플래그만 들어올때 
			0 개수 세고 data가 음수일때 - 자리 확보
		정밀도의 0이 들어오는 경우
		그렇게 센 0 출력
}

static void		print_diuxXp(va_list ap, t_option *option)
{
	d, i : 가변인자 int만큼 받아오기
	U X X : 가변인자 unsigned int만큼 받아오기
	p : 가변인자 unsigned long만큼 받아오기
	케이스마다 진수에 값 대입하기

	factor에 가변인자의 값을 받음
	data_len을 구함
	minus 플래그 없으면 공백 출력
	data가 음수면 '-'부호 출력
	p의 경우에는 0x 출력
	0패딩 출력
	알짜배기 숫자 출력
	minus플래그 있으면 여기서 공백 출력
}	

void	print_format(va_list ap, t_option *option)
{
	d i u x x p 면 print_diuxXp
		그외는 print_sc
}
