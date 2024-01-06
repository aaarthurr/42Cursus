/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:04:52 by arthur            #+#    #+#             */
/*   Updated: 2024/01/03 18:17:01 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	displayer(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit >= 8)
	{
		ft_printf("%c", i);
		if (i == '\n')
			ft_printf("Waiting for a message...\n");
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Use the executable without arguments\n-> ./server\n");
		return(0);
	}
	pid = getpid();
	ft_printf("|--PID--|\n- (%d) -\n---------\n\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, displayer);
		signal(SIGUSR2, displayer);
		pause ();
	}
	return (0);
}
