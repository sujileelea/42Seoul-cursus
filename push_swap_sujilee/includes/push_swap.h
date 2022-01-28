/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:28:34 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/28 11:32:21 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct s_carrier
{
	int				argc;
	int				min;
	int				max;
	int				pb_cnt;
	int				rra_cnt;
	int				rrb_cnt;
	int				a_cnt;
	int				b_cnt;
	t_stack			*a_remnant;
	t_stack			*b_remnant;
}					t_carrier;

/*****************************************************/
/**                     libft.c                     **/
/*****************************************************/

char		**ft_split(char const *s, char c);

/*****************************************************/
/**                   push_swap.c                   **/
/*****************************************************/

int			is_sorted(t_stack **a);
void		push_swap(t_carrier *carrier, t_stack **a, t_stack **b);
void		init_carrier(int ac, t_carrier *r);

/*****************************************************/
/**                     utils.c                     **/
/*****************************************************/

long		get_integer(char *av, t_stack **a, char **s);
int			is_overlapped(t_stack **a, t_stack *new_node, int num);
void		link_stack(t_carrier *carrier, t_stack **a,
				t_stack **new_node, char **arr);
void		fill_stack(t_carrier *carrier, char **av,
				t_stack **a, int num);
void		check_ab(t_carrier *carrier, t_stack *t, char c);

/*****************************************************/
/**                    command.c                    **/
/*****************************************************/

void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a, char is_ss);
void		sb(t_stack **b, char is_ss);
void		ra(t_stack **a, char is_rr);
void		rb(t_stack **b, char is_rr);
void		rra(t_stack **a, char is_rrr);
void		rrb(t_stack **b, char is_rrr);

/*****************************************************/
/**                     sort.c                      **/
/*****************************************************/

int			is_descending(t_carrier *carrier, t_stack **a);
int			sort_descending(t_carrier *carrier, t_stack **a, t_stack **b);
void		sort_three(t_carrier *carrier, t_stack **a);
void		sort_five(t_carrier *carrier, t_stack **a, t_stack **b);
void		sort_many(t_carrier *carrier, t_stack **a, t_stack **b);

/*****************************************************/
/**                     logic.c                     **/
/*****************************************************/

void		handle_one_two_a(t_carrier *carrier, t_stack **a);
void		handle_one_two_b(t_carrier *carrier, t_stack **a, t_stack **b);
void		b_to_a(t_carrier *carrier, t_stack **a, t_stack **b);
void		a_to_b(t_carrier *carrier, t_stack **a, t_stack **b);

/*****************************************************/
/**                   logic_utils.c                 **/
/*****************************************************/

int			get_pivot(t_stack **p, int num);
void		attach_unsorted(t_carrier *carrier, t_stack **a,
				t_stack **b, char c);
void		pivoting_a(t_carrier *carrier, t_stack **a,
				t_stack **b, int mid);
void		pivoting_b(t_carrier *carrier, t_stack **a,
				t_stack **b, int mid);

/*****************************************************/
/**                      find.c                     **/
/*****************************************************/

int			find_max(int old, int new);
int			find_min(int old, int new);
void		find_three(t_carrier *carrier, t_stack **a);

/*****************************************************/
/**                      free.c                     **/
/*****************************************************/

void		ft_split_free(char **s);
void		free_stack(t_stack **a_or_b);

/*****************************************************/
/**                      error.c                    **/
/*****************************************************/

void		print_error(t_stack **a, t_stack **b, char **s);

/*****************************************************/
/**                      debug.c                    **/
/*****************************************************/

void		print_stack(t_carrier *carrier, t_stack *stack);

#endif
