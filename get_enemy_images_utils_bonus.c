/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemy_images_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:23:36 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:22:14 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_e_right_sprites(t_data *data)
{
	get_image("./sprites/enemy/ewr0.xpm", &data->e_right[0], data);
	get_image("./sprites/enemy/ewr1.xpm", &data->e_right[1], data);
	get_image("./sprites/enemy/ewr2.xpm", &data->e_right[2], data);
	get_image("./sprites/enemy/ewr3.xpm", &data->e_right[3], data);
	get_image("./sprites/enemy/ewr4.xpm", &data->e_right[4], data);
	get_image("./sprites/enemy/ewr5.xpm", &data->e_right[5], data);
	get_image("./sprites/enemy/ewr6.xpm", &data->e_right[6], data);
	get_image("./sprites/enemy/ewr7.xpm", &data->e_right[7], data);
	get_image("./sprites/enemy/ewr8.xpm", &data->e_right[8], data);
	get_image("./sprites/enemy/ewr9.xpm", &data->e_right[9], data);
}

void	get_e_left_sprites(t_data *data)
{
	get_image("./sprites/enemy/ewl0.xpm", &data->e_left[0], data);
	get_image("./sprites/enemy/ewl1.xpm", &data->e_left[1], data);
	get_image("./sprites/enemy/ewl2.xpm", &data->e_left[2], data);
	get_image("./sprites/enemy/ewl3.xpm", &data->e_left[3], data);
	get_image("./sprites/enemy/ewl4.xpm", &data->e_left[4], data);
	get_image("./sprites/enemy/ewl5.xpm", &data->e_left[5], data);
	get_image("./sprites/enemy/ewl6.xpm", &data->e_left[6], data);
	get_image("./sprites/enemy/ewl7.xpm", &data->e_left[7], data);
	get_image("./sprites/enemy/ewl8.xpm", &data->e_left[8], data);
	get_image("./sprites/enemy/ewl9.xpm", &data->e_left[9], data);
}
