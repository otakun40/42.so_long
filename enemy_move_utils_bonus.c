/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:23:36 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:49:03 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	enemy_check_dest_cell(t_unit *unit, t_data *data)
{
	if (unit->course == 0)
		return (data->map[unit->v_pos + 1][unit->h_pos]);
	if (unit->course == 1)
		return (data->map[unit->v_pos][unit->h_pos + 1]);
	if (unit->course == 2)
		return (data->map[unit->v_pos - 1][unit->h_pos]);
	if (unit->course == 3)
		return (data->map[unit->v_pos][unit->h_pos - 1]);
	return (-1);
}

void	make_step(int v_course, int h_course, t_unit *unit, t_data *data)
{
	data->map[unit->v_pos + v_course][unit->h_pos + h_course] = unit->symbol;
	data->map[unit->v_pos][unit->h_pos] = '0';
	unit->v_pos += v_course;
	unit->h_pos += h_course;
	if (h_course != 0)
		unit->char_orient = h_course;
}

void	enemy_set_step_result(t_unit *unit, t_data *data)
{
	if (unit->course == 0)
		make_step(1, 0, unit, data);
	if (unit->course == 1)
		make_step(0, 1, unit, data);
	if (unit->course == 2)
		make_step(-1, 0, unit, data);
	if (unit->course == 3)
		make_step(0, -1, unit, data);
}

void	enemies_moves(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (enemy_check_dest_cell(&data->enemies[i], data) == 'P')
		{
			enemy_set_step_result(&data->enemies[i], data);
			exit_success("Game over!\n");
		}
		if (enemy_check_dest_cell(&data->enemies[i], data) == '0')
			enemy_set_step_result(&data->enemies[i], data);
		else
			data->enemies[i].course = rand() % 4;
		i++;
	}
}
