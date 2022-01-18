#include "get_next_line.h"

int	if_newline_in_str(char *save)
{
	int	i;

	if (!save)
		return (0);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// 개행이 있으면 1반환, 없으면 0반환하는 함수

char	*ft_strjoin_custom(char *save, char *buff)
{
	int	i;
	int	save_len;  //char *save의 길이
	int	buff_len;  //char *buff의 길이 
	char	*dest;
	int	j;

	i = 0;
	save_len = ft_strlen(save);
	buff_len = ft_strlen(buff);
	if (!(dest = (char *)malloc(save_len + buff_len + 1)))
		return (0);  //dest에 save,buff,널 자리까지 말록, 실패시 종료
	while (i < save_len)
	{
		dest[i] = save[i];
		i++;
	}
	j = 0;
	while (j < buff_len)
	{
		dest[i + j] = buff[j];
		j++;
	}
	dest[i + j] = '\0';
	free(save);
	return (dest);
}

//dest에 save + buff + 널을 동적할당으로 넣어주고 save는 free해주는 함수

int	ft_strlen(char *str)
{
	int 	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
