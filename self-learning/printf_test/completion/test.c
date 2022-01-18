#include <stdio.h>
#include <unistd.h>

void	putnbr(long long num)
{
	if (num >= 10)
		putnbr((num / 10));
	putnbr(num % 10);
}

int	main(void)
{
	putnbr(42);
	return (0);
}
