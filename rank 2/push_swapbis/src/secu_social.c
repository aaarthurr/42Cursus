/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secu_social.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:53:54 by arpages           #+#    #+#             */
/*   Updated: 2023/12/18 15:52:36 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_strstr(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

void	create_n_add(t_lst **lst, char **str, int i)
{
	long int content;

	content = ft_atoi(str[i]);
	if (content > INT_MAX || content < INT_MIN)
	{
		printf("Value too big (or small)\n");
		printf("or non numerical characters\n");
		ft_free_lst(*lst);
		free_strstr(str);
		free(str);
		exit(1);
	}
	else
	{
		ft_lstadd_back(lst, ft_lstnew(content));
		free(str[i]);
	}
}
