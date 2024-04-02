/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:51:55 by arthur            #+#    #+#             */
/*   Updated: 2024/04/02 12:03:08 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	val_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	mv_enemies_bis(t_data *data, int lx, int ly, int x, int y)
{
	if (data->map[y][x])
	{
		if (data->map[y + ly][x + lx] == '0')
		{
			data->map[y + ly][x + lx] = 'X';
			data->map[y][x] = '0';
		}
		else if (data->map[y + ly][x + lx] == 'P')
			game_win(data);
	}
}

void	mv_enemies(t_data *data, int x, int y)
{
	int lx;
	int ly;
	
	lx = data->coo_x - x;
	ly = data->coo_y - y;
	if (val_abs(lx) > val_abs(ly))
	{
		if (lx > 0)
			mv_enemies_bis(data, 1, 0, x, y);
		else if (lx < 0)
			mv_enemies_bis(data, -1, 0, x, y);
	}
	else
	{
		if (ly > 0)
			mv_enemies_bis(data, 0, 1, x, y);
		else  if (ly < 0)
			mv_enemies_bis(data, 0, -1, x, y);
	}
}

void	enemies_manage(t_data *data)
{
	int i;
	int y;

	i = 0;
	while (data->map[i] != NULL)
	{
		y = 0;
		while (data->map[i][y] != '\0')
		{
			if (data->map[i][y] == 'X')
				mv_enemies(data, y, i);
			y++;
		}
		i++;
	}
}
