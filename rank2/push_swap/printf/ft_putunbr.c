/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:54:28 by arpages           #+#    #+#             */
/*   Updated: 2023/12/26 16:55:45 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	retour;

	retour = 0;
	if (n / 10)
	{
		retour += ft_putunbr(n / 10);
		retour += ft_putunbr(n % 10);
	}
	else
		retour += ft_putchar('0' + n);
	return (retour);
}
