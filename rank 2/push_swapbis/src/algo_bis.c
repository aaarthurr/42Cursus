/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:22:51 by arpages           #+#    #+#             */
/*   Updated: 2023/12/28 17:42:00 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	calc_b(t_stack *stack)
{
	t_lst	*index;
	int		i;

	i = 0;
	index = stack->b;
	while (index)
	{
		index->to_b = i;
		if (lsize(stack->b) % 2 == 1 && (lsize(stack->b) / 2) == i)
			i = i * -1;
		else if (lsize(stack->b) % 2 == 0 && (lsize(stack->b) / 2) == i)
			i = -i + 1;
		else
			i++;
		index = index->next;
	}
}

void	calc_a(t_stack *stack)
{
	t_lst	*index;
	t_lst	*cmp;
	int		i;

	index = stack->b;
	while (index)
	{
		cmp = stack->a;
		i = 1;
		while (cmp->next && !(index->rank > cmp->rank
				&& index->rank < cmp->next->rank))
		{
			if (lsize(stack->a) % 2 == 1 && (lsize(stack->a) / 2) == i)
				i = i * -1;
			else if (lsize(stack->a) % 2 == 0 && (lsize(stack->a) / 2) == i)
				i = -i + 1;
			else
				i++;
			cmp = cmp->next;
		}
		index->to_a = i;
		calc_xtrm(stack, index, 0, 1);
		index = index->next;
	}
}

void	applie_mv(t_stack *stack)
{
	t_lst	*to_apl;

	while (stack->b)
	{
		calc_b(stack);
		calc_a(stack);
		to_apl = srch_min(stack);
		while (to_apl->to_a < 0 && to_apl->to_b < 0)
			duo_min(stack, to_apl);
		while (to_apl->to_a > 0 && to_apl->to_b > 0)
			duo_max(stack, to_apl);
		while (to_apl->to_a != 0)
			opti_a(stack, to_apl);
		while (to_apl->to_b != 0)
			opti_b(stack, to_apl);
		if (is_xtrm(stack, to_apl))
		{
			mv_pa(stack);
			mv_ra(stack);
		}
		else
			mv_pa(stack);
	}
}

t_lst	*srch_min(t_stack *stack)
{
	t_lst	*index;
	t_lst	*temp;
	int		i;

	index = stack->b;
	temp = index;
	i = abs_val(temp->to_a) + abs_val(temp->to_b);
	while (temp)
	{
		if (abs_val(temp->to_a) + abs_val(temp->to_b) < i)
		{
			i = abs_val(temp->to_a) + abs_val(temp->to_b);
			index = temp;
		}
		temp = temp->next;
	}
	return (index);
}
