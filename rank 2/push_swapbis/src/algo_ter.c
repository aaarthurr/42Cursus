/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:31:54 by arpages           #+#    #+#             */
/*   Updated: 2023/12/20 15:22:25 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_xtrm(t_stack *stack, t_lst *node)
{
	t_lst	*cmp;

	cmp = stack->a;
	while (cmp && node->rank < cmp->rank)
	{
		if (cmp->next == NULL)
			return(1);
		cmp = cmp->next;
	}
	cmp = stack->a;
	while (cmp && node->rank > cmp->rank)
	{
		if (cmp->next == NULL)
			return(2);
		cmp = cmp->next;
	}
	//printf("NO VALUE\n");
	return(0);
}
void calc_xtrm(t_stack *stack, t_lst *lst)
{
	t_lst	*tmp;
	t_lst	*max;
	int		i;
	int		rank_min;

	tmp = stack->a;
	max = tmp;
	rank_min = 0;
	i = 1;
	while (tmp)
	{
		if (tmp->rank > max->rank)
		{
			max = tmp;
			rank_min = i;
		}
		if (ft_lstsize(stack->a) % 2 == 1 && (ft_lstsize(stack->a) / 2) == i)
			i = i * -1;
		else if (ft_lstsize(stack->a) % 2 == 0 && (ft_lstsize(stack->a) / 2) == i)
			i = -i + 1;
		else
			i++;
		tmp = tmp->next;
	}
	if (is_xtrm(stack, lst) >= 1)
	{
		lst->to_a = rank_min;
		//printf("%d, will be the lowest or highest value, so %d moves in A\n", lst->rank, rank_min);
	}
}

void adjust(t_stack *stack)
{
	while (stack->a->rank != 1)
		mv_ra(stack);
}