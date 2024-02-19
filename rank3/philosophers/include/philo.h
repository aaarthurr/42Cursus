/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:20:24 by arpages           #+#    #+#             */
/*   Updated: 2024/02/18 16:23:59 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct table_s
{
	struct philo_s	*philo;
	int				time_death;
	int				time_sleep;
	int				time_eat;
	int				size;
}		t_table;

/*
	phases are what the philosophers is doing :
	0 sleeping, 1 eating, 2 thinking, 3 dead
*/
typedef struct philo_s
{
	pthread_t thread;
	int		name;
	int		phase;
	struct philo_s	*next;
	struct philo_s	*previous;
}		t_philo;


int	ft_atoi(const char *nptr);

#endif