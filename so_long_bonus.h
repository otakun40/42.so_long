/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:15:50 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/19 11:55:22 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "structs_bonus.h"
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
# define SPEED 15

int		num_of_strings(char **map);
int		has_no_empty_lines(char *string_from_file);
int		show_map(t_data *data);
int		key_press_react(int keycode, t_data *data);
int		close_window(void);
int		check_for_denied_cells(char *string_from_file);
int		check_for_valid_cells(char *string_from_file);
int		is_map_rectangular(char *string_from_file);
int		is_map_surrounded_by_walls(char **map, size_t width, size_t heigth);
int		free_cells_count(t_data *data);
void	get_sprites(t_data *data);
void	find_player_pos(t_data *data);
void	count_collectables(t_data *data);
void	is_map_name_valid(char *name);
void	player_move(int v_course, int h_course, t_data *data);
void	get_map(char *str, t_data *data);
void	set_map_properties(t_data *data);
void	exit_failure(char *message);
void	exit_success(char *message);
void	get_p_right_sprites(t_data *data);
void	get_p_left_sprites(t_data *data);
void	get_e_right_sprites(t_data *data);
void	get_e_left_sprites(t_data *data);
void	get_image(char *path, t_image *image, t_data *data);
void	enemies_moves(t_data *data);
void	show_map_sprite(t_data *data, char sprite_sym, int x, int y);
void	show_steps_counter(t_data *data);
void	print_enemies(t_data *data);
void	print_player(t_data *data);
#endif
