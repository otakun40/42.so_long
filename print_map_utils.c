/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:42:48 by pjacoby           #+#    #+#             */
/*   Updated: 2022/01/31 23:13:44 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_cell_handler(int x, int y, t_data *data)
{
	if (data->collects_remain > 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit_close_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit_open_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	player_cell_handler(int x, int y, t_data *data)
{
	if (data->player_course == 'r')
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_right_image.addr,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->player_left_image.addr,
			x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	show_sprite(t_data *data, char sprite_sym, int x, int y)
{
	if (sprite_sym == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->wall_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (sprite_sym == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->collect_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (sprite_sym == 'E')
		exit_cell_handler(x, y, data);
	if (sprite_sym == 'P')
		player_cell_handler(x, y, data);
}

int	show_map(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->empty_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
			show_sprite(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
	return (1);
}
