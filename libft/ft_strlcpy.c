/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:14:14 by rzenteno          #+#    #+#             */
/*   Updated: 2026/04/30 22:59:25 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)

{
	const char	*a = src;

	if (size != 0)
	{
		while (*src != '\0' && --size != 0)
			*dst++ = *src++;
		*dst = '\0';
	}
	while (*src)
		src++;
	return (src - a);
}

/*
#include <stdio.h>

int	main(void)
{
	char	a[4] = "Hola";
	char	*b;
	int		size;

	b = "Adios";
	size = 5;
	printf("%zu\n", ft_strlcpy(a, b, size));
}

*/