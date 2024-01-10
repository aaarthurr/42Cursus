/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:57:51 by arpages           #+#    #+#             */
/*   Updated: 2023/12/26 16:55:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long nbr, char *base)
{
	int		lbase;
	long	nb;
	int		retour;

	lbase = 0;
	nb = nbr;
	retour = 0;
	if (nb < 0)
	{
		retour += ft_putchar('-');
		nb *= -1;
	}
	while (base[lbase])
		lbase++;
	if (nb < lbase)
		retour += ft_putchar(base[nb]);
	if (nb >= lbase)
	{
		retour += ft_putnbr_base(nb / lbase, base);
		retour += ft_putnbr_base(nb % lbase, base);
	}
	return (retour);
}

int	ft_putstr(char *s)
{
	int	i;
	int	retour;

	retour = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		retour += ft_putchar(s[i]);
		i++;
	}
	return (retour);
}
