#include <stdio.h>

int	ft_sum(int *a, int *b)  //변수가 포인터니까 인자값으로 주소를 받아야지
{
	*a = 4;
	*b = 2;
	return (*a + *b);
}

int	main(void)
{
	int a;
	int b;
	int sum;

	a = 5;
	b = 7;
	sum = ft_sum(&a, &b);    //왜 이순간부터 a,b값이 같이 접근되지?
	
	printf("%d + %d = %d\n", a, b, a + b);
	//sum = ft_sum(&a, &b);
	printf("%d + %d = %d\n", a, b, sum);
	return (0);
}
	
