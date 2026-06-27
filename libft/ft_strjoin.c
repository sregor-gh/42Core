/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 03:49:52 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/18 09:29:56 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)

{
	char	*new;
	size_t	lens1;
	size_t	lens2;
	size_t	total;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	total = lens1 + lens2 + 1;
	new = malloc(total);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, lens1);
	ft_memcpy(new + lens1, s2, lens2);
	*(new + lens1 + lens2) = '\0';
	return (new);
}
/*
int main(void)

{
char *a = "Prueba";
char *b = "Texto";
printf("%s\n", ft_strjoin(&a,&b));
return(0);
}
*/
