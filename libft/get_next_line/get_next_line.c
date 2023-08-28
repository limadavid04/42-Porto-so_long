/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:06:46 by dlima             #+#    #+#             */
/*   Updated: 2023/07/06 15:56:26 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_read(int fd)
{
	char	*buff;
	int		bytes_read;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read == 0 || bytes_read == -1)
	{
		free(buff);
		return (NULL);
	}
	buff[bytes_read] = '\0';
	return (buff);
}

char	*expand_buffer(char *buff, char *new)
{
	char	*new_buff;

	if (!buff)
	{
		new_buff = malloc(sizeof(char) * (ft_strlenn(new) + 1));
		ft_strlcpyy(new_buff, new, ft_strlenn(new) + 1);
		free(new);
		return (new_buff);
	}
	new_buff = malloc(sizeof(char) * (ft_strlenn(buff) + ft_strlenn(new) + 1));
	ft_strlcpyy(new_buff, buff, ft_strlenn(buff) + 1);
	ft_strlcatt(new_buff, new, (ft_strlenn(buff) + ft_strlenn(new) + 1));
	free(buff);
	free(new);
	return (new_buff);
}

char	*shrink_buff(char *buff)
{
	char		*new_buff;
	int			new_buff_len;
	size_t		len;

	len = ft_strlenn(buff) - ft_strlenn(ft_strchrr(buff, '\n')) + 1;
	if (len == ft_strlenn(buff))
	{
		free(buff);
		return (NULL);
	}
	new_buff_len = ft_strlenn(buff) - len;
	new_buff = malloc(sizeof(char) * (new_buff_len + 1));
	ft_strlcpyy(new_buff, ft_strchrr(buff, '\n') + 1, new_buff_len + 1);
	free(buff);
	return (new_buff);
}

char	*get_line(char *buff)
{
	int		len;
	char	*line;

	if (!ft_strchrr(buff, '\n'))
	{
		len = ft_strlenn(buff);
		line = malloc(sizeof(char) * (len + 1));
		ft_strlcpyy(line, buff, len + 1);
		return (line);
	}
	len = ft_strlenn(buff) - ft_strlenn(ft_strchrr(buff, '\n')) + 1;
	line = malloc(sizeof(char) * (len + 1));
	ft_strlcpyy(line, buff, len + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*newly_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > 4096)
		return (NULL);
	if (ft_strchrr(buff, '\n'))
	{
		line = get_line(buff);
		buff = shrink_buff(buff);
		return (line);
	}
	newly_read = new_read(fd);
	if (!newly_read)
	{
		if (!buff)
			return (NULL);
		line = get_line(buff);
		free(buff);
		buff = NULL;
		return (line);
	}
	buff = expand_buffer(buff, newly_read);
	return (get_next_line(fd));
}
