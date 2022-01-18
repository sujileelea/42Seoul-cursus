#include "get_next_line.h"

char	*get_line(char *str) //dest에 첫 개행 전까지 str+널을 넣어주는 함수
{
	int	i;
	int	j;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
			return (0);  //개행 전부터 널까지 자리 말록
	j = 0;
	while (j < i)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*get_save(char *str) //dest에 첫 개행 후부터 str을 넣어주고 free str
{
	int	len;
	int	i;
	int	j;
	char	*dest;

	len = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	i++;
	if (!(dest = (char *)malloc(sizeof(char) * (len - i + 1))))
		return (0);     //첫 개행 후부터 널까지 자리 말록
	j = 0;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}

int	get_next_line(int fd, char **line)
{
	int		reader; //read함수의 반환값
	static char 	*save;  //값 지정 안한 static char *는 널을 담고 있음
	char		 *buff; //버퍼사이즈+널만큼 담는 공간

	if (fd < 0 || !line || BUFFER_SIZE <= 0)  //에러 케이스들
		return (-1);
	reader = 1;
	if (!(buff(char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1); //buffer 말록
	while (reader != 0 && !(if_newline_in_str(save))) //save에 개행이 없을동안
	{ 
		if ((reader = read(fd, buff, BUFFER_SIZE)) < 0) //reader에 값대입, 
								// buff에 값 담김
			return (-1);				//read실패시 -1반환
		buff[reader] = '\0'; //buff의 마지막에 널 대입
		if (!(save = ft_strjoin_custom(save, buff))) //initial : save에 값대입
			return (-1);
	}
	free(buff);
	*line = get_line(save); // line에 save+널 대입(첫 개행 전까지)
	save = get_save(save); //save에 line에 넣고 남은 나머지들 대입
	if (save == NULL)
		return (0);
	return (1);
}

int	main(void)
{
	int	fd;
	char	**line;

	line = (char **)malloc(sizeof(char *) * 1); //이중포인터 line 말록
	fd = open("test.txt", O_RDONLY); //open함수로 test의 fd값을 받음
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
	printf("%s\n", *line); //EOF전의 마지막 줄을 처리하기 위해
	free(*line);
	close(fd);
	free(line); //19줄의 말록 프리
	return (0);
{
