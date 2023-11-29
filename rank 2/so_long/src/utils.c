/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:39 by arpages           #+#    #+#             */
/*   Updated: 2023/11/18 17:21:49 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(0);
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	dup_map(t_data *data)
{
	int	i;

	i = 0;
	data->sec_map = malloc(sizeof(char *) * (data->height + 1));
	while (i < data->height)
	{
		data->sec_map[i] = ft_strdup(data->map[i]);
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
