/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:54:06 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/24 19:26:18 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct		s_stack
{
	int 			data;
	struct s_stack	*next;
	struct s_stack	*prev;
} 					t_stack;

typedef struct s_carrier
{
	int				ac_cnt;
	int 			min;
	int				max;
	int				a_cnt;
	int				b_cnt;
	int				error;
	int				arem_cnt; // 미정렬된 남은 개수
	int				brem_cnt; // 미정렬된 남은 개수
	int				pa_num;	//pa로 a스택으로 넘어가는 숫자 개수
	int				pb_num; //pb로 b스택으로 넘어가는 숫자 개수
	int				rra_num; //rra되는 숫자 개수
	int				rrb_num;
	t_stack			*a_remnant;  // 스택 b로 넘어가는 스택 a의 짜투리
	t_stack			*b_remnant;	// 스택 a로 넘어가는 스택 b의 짜투리
}					t_carrier;




/*****************************************************/
/**                     libft.c                     **/
/*****************************************************/

int				ft_atoi(char *str, t_carrier *carrier);
char			**ft_split(char const *s, char c);



/*****************************************************/
/**                   push_swap.c                   **/
/*****************************************************/

void		add_stack_list(t_carrier *carrier, t_stack **a, t_stack **node, char **arr);
void		fill_stack(t_carrier *carrier, t_stack **a, int size, char **argv);
void    	init_carrier(t_carrier *carrier, int argc);
void    	push_swap(t_carrier *carrier, t_stack **a, t_stack **b);
void		free_stack(t_stack **a_or_b);

/*****************************************************/
/**                     command.c                   **/
/*****************************************************/


void		pa(t_carrier *carrier, t_stack **a, t_stack **b);
void		pb(t_carrier *carrier, t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);


/*****************************************************/
/**                     utils.c                     **/
/*****************************************************/


long	get_integer(char *argv, t_stack **a, char **s);
int		is_overlap(t_stack **a, t_stack *p, int num)
int			find_max(char old, char new);
int    		find_min(char old, char new);

/*****************************************************/
/**                      sort.c                     **/
/*****************************************************/


int			is_sorted(t_stack **a);
int    is_descending(t_carrier *carrier, t_stack *a);
int    sort_descending(t_carrier *carrier, t_stack **a, t_stack **b);
void		sort_three(t_carrier *carrier, t_stack **a);
void		sort_five(t_carrier *carrier, t_stack **a, t_stack **b);
void    sort_many(t_carrier *carrier, t_stack **a, t_stack **b);


/*****************************************************/
/**                     logic.c                     **/
/*****************************************************/

void	a_to_b(t_carrier *carrier, t_stack **a, t_stack **b);
void	b_to_a(t_carrier *carrier, t_stack **a, t_stack **b);
int		find_pivot(t_stack **stack, int count);

/*****************************************************/
/**                 logic_utils.c                   **/
/*****************************************************/

void	pivoting_a(t_carrier *carrier, t_stack **a, t_stack **b, int pivot);
void	pivoting_b(t_carrier *carrier, t_stack **a, t_stack **b, int pivot);
void	attach_unsorted(t_carrier *carrier, t_stack **a, t_stack **b, char c);
void	handle_one_two_a(t_carrier *carrier, t_stack **a, t_stack **b);
void	handle_one_two_b(t_carrier *carrier, t_stack **a, t_stack **b);





/*****************************************************/
/**                      free.c                     **/
/*****************************************************/

void		free_stack(t_stack **stack);
void		free_arr(char **arr);


/*****************************************************/
/**                     debug.c                     **/
/*****************************************************/
long	get_integer(char *argv, t_stack **a, char **s);
void		print_stack(t_carrier *carrier, t_stack *stack);
void		debug(t_carrier *carrier, t_stack **a, t_stack **b);
#endif