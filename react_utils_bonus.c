/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:17:19 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:28:37 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(void)
{
	exit_success("");
	return (1);
}

void	exit_success(char *message)
{
	if (*message)
		ft_putstr_fd(message, 1);
	exit(EXIT_SUCCESS);
}

void	exit_failure(char *message)
{
	if (*message)
		ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

int	key_press_react(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window();
	if (keycode == KEY_W || keycode == KEY_UP)
		player_move(-1, 0, data);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		player_move(1, 0, data);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_move(0, 1, data);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		player_move(0, -1, data);
	return (0);
}
