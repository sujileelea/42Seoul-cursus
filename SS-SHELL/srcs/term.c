/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:21:08 by okwon             #+#    #+#             */
/*   Updated: 2022/03/19 16:24:40 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	nbr_length(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	get_cursor_position(int *col, int *row)
{
	int		row_check;
	int		i;
	char	buf[255];
	int		ret;
	int		temp;

	row_check = 0;
	i = -1;
	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	while (buf[++i])
	{
		if (buf[i] >= '0' && buf[i] <= '9')
		{
			temp = ft_atoi(&buf[i]);
			if (row_check == 0)
				*row = temp - 1;
			else
				*col = temp - 1;
			row_check++;
			i += nbr_length(temp) - 1;
		}
	}
	return ;
}

int	putchar_tc(int tc)
{
	write(1, &tc, 1);
	return (0);
}

void	delete_end(char **input)
{
	char	*tmp;
	int		i;
	int		size;

	size = ft_strlen(*input);
	if (!(*input) || size == 0)
		tmp = ft_strdup("");
	else
	{
		tmp = (char *)malloc(sizeof(char) * size);
		tputs(tgetstr("le", NULL), 1, putchar_tc);
		tputs(tgetstr("ce", NULL), 1, putchar_tc);
		i = -1;
		while (++i < size - 1)
			tmp[i] = (*input)[i];
		tmp[i] = '\0';
	}
	if (size != 0)
		free(*input);
	*input = tmp;
}

void	term_init(struct termios *term1, struct termios *ori_term)
{
	tcgetattr(STDIN_FILENO, ori_term);
	tcgetattr(STDIN_FILENO, term1);
	term1->c_lflag &= ~ICANON;
	term1->c_lflag &= ~ECHO;
	term1->c_cc[VMIN] = 1;
	term1->c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, term1);
	tgetent(NULL, "xterm");
}
