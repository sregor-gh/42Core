/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 19:52:36 by rzenteno          #+#    #+#             */
/*   Updated: 2026/06/05 22:21:41 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char str)
{
	return (write(1, &str, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str)
	{
		(write(1, str, 1));
		count++;
		str++;
	}
	return (count);
}

int	ft_putnbr(long digit)
{
	int	count;

	count = 0;
	if (digit < 0)
	{
		count = count + ft_putchar('-');
		digit = -digit;
	}
	if (digit >= 10)
	{
		count = count + ft_putnbr(digit / 10);
		count = count + ft_putnbr(digit % 10);
	}
	if (digit < 10)
		count = count + ft_putchar(digit + '0');
	return (count);
}

int	ft_unsigned(unsigned int digit)
{
	return (ft_putnbr((long)digit));
}

int	ft_hex(unsigned long digit, char type)
{
	char	*base;
	int		count;

	count = 0;
	if (type == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (digit >= 16)
		count += ft_hex(digit / 16, type);
	count += ft_putchar (base [digit % 16]);
	return (count);
}
