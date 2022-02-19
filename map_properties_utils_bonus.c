/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_properties_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:48:34 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/19 11:55:48 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				data->player.v_pos = v;
				data->player.h_pos = h;
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

void	set_enemies_pos(t_data *data)
{
	int	i;
	int	h_pos;
	int	v_pos;

	i = 0;
	while (i < 4)
	{
		h_pos = rand() % data->map_columns;
		v_pos = rand() % data->map_rows;
		if (data->map[v_pos][h_pos] != '0')
			continue ;
		data->enemies[i].v_pos = v_pos;
		data->enemies[i].h_pos = h_pos;
		data->map[v_pos][h_pos] = 'D';
		data->enemies[i].symbol = 'D';
		data->enemies[i].course = rand() % 4;
		if (data->enemies[i].course == 1)
			data->enemies[i].char_orient = 1;
		if (data->enemies[i].course == 3)
			data->enemies[i].char_orient = -1;
		else
			data->enemies[i].char_orient = rand() % 2;
		i++;
	}
}

void	set_map_properties(t_data *data)
{
	data->map_columns = (int)ft_strlen(*(data->map));
	data->map_rows = num_of_strings(data->map);
	find_player_pos(data);
	count_collectables(data);
	set_enemies_pos(data);
	data->steps_done = 0;
	data->player.char_orient = 1;
	data->player.symbol = 'P';
}
