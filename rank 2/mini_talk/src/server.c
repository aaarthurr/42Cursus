/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:04:52 by arthur            #+#    #+#             */
/*   Updated: 2024/01/12 18:18:04 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	displayer(char c)
{
	static char	*str;
	char		*tmp;

	if (!str)
	{
		str = malloc(1);
		*str = '\0';
	}
	tmp = malloc(2);
	*tmp = c;
	*(tmp + 1) = '\0';
	str = ft_strjoin(str, tmp);
	if (c == 0)
	{
		ft_printf("%s\n", str);
		free(str);
		str = NULL;
		write(1, "->", 2);
	}
	free(tmp);
}

void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	static int		c;
	static int		bit;
	static pid_t	client_pid;

	(void) context;
	if (!c || client_pid != sinfo->si_pid)
	{
		c = 255;
		bit = 0;
	}
	client_pid = sinfo->si_pid;
	if (sig == SIGUSR1)
		c ^= (128 >> bit);
	else if (sig == SIGUSR2)
		c |= (128 >> bit);
	if (++bit == 8)
	{
		displayer(c);
		if (c == 0)
			kill(client_pid, SIGUSR2);
		bit = 0;
		c = 255;
	}
	usleep(100);
	kill(client_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sact;

	pid = getpid();
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_sig_handler;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);
	ft_printf("PID:[%d]\n\n", pid);
	write(1, "->", 2);
	while (1)
		pause();
	return (EXIT_FAILURE);
}
