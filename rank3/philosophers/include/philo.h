/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:20:24 by arpages           #+#    #+#             */
/*   Updated: 2024/03/02 16:33:06 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct table_s
{
	struct philo_s	*philo;
	int				turn;
	int				start_time;
	int				seconde;
	int				time_death;
	int				time_sleep;
	int				time_eat;
	int				size;
	int				death;
}		t_table;

/*
	phases are what the philosophers is doing :
	0 sleeping, 1 eating, 2 thinking, 3 dead
*/
typedef struct philo_s
{
	pthread_t thread;
	int		turn;
	int		name;
	int		phase;
	int		last_meal;
	int		fork;
	int		is_hungry;
	pthread_mutex_t	mutex;
	struct philo_s	*next;
	struct philo_s	*previous;
	struct table_s	*table;
}		t_philo;


int		ft_atoi(const char *nptr);

int		get_time(t_table *table);

void	create_thread(t_table *table);
void	wait(t_table *table);

int		eat(t_philo *philo);
void	end_simu(t_table *table);

void	eat_bis(t_philo *philo, int entry);

int		psleep(int mtime, t_philo *philo);


t_table	*setup_args(char **argv, int argc);
int		verif_args(char **str);

#endif