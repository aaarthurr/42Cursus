/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:36:28 by arpages           #+#    #+#             */
/*   Updated: 2024/04/02 11:20:20 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	is_map_ok(t_data *data)
{
	t_pos	pos[1024];

	if (check_shape(data) == -1)
	{
		ft_printf("Map Error -> wrong map shape\n");
		return (-1);
	}
	else if (count_content(data, 0, 0) < 0)
	{
		ft_printf("Map Error -> wrong content\n");
		return (-1);
	}
	else if (check_wall(data) < 0)
	{
		ft_printf("Map Error -> all sides must be walls\n");
		return (-1);
	}
	else if (check_path(data, data->x_end, data->y_end, &pos[0]) < 0)
	{
		ft_printf("Map Error -> a path must exist\n");
		free_map(data->sec_map, data);
		return (-1);
	}
	free_map(data->sec_map, data);
	return (0);
}

int	check_shape(t_data *data)
{
	int	i;
	int	k;

	i = ft_linelen(data->map[0]);
	k = 0;
	if (data->height == data->width || data->height == 0)
		return (-1);
	if (i == 0)
		return (-1);
	while (k < data->height)
	{
		if (ft_linelen(data->map[k]) != i)
			return (-1);
		k++;
	}
	return (0);
}

void	set_end(t_data *data, int y, int x)
{
	data->x_end = x;
	data->y_end = y;
	data->is_end++;
}

int	count_content(t_data *data, int i, int j)
{
	data->is_end = 0;
	data->is_item = 0;
	data->is_start = 0;
	while (i < data->height)
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
				data->is_start++;
			else if (data->map[i][j] == 'C')
				data->is_item++;
			else if (data->map[i][j] == 'E')
				set_end(data, i, j);
			else if (data->map[i][j] == '0' && data->map[i][j] == '1')
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	return (check_content(data, 0, 0));
}

int	check_content(t_data *data, int i, int j)
{
	if (data->is_start != 1)
		return (-2);
	if (data->is_end != 1)
		return (-3);
	if (data->is_item < 1)
		return (-4);
	while (i < data->height)
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->coo_x = j;
				data->coo_y = i;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
