/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:20:24 by arpages           #+#    #+#             */
/*   Updated: 2024/03/15 08:22:32 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/*
	phases are what the philosophers is doing :
	0 sleeping, 1 eating, 2 thinking
*/
typedef struct philo_s
{
	pthread_t		thread;
	int				name;
	int				eating;
	int				meal_eaten;
	int				size;
	int				num_meals;
	int				*is_dead;
	size_t			last_meal;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			time_to_die;
	size_t			start_time;
	pthread_mutex_t	*previous_fork;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*print_line;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}		t_philo;

typedef struct table_s
{
	int					is_dead;
	t_philo				*philo;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		print_line;
}		t_table;

void				destory_all(int type, t_table *table,
						pthread_mutex_t *forks);

// Initialization
void				init_all(t_table *program, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int philo_num);
void				init(t_philo *phi, t_table *prog,
						pthread_mutex_t *frks, char **argv);

// Threads
int					create_thread(t_table *program, pthread_mutex_t *forks);
void				*monitor(void *pointer);
void				*philo_routine(void *pointer);

// Actions
void				eat(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				think(t_philo *philo);

// Monitor utils
int					dead_loop(t_philo *philo);
int					check_if_all_ate(t_philo *philos);
int					check_if_dead(t_philo *philos);
int					philosopher_dead(t_philo *philo, size_t time_to_die);

// Utils
int					ft_atoi(char *str);
int					ft_usleep(size_t time, t_philo *philo);
int					ft_strlen(char *str);
void				print_message(char *str, t_philo *philo, int id);
size_t				get_current_time(void);

#endif