/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:11:43 by arpages           #+#    #+#             */
/*   Updated: 2023/10/14 12:57:56 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char *txt, va_list args, int retour)
{
	int	i;

	i = 0;
	while (i + 1 <= ft_strlen(txt) - 1)
	{
		if (txt[i] == '%' && ft_strchr("cdixX", txt[i + 1]))
			retour += is_int(txt[i + 1], va_arg(args, int));
		else if (txt[i] == '%' && txt[i + 1] == 'p')
			retour += is_point(va_arg(args, unsigned long long));
		else if (txt[i] == '%' && txt[i + 1] == 's')
			retour += is_str(va_arg(args, int *));
		else if (txt[i] == '%' && txt[i + 1] == '%')
			retour += ft_putchar('%');
		else if (txt[i] == '%' && txt[i + 1] == 'u')
			retour += is_uint(va_arg(args, unsigned int));
		else
			retour += ft_putchar(txt[i--]);
		i = i + 2;
	}
	if (txt[i])
		retour += ft_putchar(txt[i]);
	return (retour);
}

int	ft_printf(const char *txt, ...)
{
	int		retour;
	va_list	args;

	retour = 0;
	va_start(args, txt);
	retour = ft_type(txt, args, retour);
	va_end(args);
	return (retour);
}
