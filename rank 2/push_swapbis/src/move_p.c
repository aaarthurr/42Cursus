/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:32:05 by arpages           #+#    #+#             */
/*   Updated: 2023/12/28 17:39:20 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	mv_pa(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*rmv;

	if (stack->b == NULL)
		return ;
	tmp = ft_lstdup(stack->b);
	tmp->next = NULL;
	ft_lstadd_front(&stack->a, tmp);
	rmv = stack->b;
	stack->b = stack->b->next;
	free(rmv);
	ft_printf("pa\n");
}

void	mv_pb(t_stack *stack)
{
	t_lst	*tmp;
	t_lst	*rmv;

	if (stack->a == NULL)
		return ;
	tmp = ft_lstdup(stack->a);
	tmp->next = NULL;
	ft_lstadd_front(&stack->b, tmp);
	rmv = stack->a;
	stack->a = stack->a->next;
	free(rmv);
	ft_printf("pb\n");
}
