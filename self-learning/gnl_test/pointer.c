#include <stdio.h>

int	main()
{
	int a = 4;
	int *p;

	p = &a;
	*p = 5;
	printf("5 : %d\n", a);
	return (0);
}
