/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:24:19 by arpages           #+#    #+#             */
/*   Updated: 2024/04/02 11:54:31 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define KEYCODE_ESC 65307
# define KEYCODE_LEFT 65361
# define KEYCODE_UP 65362
# define KEYCODE_RIGHT 65363
# define KEYCODE_DOWN 65364

typedef struct pos_s
{
	int	x;
	int	y;
}			t_pos;

typedef struct img_s
{
	void	*img_ptr;
	char	*img_char;
	int		bits_pix;
	int		endian;
	int		line;
}				t_img;

typedef struct sprite_s
{
	t_img	ground;
	t_img	fin;
	t_img	perso_1_r;
	t_img	perso_2_r;
	t_img	perso_1_l;
	t_img	perso_2_l;
	t_img	item;
	t_img	wall;
}				t_sprite;

typedef struct data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	char		**map;
	char		**sec_map;
	char		*map_path;
	t_sprite	img;
	int			width;
	int			height;
	int			count;
	int			coo_x;
	int			coo_y;
	int			get_item;
	int			is_left;
	int			is_start;
	int			is_item;
	int			is_end;
	int			x_end;
	int			y_end;
}				t_data;

int		end_game(t_data *data);

int		ft_linelen(char *str);
char	*ft_strdup(const char *s);
void	dup_map(t_data *data);

char	*ft_itoa(int n);

void	get_map(t_data *data, int j);
void	free_map(char **map, t_data *data);

void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

void	get_image(t_data *data);
void	create_image(t_data *data);
void	draw_all(t_data *data, int x, int y);
void	print_count(t_data *data);
void	draw_perso(t_data *data, int x, int y);

int		is_map_ok(t_data *data);
int		check_shape(t_data *data);
int		count_content(t_data *data, int i, int j);
int		check_content(t_data *data, int i, int j);
int		check_wall(t_data *data);
int		check_path(t_data *data, int x_end, int y_end, t_pos *pos);
void	check_path2(char **map, t_pos *pos, int *top, t_pos cur);

void	printer(t_data *data);

void	game_win(t_data *data);

void	enemies_manage(t_data *data);

#endif