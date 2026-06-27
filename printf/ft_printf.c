/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 20:29:35 by rzenteno          #+#    #+#             */
/*   Updated: 2026/06/05 22:18:31 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	comparer(char letter, va_list *args)
{
	int				count;
	unsigned long	ptr;

	count = 0;
	if (letter == 'c')
		count += ft_putchar(va_arg(*args, int));
	else if (letter == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (letter == 'p')
	{
		ptr = (unsigned long)va_arg(*args, void *);
		if (ptr == 0)
			return (ft_putstr("(nil)"));
		return (ft_putstr("0x") + ft_hex(ptr, 'x'));
	}
	else if (letter == 'd' || letter == 'i')
		count += ft_putnbr(va_arg(*args, int));
	else if (letter == 'u')
		count += ft_unsigned(va_arg(*args, unsigned int));
	else if (letter == 'x' || letter == 'X')
		count += ft_hex(va_arg(*args, unsigned int), letter);
	else if (letter == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += comparer(*format, &args);
			format++;
		}
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int	a;

	ft_printf("Texto: %c %s", 'U', "Texto");
	a = ft_printf("Texto: %c %s\n", 'U', "Texto");
	printf("%d", a);
	return (0);
}*/
/*
%c Prints a single character.
%s Prints a string (as defined by the common C convention).
%p The v  printed in hexadecimal format.
%d Prints a decimal (base 10) number.
%i Prints an integer in base 10.
%u Prints an unsigned decimal (base 10) number.
%x Prints a number in hexadecimal (base 16) lowercase format.
%X Prints a number in hexadecimal (base 16) uppercase format.
%% Prints a percent sign.
*/