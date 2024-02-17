/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:20:24 by arpages           #+#    #+#             */
/*   Updated: 2024/02/17 16:13:58 by arpages          ###   ########.fr       */
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
	int				size;
}		t_table;

typedef struct philo_s
{
	pthread_t thread;
	int		name;
	int		phase;
	int		is_doing;
	struct philo_s	*next;
	struct philo_s	*previous;
}		t_philo;


#endif