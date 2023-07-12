/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:13:10 by dlima             #+#    #+#             */
/*   Updated: 2023/07/12 16:22:38 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "./mlx/mlx.h"
typedef struct Map_info
{
	char	**map_matrix;
	int		collectibles;
	int		exit;
	int		start;
	int		row;
	int		col;
}	t_map;

typedef struct Game_info
{
	t_map	*map;
	int		nbr_rows;
	int		nbr_cols;
	void	*wall;
	void	*tiles;
	void	*coins;
	void	*player;
	void	*exit;
	void	*mlx;
	void	*mlx_win;

}	t_game;

void	replace_newlines(char *line);
int		check_map_path(t_map *map);
void	matrix_free(char **matrix);
int		check_map_elements(t_map *map);
void	matrix_copy(char **src, char **dest);
int		nbr_rows(char **matrix);
void	game_main(t_map *map);
void	xpm_img(t_game *game);

#endif
