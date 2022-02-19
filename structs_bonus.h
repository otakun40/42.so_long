/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:15:50 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/01 01:47:56 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

typedef struct s_image
{
	void	*addr;
	int		width;
	int		heigth;
}	t_image;

typedef struct s_unit
{
	char	symbol;
	int		char_orient;
	int		course;
	int		h_pos;
	int		v_pos;
	int		player_condition;
}	t_unit;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_rows;
	int			map_columns;
	int			collects_remain;
	int			steps_done;
	t_unit		player;
	t_unit		enemies[4];
	t_image		empty_image;
	t_image		wall_image;
	t_image		collect_image;
	t_image		exit_close_image;
	t_image		exit_open_image;
	t_image		p_right[10];
	t_image		p_left[10];
	t_image		e_right[10];
	t_image		e_left[10];
}	t_data;

#endif
