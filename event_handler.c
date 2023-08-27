/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:15:20 by dlima             #+#    #+#             */
/*   Updated: 2023/08/27 16:00:17 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->tiles);
	mlx_destroy_image(game->mlx, game->coins);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->exit_overlay);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	matrix_free(game->map->map_matrix);
	free(game->map);
	free(game);
	exit (EXIT_SUCCESS);
}

void	move(t_game *game, int i, int j)
{
	char	**matrix;

	matrix = game->map->map_matrix;
	if (matrix[i][j] == '1')
		return ;
	game->nbr_moves++;
	ft_printf("move = %d\n", game->nbr_moves);
	if (matrix[i][j] == 'C')
	{
		game->collected++;
		replace_tile(game, i, j);
	}
	else if (matrix[i][j] == '0' || matrix[i][j] == 'P')
		replace_tile(game, i, j);
	else if (matrix[i][j] == 'E')
	{
		if (game->collected == game->map->collectibles)
		{
			ft_printf("YOU WIN!!");
			close_game(game);
		}
		replace_tile(game, i, j);
	}
	edit_map(game, i, j);
}

int	event_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W)
		move(game, game->map->p_row - 1, game->map->p_col);
	else if (keycode == A)
		move(game, game->map->p_row, game->map->p_col - 1);
	else if (keycode == S)
		move(game, game->map->p_row + 1, game->map->p_col);
	else if (keycode == D)
		move(game, game->map->p_row, game->map->p_col + 1);
	return (0);
}

void	edit_map(t_game *game, int i, int j)
{
	if (game->map->map_matrix[i][j] == 'C')
		game->map->map_matrix[i][j] = '0';
	game->map->p_row = i;
	game->map->p_col = j;
}
