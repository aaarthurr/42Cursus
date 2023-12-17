/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:27:53 by arpages           #+#    #+#             */
/*   Updated: 2023/12/17 15:41:15 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(t_stack *stack)
{
    t_lst *tmp;
	t_lst *rmv;

    tmp = ft_lstdup(stack->a);
    ft_lstadd_back(&stack->a, tmp);
	rmv = stack->a;
    stack->a = stack->a->next;
	free(rmv);
}

void ft_rb(t_stack *stack)
{
    t_lst *tmp;
	t_lst *rmv;

    tmp = ft_lstdup(stack->b);
    ft_lstadd_back(&stack->b, tmp);
	rmv = stack->b;
    stack->b = stack->b->next;
	free(rmv);
}

void mv_ra(t_stack *stack)
{
	if (stack->a == NULL || stack->a->next == NULL)
		return;
	ft_ra(stack);
	printf("ra\n");
}

void mv_rb(t_stack *stack)
{
	if (stack->b == NULL || stack->b->next == NULL)
		return;
	ft_rb(stack);
	printf("rb\n");
}

void mv_rr(t_stack *stack)
{
	if (stack->a == NULL || stack->a->next == NULL)
		return;
	else if (stack->b == NULL || stack->b->next == NULL)
		return;
	ft_ra(stack);
	ft_rb(stack);
	printf("rr\n");
}