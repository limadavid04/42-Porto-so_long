/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:06:23 by dlima             #+#    #+#             */
/*   Updated: 2023/07/12 17:22:38 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_img(t_game *game)
{
	int	size = 64;
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &size, &size);
	game->tiles = mlx_xpm_file_to_image(game->mlx, "textures/tiles.xpm", &size, &size);
	game->coins = mlx_xpm_file_to_image(game->mlx, "textures/coins.xpm", &size, &size);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &size, &size);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &size, &size);
}


void	get_img(char element, t_game *game, int	x, int y)
{
	if(element == '1')
		mlx_put_image_to_window(game->mlx ,game->mlx_win, game->wall, y * 64, x * 64);
	else if (element == '0')
		mlx_put_image_to_window(game->mlx ,game->mlx_win, game->tiles, y * 64, x * 64);
	else if (element == 'C')
		mlx_put_image_to_window(game->mlx ,game->mlx_win, game->coins, y * 64, x * 64);
	else if (element == 'P')
		mlx_put_image_to_window(game->mlx ,game->mlx_win, game->player, y * 64, x * 64);
	else if (element == 'E')
		mlx_put_image_to_window(game->mlx ,game->mlx_win, game->exit, y * 64, x * 64);
}
void	put_img_to_Window(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map->map_matrix[x])
	{
		y = 0;
		while (game->map->map_matrix[x][y])
		{
			printf("x = %d\ny = %d\n", x , y);
			get_img(game->map->map_matrix[x][y], game, x, y);
			y++;
		}
		x++;
	}
}
void game_main(t_map *map)
{
	t_game	*game;
	
	game = (t_game *)malloc(sizeof(t_game));
	game->map = (t_map*)malloc(sizeof(t_map));
	game->map = map;
	game->nbr_rows = nbr_rows(map->map_matrix);
	printf("nbr rows = %d\n", game->nbr_rows);
	game->nbr_cols = ft_strlen(map->map_matrix[0]);
	printf("nbr cols = %d\n", game->nbr_cols);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->nbr_cols * 64, game->nbr_rows * 64, "Hello world!");
	xpm_img(game);
	put_img_to_Window(game);
	mlx_loop(game->mlx);
}