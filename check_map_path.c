/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:22:24 by dlima             #+#    #+#             */
/*   Updated: 2023/07/11 13:44:53 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_elements(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map_matrix[x])
	{
		y = 0;
		while (map->map_matrix[x][y])
		{
			if (map->map_matrix[x][y] == 'E')
				map->exit++;
			else if (map->map_matrix[x][y] == 'P')
			{
				map->row = x;
				map->col = y;
				map->start++;
			}
			else if (map->map_matrix[x][y] == 'C')
				map->collectibles++;
			else if (!(map->map_matrix[x][y] == '1' || map->map_matrix[x][y] == '0'))
				return (0);
			y++;
		}
		x++;
	}
	if (map->exit != 1 || map->start != 1 || map->collectibles < 1)
		return (0);
	return (1);
}

void	flood_fill(t_map *map, int i, int j)
{
	int	rows;
	int	cols;

	rows = nbr_rows(map->map_matrix);
	cols = ft_strlen(map->map_matrix[0]);
	if (i < 0 || j < 0 || i >= rows || j >= cols)
		return ;
	else if (map->map_matrix[i][j] == '1')
		return ;
	else if (map->map_matrix[i][j] == 'C')
		map->collectibles++;
	else if (map->map_matrix[i][j] == 'E')
		map->exit++;
	map->map_matrix[i][j] = '1';
	flood_fill(map, i + 1, j);
	flood_fill(map, i - 1, j);
	flood_fill(map, i, j + 1);
	flood_fill(map, i, j - 1);
	return ;
}

int	check_map_path(t_map *map)
{
	t_map	*map_cpy;

	map->collectibles = 0;
	map->exit = 0;
	map->start = 0;
	if (!(check_map_elements(map)))
		return (0);
	map_cpy = (t_map *)malloc(sizeof(t_map));
	map_cpy->map_matrix = (char **)malloc((nbr_rows(map->map_matrix) + 1) * sizeof(char *));
	matrix_copy(map->map_matrix, map_cpy->map_matrix);
	map_cpy->collectibles = 0;
	map_cpy->exit = 0;
	flood_fill(map_cpy, map->row, map->col);
	if (map_cpy->collectibles != map->collectibles || map_cpy->exit != 1)
	{
		matrix_free(map_cpy->map_matrix);
		free(map_cpy);
		return (0);
	}
	matrix_free(map_cpy->map_matrix);
	free(map_cpy);
	return (1);
}

