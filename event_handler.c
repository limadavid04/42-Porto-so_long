/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:15:20 by dlima             #+#    #+#             */
/*   Updated: 2023/07/12 20:18:01 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void close_game(t_game *game)
{
    //free the structs and close
    mlx_destroy_image(game->mlx, game->wall);
    mlx_destroy_image(game->mlx, game->tiles);
    mlx_destroy_image(game->mlx, game->coins);
    mlx_destroy_image(game->mlx, game->player);
    mlx_destroy_image(game->mlx, game->exit);
    mlx_destroy_window(game->mlx, game->mlx_win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    free(game->mlx_win);
	// matrix_free(game->map->map_matrix);
    // free(game->map);
    free(game);
}
int event_handler(int keycode, t_game *game)
{
    (void)game;
    printf("key = %d\n", keycode);
    if (keycode == ESC)
    {
        exit (EXIT_SUCCESS);
        // close_game(game);
    }
    return (0);
}
