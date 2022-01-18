#include <stdio.h>
#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	count;

	count = write(1, &c, 1);
	return (count);
	//return (1)로 그냥 count 변수 쓸 것 없이 해도 됨
}

void	init_option(t_option *option)
{
	option->zero = 0;
	option->minus = 0;
	option->star = 0;
	option->width = 0;
	option->prec = 0;
	option->spec = 0;
}

int	specifier_yes(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'c' || c == 's' ||
			c == 'x' || c == 'X')
		return (1);
	else
		return (0);
}

void	handle_minus(t_option *option)
{
	option->minus = 1;
	option->zero = 0;
}

void	handle_width(char c, t_option *option)
{
	if (option->star == 1)
		option->width = 0;
	option->width = (option->width * 10) + (c - '0');
}

void	handle_star(t_option *option, va_list ap)
{
	option->star = 1;
	option->width = va_arg(ap, int);
	if (option->width < 0)
	{
		option->minus = 1;   // minus flag on
		option->width *= -1;// width becomes positive number
	}
}

int	handle_dot(const char *str, t_option *option, va_list ap)
{
	int i;

	i = 0;
	if (str[i] == '*')
		option->prec = va_arg(ap, int);
	while (str[i] >= '0' && str[i] <= '9') 
	{	
		option->prec = (option->prec * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}

int	parse_option(const char *str, t_option *option, va_list ap)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (specifier_yes(str[i]))
			break;
		if (str[i] == '0' && option->minus == 0 && option->width == 0) // '0'이고 '-'플래그 없고(만나면
			option->zero = 1;										  //죽으니까) width값이 암것도 없을때
		if (str[i] == '-')
			handle_minus(option);
		if (str[i] == '*')
			handle_star(option, ap);
		if (str[i] >= '0' && str[i] <= '9')
			handle_width(str[i], option);
		if (str[i] == '.')
			i = handle_dot(&str[i + 1], option, ap);
		if (str[i] == '%')
			break;
		i++;
	}
		return (i + 1);
}

int	parse_format(const char *str, va_list ap)
{
	int i;
	int size;
	t_option	option;
	
	i = 0;
	size = 0;
	while (str[i])
	{
		init_option(&option); //flags의 모든 값을 0으로 초기화
		if (str[i] == '%' && str[i + 1])
		{
			i += parse_option(&str[i + 1], &option, ap);
			if (specifier_yes(str[i]))
				size += handle_specifier(&str[i], option, ap);
			else if (str[i])
				size += ft_putchar(str[i]);
		}
		else if (str[i] != '%')
			size += ft_putchar(str[i]);
		i++;
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		size; //printf로 stdout 출력하는 문자개수
	va_list 	ap; //가변인자를 가리킬 포인터 선언


	va_start(ap, format); //포인터 ap를 가변인자의 첫 주소에 위치시킴
	size += parse_format(format, ap);
	va_end(ap);
	return (size);
}

int	main(void)
{
	printf("return : %d\n", ft_printf("%d", 42));
	printf("answer : %d return : %d\n", 42, printf("%d\n", 42));
	return (0);
}
