/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:17:25 by okwon             #+#    #+#             */
/*   Updated: 2022/02/17 21:44:01 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int ac, int **av, char **env)
{
	t_data data;

	// minishell에서 사용될 시그널 정의
	//ctrl + c -> 종료
	signal(SIGINT, signal_handler);
	//ctrl + W 입력 시 -> 코어 덤프
	signal(SIGQUIT, SIG_IGN);


	//term1 : 미니쉘에서 사용할 터미널
	//표준입력의 속성을 term1에??
	tcgetattr(STDIN_FILENO, term1);

	
}