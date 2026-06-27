/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 20:37:40 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/05 20:39:35 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)

{
	char	*a;

	a = NULL;
	while (*s)
	{
		if (*s == (char)c)
			a = (char *)s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (a);
}
/*
int	main(void)

{
	char a[11] = "Hola como";
	printf("%s\n", ft_strrchr(a, 'o'));
	return(0);
}
	*/