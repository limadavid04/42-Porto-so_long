/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:11:45 by dlima             #+#    #+#             */
/*   Updated: 2023/07/07 16:14:13 by dlima            ###   ########.fr       */
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

void	fill_map_matrix(int n, char **map, char *file_path)
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
		printf("%s\n", line);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		map[i] = line;
		i++;
	}
	map[n] = NULL;
	close(fd);
}

int	check_rectangular(char **map, int rows)
{
	int	m;
	int	i;
	int	*row_len;

	m = 0;
	i = 0;
	row_len = ft_calloc(rows, sizeof(int));
	while (map[i])
	{
		row_len[i] = ft_strlen(map[i]);
		i++;
	}
	i = 0;
	m = row_len[0];
	while (i < rows)
	{
		printf("len = %d\n", row_len[i]);
		if (row_len[i] != m)
		{
			free(row_len);
			return (0);
		}
		i++;
	}
	free(row_len);
	if (rows == m || m < 5)
		return (0);
	return (1);
}

int	check_walls(char **map, int rows)
{
	int	x;
	int	y;
	int	m;

	m = ft_strlen(map[0]);
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if ((x == 0 || x == rows - 1 || y == 0 || y == m - 1))
			{
				// printf("%c\n", map[x][y]);
				// printf("x = %d, y = %d\n ", x, y);
				if (map[x][y] != '1')
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
	char	**map;

	(void)argc;
	n = get_nr_rows(argv[1]);
	printf("nbr rows = %d\n", n);
	map = (char **)ft_calloc(n + 1, sizeof(char *));
	fill_map_matrix(n, map, argv[1]);
	map[n] = NULL;
	if (!(n >= 5 && check_rectangular(map, n) && check_walls(map, n)))
	{
		printf("ERROR\n");
		return (0);
	}
	printf("GOOD MAP");
	return (0);
}
