/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:50:58 by arpages           #+#    #+#             */
/*   Updated: 2023/10/13 20:40:00 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_int(char c, int value)
{
	int	retour;

	if (c == 'c')
		retour = ft_putchar(value);
	else if (c == 'd' || c == 'i')
		retour = ft_putnbr(value, "0123456789");
	else if (c == 'x')
		retour = ft_putnbr_base(value, "0123456789abcdef");
	else if (c == 'X')
		retour = ft_putnbr_base(value, "0123456789ABCDEF");
	return (retour);
}

int	is_str(int *value)
{
	int	retour;

	if (!value)
		retour = ft_putstr("(null)");
	else
		retour = ft_putstr((char *)value);
	return (retour);
}

int	is_point(unsigned long long value)
{
	int	retour;

	if (value == 0)
		retour = ft_putstr("(nil)");
	else
	{
		retour = ft_putstr("0x");
		retour += ft_putpoint((unsigned long long)value);
	}
	return (retour);
}

int	is_uint(unsigned int value)
{
	int	retour;

	retour = ft_putunbr((int)value);
	return (retour);
}
