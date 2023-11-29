/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:49:11 by arpages           #+#    #+#             */
/*   Updated: 2023/11/18 17:25:17 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	get_map(t_data *data, int j)
{
	int		fd;
	char	*temp;

	data->height = 0;
	fd = open(data->map_path, O_RDWR);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		free(temp);
		data->height++;
		temp = get_next_line(fd);
	}
	free(temp);
	close(fd);
	data->map = malloc(sizeof(char *) * (data->height + 1));
	fd = open(data->map_path, O_RDWR);
	while (j < data->height)
	{
		data->map[j] = get_next_line(fd);
		j++;
	}
	data->map[j] = NULL;
	data->width = ft_linelen(data->map[0]);
	close(fd);
}

void	free_map(char **map, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
