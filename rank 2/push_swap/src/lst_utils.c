/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:54:27 by arpages           #+#    #+#             */
/*   Updated: 2023/11/29 16:54:10 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lstnew(int content)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	new->content = content;
	new->rank = -1;
	new->next = NULL;
	return (new);
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}

void	ft_lstadd_front(t_lst **lst, t_lst *new)
{
	t_lst	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	*lst = new;
	new -> next = tmp;
}
