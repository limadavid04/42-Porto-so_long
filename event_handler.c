/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:15:20 by dlima             #+#    #+#             */
/*   Updated: 2023/07/13 15:31:28 by dlima            ###   ########.fr       */
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
	matrix_free(game->map->map_matrix);
    free(game->map);
    free(game);
    exit (EXIT_SUCCESS);
}
int event_handler(int keycode, t_game *game)
{
    printf("key = %d\n", keycode);
    if (keycode == ESC)
        close_game(game);
    // else if (keycode == W)

    return (0);
}

// void    move_up(t_game *game)
// {
//     int i;
//     int j;

//     i = game->map->p_row + 1;
//     j = game->map->p_col;

//     if (game->map->map_matrix[i][j] == '1')
//         return ;
//     else if ()
// }