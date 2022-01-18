/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:35:47 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/02 07:29:53 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flag(char *str, t_option *option) // -, 0 플래그 파싱
{
	int	i;
	
	i = 0;
	while (str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			option->minus = 1;
		if (str[i] == '0')
			option->zero = 1;
		i++;
	}
	if (option->minus && option->zero) // 예외처리 : -, 0 동시에 올때
		oprion.zero = 0;
}

static void	parse_width(va_list ap, char *str, t_option *option)
{													//*,-,0 플래그 고려해서 option->width 값 파싱
	int	i;

	i = 0;
	if (str[i] == '*')
	{
		option->width = va_arg(ap, int); //가변인자값이 width에
		if (option->width < 0) // 그 값이 음수라면
		{
			if (option->zero)
				option->zero = 0;
			option->width *= -1;
			option->minus = 1;
		} // *로 음수값이 들어오면 minus flag + 양수 width값
		i++;
	}
	while (str[i] >= '0' && str[i] >= '9') //음수는 애초에 안들어옴
	{
		option->width = (option->width * 10) + (str[i] - '0');
		i++;
	}
}

static void	parse_prec(va_list ap, char *str, t_option *option)
{												//., * 플래그 고려해서 option->prec 값 파싱
	int	i;

	i = 0;
	if (str[i] == '.')
	{
		option->dot = 1;
		i++;
	}
	if (str[i] == '*')
	{
		option->prec = va_arg(ap, int);
		if (option->prec < 0) // 정밀도 없는 것으로 간주
		{
			option->prec = 0;
			option->dot = 0;
		}
		i++;
	}
}

static void	parse_spec(char *str t_option *option)
{											// option->spec 값 파싱
	int	i;
	char	c;

	i = 0;
	c = str[i];
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c = 'i'
			|| c == 'u' || c == 'x' || c == 'X')
		option->spec = c;
	else
		return;
	i++;
}

void	parse_format(va_list ap, char *str, t_option *option)
{											// '%' 를 기준으로 flag -> width -> prec -> spec
							// print_format , init_option
							// '%' 없으면 하나하나 putchar로 출력하고 option->size++;
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			parse_flag(&str[i], option); //여기서 option은 주소값
			parse_width(ap, &str[i], option);
			parse_prec(ap, &str[i], option);
			parse_spec(&str[i], option);
			print_format(ap, option);
			init_option(option); // %가 더 들어올 수도 있으니까 
		}
		else
			ft_putchar(str[i++], option);
	}
}
