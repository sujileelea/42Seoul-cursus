/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:33:42 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/27 16:59:33 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	error_check(int n, char *error_message)
{
	printf("Error\n");
	if (n == 1)
		printf("Invalid argument : Wrong number of args\n");
	if (n == 2)
		perror("Check file form. Dosen't it has to be .rt?");
	if (n == 3)
		printf("Invalid argument : Wrong input of 3rd arg. \
				Dosen't it has to be --save?");
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

void	*err_malloc(unsigned int n)
{
	void	*ptr;

	ptr = malloc(n);
	if (ptr == NULL)
		error_check(5, "Fail to allocate memory");
	return (ptr);
}
