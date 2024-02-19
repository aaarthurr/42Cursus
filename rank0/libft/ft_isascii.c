/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:48:55 by arpages           #+#    #+#             */
/*   Updated: 2023/10/04 10:36:19 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main()
{
    char    str[] = "tst565 ]";
    printf("%d \n", ft_isascii(str[1]));
    printf("%d \n", ft_isascii(str[4]));
    printf("%d", ft_isascii(str[11]));
}*/