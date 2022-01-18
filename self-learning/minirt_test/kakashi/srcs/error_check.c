/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:33:42 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//에러 체크 함수 : 식별자 n에 따라 종류를 나누고 그에 맞는 에러메세지 출력
void	error_check(int n, char *error_massage)
{
	printf("Error\n");
	if (n == 1) //잘못된 인자 개수가 들어온 경우(2나 3이 아니면 오류)
		printf("Invalid argument : Wrong number of args\n");
	if (n == 2) //두번째 인자가 .rt 파일이 아닌 경우
		perror("Check file form. Dosen't it has to be .rt?");
	if (n == 3) //세번째 인자가 --save 옵션이 아닌 경우
		printf("Invalid argument : Wrong input of 3rd arg. Dosen't it has to be --save?");
	if (n == 4)
		printf("Check rt file : %s\n", error_message);
	if (n == 5)
		printf("Memory error : %s\n", error_message);
	if (n == 6)
		printf("Check rt file : %s parameter out of range\n", error_message);
	if (n == 7)
		printf("Open error : %s\n", error_message);
	exit(1);
}

void	success_message(int ac)
{
	if (ac == 2)
	{
		printf("\nminiRT made scene successfully rendered with ");
		printf("%d thread\n", THREAD_NUM); //보너스용.
		printf("press ESC or click RED BUTTON to close program\n");
		printf("press space to switch camera\n\n");
	}
	else
	{
		printf("\nScene has successfully saved as BMP file\n");
		printf("You can check your file in \"images\" directory\n\n");
		exit(0);
	}
}

void	check_values(double n, double min, double max, char *err)
{
	if (n < min || n > max)
		error_check(6, err);
}

//포인터 할당과 동시에 에러까지 체크하는 함수(얘가 줄을 많이 줄여줌)
void	*err_malloc(unsigned int n)
{
	void	*ptr;

	ptr = malloc(n);
	if (ptr == NULL)
		error_check(5, "Fail to allocate memory");
	return (ptr);
}