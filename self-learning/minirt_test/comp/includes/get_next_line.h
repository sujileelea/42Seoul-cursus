/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:08:22 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/27 19:11:04 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../utils/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);
int		buf_check(char *buf);
void	ft_strdel(char **as);
int		get_line(char **str, char **line);
int		result(int len, int fd, char **str, char **line);

#endif
