/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:11:52 by arpages           #+#    #+#             */
/*   Updated: 2023/10/07 11:24:05 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*start;

	if (!lst || !del)
		return ;
	start = *lst;
	while (start)
	{
		temp = start->next;
		(*del)(start->content);
		free(start);
		start = temp;
	}
	*lst = NULL;
}
