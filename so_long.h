/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:15:50 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/19 11:12:09 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <unistd.h>
# include <sys/file.h>
# define SPRITE_SIZE 64
# define BUFFER_SIZE 1000
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2
# define KEY_A 0
# define KEY_ESC 53

typedef struct s_image
{
	void	*addr;
	int		width;
	int		heigth;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	player_course;
	char	**map;
	int		map_rows;
	int		map_columns;
	int		player_v_pos;
	int		player_h_pos;
	int		collects_remain;
	int		steps_done;
	t_image	empty_image;
	t_image	wall_image;
	t_image	collect_image;
	t_image	player_right_image;
	t_image	player_left_image;
	t_image	exit_close_image;
	t_image	exit_open_image;
}	t_data;

int		num_of_strings(char **map);
int		has_no_empty_lines(char *string_from_file);
int		show_map(t_data *data);
int		key_press_react(int keycode, t_data *data);
int		close_window(void);
int		check_for_denied_cells(char *string_from_file);
int		check_for_valid_cells(char *string_from_file);
int		is_map_rectangular(char *string_from_file);
int		is_map_surrounded_by_walls(char **map, size_t width, size_t heigth);
void	get_sprites(t_data *data);
void	is_map_name_valid(char *name);
void	player_move(int v_course, int h_course, t_data *data);
void	get_map(char *str, t_data *data);
void	set_map_properties(t_data *data);
void	exit_failure(char *message);
#endif
