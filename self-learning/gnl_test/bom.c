#include "get_next_line.h"

char	*get_save(char *save)
{
	int	i;
	char	*dest;
	int	j;
	int	save_len;

	save_len = ft_strlen(save);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (0);
	}
	i++;
	if (!(dest = (char *)malloc(sizeof(char) * save_len - i + 1)))
		return (0);	//첫 개행 후부터 널까지 자리 말록
	j = 0;
	while (save[i])
		dest[j++] = save[i++];
	dest[j] = '\0';
	free(save);
	return (dest);
}
//dest에 첫 개행 후부터 널까지 save를 넣어주고 save는 free해주는 함수

char	*get_line(char *save)
{
	int	i;
	char	*dest;
	int	dest_len;

	dest_len = 0;
	while (save[dest_len] && save[dest_len] != '\n')
		dest_len++;
	if (!(dest = (char *)malloc(sizeof(char) * dest_len + 1)))
		return (0); //save의 첫 개행 전 글자 + 널까지 자리 말록
	i = 0;
	while (i < dest_len)
	{
		dest[i] = save[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
//dest에 첫 개행 전까지 save를 넣어주는 함수, 마지막에 널까지

int	get_next_line(int fd, char **line)
{
	int		reader; //read 함수가 반환하는 값을 저장하는 변수
	static char	*save;  //값 지정 안한 static char *는 널을 담고있음
	char		*buff;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);       // gathering of error cases
	reader = 1101;
	if (!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);      //buffer에 버퍼사이즈 + 널자리 동적할당
	while (reader != 0 && !(if_newline_in_str(save))) //save에 개행이 없는 동안
	{
		if ((reader = read(fd, buff, BUFFER_SIZE)) < 0)
			return (-1);
		buff[reader] = '\0';
		if (!(save = ft_strjoin_custom(save, buff))) 
			return (-1)
	}
	free(buff);
	*line = get_line(save);
	save = get_save(save);   //여기서 free해주니까 윗줄 함수에는 없어도됨 
	if (save == NULL)
		return (0);
	return (1);
}
