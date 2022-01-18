/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 01:17:33 by sujilee           #+#    #+#             */
/*   Updated: 2021/05/26 17:12:25 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include "../utils/libft/libft.h" //ft_strlen을 쓰기위해

int		no_newline(char *str);
char	*ft_strjoin_custom(char *save, char *buff);
char	*this_is_line(char *str);
char	*this_is_save(char *str);
int		get_next_line(int fd, char **line);

#endif