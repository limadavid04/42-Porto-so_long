/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:28:47 by dlima             #+#    #+#             */
/*   Updated: 2023/07/15 20:57:04 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	replace_tile(t_game *game, int i, int j)
{
	int	old_i;
	int	old_j;

	old_i = game->map->p_row;
	old_j = game->map->p_col;
	if (game->map->map_matrix[old_i][old_j] == 'E')
	{
		get_img('E', game, old_i, old_j);
		get_img('P', game, i, j);
		return ;
	}
	get_img('0', game, old_i, old_j);
	get_img('P', game, i, j);
}
