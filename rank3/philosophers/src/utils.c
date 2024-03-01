/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:05:44 by arpages           #+#    #+#             */
/*   Updated: 2024/02/22 22:14:16 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		++i;
	}
	return (sign * res);
}

int	get_time(t_table *table)
{
	struct timeval	time;
	int				usec;

	usec = 0;
	gettimeofday(&time, NULL);
	if (time.tv_usec < table->start_time)
	{
		usec += (time.tv_sec - table->seconde - 1) * 1000000;
		usec += (1000000 - table->start_time + time.tv_usec);
	}
	else
	{
		usec += (time.tv_sec - table->seconde) * 1000000;
		usec += (time.tv_usec - table->start_time);
	}
	return (usec / 1000);
}

int	psleep(int mtime, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < mtime / 5)
	{
		if (get_time(philo->table) - philo->last_meal > philo->table->time_death || philo->table->death == 1)
		{
			printf ("\033[31m%d  %d  Died\033[0m\n", get_time(philo->table), philo->name);
			philo->table->death = 1;
			return (1);
		}
		usleep(5000);
		i++;
	}
	return (0);
}
