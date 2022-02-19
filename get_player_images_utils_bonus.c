/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_images_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:23:36 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:22:14 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_p_right_sprites(t_data *data)
{
	get_image("./sprites/player/psr0.xpm", &data->p_right[0], data);
	get_image("./sprites/player/psr1.xpm", &data->p_right[1], data);
	get_image("./sprites/player/psr2.xpm", &data->p_right[2], data);
	get_image("./sprites/player/psr3.xpm", &data->p_right[3], data);
	get_image("./sprites/player/psr4.xpm", &data->p_right[4], data);
	get_image("./sprites/player/psr5.xpm", &data->p_right[5], data);
	get_image("./sprites/player/psr6.xpm", &data->p_right[6], data);
	get_image("./sprites/player/psr7.xpm", &data->p_right[7], data);
	get_image("./sprites/player/psr8.xpm", &data->p_right[8], data);
	get_image("./sprites/player/psr9.xpm", &data->p_right[9], data);
}

void	get_p_left_sprites(t_data *data)
{
	get_image("./sprites/player/psl0.xpm", &data->p_left[0], data);
	get_image("./sprites/player/psl1.xpm", &data->p_left[1], data);
	get_image("./sprites/player/psl2.xpm", &data->p_left[2], data);
	get_image("./sprites/player/psl3.xpm", &data->p_left[3], data);
	get_image("./sprites/player/psl4.xpm", &data->p_left[4], data);
	get_image("./sprites/player/psl5.xpm", &data->p_left[5], data);
	get_image("./sprites/player/psl6.xpm", &data->p_left[6], data);
	get_image("./sprites/player/psl7.xpm", &data->p_left[7], data);
	get_image("./sprites/player/psl8.xpm", &data->p_left[8], data);
	get_image("./sprites/player/psl9.xpm", &data->p_left[9], data);
}
