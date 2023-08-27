/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_conditions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:11:45 by dlima             #+#    #+#             */
/*   Updated: 2023/08/27 16:00:20 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nr_rows(char *file_path)
{
	int		fd;
	int		n;
	char	*line;

	n = 0;
	fd = open(file_path, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		n++;
		free(line);
	}
	free(line);
	close(fd);
	return (n);
}

void	fill_map_matrix(int n, char **map_matrix, char *file_path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	i = 0;
	while (i < n)
	{
		line = get_next_line(fd);
		replace_newlines(line);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		map_matrix[i] = line;
		i++;
	}
	map_matrix[n] = NULL;
	close(fd);
}

int	check_rectangular(char **map_matrix, int rows)
{
	int	m;
	int	i;
	int	*row_len;

	m = 0;
	i = -1;
	row_len = ft_calloc(rows, sizeof(int));
	while (map_matrix[++i])
		row_len[i] = ft_strlen(map_matrix[i]);
	i = 0;
	m = row_len[0];
	while (i < rows)
	{
		if (row_len[i] != m)
		{
			free(row_len);
			return (0);
		}
		i++;
	}
	free(row_len);
	if (rows == m || m < 3)
		return (0);
	return (1);
}

int	check_walls(char **map_matrix, int rows)
{
	int	x;
	int	y;
	int	m;

	m = ft_strlen(map_matrix[0]);
	x = 0;
	while (map_matrix[x])
	{
		y = 0;
		while (map_matrix[x][y])
		{
			if ((x == 0 || x == rows - 1 || y == 0 || y == m - 1))
			{
				if (map_matrix[x][y] != '1')
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	check_map_conditions(t_map *map)
{
	int		n;

	map->collectibles = 0;
	map->exit = 0;
	map->start = 0;
	n = nbr_rows(map->map_matrix);
	if (n < 3)
		throw_error("The map is not long enough");
	else if (!(check_rectangular(map->map_matrix, n)))
		throw_error("The map is not rectangular");
	else if (!(check_walls(map->map_matrix, n)))
		throw_error("The map is not sorrounded by walls");
	else if (!(check_map_elements(map)))
		throw_error("The elements contained in the map are invalid");
	else if (!(check_map_path(map)))
		throw_error("The map does not have a valid path");
	else
	{
		ft_printf("GOOD MAP");
		return (1);
	}
	matrix_free(map->map_matrix);
	free(map);
	return (0);
}
