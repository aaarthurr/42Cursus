/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:52:43 by arpages           #+#    #+#             */
/*   Updated: 2023/12/02 17:23:33 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_lst *lst)
{
	int		i;
	t_lst	*next;

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

void    ranker(t_lst *lst)
{
    int rank_num;
    int min_value;
    int size;
    t_lst      *temp;
    t_lst      *min;

    size = ft_lstsize(lst);
    rank_num = 1;
    while (size-- > 0)
	{
        temp = lst;
        min_value = INT_MAX;
		while (temp != NULL)
        {
            if (min_value > temp->content && temp->rank == -1)
            {
                min_value = temp->content;
                min = temp;
                printf("min value is ->%d\n", min_value);
            }
            temp = temp->next;
        }
        printf("\n[rank num = %d]\n", rank_num);
        printf("-> applied to : %d\n", min->content);
        min->rank = rank_num;
        rank_num++;
        printf("-------------------\n");
    }
}
