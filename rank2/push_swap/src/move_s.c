/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:42:42 by arpages           #+#    #+#             */
/*   Updated: 2024/01/08 11:01:08 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_stack *stack)
{
	t_lst	*tmp;
	int		content;
	int		rank;

	tmp = stack->a;
	rank = tmp->next->rank;
	content = tmp->next->content;
	tmp->next->rank = tmp->rank;
	tmp->next->content = tmp->content;
	tmp->content = content;
	tmp->rank = rank;
}

void	ft_sb(t_stack *stack)
{
	t_lst	*tmp;
	int		content;
	int		rank;

	tmp = stack->b;
	rank = tmp->next->rank;
	content = tmp->next->content;
	tmp->next->rank = tmp->rank;
	tmp->next->content = tmp->content;
	tmp->content = content;
	tmp->rank = rank;
}

void	mv_sa(t_stack *stack)
{
	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	ft_sa(stack);
	write(1, "sa\n", 3);
}

void	mv_sb(t_stack *stack)
{
	if (stack->b == NULL || stack->b->next == NULL)
		return ;
	ft_sb(stack);
	write(1, "sb\n", 3);
}

void	mv_ss(t_stack *stack)
{
	if (stack->a == NULL || stack->a->next == NULL)
		return ;
	else if (stack->b == NULL || stack->b->next == NULL)
		return ;
	ft_sa(stack);
	ft_sb(stack);
	write(1, "ss\n", 3);
}
