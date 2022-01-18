/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:49:55 by sujilee           #+#    #+#             */
/*   Updated: 2021/11/14 22:52:15 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include "../include/push_swap.h"

//스택 내부의 숫자가 오름차순인지 아닌지 판별하는 함수
int     is_ascending(t_stack **a)
{
    int     before;
    t_stack *p; //노드 a를 담을 노드생성..이 아니라 주소값인가? 맞음! 노드 순회용 포인터처럼
    
    p = *a; //이게 주소값을 담는건가?
    before = p->value;
    p = p->next;
    //노드를 돌면서 오름차순이 아니면 0 반환
    while (p != 0)
    {
        if (before > p->value)
            return (0);
        before = p->value;
        p = p->next;
    }
    //즉, 모든 숫자가 오름차순이면 1 반환
    return (1);
}

//스택 내부의 숫자가 내림차순인지 아닌지 판별하는 함수
//내림차순이면 1 반환. 아니면 0 반환
int    is_descending(t_carrier *c, t_stack **a)
{
    int     before;
    t_stack *p;

    p = *a;
    if (p->value != c->max)
        return (0);
    before = p->value; //max값인 노드의 주소 넣음
    p = p->next;
    while (p)
    {
        if (before < p->value)
            return (0);
        before = p->value;
        p = p->value;
    }
    return (1);
}

void    sort_and_print(t_stack **a, t_stack **b, t_carrier *carrier)
{   
    //들어온 숫자가 한개이거나, 오름차순이면 프로그램 종료
    if (carrier->ac_cnt == 1 || ((is_ascending(a)) == 1))
        return ;
    else if (carrier->ac_cnt == 2)
    {
        //만약 숫자가 두개 들어왔을때, 제일 윗 노드의 숫자가 최소값이라면 프로그램 종료
        if ((*a)->value == carrier->min)
            return ;
        //그게 아니라면, sa를 실행시켜야겠지?
        else
            sa(a, 0, 0);
    }
    else if (carrier->ac_cnt == 3)
        sort_three(carrier, a);
    else if (carrier->ac_cnt == 5)
        sort_five(carrier, a, b);
    else
        sort_else(carrier, a, b);
}

// num이 뭐지 ? 
void    fill_a(char **argv,  t_carrier *c, t_stack **a, int num)
{
    int     i;
    int     j;
    char    **arr;  //블록을 담을 배열
    t_stack *p; //이게 뭘까 ?

    i = 0;
    while (argv[++i])
    {
        arr = ft_split(argv[i], ' ');
        if (!arr)
            print_error(a, 0, 0);
        j = 0;
        while (arr[j++])
        {
            c->b_num = (int)get_integer(arr[j], a, arr);
            add_stack_list(c, a, &p, arr);
            if ((is_overlap(a, p, c->b_num)) == 1)
                print_error(a, 0, arr);
            num++;
        }
        //ft_split_free(arr);
    }
    c->b_num = 0;
    c->ac_cnt = num;
}

//캐리어 초기화 함수
void    init_carrier(int argc, t_carrier *c)
{
    c->ac_cnt = argc;
    c->max = 2147483647;
    c->min = -2147483648;
    c->pivot = 0;
    c->a_stack = 0;
    c->b_stack = 0;
}

//말해뭐해 메인 함수임
int     main(int argc, char **argv)
{
    t_stack     *a; //a 스택 선언
    t_stack     *b; //b 스택 선언
    t_carrier   carrier;

    if (argc >= 2)
    {
        a = 0;
        b = 0;
        init_carrier(argc, &carrier);   //캐리어 초기화
        fill_a(argv, &carrier, &a, 0);  //a 스택 채우기
        sort_and_print(&a, &b, &carrier);       
        
    }

}