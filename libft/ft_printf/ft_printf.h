/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 10:50:06 by dlima             #+#    #+#             */
/*   Updated: 2023/08/28 12:39:58 by dlima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_char_format(int c);
int		ft_string_format(char *str);
int		ft_pointer_format(unsigned long long num);
int		ft_decimal_format(int num);
int		ft_unsigned_format(unsigned int num);
int		ft_hexadecimal_format(long long int num, char c);
int		ft_hexanumlen(long long int num);
void	ft_putchar_fdd(char c, int fd);
void	ft_putnbr_fdd(int n, int fd);
void	ft_put_unsigned_nbr_fd(unsigned int n, int fd);
#endif
