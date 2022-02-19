/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:42:48 by pjacoby           #+#    #+#             */
/*   Updated: 2022/01/31 23:13:44 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_exit(int x, int y, t_data *data)
{
	if (data->collects_remain > 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit_close_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit_open_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	print_player(t_data *data)
{
	static size_t	frame = 0;

	if (data->player.char_orient == 1)
		mlx_put_image_to_window(data->mlx, data->win,
			data->p_right[frame++ % 10].addr,
			data->player.h_pos * SPRITE_SIZE, data->player.v_pos * SPRITE_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win,
			data->p_left[frame++ % 10].addr,
			data->player.h_pos * SPRITE_SIZE, data->player.v_pos * SPRITE_SIZE);
}

void	print_enemies(t_data *data)
{
	static size_t	frame = 0;
	int				i;

	i = 0;
	while (i < 4)
	{
		if (data->enemies[i].char_orient == 1)
			mlx_put_image_to_window(data->mlx, data->win,
				data->e_right[frame++ / 5 % 10].addr,
				data->enemies[i].h_pos * SPRITE_SIZE,
				data->enemies[i].v_pos * SPRITE_SIZE);
		else
			mlx_put_image_to_window(data->mlx, data->win,
				data->e_left[frame++ / 5 % 10].addr,
				data->enemies[i].h_pos * SPRITE_SIZE,
				data->enemies[i].v_pos * SPRITE_SIZE);
		i++;
	}
}

void	show_steps_counter(t_data *data)
{
	char	*steps;

	steps = ft_itoa(data->steps_done);
	mlx_string_put(data->mlx, data->win, data->map_columns * 64 / 2 - 52, 32,
		0x00000000, "Steps: ");
	mlx_string_put(data->mlx, data->win, data->map_columns * 64 / 2 + 25, 32,
		0x00000000, steps);
	free(steps);
}

void	show_map_sprite(t_data *data, char sprite_sym, int x, int y)
{
	if (sprite_sym == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->wall_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (sprite_sym == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->collect_image.addr, x * SPRITE_SIZE, y * SPRITE_SIZE);
	if (sprite_sym == 'E')
		print_exit(x, y, data);
}
