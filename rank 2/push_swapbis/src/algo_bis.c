/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:22:51 by arpages           #+#    #+#             */
/*   Updated: 2023/12/19 18:04:50 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_b(t_stack *stack)
{
	t_lst *index;
	int i;
	
	i = 0;
	index = stack->b;
	while (index)
	{
		index->to_b = i;
		if (ft_lstsize(stack->b) % 2 == 1 && (ft_lstsize(stack->b) / 2) == i)
			i = i * -1;
		else if (ft_lstsize(stack->b) % 2 == 0 && (ft_lstsize(stack->b) / 2) == i)
			i = -i + 1;
		else
			i++;
		index = index->next;
	}
}

void calc_a(t_stack *stack)
{
	t_lst *index;
	t_lst *cmp;
	int i;
	
	index = stack->b;
	while (index)
	{
		cmp = stack->a;
		i = 1;
		while (cmp->next && !(index->rank > cmp->rank && index->rank < cmp->next->rank))
		{
			if (ft_lstsize(stack->a) % 2 == 1 && (ft_lstsize(stack->a) / 2) == i)
				i = i * -1;
			else if (ft_lstsize(stack->a) % 2 == 0 && (ft_lstsize(stack->a) / 2) == i)
				i = -i + 1;
			else
				i++;
			cmp = cmp->next;
		}
		index->to_a = i;
		index = index->next;
	}
}

void applie_mv(t_stack *stack)
{
	t_lst *to_apl;
	
	while (stack->b)
	{
		calc_b(stack);
		calc_a(stack);
		to_apl = srch_min(stack);
		//printf("will us node at rank : %d | with %d AND %d\n", to_apl->rank, to_apl->to_a, to_apl->to_b);
		while (to_apl->to_a != 0)
		{
			if (to_apl->to_a < 0)
			{
				to_apl->to_a++;
				mv_rra(stack);
			}
			else
			{
				to_apl->to_a--;
				mv_ra(stack);
			}
		}		
		while (to_apl->to_b != 0)
		{
			if (to_apl->to_b < 0)
			{
				to_apl->to_b++;
				mv_rrb(stack);
			}
			else
			{
				to_apl->to_b--;
				mv_rb(stack);
			}
		}
		mv_pa(stack);
	}
}

t_lst *srch_min(t_stack *stack)
{
	t_lst *index;
	t_lst *temp;
	int i;

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
	return(index);
}
