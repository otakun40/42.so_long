/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:23:36 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:22:14 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_image(char *path, t_image *image, t_data *data)
{
	image->addr = mlx_xpm_file_to_image(data->mlx, path,
			&image->width, &image->heigth);
	if (image->addr == NULL)
		exit_failure("Error\nCannot load sprite\n");
}

void	get_sprites(t_data *data)
{
	get_image("./sprites/empty.xpm", &data->empty_image, data);
	get_image("./sprites/wall.xpm", &data->wall_image, data);
	get_image("./sprites/collect.xpm", &data->collect_image, data);
	get_image("./sprites/exit_close.xpm", &data->exit_close_image, data);
	get_image("./sprites/exit_open.xpm", &data->exit_open_image, data);
	get_image("./sprites/player/psr0.xpm", &data->player_right_image, data);
	get_image("./sprites/player/psl0.xpm", &data->player_left_image, data);
}
