/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:42:48 by pjacoby           #+#    #+#             */
/*   Updated: 2022/01/31 23:13:44 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	show_map(t_data *data)
{
	int				x;
	int				y;
	static size_t	enemies_steps = 0;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->empty_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
			show_map_sprite(data, data->map[y][x], x, y);
			x++;
		}
		y++;
	}
	print_player(data);
	print_enemies(data);
	if (++enemies_steps % SPEED == 0)
		enemies_moves(data);
	show_steps_counter(data);
	return (1);
}
