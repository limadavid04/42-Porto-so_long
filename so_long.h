/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:13:10 by dlima             #+#    #+#             */
/*   Updated: 2023/07/11 12:30:40 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

typedef struct Map_info
{
	char	**map_matrix;
	int		collectibles;
	int		exit;
	int		start;
	int		free_space;
	int		row;
	int		col;
}	t_map;

void	replace_newlines(char *line);
int		check_map_path(t_map *map);
void	matrix_free(char **matrix);
int		check_map_elements(t_map *map);
void	matrix_copy(char **src, char **dest);
int		nbr_rows(char **matrix);



#endif
