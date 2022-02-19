/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_properties_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:48:34 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:47:56 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	num_of_strings(char **map)
{
	int	num;

	num = 0;
	while (*map++)
		num++;
	return (num);
}

void	find_player_pos(t_data *data)
{
	int	v;
	int	h;

	v = 0;
	while (data->map[v] != 0)
	{
		h = 0;
		while (data->map[v][h] != 0)
		{
			if (data->map[v][h] == 'P')
			{
				data->player_v_pos = v;
				data->player_h_pos = h;
				break ;
			}
			h++;
		}
		v++;
	}
}

void	count_collectables(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->collects_remain = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'C')
				data->collects_remain++;
			y++;
		}
		x++;
	}
}

void	set_map_properties(t_data *data)
{
	data->map_columns = (int)ft_strlen(*(data->map));
	data->map_rows = num_of_strings(data->map);
	find_player_pos(data);
	count_collectables(data);
	data->steps_done = 0;
	data->player_course = 'r';
}
