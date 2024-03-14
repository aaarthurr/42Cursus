/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:23:18 by arthur            #+#    #+#             */
/*   Updated: 2024/03/14 11:12:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_args(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->size = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_meals = ft_atoi(argv[5]);
	else
		philo->num_meals = -1;
}

void	init_philos(t_philo *philos, t_table *program, pthread_mutex_t *forks,
		char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		init_args(&philos[i], argv);
		philos[i].name = i + 1;
		philos[i].eating = 0;
		philos[i].meal_eaten = 0;
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].is_dead = &program->dead_flag;
		philos[i].fork = &forks[i];
		if (i == 0)
			philos[i].previous_fork = &forks[philos[i].size - 1];
		else
			philos[i].previous_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_all(t_table *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philo = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
