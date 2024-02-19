/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:58:29 by arpages           #+#    #+#             */
/*   Updated: 2024/02/18 17:13:36 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*new_node(t_table *table, int name)
{
	t_philo *new;

	new = (t_philo*)malloc(sizeof(t_philo));
	new->name = name;
	new->phase = 0;
	return (new);
}

void	test(t_philo *p)
{
	while (1)
	{
		printf("current -> %d | previous -> %d\n", p->name, p->previous->name);
		p = p->next;
	}
}

void	*create_table(t_table *table)
{
	int 	i;
	t_philo *temp;
	t_philo	*temp_pre;
	t_philo *first;

	i = 2;
	temp_pre = NULL;
	temp = new_node(table, i-1);
	temp->next = NULL;
	temp->previous = NULL;
	first = temp;
	while (i <= table->size)
	{
		temp->next = new_node(table, i);
		temp_pre = temp;
		temp = temp->next;
		temp->previous = temp_pre;
		i++;
		printf("current -> %d | previous -> %d\n", temp->name, temp->previous->name);
	}
	temp->next = first;
	first->previous = temp;
	test(temp);
}
/* Programme takes 4 mandatory arguments :
	Num of Philosophers, Time until death, time to eat, time to sleep
	And 1 optionnal argument :
	number of meal par philo until end;
*/
int main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5)
		return(printf("\033[31mERROR !\033[0m\n"), 0);
	table = (t_table *)malloc(sizeof(t_table));
	table->size = ft_atoi(argv[1]);
	table->time_death = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	create_table(table);

	return 0;
}