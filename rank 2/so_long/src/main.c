/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpages <arpages@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:33:21 by arpages           #+#    #+#             */
/*   Updated: 2023/11/18 17:24:07 by arpages          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	end_game(t_data *data)
{
	free_map(data->map, data);
	mlx_destroy_image(data->mlx_ptr, data->img.ground.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.fin.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.perso_1_r.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.perso_2_r.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.perso_1_l.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.perso_2_l.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.wall.img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.item.img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
}

int	event(int keycode, t_data *data)
{
	if (keycode == KEYCODE_ESC)
	{
		end_game(data);
	}
	if (keycode == KEYCODE_UP)
	{
		move_up(data);
	}
	if (keycode == KEYCODE_DOWN)
	{
		move_down(data);
	}
	if (keycode == KEYCODE_LEFT)
	{
		move_left(data);
	}
	if (keycode == KEYCODE_RIGHT)
	{
		move_right(data);
	}
	draw_all(data, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf("mettre le nom de la carte en argument\n"));
	data.map_path = argv[1];
	data.get_item = 0;
	data.is_left = 0;
	data.count = 0;
	get_map(&data, 0);
	get_next_line(-1);
	if (is_map_ok(&data) != 0)
	{
		free_map(data.map, &data);
		return (0);
	}
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, (data.width * 64),
			(data.height * 64), "So long");
	get_image(&data);
	draw_all(&data, 0, 0);
	mlx_hook(data.mlx_win, 17, 0L, end_game, &data);
	mlx_key_hook(data.mlx_win, event, &data);
	mlx_loop(data.mlx_ptr);
}
