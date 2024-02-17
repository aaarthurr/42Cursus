/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:31:38 by arpages           #+#    #+#             */
/*   Updated: 2023/12/28 17:39:55 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_lst(t_lst *lst)
{
	t_lst	*rmv;

	if (lst)
	{
		rmv = lst;
		while (lst->next)
		{
			lst = lst->next;
			free(rmv);
			rmv = lst;
		}
		free(lst);
	}
}
