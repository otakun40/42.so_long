/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:48:34 by pjacoby           #+#    #+#             */
/*   Updated: 2022/01/31 22:42:43 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_name_valid(char *name)
{
	char	*ext;

	ext = ft_strrchr(name, '.');
	if (ext)
		if (ft_strncmp(ext, ".ber", 5) == 0)
			return ;
	ft_putstr_fd("Error\nWrong map extension!\n", 1);
	exit(EXIT_FAILURE);
}

int	check_char_for_wall(char c)
{
	if (c != '1')
		return (0);
	return (1);
}

int	is_map_surrounded_by_walls(char **map, size_t width, size_t heigth)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (j < width)
		if (!check_char_for_wall(map[0][j++]))
			return (0);
	while (i < heigth - 1)
	{
		if (!check_char_for_wall(map[i][0])
			|| !check_char_for_wall(map[i][width - 1]))
			return (0);
		i++;
	}
	j = 0;
	while (j < width)
		if (!check_char_for_wall(map[heigth - 1][j++]))
			return (0);
	return (1);
}
