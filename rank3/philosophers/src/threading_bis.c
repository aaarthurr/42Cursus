/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:06:24 by arpages           #+#    #+#             */
/*   Updated: 2024/03/09 13:49:45 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eat_bis(t_philo *philo, int entry)
{
	if (philo->table->death == 0)
	{
		printf("%d  %d  is eating\n", get_time(philo->table), philo->name);
		philo->last_meal = get_time(philo->table);
		psleep(entry + philo->table->time_eat, philo);
	}
	philo->fork = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->next->mutex);
	philo->next->fork = 0;
	philo->is_hungry = 0;
}

void	death_philo(t_philo *philo)
{
	int tdeath;
	
	if (philo->is_dead != 1)
	{
		tdeath = get_time(philo->table);
		philo->table->death++;
		if (philo->table->death - 1 == 0)
		{
			usleep(1000);
			printf ("\033[31m%d  %d  Died\033[0m\n", tdeath, philo->name);
		}
	}
	philo->is_dead = 1;
}

void	end_simu(t_table *table)
{
	int i;
	t_philo *temp;
	
	i = 0;
	temp = table->philo;
	while (i != table->size - 1)
	{
		free(temp->previous);
		temp = temp->next;
		i++;
	}
	free(temp);
	free(table);
}