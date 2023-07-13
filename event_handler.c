/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:15:20 by dlima             #+#    #+#             */
/*   Updated: 2023/07/13 16:05:08 by dlima            ###   ########.fr       */
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

void    movement_possible(t_game *game, int i, int j)
{
    char    **matrix;

    matrix = game->map->map_matrix;
    if (matrix[i][j] == '1')
        return ;
    else if (matrix[i][j] == 'C')
    {
        game->collected++;
        collect_coin(game, i, j);
        edit_map(game, i, j);
    }
    else if (matrix[i][j] == '0')
    {
        floor_move(game, i , j);
        edit_map(game, i , j);
    }
    else if (matrix[i][j] == 'E')
    {
        if (game->collected == game->map->collectibles)
            close_game(game);
        pass_over_exit(game, i, j);
        edit_map(game, i, j);
    }
}
void    move_up(t_game *game)
{
    int i;
    int j;

    i = game->map->p_row + 1;
    j = game->map->p_col;
    movement_possible(game, i, j);
}

int event_handler(int keycode, t_game *game)
{
    printf("key = %d\n", keycode);
    if (keycode == ESC)
        close_game(game);
    else if (keycode == W)
        move_up(game);
    return (0);
}
void    edit_map(t_game *game, int i, int j)
{
    (void)game;
}
// edit map needs to edit the map with the new player position
// registered in map->p_row and map->p_col and also edits the map;

//the functions in render replace the images on the respective tiles
//where the player moved

//finally the event handle function still needs to handle movemenst in the other 
//directions

//every movement function, move_up, move_down, etc edits the next
//position of the player by editing i and j and sends it to 
//movement possible to update the window accordingly