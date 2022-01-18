/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 05:28:05 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/03 21:40:02 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft"

파싱해야할 문자 덩어리가 두 글자 이상이면 while 문으로 돌려야

static void		parse_flag(char *str, t_option *option)
{
	-, 0 플래그 파싱
	예외 처리 : -, 0 동시에 올때
}

static void		parse_width(va_list ap, char *str, t_option *option)
{
	*, -, 0 플래그 고려해서 option->width 값 파싱
		str[i] == '*'라면
		가변인자 값을 width에 
		그 값이 음수라면
		...
		*로 음수값이 들어오면 minus flag + 양수 width값
		0~9일때 파싱
		예외ㅓ처리 : %00d 이런식으로 들어오면 그냥 출력함
}

static void		parse_prec(va_list ap, char *str, t_option *option)
{
	., * 플래그 고려해서 option->prec 값 파싱
	
		예외처리 : prec이 음수로 들ㅇ어오면 정밀도, . 없는 것으로 간주
}

static void		parse_spec(char *str, t_option *option)
{
	option->spec 값 파싱
	그 외는 함수를 리턴시킴
}

void	parse_format(va_list ap, char *str, t_option *option)
{
	포맷을 인덱스 돌리며 파싱하며 
		flag -> width -> prec ->spec 순으로 파싱하는 함수
		print_format(ap, option)
		init_option (%가 두번씩 들어올 수도 있으니까)
		
		저게 아니라면 그냥 putchar로 바로바로 출력
}
