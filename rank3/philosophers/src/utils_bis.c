/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:43:58 by arthur            #+#    #+#             */
/*   Updated: 2024/03/01 13:03:31 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int ft_strchr(char *str, char letter)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == letter)
			return(1);
		i++;
	}
	return(0);
}

int verif_args(char **str)
{
	int i;
	int y;

	i = 1;
	while (str[i] != NULL)
	{
		y = 0;
		while(str[i][y] != '\0')
		{
			if (ft_strchr("0123456789", str[i][y]) == 0)
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}
