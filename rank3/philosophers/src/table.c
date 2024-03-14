/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:10:55 by arthur            #+#    #+#             */
/*   Updated: 2024/03/14 10:34:00 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	printf("\033[0m");
	pthread_mutex_unlock(philo->write_lock);	
}

int	philoopher_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_if_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].size)
	{
		if (philoopher_dead(&philo[i], philo[i].time_to_die))
		{
			printf("\033[31m");
			print_message("died", &philo[i], philo[i].name);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->is_dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}


int	check_if_all_ate(t_philo *philo)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philo[0].num_meals == -1)
		return (0);
	while (i < philo[0].size)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meal_eaten >= philo[i].num_meals)
			finished_eating++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (finished_eating == philo[0].size)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->is_dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		return (1);
	}
	return (0);
}


void	*monitor(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philo) == 1 || check_if_all_ate(philo) == 1)
			break ;
	return (pointer);
}