#include "ft_printf.h"



char	*ft_strjoin_custom(char *str1, char *str2)
{
	int s1;
	int s2;
	int i;
	int j;
	char *result;

	s1 = ft_strlen(str1);
	s2 = ft_strlen(str2);
	if (!(result = (char *)malloc(sizeof(char) * (s1 + s2) + 1)))
		return (0);
	while (i < s1)
	{
		result[i] = str1[i];
		i++;
	}
	j = 0;
	while (j < s2)
	{
		result[i + j] = str2[j];
		j++;
	}
	result[i + j] = '\0';
	free(str1);
	free(str2);
	return (result);
}

int	handle_specifier(const char *str, t_option option, va_list ap)
{
	int size;
	int i;

	size = 0;
	i = 0;
	if (str[i] == 'd' || str[i] == 'i')
		size = handle_integer(va_arg(ap, int), option, ap);
	return (size);
}

int	find_max(int a, int b)
{
	if (a >= b)
		return (a);
	else if (a < b)
		return (b);
}

char	*make_string(int count, char c)
{
	int i;
	char *result;

	i = 0;
	result = (char *)malloc(sizeof(char) * count);
	while (i < count)
	{
		result[i] = c;
		i++;
	}
	return (result);
	//free
}

char	*get_affix(t_option option)
{
	char	*affix;

	if (option.zero)
		affix  = make_string(option.width - option.prec - 1, '0');
	if (!option.zero)
		affix = make_string(option.width - option.prec - 1, ' ');
	return (affix);
}

int	handle_integer(int num, t_option option, va_list ap)  //int i; int numlen
{
	int	size; //printf의 반환, 즉 최종 출력될 문자열의 길이
	int	i;
	char	*number; //알짜배기 숫자
	char	*result; //strjoin으로 채워갈 결과물
	char	*temp; // temporarily use for strjoin
	int	numlen;

	size = 0;
	i = 0;
//	if (option.minus)
//	{
//		공백이 있다면 오른쪽으로
//	}
	number = ft_itoa(va_arg(ap, int));
	numlen = ft_strlen(number);
	size = find_max(numlen, find_max(option.width, option.prec));
	if (size == option.width)
	{
		if (number < 0)
		{
			result = get_affix(option);
			temp = make_string(1, '-');
			result = ft_strjoin_custom(result, temp);
		}
		else if (number >= 0)
			result = get_affix(option);
		if (option.prec - numlen) // size(prec) > numlen
		{
			
			temp = make_string(option.prec - numlen, '0');
			result = ft_strjoin_custom(result, temp);
			result = ft_strjoin_custom(result, number);
		}
		size =  write(1, result, ft_strlen(result));// is it bad?
	}
	if (size == option.prec)
	{
		result  = make_string(option.prec - numlen, '0');
		result = ft_strjoin_custom(result, number);
		size = write(1, result, ft_strlen(result));
	}
	if (size == numlen) //이게 맨 앞에 와야함 그리고 나머지를 else if로
	{	
		size = write(1, number, numlen);
	}
//	if (option.zero)
//	{
//		zero_pad = make_string(, '0');
//	}
	free(result);
	return (size);
}
