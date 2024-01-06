/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:51:28 by arthur            #+#    #+#             */
/*   Updated: 2023/12/28 17:39:38 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*rmv;

	tmp = stack->a;
	while (tmp->next->next)
		tmp = tmp->next;
	rmv = tmp;
	tmp = tmp->next;
	rmv->next = NULL;
	ft_lstadd_front(&stack->a, tmp);
	stack->a = tmp;
}

void	ft_rrb(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*rmv;

	tmp = stack->b;
	while (tmp->next->next)
		tmp = tmp->next;
	rmv = tmp;
	tmp = tmp->next;
	rmv->next = NULL;
	ft_lstadd_front(&stack->b, tmp);
	stack->b = tmp;
}

void	mv_rra(t_stack *stack)
{
	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	ft_rra(stack);
	ft_printf("rra\n");
}

void	mv_rrb(t_stack *stack)
{
	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	ft_rrb(stack);
	ft_printf("rrb\n");
}

void	mv_rrr(t_stack *stack)
{
	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	else if (stack->b == NULL || stack->b->next == NULL)
		return ;
	ft_rra(stack);
	ft_rrb(stack);
	ft_printf("rrr\n");
}
