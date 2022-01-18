/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:05:52 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/17 16:23:10 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// ?? node 추가 -> push 함수의 인자 ???
void     fill_stack(t_carrier *carrier, t_stack **a, int size, char **argv)
{
    int data;
    char **array;
    int arr_index;
    int argv_index;

    argv_index = 0;
    if (!argv)
        return ;
    while (argv[argv_index])
    {
        arr_index = 0;
        array = ft_split(argv[argv_index], ' ');
        if (!array)
        {
            printf("array is null");
            error(carrier);
        }
        while (array[arr_index])
        {
            data = ft_atoi(array[arr_index], carrier);
            init_pushed_stack(carrier, a, data); 
            arr_index++;
        }
        argv_index++;
        free_arr(array);
    }
    is_overlapped(carrier, a);
    return ;
}

void    init_carrier(t_carrier *carrier)
{
    carrier->ac_cnt = 0;
    carrier->min = -2147483648;
    carrier->max = 2147483637;
    carrier->pivot = 0;
    carrier->a_cnt = 0;
    carrier->b_cnt = 0;    
    carrier->error = 0;
    carrier->arem_cnt = 0;
    carrier->brem_cnt = 0;
    carrier->pa_num = 0;
    carrier->pb_num = 0;
    carrier->a_remnant = 0;
    carrier->b_remnant = 0;
    
    return ;
}

//채워진 a스택을 정렬하는 로직을 담은 함수
//void    push_swap(t_carrier *carrier, t_stack *a, t_stack *b)
//{


//}
// int		main(int argc, char **argv)
// {
//     t_carrier carrier;
//     t_stack *a;
//     t_stack *b;

//     a = 0;
//     b = 0;
//     if (argc < 2)
//         exit(0);
//     init_carrier(&carrier);
//     fill_stack(&a, argc - 1, &argv[1], &carrier);
//     push_swap(carrier, a, b);
	
// }