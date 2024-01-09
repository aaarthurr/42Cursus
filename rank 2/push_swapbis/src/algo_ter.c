/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:31:54 by arpages           #+#    #+#             */
/*   Updated: 2024/01/09 14:10:15 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_xtrm(t_stack *stack, t_lst *node)
{
	t_lst	*cmp;

	cmp = stack->a;
	while (cmp && node->rank < cmp->rank)
	{
		if (cmp->next == NULL)
			return (1);
		cmp = cmp->next;
	}
	cmp = stack->a;
	while (cmp && node->rank > cmp->rank)
	{
		if (cmp->next == NULL)
			return (2);
		cmp = cmp->next;
	}
	return (0);
}

void	calc_xtrm(t_stack *stack, t_lst *lst, int rank_min, int i)
{
	t_lst	*tmp;
	t_lst	*max;

	tmp = stack->a;
	max = tmp;
	if (is_xtrm(stack, lst) >= 1)
	{
		while (tmp)
		{
			if (tmp->rank > max->rank)
			{
				max = tmp;
				rank_min = i;
			}
			if (lsize(stack->a) % 2 == 1 && (lsize(stack->a) / 2) == i)
				i = i * -1;
			else if (lsize(stack->a) % 2 == 0 && (lsize(stack->a) / 2) == i)
				i = -i + 1;
			else
				i++;
			tmp = tmp->next;
		}
		lst->to_a = rank_min;
	}
}

void	adjust(t_stack *stack)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = stack->a;
	while (tmp->rank != 1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i < lsize(stack->a) / 2)
	{
		while (stack->a->rank != 1)
			mv_ra(stack);
	}
	else
	{
		while (stack->a->rank != 1)
			mv_rra(stack);
	}
}
