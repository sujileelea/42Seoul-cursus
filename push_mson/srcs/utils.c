/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:57:45 by sujilee           #+#    #+#             */
/*   Updated: 2022/01/20 12:33:15 by sujilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

//에러 출력 함수. 에러 시 carrier->error 멤버 값 == 1
void        error(t_carrier *carrier)
{
    if (!carrier)
        exit(1);
    if (!carrier->error)
    {
        printf("Error\n");
        carrier->error = 1;
    }
}

// A스택 내부에 중복 숫자 여부를 확인하는 함수
void        is_overlapped(t_carrier *carrier, t_stack **a)
{
    t_stack *temp;
    t_stack *comp;

    temp = *a;
    while (temp != 0)
    {
        comp = temp->next;
        while (comp != 0)
        {
            if (temp->data == comp->data)
            {
                error(carrier);
                printf("is overlapped!\n");
                return ;
            }
            comp = comp->next;
        }
        temp = temp->next;
    }
}

// ??? 스택에 푸시했을때 정보를 바꿔주는 함수 ?
void        init_pushed_stack(t_carrier *carrier, t_stack **stack, int data)
{
    t_stack *temp;
    t_stack *tail;

    temp = (t_stack *)malloc(sizeof(t_stack));
    if (!temp)
    {
        printf("mallocation of temp failed\n");     
        error(carrier);
    }
    temp->data = data;
    //최대값 최소값 다시 할당
    if (data > carrier->max)
        carrier->max = data;
    if (data < carrier->min)
        carrier->min = data;
    // string형태로 들어올때 ac_cnt == 1 이기 때문에 ac_cnt++;
    carrier->ac_cnt++;
    carrier->a_cnt++;
    carrier->arem_cnt++;
    //빈 스택이 들어오는 경우
    if (*stack == 0)
    {
        *stack = temp;
        (*stack)->prev = *stack;
        return ;
    }
    tail = (*stack)->prev;
    temp->next = 0;
    tail->next = temp;
    //새로 들어온 노드를 기존 노드의 다음 노드로 연결
    temp->prev = tail;
    (*stack)->prev = temp;
}


//스택에서 head노드를 꺼내고 반환하는 함수
int     pop(t_stack **stack)
{
    t_stack *pop;
    int     data;
    
    if (!stack)
        exit(1);
    pop = *stack;
    //headNext를 head로 바꿔주는 과정
    if ((*stack)->next)
    {
        (*stack)->next->prev = (*stack)->prev;
        *stack = (*stack)->next;
    }
    data = pop->data;
    free(pop);
    return (data);
}

//매개변수 node : 스택에 새로 집어넣을 노드
void    push(t_stack **stack, int data)
{
    t_stack *newNode;
    
    newNode = (t_stack *)malloc(sizeof(t_stack));
    newNode->data = data;
    // ??? 스택이 비어있을 경우
    if (*stack == 0)
    {
        newNode->prev = newNode;
        *stack = newNode;
    }
    // 스택의 head를 인자로 들어온 node로 교체
    else
    {
        newNode->prev = (*stack)->prev;
        newNode->next = *stack;
        *stack = newNode;
    }
}

int    find_max(t_carrier *carrier, t_stack **stack, char c)
{
    t_stack     *curr;
    int         max;
    int         i;

    if (!stack)
        exit(1);
    curr = *stack;
    printf("ac_cnt in find_max: %d\n", carrier->ac_cnt);
    if (!carrier->a_remnant && !carrier->b_remnant)
        i =  carrier->ac_cnt;
    else
    {
        if (c == 'a')
            i = carrier->a_remnant->data;
        else
            i = carrier->b_remnant->data;
    }

    max = curr->data;
    while (i--)
    {
        if (max < curr->data)
            max = curr->data;
        curr = curr->next;
    }
    return (max); 
}

int    find_min(t_carrier *carrier, t_stack **stack, char c)
{
    t_stack     *curr;
    int         min;
    int         i;

    if (!stack)
        exit(1);
    curr = *stack;
    if (!carrier->a_remnant && !carrier->b_remnant)
        i =  carrier->ac_cnt;
    else 
    {
        if (c == 'a')
            i = carrier->a_remnant->data;
        else
            i = carrier->b_remnant->data;
    }
    min = curr->data;
    while (i--)
    {
        if (min > curr->data)
            min = curr->data;
        curr = curr->next;
    }
    return (min); 
}