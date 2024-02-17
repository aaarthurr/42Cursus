/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:48:55 by arpages           #+#    #+#             */
/*   Updated: 2023/10/04 10:00:56 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int main()
{
    char    str[] = "tst565 ]";
    printf("%d \n", ft_isalnum(str[1]));
    printf("%d \n", ft_isalnum(str[4]));
    printf("%d", ft_isalnum(str[7]));
}*/