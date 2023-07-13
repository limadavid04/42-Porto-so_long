/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:54:51 by dlima             #+#    #+#             */
/*   Updated: 2023/07/13 11:22:44 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	replace_newlines(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

void	matrix_free(char **matrix)
{
	int	x;

	x = 0;
	while (matrix[x])
	{
		free(matrix[x]);
		x++;
	}
	free(matrix);
}

void	matrix_copy(char **src, char **dest)
{
	int	x;

	x = 0;
	while (src[x])
	{
		dest[x] = (char *)malloc((ft_strlen(src[x]) + 1) * sizeof(char));
		ft_strlcpy(dest[x], src[x], ft_strlen(src[x]) + 1);
		x++;
	}
	dest[x] = NULL;
}

int	nbr_rows(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	throw_error(char *str)
{
	printf("ERROR\n");
	printf("%s", str);
}

