/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:58:29 by arpages           #+#    #+#             */
/*   Updated: 2024/02/27 15:16:36 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*new_node(int name, t_table *table)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	new->name = name;
	new->phase = 0;
	new->table = table;
	new->fork = 0;
	new->last_meal = 0;
	new->is_hungry = 0;
	pthread_mutex_init(&new->mutex, NULL);
	return (new);
}

void	create_table(t_table *table)
{
	int		i;
	t_philo	*temp;
	t_philo	*temp_pre;
	t_philo	*first;

	i = 2;
	temp_pre = NULL;
	temp = new_node(i - 1, table);
	temp->next = NULL;
	temp->previous = NULL;
	first = temp;
	while (i <= table->size)
	{
		temp->next = new_node(i, table);
		temp_pre = temp;
		temp = temp->next;
		temp->previous = temp_pre;
		i++;
	}
	temp->next = first;
	first->previous = temp;
	table->philo = first;
}

t_table	*setup_args(char **argv, int argc)
{	
	t_table *table;
	struct timeval	time;
	
	table = (t_table *)malloc(sizeof(t_table));
	table->death = 0;
	gettimeofday(&time, NULL);
	table->seconde = time.tv_sec;
	table->start_time = time.tv_usec;
	table->size = ft_atoi(argv[1]);
	table->time_death = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	table->turn = -1;
	if (argc == 6)
		table->turn = ft_atoi(argv[5]);
	create_table(table);
	return(table);
}
/* Programme takes 4 mandatory arguments :
	Num of Philosophers, Time until death, time to eat, time to sleep
	And 1 optionnal argument :
	number of meal par philo until end;
*/
int	main(int argc, char **argv)
{
	t_table			*table;

	if (!(argc == 5 || argc == 6))
		return (printf("\033[31mERROR !\033[0m\n"), 0);
	if (verif_args(argv) == 1)
		return (printf("\033[31mArguments should only be positive numbers !\033[0m\n"), 0);
	table = setup_args(argv, argc);
	create_thread(table);	
	wait(table);
	return (0);
}
