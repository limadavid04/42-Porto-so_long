/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:53:27 by dlima             #+#    #+#             */
/*   Updated: 2023/08/27 15:37:53 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_format(unsigned int num)
{
	int	nbr_digits;

	nbr_digits = 0;
	if (num == 0)
		nbr_digits = 1;
	ft_put_unsigned_nbr_fd(num, 1);
	while (num)
	{
		num /= 10;
		nbr_digits++;
	}
	return (nbr_digits);
}
