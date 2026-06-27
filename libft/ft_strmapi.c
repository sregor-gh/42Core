/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:55:13 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/19 14:53:54 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	example(size_t int i, char c)

{
(void) i;
if (c >= 'a' && c <= 'z')
return (c - 32);
return (c);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

{
	size_t	len;
	char	*newstr;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	newstr = malloc(len + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	newstr[len] = '\0';
	return (newstr);
}
/*
int	main(void)

{
char	*original = "holaprueba";
char	*resultado;

resultado = ft_strmapi(original, example);
printf("%s\n", resultado);
return (0);
}
*/
