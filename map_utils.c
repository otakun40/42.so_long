/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 11:36:47 by pjacoby           #+#    #+#             */
/*   Updated: 2022/02/19 11:36:47 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_fd_exit(int fd, char **str, char *message)
{
	close(fd);
	free(*str);
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	read_errors_handler(int rd, int fd, char **result)
{
	if (rd == -1)
		close_fd_exit(fd, result, "Error\nCannot read map file\n");
	if (rd == 0)
		close_fd_exit(fd, result, "Error\nMap is empty\n");
}

char	*read_map_file_to_string(char *file_path)
{
	int		fd;
	int		rd;
	char	buf[BUFFER_SIZE + 1];
	char	*temp;
	char	*result;

	result = ft_strdup("");
	if (!result)
		exit(EXIT_FAILURE);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		close_fd_exit(fd, &result, "Error\nCannot open map file\n");
	rd = read(fd, &buf, BUFFER_SIZE);
	read_errors_handler(rd, fd, &result);
	while (rd)
	{
		buf[rd] = 0;
		temp = result;
		result = ft_strjoin(temp, buf);
		if (!result)
			close_fd_exit(fd, &result, "Error\nCannot allocate memory\n");
		free(temp);
		rd = read(fd, &buf, BUFFER_SIZE);
	}
	return (result);
}

void	get_map(char *file_path, t_data *data)
{
	char	*str;

	is_map_name_valid(file_path);
	str = read_map_file_to_string(file_path);
	if (!has_no_empty_lines(str) || !check_for_denied_cells(str)
		|| !check_for_valid_cells(str) || !is_map_rectangular(str))
		exit_failure("");
	data->map = ft_split(str, '\n');
	free(str);
	if (!data->map)
		exit(EXIT_FAILURE);
	if (!is_map_surrounded_by_walls(data->map,
			ft_strlen(*data->map), num_of_strings(data->map)))
		exit_failure("Error\nMap is not surrounded by the wall\n");
}
