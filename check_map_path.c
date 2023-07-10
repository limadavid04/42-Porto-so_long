/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:22:24 by dlima             #+#    #+#             */
/*   Updated: 2023/07/10 18:59:55 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_elements(map_info *map)
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
			else if (map->map_matrix[x][y] == '0')
				map->free_space++;
			else if (!(map->map_matrix[x][y] == '1'))
				return(0);
			y++;
		}
		x++;
	}
	printf("collectibles = %d\nfree_space = %d\n", map->collectibles, map->free_space);
	if (map->exit != 1 || map->start != 1 || map->collectibles < 1 || map->free_space == 0)
		return (0);
	return (1);
}
// void	flood_fill(map_info *map, int i, int j)
// {
// 	nbr_columns(map->map_matrix);
// 	(void) i;
// 	(void)j;
// }
int	check_map_path(map_info *map)
{
	map->collectibles = 0; 
	map->exit = 0;
	map->start = 0;
	map->free_space = 0;
	map_info *map_cpy = (map_info*)malloc(sizeof(map_info));
	map_cpy->map_matrix = (char **)malloc((nbr_columns(map->map_matrix)+ 1) * sizeof(char *));
	matrix_copy(map->map_matrix, map_cpy->map_matrix);
	map_cpy->collectibles = 0; 
	map_cpy->exit = 0;
	map_cpy->start = 0;
	map_cpy->free_space = 0;

	// flood_fill(map_cpy, map->row, map->col);
	if(!(check_map_elements(map)))
		return(0);
	return(1);

}
