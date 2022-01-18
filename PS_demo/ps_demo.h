/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:00:45 by sujilee           #+#    #+#             */
/*   Updated: 2021/10/03 18:01:19 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//libft 참조

//스택 a, 스택 b 를 선언하기 위한 연결리스트의 노드 구조체
typedef struct      s_stack
{
    struct s_stack *next;   //다음 노드의 주소를 저장할 포인터
    int             value;  //데이터를 저장할 멤버

}                   t_stack;              


typedef struct      s_record
{       
    int             argc;
    int             min;
    int             max;
    int             pa_num;
    int             rra_num;
    int             rrb_num;
    int             a_num;
    int             b_num;
    t_stack         *a_rest;
    t_stack         *b_rest;
    
}                   t_record;

/** push_swap.c */
void                arrange_three_digits(t_record *r, t_stack **a);
int	            	is_arranged(t_stack **a);
void                arrange_and_print(t_record *record, t_stack **a, t_stack **b);
void	            set_record(int argc, t_record *r);







#endif