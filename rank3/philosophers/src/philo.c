/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:51:23 by arthur            #+#    #+#             */
/*   Updated: 2024/03/14 10:46:54 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	destory_all(int type, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (type == 1)
		printf("\033[31mERROR : Unwanted Thread error !\n\033[");
	pthread_mutex_destroy(&table->dead_lock);
	pthread_mutex_destroy(&table->write_lock);
	pthread_mutex_destroy(&table->meal_lock);
	while (i < table->philo[0].size)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int	check_letters(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	verif_args(char **argv)
{
	if (ft_atoi(argv[1]) > 500 || ft_atoi(argv[1]) <= 0
		|| check_letters(argv[1]) == 1)
		return (printf("\033[31mERROR : philosophers number !"), 1);
	if (ft_atoi(argv[2]) <= 0 || check_letters(argv[2]) == 1)
		return (printf("\033[31mERROR : time to die !"), 1);
	if (ft_atoi(argv[3]) <= 0 || check_letters(argv[3]) == 1)
		return (printf("\033[31mERROR : time to eat!"), 1);
	if (ft_atoi(argv[4]) <= 0 || check_letters(argv[4]) == 1)
		return (printf("\033[31mERROR : time to sleep !"), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_letters(argv[5]) == 1))
		return (printf("\033[31mERROR : Number of meals !"), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table			table;
	t_philo			philos[500];
	pthread_mutex_t	forks[500];

	if (argc != 5 && argc != 6)
		return (printf("\033[31mERROR : 4 or 5 arguments !\033[0m\n"), 1);
	if (verif_args(argv) == 1)
		return (printf("\033[0m\n"), 1);
	init_all(&table, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &table, forks, argv);
	create_thread(&table, forks);
	destory_all(0, &table, forks);
	return (0);
}