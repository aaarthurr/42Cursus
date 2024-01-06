/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:09:38 by arpages           #+#    #+#             */
/*   Updated: 2023/12/28 17:40:36 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	verif_lst(t_lst *lst)
{
	t_lst	*lst_cpy;

	while (lst->next)
	{
		lst_cpy = lst->next;
		while (lst_cpy)
		{
			if (lst->content == lst_cpy->content)
				return (-1);
			lst_cpy = lst_cpy->next;
		}
		lst = lst->next;
	}
	return (1);
}

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if ((char)c == 0)
		return (ptr);
	return (NULL);
}

int	verif_char(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strchr(" +-0123456789", str[i]) == NULL)
			return (-1);
		if (ft_strchr("+-", str[i]))
		{
			count++;
			if (count > 1)
				return (-2);
		}
		if (str[i] == ' ')
			count = 0;
		i++;
	}
	return (1);
}

int	verif_strstr(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (verif_char(str[i]) < 0)
			return (-1);
		i++;
	}
	return (1);
}
