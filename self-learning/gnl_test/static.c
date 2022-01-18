#include <stdio.h>

//static은 초기화를 무시
void	plus_one()
{
	static int	num = 0; //static이 아니면 함수가 호출될때마다 초기화

	//num = 0; 초기화를 여기서 하면 static이어도 계속 0으로 출력
	printf("%d\n", num);
	num++;
}

int	main()
{
	plus_one();
	plus_one();
	plus_one();
	plus_one();

	return (0);
}
