/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <dlima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:20:25 by dlima             #+#    #+#             */
/*   Updated: 2023/07/06 15:57:47 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpyy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (!src)
	{
		dest = NULL;
		return (0);
	}
	i = 0;
	len = ft_strlenn(src);
	if (!dest || !src)
		return (0);
	if (size == 0)
		return (len);
	while (i < (size - 1) && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

char	*ft_strchrr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlenn(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcatt(char *dst, const char *src, size_t size)
{
	size_t	length;
	size_t	index;

	if (size == 0 || size <= ft_strlenn(dst))
		return (size + ft_strlenn(src));
	length = ft_strlenn(dst);
	index = 0;
	while (src[index] && length + 1 < size)
	{
		dst[length] = src[index];
		length++;
		index++;
	}
	dst[length] = 0;
	return (length + ft_strlenn(&src[index]));
}
