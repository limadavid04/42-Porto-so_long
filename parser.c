/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:11:45 by dlima             #+#    #+#             */
/*   Updated: 2023/07/06 17:00:07 by dlima            ###   ########.fr       */
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
			break;
		n++;
		free(line);
	}
	close(fd);
	return (n);

}
void	fill_map_matrix(int n, char **map, char *file_path)
{
	int	i;
	int	fd;
	char	*line;
	fd = open(file_path, O_RDONLY);
	i = 0;
	
	while (i < n)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		map[i] = line;
		i++;
	}
	map[n] = NULL;
	
	//Prints map;
	// int x = 0;
	// int y = 0;

	// while (map[x]) {
	// 	y = 0;
	// 	while (map[x][y])
	// 	{
	// 		printf("%c", map[x][y]);
	// 		y++;
	// 	}
	// 	free(map[x]);
	// 	x++;
	// }
	// free(map);
}

int	main(int argc, char *argv[])
{
	int n;

	char	**map;
	(void)argc;

	n = get_nr_rows(argv[1]);
	map = (char **)ft_calloc(n + 1, sizeof(char *));
	fill_map_matrix(n, map, argv[1]);

	
}