/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:13:10 by dlima             #+#    #+#             */
/*   Updated: 2023/07/10 13:59:22 by dlima            ###   ########.fr       */
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
}	map_info;

void	replace_newlines(char *line);
int		check_map_elements(map_info *map);
void	matrix_free(char **matrix);


#endif
