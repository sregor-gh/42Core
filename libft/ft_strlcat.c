/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 16:02:37 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/05 23:44:14 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	space;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (dst_len + src_len);
	space = size - dst_len - 1;
	dst += dst_len;
	while (*src && space-- != 0)
		*dst++ = *src++;
	*dst = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char	a[10] = "Hola";
	char	*b;

	b = "Adios";
	printf("%zu\n", ft_strlcat(a, b, 3));
	return (0);
}

*/