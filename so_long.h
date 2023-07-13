/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:13:10 by dlima             #+#    #+#             */
/*   Updated: 2023/07/13 15:31:07 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "./mlx/mlx.h"

# ifndef ESC
#  define ESC 65307
#endif
# ifndef W
#  define W 119
#endif
# ifndef A
#  define A 97
#endif
# ifndef S
#  define S 115
#endif
# ifndef D
#  define D 100
#endif
typedef struct Map_info
{
	char	**map_matrix;
	int		collectibles;
	int		exit;
	int		start;
	int		p_row;
	int		p_col;
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
	int		collected;
}	t_game;

void	replace_newlines(char *line);
int		check_map_path(t_map *map);
void	matrix_free(char **matrix);
int		check_map_elements(t_map *map);
void	matrix_copy(char **src, char **dest);
int		nbr_rows(char **matrix);
int		get_nr_rows(char *file_path);
void	fill_map_matrix(int n, char **map_matrix, char *file_path);
void	game_main(t_map *map);
void	xpm_img(t_game *game);
int		event_handler(int keycode, t_game *game);
void	close_game(t_game *game);
int		check_map_conditions(t_map *map);
void	throw_error(char *str);



#endif
