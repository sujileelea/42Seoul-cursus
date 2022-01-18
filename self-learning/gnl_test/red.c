#include <stdio.h>

void	ft_sum(int a, int b, int sum)
{
	sum = a + b;
}

void	ft_psum(int a, int b, int *sum)
{
	*sum = a + b;
}

int	ft_rsum(int a, int b)
{
	int sum;
	
	sum =  a + b;
	return (sum);
}

int	main(void)
{
	int a = 4;
	int b = 2;
	int sum ; //0x100

	sum = 0;
	ft_sum(a, b, sum); //얘는 main의 sum에서 힘을 못씀
	printf("sum(0) : %d\n", sum);
	
	ft_psum(a, b, &sum);
	printf("psum(6) : %d\n", sum);
	
	printf("rsum(6) : %d\n", ft_rsum(a, b));
	return (0);
}
