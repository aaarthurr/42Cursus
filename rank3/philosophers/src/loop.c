/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:30:44 by arthur            #+#    #+#             */
/*   Updated: 2024/03/14 11:12:37 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	think(t_philo *philo)
{
	print_message("is thinking", philo, philo->name);
}

void	philo_sleep(t_philo *philo)
{
	print_message("is sleeping", philo, philo->name);
	ft_usleep(philo->time_to_sleep, philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->previous_fork);
	print_message("has taken a fork", philo, philo->name);
	if (philo->size == 1)
	{
		ft_usleep(philo->time_to_die, philo);
		pthread_mutex_unlock(philo->previous_fork);
		return ;
	}
	pthread_mutex_lock(philo->fork);
	print_message("has taken a fork", philo, philo->name);
	philo->eating = 1;
	print_message("is eating", philo, philo->name);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meal_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat, philo);
	philo->eating = 0;
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->previous_fork);
}
