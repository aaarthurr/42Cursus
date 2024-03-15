/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:23:18 by arthur            #+#    #+#             */
/*   Updated: 2024/03/15 08:22:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init_var(t_philo *philo, char **argv, int i)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->size = ft_atoi(argv[1]);
	philo->name = i + 1;
	philo->eating = 0;
	philo->meal_eaten = 0;
	philo->start_time = get_current_time();
	philo->last_meal = get_current_time();
	if (argv[5])
		philo->num_meals = ft_atoi(argv[5]);
	else
		philo->num_meals = -1;
}

void	init(t_philo *phi, t_table *prog, pthread_mutex_t *frks, char **argv)
{
	int	i;

	i = 0;
	while (i < atoi(argv[1]))
	{
		init_var(&phi[i], argv, i);
		phi[i].dead_lock = &prog->dead_lock;
		phi[i].is_dead = &prog->is_dead;
		phi[i].meal_lock = &prog->meal_lock;
		phi[i].print_line = &prog->print_line;
		phi[i].fork = &frks[i];
		if (i == 0)
			phi[i].previous_fork = &frks[phi[i].size - 1];
		else
			phi[i].previous_fork = &frks[i - 1];
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
	program->is_dead = 0;
	program->philo = philos;
	pthread_mutex_init(&program->print_line, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}
