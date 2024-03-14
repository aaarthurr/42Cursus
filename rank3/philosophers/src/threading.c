/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:26:31 by arthur            #+#    #+#             */
/*   Updated: 2024/03/14 11:06:16 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->is_dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->name % 2 == 0)
		ft_usleep(1, philo);
	while (!dead_loop(philo)) 
	{
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (pointer);
}

int	create_thread(t_table *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->philo) != 0)
		destory_all(1, program, forks);
	i = 0;
	while (i < program->philo[0].size)
	{
		if (pthread_create(&program->philo[i].thread, NULL, &philo_routine,
				&program->philo[i]) != 0)
			destory_all(1, program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destory_all(1, program, forks);
	while (i < program->philo[0].size)
	{
		if (pthread_join(program->philo[i].thread, NULL) != 0)
			destory_all(1, program, forks);
		i++;
	}
	return (0);
}
