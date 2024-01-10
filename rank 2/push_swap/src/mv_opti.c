/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:58:45 by arthur            #+#    #+#             */
/*   Updated: 2023/12/27 14:58:59 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	duo_min(t_stack *stack, t_lst *to_apl)
{
	if (to_apl->to_a < 0 && to_apl->to_b < 0)
	{
		to_apl->to_a++;
		to_apl->to_b++;
		mv_rrr(stack);
	}
}

void	duo_max(t_stack *stack, t_lst *to_apl)
{
	if (to_apl->to_a > 0 && to_apl->to_b > 0)
	{
		to_apl->to_a--;
		to_apl->to_b--;
		mv_rr(stack);
	}
}

void	opti_a(t_stack *stack, t_lst *to_apl)
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

void	opti_b(t_stack *stack, t_lst *to_apl)
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
