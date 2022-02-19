/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:59:33 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/19 11:28:15 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc != 2)
		exit_failure("Error\nEnter path to the map as one parameter.\n");
	get_map(argv[1], &data);
	set_map_properties(&data);
	data.mlx = mlx_init();
	get_sprites(&data);
	data.win = mlx_new_window(data.mlx, data.map_columns * SPRITE_SIZE,
			data.map_rows * SPRITE_SIZE, "so_long");
	mlx_loop_hook(data.mlx, show_map, &data);
	mlx_hook(data.win, 17, 0L, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press_react, &data);
	mlx_loop(data.mlx);
}
