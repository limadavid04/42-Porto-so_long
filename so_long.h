/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:13:10 by dlima             #+#    #+#             */
/*   Updated: 2023/07/10 18:37:16 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct Map_info
{
	char	**map_matrix;
	int	collectibles;
	int	exit;
	int	start;
	int	free_space;
	int	row;
	int	col;
}	map_info;

void	replace_newlines(char *line);
int		check_map_path(map_info *map);
void	matrix_free(char **matrix);
int		check_map_elements(map_info *map);
void	matrix_copy(char **src, char **dest);
int		nbr_columns(char **matrix);



#endif
