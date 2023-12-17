/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:31:38 by arpages           #+#    #+#             */
/*   Updated: 2023/12/17 16:39:17 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void ft_free_lst(t_lst *lst)
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
