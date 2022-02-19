/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:23:36 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:49:03 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_steps_done(t_data *data)
{
	ft_putstr_fd("Steps done: ", 1);
	ft_putnbr_fd(data->steps_done, 1);
	ft_putstr_fd("\n", 1);
}

int	check_dest_cell(int v_course, int h_course, t_unit *unit, t_data *data)
{
	if (data->map[unit->v_pos + v_course][unit->h_pos + h_course] == '1')
		return (0);
	if (data->map[unit->v_pos + v_course][unit->h_pos + h_course] == 'E'
		&& data->collects_remain > 0)
		return (0);
	if (data->map[unit->v_pos + v_course][unit->h_pos + h_course] == 'E'
		&& data->collects_remain == 0)
		exit_success("You win!\n");
	if (data->map[unit->v_pos + v_course][unit->h_pos + h_course] == 'D')
		exit_success("Game over!\n");
	if (data->map[unit->v_pos + v_course][unit->h_pos + h_course] == 'C')
		data->collects_remain--;
	return (1);
}

void	set_step_result(int v_course, int h_course, t_unit *unit, t_data *data)
{
	if (h_course != 0)
		unit->char_orient = h_course;
	data->map[unit->v_pos + v_course][unit->h_pos + h_course] = unit->symbol;
	data->map[unit->v_pos][unit->h_pos] = '0';
	unit->v_pos += v_course;
	unit->h_pos += h_course;
}

void	player_move(int v_course, int h_course, t_data *data)
{
	if (check_dest_cell(v_course, h_course, &data->player, data) == 0)
		return ;
	set_step_result(v_course, h_course, &data->player, data);
	data->steps_done++;
	print_steps_done(data);
}
