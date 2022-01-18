/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:17:51 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/17 22:26:14 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
//스택 a, 스택 b를 선언하기 위한 연결리스트의 노드 구조체
typedef struct      s_stack
{
    struct s_stack  *next;  //다음 노드의 주소를 저장할 포인터
    int             value;  //데이터를 저장할 멤버, 즉 노드의 값
}                   t_stack;


typedef struct      s_carrier
{
    int ac_cnt;     //프롬프트에 입련된 인자 개수
    int min;        //스택 내부 최대값
    int max;        //스택 내부 최소값
//    int pivot;      //피봇
    int a_num;      //a to b 전에 스택 내부에서 정렬여부를 검사해야할 개수(남는 개수)
    int b_num;      //b to a 전에 스택 내부에서 정렬여부를 검사해야할 개수(남는 개수)
    int pa_num;     //pa 실행 시 스택 a로 넘어가는 숫자
    int pb_num;     //pb 실행 시 스택 a로 넘어가는 숫자
    int rra_num;    //rra 실행 시 스택 a의 최상단으로 이동하는 숫자
    int rrb_num;    //rrb 실행 시 스택 b의 최상단으로 이동하는 숫자
    
    t_stack         *a_rest;    //b에서 a로 넘겨줘서 반복문으로 검사해야할 개수(2개 이하면 반복문 필요없음)
    t_stack         *b_rest;   
}                   t_carrier;       

/** push_swap.c **/

int     is_ascending(t_stack **a);
int     is_descending(t_carrier *c, t_stack **a);
void    sort_and_print(t_stack **a, t_stack **b, t_carrier *carrier);
void    fill_a(char **argv, t_carrier *c, t_stack **a, int num);
void    init_carrier(int argc, t_carrier *c);

/** parse.c **/

long	parse_integer(char *argv, t_stack **a, char **s);
void	add_stack_list(t_carrier *c, t_stack **a, t_stack **p, char **arr);
int		is_overlap(t_stack **a, t_stack *p, int num);

/** common_rules.c **/
void	add_front_stack(t_carrier *c, t_stack **a, t_stack **b, char c);
void    iterate_a(t_carrier *c, t_stack **a, t_stack **b, int pivot);
void	iterate_b(t_carrier *c, t_stackk **a, t_stack **b, int pivot);
void	free_stack(t_stack **a_or_b);
void	print_error(t_stack **a, t_stack **b, char **s);

/** command.c **/
void	sa(t_stack **a, char is_ss, char is_checker);
void	sb(t_stack **, char is_ss, char is_checker);
void	pa(t_stack **a, t_stack **b, char is_checker);
void	pb(t_stack **a, t_stack **b, char is_checker);


/** command2.c**/
void	ra(t_stack **a, char is_rr, char is_checker);
void	rb(t_stack **b, char is_rr, char is_checker);
void	rra(t_stack **a, char is_rrr, char is_checker);
void	rrb(t_stack **b, char is_rrr, char is_checker);


/** sort.c**/
int		sort_descending(t_carrier *c, t_stack **a, t_stack **b);
void	sort_three(t_carrier *c, t_stack **a);
void	sort_five2(t_stack **a);
void	sort_five(t_carrier *c, t_stack **a, t_stack **b);
void	sort_else(t_carrier *c, t_stack **a, t_stack **b);

/** sort_tool.c**/
int     get_pivot(t_stack **p, int num);
void    sort_a(t_carrier *c, t_stack **a);
void    sort_b(t_carrier *c, t_stack **b);
void	a_use_b(t_carrier *c, t_stack **a, t_stack **b);
void	b_use_a(t_carrier *c, t_stack **a, t_stack **b);


#endif
