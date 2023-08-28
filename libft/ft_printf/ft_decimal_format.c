/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:42:57 by dlima             #+#    #+#             */
/*   Updated: 2023/08/27 15:38:06 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal_format(int num)
{
	int	nbr_digits;

	nbr_digits = 0;
	if (num < 0)
		nbr_digits++;
	if (num == 0)
		nbr_digits = 1;
	ft_putnbr_fdd(num, 1);
	while (num)
	{
		num /= 10;
		nbr_digits++;
	}
	return (nbr_digits);
}
