/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:23:36 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:49:03 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_steps_counter(t_data *data)
{
	ft_putstr_fd("Steps done: ", 1);
	ft_putnbr_fd(data->steps_done, 1);
	ft_putstr_fd("\n", 1);
}

void	player_move(int v_course, int h_course, t_data *data)
{
	if (data->map[data->player_v_pos + v_course][data->player_h_pos + h_course]
		== '1')
		return ;
	if (h_course == 1)
		data->player_course = 'r';
	if (h_course == -1)
		data->player_course = 'l';
	if (data->map[data->player_v_pos + v_course]
		[data->player_h_pos + h_course] == 'E' && data->collects_remain > 0)
		return ;
	if (data->map[data->player_v_pos + v_course]
		[data->player_h_pos + h_course] == 'E'
		&& data->collects_remain == 0)
		exit(EXIT_SUCCESS);
	if (data->map[data->player_v_pos + v_course]
		[data->player_h_pos + h_course] == 'C')
		data->collects_remain--;
	data->map
	[data->player_v_pos + v_course][data->player_h_pos + h_course] = 'P';
	data->map[data->player_v_pos][data->player_h_pos] = '0';
	data->player_v_pos += v_course;
	data->player_h_pos += h_course;
	data->steps_done++;
	print_steps_counter(data);
}
