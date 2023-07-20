/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:16:05 by dlima             #+#    #+#             */
/*   Updated: 2023/07/20 21:52:02 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fetch_map(char *file, t_map *map)
{
	char	**map_matrix;
	int		n;

	n = get_nr_rows(file);
	map_matrix = (char **)ft_calloc(n + 1, sizeof(char *));
	fill_map_matrix(n, map_matrix, file);
	map_matrix[n] = NULL;
	map->map_matrix = map_matrix;
}

int	check_file_extension(char *file)
{
	int		i;
	int		len;
	char	extension[5];

	len = ft_strlen(file);
	if (len < 5)
	{
		throw_error("Invalid file extension");
		return (0);
	}
	extension[4] = '\0';
	i = 3;
	while (i >= 0)
	{
		extension[i] = file[len - 1];
		len--;
		i--;
	}
	if (ft_strncmp(extension, ".ber", 4))
	{
		throw_error("Invalid file extension");
		return (0);
	}
	return (1);
}

int	check_file_path(char *file)
{
	int	fd;

	if (!(check_file_extension(file)))
		return (0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		throw_error("Can't find that map");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
		throw_error("Invalid number of arguments");
	if (!(check_file_path(argv[1])))
		return (0);
	map = (t_map *)malloc(sizeof(t_map));
	fetch_map(argv[1], map);
	if (!(check_map_conditions(map)))
		return (0);
	game_main(map);
	return (0);
}
//replace printf with ft_printf
//display moves on the screen
//add mouse event to close window
