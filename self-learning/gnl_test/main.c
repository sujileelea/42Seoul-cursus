#include <stdio.h>

int	main()
{
	char *line; // 포인터로 해줬기 때문에 변경할 수 있는거
	int fd;
	int i = 1;

	fd = open("path", O_RDONLY); //google open 매크로
	while (get_next_line(fd, &line))
		printf("%d : %s\n", i++, line);
	return (0);
}
