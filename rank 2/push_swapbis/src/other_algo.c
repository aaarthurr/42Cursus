/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 20:27:01 by arthur            #+#    #+#             */
/*   Updated: 2023/12/28 17:45:35 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_lst	*tmp;

	tmp = stack->a;
	if (lsize(tmp) == 1)
		return (1);
	while (tmp->next)
	{
		if (tmp->rank >= tmp->next->rank)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	lil_sort(t_stack *stack)
{
	while (is_sorted(stack) != 1)
	{
		while (lsize(stack->a) > 2 && is_sorted(stack) == 0)
		{
			min_sort_a(stack->a, stack);
		}
		if (stack->a->rank > stack->a->next->rank)
			mv_sa(stack);
		while (stack->b)
		{
			max_sort_b(stack->b, stack);
		}
	}
}

void	min_sort_a(t_lst *a, t_stack *stack)
{
	t_lst	*last;

	last = ft_lstlast(a);
	if (a->next->rank < a->rank && a->next->rank < last->rank)
	{
		mv_sa(stack);
	}
	else if (last->rank < a->rank && last->rank < a->next->rank)
	{
		mv_rra(stack);
	}
	if (is_sorted(stack) == 0)
		mv_pb(stack);
}

void	max_sort_b(t_lst *b, t_stack *stack)
{
	t_lst	*last;

	if (!b->next)
	{
		mv_pa(stack);
		return ;
	}
	last = ft_lstlast(b);
	if (b->next->rank > b->rank && b->next->rank >= last->rank)
	{
		mv_sb(stack);
	}
	else if (last->rank > b->rank && last->rank >= b->next->rank)
	{
		mv_rrb(stack);
	}
	mv_pa(stack);
}
