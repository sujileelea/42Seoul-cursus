#include <stdio.h>

int	ft_sum(int a, int b) //(int *a, int *b)
{
	a = 4;
	b = 2;
	return (a + b);
}

int	main(void)
{
	int a; //그럼 얘도 4
	int b; //얘도 2로 바뀜
	int sum;

	a = 5;
	b = 7;
	printf("%d + %d = %d\n", a, b, a + b);
	sum = ft_sum(a, b); //ft_sum(&a, &b);
	printf("%d + %d = %d\n", a, b, sum);
	return (0);
} 

//기존 : call by value
// 후  : call by reference
