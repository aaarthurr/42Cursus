/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:11:43 by arpages           #+#    #+#             */
/*   Updated: 2023/12/26 17:04:38 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_type(const char *txt, va_list args, int retour)
{
	int	i;

	i = 0;
	while (i + 1 <= ft_strlen(txt) - 1)
	{
		if (txt[i] == '%' && ft_strchr_boo("cdixX", txt[i + 1]))
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

/*
#include <stdio.h>

int	main(void)
{
	int a;
	//unsigned int b;
	//char * str;
	//int tst;

	a = 69;
	//b = 69;
	//str = "la maison a tutur";
	//tst = -2147483648;

	ft_printf("BOOONJOOOUUUR\n\n ~voici un 
	petit test de la fonction ft_printf~\n");
	ft_printf("j'ai une maison de %i m2, oui oui %u m2 !!!\n", a, b);
	ft_printf("voud voulez savoir son nom ? : %s\n", str);
	ft_printf("vous voulez savoir ou elle est ? voici
	 son adresse ;) : %p\n", &tst);
	ft_printf("tu savais que :%d est la plus petite valeur 
	pour un int\n", tst);
	ft_printf("et tu savais que %% non rien, haa siiii    ");
	ft_printf("%d en exa c'est : %x lolilol...", a, a);
	ft_printf("\n\n*****\nd'autre test :\n");
	ft_printf("%d%d%d", 400, 42, -42);
	a = ft_printf("une chaine de 28 characters\n");
	ft_printf("(%d)", a);
	ft_printf("my_point%p\n", &a);
	printf("printf%p", &a);
}
*/