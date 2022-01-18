/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:01:38 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/04 20:18:29 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_option *option)
{
	문자 출력하고
	그만큼 size 올림
}

void	ft_putstr(char *str, t_option *option)
{
	s 경우 처리
	putstr 함수 구현
}

int		ft_strlen(char *str, t_option *option)
{
	s 경우 처리
	strlen 함수 구현
}

void	putnbr_base(long long num, char *base, t_option *option) 
{
	//알짜배기 data를 base에 따라 출력함
	예외처리 : 숫자로 0이 들어오고, . 이 있으며, 정밀도가 없을떄
}

void	nbrlen_base(long long num, char *base, t_option *option)
{
	//알짜배기 data의 글자길이를 base에 따라 셈
	//여기 넘어오는 num은 전부 양수 처리 돼서 넘어옴
	예외처리 : 숫자로 0 들어오고, .이 있으며, 정밀도 없을때
}
