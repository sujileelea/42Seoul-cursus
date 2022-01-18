#include <stdio.h>

int	main(void)
{
	
	printf("00000000000\n");
	printf("%7.4d\n", 42); // __-0042
	printf("%07.4d\n", -42); // __-0042
	printf("%03d\n", 42); // 042
	printf("%.4d\n", 42); //0042
	printf("%.d\n", 42); //42
	printf("%*.*d\n", 3, 3, 42); //042
	//printf("%*4d\n", 4, 42); // error occurs
	printf("00000000000\n");
	printf("%*d %4d\n", 4, 42, 42); // __42___42
	printf("suji%dsuji%d\n", 777, 7777); //suji777suji7777
	printf("%%%%\n"); // %%
	printf("%-*.*d\n", 3, 4, 42); //0042 
	printf("%d\n", printf("%-*.*d\n", 4, 3, 42)); // 042_\n , 5
	return (0);
}
