/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:45:30 by arthur            #+#    #+#             */
/*   Updated: 2024/03/02 16:38:57 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

void	*living(void *temp)
{
	t_philo	*philo;
	int i;

	i = 0;
	philo = (t_philo *)temp;
	while (philo->table->death != 1 && i != philo->table->turn)
	{
		if (philo->phase == 3 || philo->table->death > 0)
		{
			printf ("\033[31m%d  %d  Died\033[0m\n", get_time(philo->table), philo->name);
			philo->table->death++;
			break ;
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
			psleep(get_time(philo->table) + philo->table->time_sleep, philo);
		}
	}
	printf("\033[36m%d FINISHED HIS CICLE\033[0m\n", philo->name);
	if (philo->name == 1)
		end_simu(philo->table);
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
		eat_bis(philo, get_time(philo->table));
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
