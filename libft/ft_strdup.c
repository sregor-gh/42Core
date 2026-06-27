/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 02:23:54 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/19 14:53:16 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)

{
	char	*dup;
	size_t	len;
	char	*p;

	p = (char *) s1;
	len = 0;
	while (*p)
	{
		p++;
		len++;
	}
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	p = (char *) s1;
	while (*p)
	{
		*dup = *p;
		dup++;
		p++;
	}
	*dup = '\0';
	return (dup - len);
}
/*
int main (void)

{
char *a = "holatexto";
printf("%s\n", ft_strdup(a));
return(0);
}
*/
//
