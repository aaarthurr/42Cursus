/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:45:30 by arthur            #+#    #+#             */
/*   Updated: 2024/02/27 15:17:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*living(void *temp)
{
	t_philo	*philo;
	int i;

	i = 0;
	philo = (t_philo *)temp;
	while (philo->table->death != 1 && i != philo->table->turn)
	{
		if (get_time(philo->table) - philo->last_meal > philo->table->time_death || philo->table->death == 1)
		{
			printf ("\033[31m%d  %d  Died\033[0m\n", get_time(philo->table), philo->name);
			philo->table->death = 1;
			return (NULL);
		}
		else if (eat(philo) == 1)
		{
			if (philo->phase != 2)
				printf ("%d  %d  is thinking\n", get_time(philo->table), philo->name);
			philo->phase = 2;
		}
		else
		{
			i++;
			printf ("%d  %d  is sleeping\n", get_time(philo->table), philo->name);
			philo->phase = 0;
			psleep(philo->table->time_sleep, philo);
		}
	}
	printf("\033[36m%d FINISHED HIS CICLE\033[0m\n", philo->name);
	return (NULL);
}

int	eat(t_philo *philo)
{
	if (philo->next->name == philo->name)
		return (1);
	else if ((philo->fork == 0 && philo->next->fork == 0 && philo->phase != 1) || (get_time(philo->table) - philo->last_meal + philo->table->time_sleep > philo->table->time_death && philo->phase != 1))
	{
		philo->phase = 1;
		if ((philo->next->fork == 1 || philo->previous->phase == 1) && philo->is_hungry == 0 && get_time(philo->table) - philo->last_meal + philo->table->time_sleep < philo->table->time_death)
		{
			philo->is_hungry = 1;
			philo->phase = 0;
			return (1);
		}
		pthread_mutex_lock(&philo->mutex);
		philo->fork = 1;
		printf("%d  %d  has taken a fork\n", get_time(philo->table), philo->name);
		pthread_mutex_lock(&philo->next->mutex);
		philo->next->fork = 1;
		printf("%d  %d  has taken a fork\n", get_time(philo->table), philo->name);
		printf("%d  %d  is eating\n", get_time(philo->table), philo->name);
		philo->last_meal = get_time(philo->table);
		psleep(philo->table->time_eat, philo);
		philo->fork = 0;
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&philo->next->mutex);
		philo->next->fork = 0;
		philo->is_hungry = 0;
		return (0);
	}
	philo->is_hungry = 1;
	return (1);
}

void	create_thread(t_table *table)
{
	t_philo	*temp;
	int		i;

	i = 0;
	temp = table->philo;
	while (i < table->size)
	{
		pthread_create(&temp->thread, NULL, &living, temp);
		temp = temp->next;
		i++;
	}
}

void	wait(t_table *table)
{
	t_philo	*temp;
	int		i;

	i = 0;
	temp = table->philo;
	while (i < table->size)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
		i++;
	}
}
