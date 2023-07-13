/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:11:45 by dlima             #+#    #+#             */
/*   Updated: 2023/07/12 20:10:48 by dlima            ###   ########.fr       */
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
	i = 0;
	row_len = ft_calloc(rows, sizeof(int));
	while (map_matrix[i])
	{
		row_len[i] = ft_strlen(map_matrix[i]);
		i++;
	}
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

int	main(int argc, char *argv[])
{
	int		n;
	char	**map_matrix;
	t_map	*map;

	(void)argc;
	n = get_nr_rows(argv[1]);
	map_matrix = (char **)ft_calloc(n + 1, sizeof(char *));
	fill_map_matrix(n, map_matrix, argv[1]);
	map_matrix[n] = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	map->map_matrix = map_matrix;
	if (!(n >= 3 && check_rectangular(map_matrix, n) && check_walls(map_matrix, n) && check_map_path(map)))
	{
		matrix_free(map_matrix);
		free(map);
		printf("ERROR\n");
		return (0);
	}
	printf("GOOD MAP");
	game_main(map);
	matrix_free(map_matrix);
	free(map);
	return (0);
}
