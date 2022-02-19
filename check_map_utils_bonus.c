/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 12:48:34 by pjacoby           #+#    #+#             */
/*   Updated: 2022/01/31 22:42:43 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	has_no_empty_lines(char *string_from_file)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(string_from_file);
	i = 0;
	while (string_from_file[i] == '\n')
		i++;
	while (i < len - 3)
	{
		if (string_from_file[i] == '\n' && string_from_file[i + 1] == '\n'
			&& string_from_file[i + 2] != '\n')
		{
			ft_putstr_fd("Error\nMap is not rectangular\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_for_denied_cells(char *str)
{
	while (*str)
	{
		if (*str != '0' && *str != '1' && *str != 'P' && *str != 'C'
			&& *str != 'E' && *str != '\n')
		{
			ft_putstr_fd("Error\nFound invalid characters in map\n", 1);
			return (0);
		}
		str++;
	}
	return (1);
}

int	check_for_valid_cells(char *string_from_file)
{
	int		has_start_pos;
	int		has_collect;
	int		has_exit;

	has_start_pos = 0;
	has_collect = 0;
	has_exit = 0;
	while (*string_from_file)
	{
		if (*string_from_file == 'P')
			has_start_pos++;
		if (*string_from_file == 'C')
			has_collect++;
		if (*string_from_file == 'E')
			has_exit++;
		string_from_file++;
	}
	if ((has_start_pos == 1 && has_collect && has_exit) == 0)
	{
		ft_putstr_fd("Error\nWrong number of \"PCE\" characters\n", 1);
		return (0);
	}
	return (1);
}

int	is_map_rectangular(char *str)
{
	int	width;
	int	next_line;

	width = 0;
	while (*str && *str != '\n')
	{
		width++;
		str++;
	}
	while (*str++)
	{
		next_line = 0;
		while (*str && *str != '\n')
		{
			next_line++;
			str++;
		}
		if (next_line != width)
		{
			ft_putstr_fd("Error\nMap is not rectangular\n", 1);
			return (0);
		}
	}
	return (1);
}
