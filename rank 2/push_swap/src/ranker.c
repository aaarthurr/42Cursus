/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:52:43 by arpages           #+#    #+#             */
/*   Updated: 2023/11/29 17:13:37 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void    ranker(t_lst *lst)
{
    int rank_num;
    int min_value;
    t_lst      *temp;
    t_lst      *min;

    temp = lst;
    rank_num = 1;
    min_value = lst->content;
    while (lst)
	{
        lst = temp;
		if ()
		lst = lst->next;
	}
}