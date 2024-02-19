/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:30:22 by arpages           #+#    #+#             */
/*   Updated: 2024/01/09 14:22:32 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo(t_stack *stack)
{
	if (is_sorted(stack) == 1)
		return ;
	if (lsize(stack->a) == 3)
		sort_trio(stack, stack->a);
	else if (lsize(stack->a) <= 10)
		lil_sort(stack);
	else
	{
		devide(stack, 1, 0);
		sort_trio(stack, stack->a);
		applie_mv(stack);
		adjust(stack);
	}
}

void	devide(t_stack *stack, int i, int j)
{
	int	size;
	int	div;

	div = divide_size(stack->a);
	size = lsize(stack->a);
	while (lsize(stack->a) > 3)
	{
		if (stack->a->rank <= (size / div) * i)
		{
			j = j + devide_bis(stack, size, div, i);
		}
		else if (stack->a->rank <= (size / div) * (i + 1))
		{
			mv_pb(stack);
			j++;
		}
		else
			mv_ra(stack);
		if (j >= (size / div) * 2)
		{
			i += 2;
			j = 0;
		}
	}
}

int	devide_bis(t_stack *stack, int size, int div, int i)
{
	mv_pb(stack);
	if (stack->a->rank > (size / div) * (i + 1))
		mv_rr(stack);
	else
		mv_rb(stack);
	return (1);
}

void	sort_trio(t_stack *stack, t_lst *a)
{
	if ((a->rank > a->next->rank && a->rank < a->next->next->rank)
		&& (a->next->rank < a->rank && a->next->rank < a->next->next->rank))
		mv_sa(stack);
	else if ((a->rank > a->next->rank && a->rank > a->next->next->rank)
		&& (a->next->rank < a->rank && a->next->rank > a->next->next->rank))
	{
		mv_sa(stack);
		mv_rra(stack);
	}
	else if ((a->rank > a->next->rank && a->rank > a->next->next->rank)
		&& (a->next->rank < a->rank && a->next->rank < a->next->next->rank))
		mv_ra(stack);
	else if ((a->rank < a->next->rank && a->rank < a->next->next->rank)
		&& (a->next->rank > a->rank && a->next->rank > a->next->next->rank))
	{
		mv_sa(stack);
		mv_ra(stack);
	}
	else if ((a->rank < a->next->rank && a->rank > a->next->next->rank)
		&& (a->next->rank > a->rank && a->next->rank > a->next->next->rank))
		mv_rra(stack);
}

int	divide_size(t_lst *lst)
{
	if (lsize(lst) <= 200)
		return (4);
	else
		return (8);
}
