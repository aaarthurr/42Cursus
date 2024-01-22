/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:04:56 by arthur            #+#    #+#             */
/*   Updated: 2024/01/12 18:26:06 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int		g_recieved;

static void	ft_sig_handler(int sig, siginfo_t *sinfo, void *context)
{
	(void) context;
	if (sig == SIGUSR1)
		g_recieved = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Successfully sent the message to : %d ! \n", sinfo->si_pid);
		exit(EXIT_SUCCESS);
	}
}

static void	send_bit(char c, int bit, int pid)
{
	if (c & (128 >> bit))
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error("Signal can't be sent.\n");
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error("Signal can't be sent.\n");
	}
}

static void	convert(char c, int pid)
{
	int	bit;
	int	time_out;

	bit = 0;
	time_out = 0;
	while (bit < 8)
	{
		g_recieved = 0;
		send_bit(c, bit, pid);
		while (!g_recieved)
		{
			if (time_out >= 3)
				ft_error("Server did not respond in time...\n");
			time_out++;
			sleep(1);
		}
		time_out = 0;
		bit++;
		usleep(100);
	}
}

static void	send_text(char *str, int len, int pid)
{
	int	i;

	i = 0;
	while (i <= len)
		convert(str[i++], pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sact;

	if (argc != 3)
		ft_error("USE : ./client <PID> <message>\n");
	pid = ft_atoi(argv[1]);
	if (!pid)
		ft_error("Pid error.\n");
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = ft_sig_handler;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);
	send_text(argv[2], ft_strlen(argv[2]), pid);
	return (0);
}
