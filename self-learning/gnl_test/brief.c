#include "get_next_line.h"

char	*this_is_line(char *str) //개행 전까지 따는 함수
{
	int i;
	int j;
	char *dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++; // i = 8
	j = 0;
	while (j < i) //till j = 7
	{
		dest[j] = str[j];
		j++;
	}
	return (dest);
}

char	*this_is_save(char *str)  //개행 후부터 따는 함수
{
	int i;
	int j;
	int len;
	char *dest;

	len = ft_strlen(str);  //len = 13
	i = 0;
	while (str[i] && str[i] != \n)
		i++; // i = 8
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	if (!(dest = (char *)malloc(sizeof(char) * (len - i))))
		return (0);
	j = 0;
	while (i + 1 < len) //str[9~12]
	{
		dest[j++] = str[i + 1];
		i++;
	}
	dest[j] = '\0';
	free(str);
	return (dest);
}

int	get_next_line(int fd, char **line)
{
	int i;  //read값 담음
	char *buff;
	static char *save; //백업

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	i = 1;
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (i != 0 && no_newline(save))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (-1);
		buff[i] = '\0';
		if (!(save = ft_strjoin_custom(save, buff)))
			return (-1);
	}
	free(buff);
	*line = this_is_line(save);
	save = this_is_save(save);
	if (save == NULL)
		return (0);
	return (1);
}

int	main(void)
{
	int fd;
	char **line;
	
	line = (char **)malloc(sizeof(char *) * 1);

	fd = open("test.txt", O_RDONLY);
	while (0 < (get_next_line(fd, line)))
	{
		printf("%s\n", *line);
		free(*line);
	}
	printf("%s\n", *line);
	free(*line);
	close(fd);
	fd = open("test.txt", O_RDONLY);
	while (0 < (get_next_line(fd, line)))
	{
		printf("%s\n", *line);
		free(*line);
	}
	printf("%s\n", *line); // EOF전의 마지막 줄을 처리해줘야하기 때문
	free(*line);
	close(fd);
	free(line); //19번의 말록 프리
	return (0);
}

