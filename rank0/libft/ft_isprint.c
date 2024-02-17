/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:48:55 by arpages           #+#    #+#             */
/*   Updated: 2023/10/04 10:36:16 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main()
{
    char    str[] = "tst565]\n";
    printf("%d \n", ft_isprint(str[1]));
    printf("%d \n", ft_isprint(str[4]));
    printf("%d", ft_isprint(str[7]));
}*/