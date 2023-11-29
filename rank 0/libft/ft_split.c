/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:35:51 by arpages           #+#    #+#             */
/*   Updated: 2023/10/07 13:06:08 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_word(char const *s, char c, int i)
{
	size_t	size;
	char	*result;

	size = 0;
	while (s[i] == c)
	{
		i++;
	}
	while (s[i + size] != c && s[i + size])
		size++;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	size = 0;
	while (s[i + size] != c && s[i + size])
	{
		result[size] = s[i + size];
		size++;
	}
	result[size] = '\0';
	return (result);
}

static int	ft_get_size(char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	while (s[i] == c)
	{
		i++;
	}
	if (i == ft_strlen(s))
		return (0);
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**result;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_get_size(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i + 1])
	{
		if ((s[i] == c && s[i + 1] != c) || (i == 0 && s[i] != c))
		{
			result[j] = ft_word(s, c, i);
			j++;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}
