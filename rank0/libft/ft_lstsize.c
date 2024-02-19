/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:39:05 by arpages           #+#    #+#             */
/*   Updated: 2023/10/06 20:09:36 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*next;

	if (lst == NULL)
		return (0);
	i = 1;
	next = lst->next;
	while (next != NULL)
	{
		i++;
		next = next->next;
	}
	return (i);
}
