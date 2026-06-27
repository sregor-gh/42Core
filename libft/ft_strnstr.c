/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:45:04 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/07 15:45:07 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	size_t		remaining;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		h = haystack;
		n = needle;
		remaining = len;
		while (*h && *n && *h == *n && remaining > 0)
		{
			h++;
			n++;
			remaining--;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
/*
int	main(void)

{
	char a[40] = "lorem ipsum dolor sit amet";
	char b[10] = "sit";
	printf("%s\n", ft_strnstr(a,b,10));
	return(0);
}*/