/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:06:24 by arpages           #+#    #+#             */
/*   Updated: 2024/03/02 16:31:58 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eat_bis(t_philo *philo, int entry)
{
	printf("%d  %d  is eating\n", get_time(philo->table), philo->name);
	philo->last_meal = get_time(philo->table);
	psleep(entry + philo->table->time_eat, philo);
	philo->fork = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->next->mutex);
	philo->next->fork = 0;
	philo->is_hungry = 0;
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