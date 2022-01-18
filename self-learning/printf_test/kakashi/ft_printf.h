/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:21:44 by sujilee           #+#    #+#             */
/*   Updated: 2021/03/01 22:08:54 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_option
{
	int	minus;  //minus flag (align)
	int	zero;
	int	width;
	int	dot;
	int	prec;
	int	spec;
	int	data_len; //data(가변인자 데이터)의 길이 
	int	space_len;
	int	zero_len;
	int	size; //ft_printf의 반환값: printed_len
}		t_option;
