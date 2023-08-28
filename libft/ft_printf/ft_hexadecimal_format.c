/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:26:06 by dlima             #+#    #+#             */
/*   Updated: 2022/12/27 14:26:54 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hexa(long long int num, char c)
{
	char	*chars;

	chars = "0123456789abcdef";
	if (c == 'X')
		chars = "0123456789ABCDEF";
	if (num < 0)
	{
		num = 4294967295 - (num * (-1)) + 1;
	}
	if (num < 16)
		write(1, &chars[num], 1);
	else
	{
		hexa(num / 16, c);
		hexa(num % 16, c);
	}
}

int	ft_hexadecimal_format(long long int num, char c)
{
	int	len;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hexa(num, c);
	if (num < 0)
		num *= -1;
	len = ft_hexanumlen(num);
	return (len);
}
