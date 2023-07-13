/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sean <sean@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:12:48 by okwon             #+#    #+#             */
/*   Updated: 2022/03/19 23:01:53 by sean             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_glob	g_glob;

char	*print_history(t_term *term, t_input *input)
{
	t_list	*head;
	int		i;

	head = input->log;
	if (input->buf == DOWN && input->nidx >= 0)
		input->nidx--;
	else if (input->buf == K_UP && input->nidx < (ft_lstsize(head) - 1))
		input->nidx++;
	i = -1;
	while (head && ++i < input->nidx)
		head = head->next;
	tputs(tgoto(term->cm, 0, term->r), 1, putchar_tc);
	tputs(term->ce, 1, putchar_tc);
	prompt(0);
	if (input->nidx == -1)
	{
		write(1, input->his_input, ft_strlen(input->his_input));
		return (ft_strdup(input->his_input));
	}
	write(1, head->content, ft_strlen(head->content));
	return (ft_strdup(head->content));
}

int	input_handler(t_input *input)
{
	char	*tmp;

	write(STDIN_FILENO, &input->buf, 1);
	if ((char)input->buf == '\n')
	{
		if (ft_strncmp(input->input, "", 1) && \
		!ft_strncmp(input->input, "cat", ft_strlen(input->input)))
			g_glob.cflag = 2;
		tmp = ft_strjoin(input->input, "\n");
		if (ft_strncmp(input->input, "", ft_strlen(input->input)))
			free(input->input);
		input->input = tmp;
		return (1);
	}
	else
		case_not_newline(input, tmp);
	return (0);
}

void	case_not_newline(t_input *input, char *tmp)
{
	if (!ft_strncmp(input->input, "", 1))
		tmp = ft_substr(&input->buf, 0, 1);
	else
		tmp = ft_strjoin(input->input, &input->buf);
	free(input->input);
	if (input->his_input && \
	!ft_strncmp(input->his_input, "", ft_strlen(input->his_input)))
		free(input->his_input);
	input->input = tmp;
	input->his_input = input->input;
}

int	key_else(t_data *data, t_input *input)
{
	if (input->buf == 4)
		ctrl_d_func(input->input, &data->term.ori_term);
	else if (input->buf == DEL)
		delete_end(&input->input);
	else if (input->buf == K_UP || input->buf == DOWN)
	{
		if (input->input)
			free(input->input);
		input->input = print_history(&data->term, input);
	}
	else
		return (1);
	return (0);
}

char	*input_recive(t_data *data)
{
	t_input	input;

	input = data->input;
	input.input = ft_strdup("");
	input.nidx = -1;
	input.his_input = ft_strdup("");
	g_glob.read_size = 0;
	data->term.cm = tgetstr("cm", NULL);
	data->term.ce = tgetstr("ce", NULL);
	while (read(0, &input.buf, sizeof(int)) > 0)
	{
		get_cursor_position(&data->term.c, &data->term.r);
		if (g_glob.read_size == -1 && ctrl_c_func(&input))
			return (ft_strdup("\n"));
		if (key_else(data, &input) && input_handler(&input))
			return (input.input);
		input.buf = 0;
	}
	g_glob.cflag = 0;
	return (0);
}
