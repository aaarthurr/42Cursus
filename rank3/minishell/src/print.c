/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:04:22 by lle-saul          #+#    #+#             */
<<<<<<< HEAD:rank 3/minishell/src/print.c
/*   Updated: 2024/01/22 15:35:13 by arthur           ###   ########.fr       */
=======
/*   Updated: 2024/02/05 11:30:16 by lle-saul         ###   ########.fr       */
>>>>>>> 61fe67aa2fb57ffbe7b16b3abf3f8b1f3a6738b8:rank3/minishell/src/print.c
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *str1, char *str2, char *str3)
{
	if (str1)
		ft_putstr(str1, 2);
	if (str2)
		ft_putstr(str2, 2);
	if (str3)
		ft_putstr(str3, 2);
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], fd);
		i++;
	}
}

void	ft_putstr_n(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], fd);
		i++;
	}
	ft_putchar('\n', fd);
}
