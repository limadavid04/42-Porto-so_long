/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:22:24 by dlima             #+#    #+#             */
/*   Updated: 2023/07/10 13:57:19 by dlima            ###   ########.fr       */
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
				map->start++;
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
	printf("collectibles = %d\n free_space = %d\n", map->collectibles, map->free_space);
	if (map->exit != 1 || map->start != 1 || map->collectibles < 1 || map->free_space == 0)
		return (0);
	return (1);
}
