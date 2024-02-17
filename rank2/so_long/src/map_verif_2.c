/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:48:31 by arpages           #+#    #+#             */
/*   Updated: 2023/11/18 16:44:29 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->height - 1][i] != '1')
			return (-5);
		i++;
	}
	while (j < data->height)
	{
		if (data->map[j][0] != '1' || data->map[j][data->width - 1] != '1')
			return (-5);
		j++;
	}
	return (0);
}

int	check_path(t_data *data, int x_end, int y_end, t_pos *pos)
{
	int		top;
	t_pos	cur;

	pos->x = data->coo_x;
	pos->y = data->coo_y;
	top = 1;
	dup_map(data);
	while (top > 0)
	{
		top--;
		cur.y = pos[top].y;
		cur.x = pos[top].x;
		if (cur.x == x_end && cur.y == y_end)
			return (0);
		if (data->sec_map[cur.y + 1][cur.x] != '1'
				&& data->sec_map[cur.y + 1][cur.x] != '2')
		{
			pos[top].y = cur.y + 1;
			pos[top].x = cur.x;
			data->sec_map[cur.y + 1][cur.x] = '2';
			top++;
		}
		check_path2(data->sec_map, pos, &top, cur);
	}
	return (-1);
}

void	check_path2(char **map, t_pos *pos, int *top, t_pos cur)
{
	if (map[cur.y][cur.x + 1] != '1' && map[cur.y][cur.x + 1] != '2')
	{
		pos[*top].y = cur.y;
		pos[*top].x = cur.x + 1;
		map[cur.y][cur.x + 1] = '2';
		*top = *top + 1;
	}
	if (map[cur.y - 1][cur.x] != '1' && map[cur.y - 1][cur.x] != '2')
	{
		pos[*top].y = cur.y - 1;
		pos[*top].x = cur.x;
		map[cur.y - 1][cur.x] = '2';
		*top = *top + 1;
	}
	if (map[cur.y][cur.x - 1] != '1' && map[cur.y][cur.x - 1] != '2')
	{
		pos[*top].y = cur.y;
		pos[*top].x = cur.x - 1;
		map[cur.y][cur.x - 1] = '2';
		*top = *top + 1;
	}
}
