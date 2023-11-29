/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:32:19 by arpages           #+#    #+#             */
/*   Updated: 2023/10/13 16:39:57 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	lbase;
	unsigned int	nb;
	int				retour;

	lbase = 0;
	nb = nbr;
	retour = 0;
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
