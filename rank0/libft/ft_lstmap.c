/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:47:22 by arpages           #+#    #+#             */
/*   Updated: 2023/10/07 11:30:34 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*first;
	t_list	*to_add;

	if (!lst || !f || !del)
		return (NULL);
	first = ft_lstnew((*f)(lst->content));
	start = first;
	to_add = lst->next;
	while (to_add->next != NULL)
	{
		ft_lstadd_back(&start, ft_lstnew((*f)(to_add->content)));
		to_add = to_add->next;
		start = start->next;
	}
	ft_lstadd_back(&start, ft_lstnew((*f)(to_add->content)));
	return (first);
}
