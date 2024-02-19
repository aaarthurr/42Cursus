/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:54:54 by arpages           #+#    #+#             */
/*   Updated: 2023/11/18 16:45:00 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	get_image(t_data *data)
{
	int	x;
	int	y;

	x = 64;
	y = 64;
	data->img.ground.img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, "textures/ground.xpm", &x, &y);
	data->img.fin.img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, "textures/fin.xpm", &x, &y);
	data->img.perso_1_r.img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, "textures/perso_1_R.xpm", &x, &y);
	data->img.perso_2_r.img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, "textures/perso_2_R.xpm", &x, &y);
	data->img.perso_1_l.img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, "textures/perso_1_L.xpm", &x, &y);
	data->img.perso_2_l.img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, "textures/perso_2_L.xpm", &x, &y);
	data->img.item.img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, "textures/item.xpm", &x, &y);
	data->img.wall.img_ptr = mlx_xpm_file_to_image
		(data->mlx_ptr, "textures/wall.xpm", &x, &y);
	create_image(data);
}

void	create_image(t_data *data)
{
	data->img.ground.img_char = mlx_get_data_addr(data->mlx_ptr,
			&data->img.ground.bits_pix,
			&data->img.ground.line, &data->img.ground.endian);
	data->img.fin.img_char = mlx_get_data_addr(data->mlx_ptr,
			&data->img.fin.bits_pix,
			&data->img.fin.line, &data->img.fin.endian);
	data->img.perso_1_r.img_char = mlx_get_data_addr(data->mlx_ptr,
			&data->img.perso_1_r.bits_pix,
			&data->img.perso_1_r.line, &data->img.perso_1_r.endian);
	data->img.perso_2_r.img_char = mlx_get_data_addr(data->mlx_ptr,
			&data->img.perso_2_r.bits_pix,
			&data->img.perso_2_r.line, &data->img.perso_2_r.endian);
	data->img.perso_1_l.img_char = mlx_get_data_addr(data->mlx_ptr,
			&data->img.perso_1_l.bits_pix,
			&data->img.perso_1_l.line, &data->img.perso_1_l.endian);
	data->img.perso_2_l.img_char = mlx_get_data_addr(data->mlx_ptr,
			&data->img.perso_2_l.bits_pix,
			&data->img.perso_2_l.line, &data->img.perso_2_l.endian);
	data->img.item.img_char = mlx_get_data_addr(data->mlx_ptr,
			&data->img.item.bits_pix,
			&data->img.item.line, &data->img.item.endian);
	data->img.wall.img_char = mlx_get_data_addr(data->mlx_ptr,
			&data->img.wall.bits_pix,
			&data->img.wall.line, &data->img.wall.endian);
}

void	draw_all(t_data *data, int x, int y)
{
	while (y < data->height)
	{
		while (x < data->width)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr,
					data->mlx_win, data->img.wall.img_ptr, x * 64, y * 64);
			else if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr,
					data->mlx_win, data->img.ground.img_ptr, x * 64, y * 64);
			else if (data->map[y][x] == 'P')
				draw_perso(data, x, y);
			else if (data->map[y][x] == 'c')
				mlx_put_image_to_window(data->mlx_ptr,
					data->mlx_win, data->img.item.img_ptr, x * 64, y * 64);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr,
					data->mlx_win, data->img.fin.img_ptr, x * 64, y * 64);
			x++;
		}
		x = 0;
		y++;
	}
	print_count(data);
}

void	print_count(t_data *data)
{
	char	*count;

	count = ft_itoa(data->count);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 10, 10, 0xFFFFFF, count);
	free(count);
}

void	draw_perso(t_data *data, int x, int y)
{
	if (data->get_item == data->is_item)
	{
		if (data->is_left == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->img.perso_2_l.img_ptr, x * 64, y * 64);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->img.perso_2_r.img_ptr, x * 64, y * 64);
	}
	else
	{
		if (data->is_left == 1)
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->img.perso_1_l.img_ptr, x * 64, y * 64);
		}
		else
		{
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
				data->img.perso_1_r.img_ptr, x * 64, y * 64);
		}
	}
}
