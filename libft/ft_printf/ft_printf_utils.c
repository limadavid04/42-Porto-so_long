/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:56:13 by dlima             #+#    #+#             */
/*   Updated: 2023/08/28 12:39:25 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexanumlen(long long int num)
{
	int	len;

	len = 0;
	while (num)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_putchar_fdd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putnbr_fdd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fdd('-', fd);
		ft_putchar_fdd('2', fd);
		ft_putnbr_fdd(147483648, fd);
	}
	else if (n < 0)
	{
		n *= -1;
		ft_putchar_fdd('-', fd);
		ft_putnbr_fdd(n, fd);
	}
	else
	{
		if (n < 10)
			ft_putchar_fdd((n + 48), fd);
		else
		{
			ft_putnbr_fdd(n / 10, fd);
			ft_putchar_fdd((n % 10) + 48, fd);
		}
	}
}

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fdd((n + 48), fd);
	else
	{
		ft_putnbr_fdd(n / 10, fd);
		ft_putchar_fdd((n % 10) + 48, fd);
	}
}
