/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:30:22 by arpages           #+#    #+#             */
/*   Updated: 2023/12/20 15:22:38 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo(t_stack *stack)
{
	devide(stack);
	sort_trio(stack, stack->a);
	applie_mv(stack);
	adjust(stack);
}

void devide(t_stack *stack)
{
	int i;
	int j;
	int size;
	int div;

	div = divide_size(stack->a);
	size = ft_lstsize(stack->a);
	i = 1;
	j = 0;
	while (ft_lstsize(stack->a) > 3)
	{
		if (stack->a->rank <= (size / div) * i)
		{
			mv_pb(stack);
			if (stack->a->rank > (size / div) * (i + 1))
				mv_rr(stack);
			else
				mv_rb(stack);
			j++;
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
		//print_lst(stack->a, stack->b);
	}
}

void sort_trio(t_stack *stack, t_lst *a)
{
	if ((a->rank > a->next->rank && a->rank < a->next->next->rank) && 
		(a->next->rank < a->rank && a->next->rank < a->next->next->rank))
		mv_sa(stack);
	else if ((a->rank > a->next->rank && a->rank > a->next->next->rank) && 
		(a->next->rank < a->rank && a->next->rank > a->next->next->rank))
	{
		mv_sa(stack);
		mv_rra(stack);
	}
	else if ((a->rank > a->next->rank && a->rank > a->next->next->rank) && 
		(a->next->rank < a->rank && a->next->rank < a->next->next->rank))
		mv_ra(stack);
	else if ((a->rank < a->next->rank && a->rank < a->next->next->rank) && 
		(a->next->rank > a->rank && a->next->rank > a->next->next->rank))
	{
		mv_sa(stack);
		mv_ra(stack);
	}
	else if ((a->rank < a->next->rank && a->rank > a->next->next->rank) && 
		(a->next->rank > a->rank && a->next->rank > a->next->next->rank))
		mv_rra(stack);
	
}

int divide_size(t_lst *lst)
{
	if (ft_lstsize(lst) <= 200)
		return (4);
	else
		return (8);
}
