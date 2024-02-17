/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:40:52 by arpages           #+#    #+#             */
/*   Updated: 2023/10/13 20:42:45 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint(unsigned long long nbr)
{
	int	result;

	result = 0;
	if (nbr >= 16)
	{
		result += ft_putpoint(nbr / 16);
		result += ft_putpoint(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			result += ft_putchar(nbr + '0');
		else if (nbr >= 10)
			result += ft_putchar((nbr - 10) + 'a');
	}
	return (result);
}
