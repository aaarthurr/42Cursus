/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:17:19 by arpages           #+#    #+#             */
/*   Updated: 2024/04/02 11:20:50 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	game_win(t_data *data)
{
	if (data->is_item == data->get_item)
	{
		end_game(data);
		data->count++;
	}
}

void	move_up(t_data *data)
{
	if (data->map[data->coo_y - 1][data->coo_x])
	{
		if (data->map[data->coo_y - 1][data->coo_x] == '0')
		{
			data->map[data->coo_y - 1][data->coo_x] = 'P';
			data->map[data->coo_y][data->coo_x] = '0';
			data->coo_y--;
			data->count++;
		}
		else if (data->map[data->coo_y - 1][data->coo_x] == 'C')
		{
			data->map[data->coo_y - 1][data->coo_x] = 'P';
			data->map[data->coo_y][data->coo_x] = '0';
			data->get_item++;
			data->coo_y--;
			data->count++;
		}
		else if (data->map[data->coo_y - 1][data->coo_x] == 'E')
			game_win(data);
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->coo_y + 1][data->coo_x])
	{
		if (data->map[data->coo_y + 1][data->coo_x] == '0')
		{
			data->map[data->coo_y + 1][data->coo_x] = 'P';
			data->map[data->coo_y][data->coo_x] = '0';
			data->coo_y++;
			data->count++;
		}
		else if (data->map[data->coo_y + 1][data->coo_x] == 'C')
		{
			data->map[data->coo_y + 1][data->coo_x] = 'P';
			data->map[data->coo_y][data->coo_x] = '0';
			data->get_item++;
			data->coo_y++;
			data->count++;
		}
		else if (data->map[data->coo_y + 1][data->coo_x] == 'E')
			game_win(data);
	}
}

void	move_left(t_data *data)
{
	data->is_left = 1;
	if (data->map[data->coo_y][data->coo_x -1])
	{
		if (data->map[data->coo_y][data->coo_x - 1] == '0')
		{
			data->map[data->coo_y][data->coo_x - 1] = 'P';
			data->map[data->coo_y][data->coo_x] = '0';
			data->coo_x--;
			data->count++;
		}
		else if (data->map[data->coo_y][data->coo_x - 1] == 'C')
		{
			data->map[data->coo_y][data->coo_x - 1] = 'P';
			data->map[data->coo_y][data->coo_x] = '0';
			data->get_item++;
			data->coo_x--;
			data->count++;
		}
		else if (data->map[data->coo_y][data->coo_x - 1] == 'E')
			game_win(data);
	}
}

void	move_right(t_data *data)
{
	data->is_left = 0;
	if (data->map[data->coo_y][data->coo_x + 1])
	{
		if (data->map[data->coo_y][data->coo_x + 1] == '0')
		{
			data->map[data->coo_y][data->coo_x + 1] = 'P';
			data->map[data->coo_y][data->coo_x] = '0';
			data->coo_x++;
			data->count++;
		}
		else if (data->map[data->coo_y][data->coo_x + 1] == 'C')
		{
			data->map[data->coo_y][data->coo_x + 1] = 'P';
			data->map[data->coo_y][data->coo_x] = '0';
			data->get_item++;
			data->coo_x++;
			data->count++;
		}
		else if (data->map[data->coo_y][data->coo_x + 1] == 'E')
			game_win(data);
	}
}
