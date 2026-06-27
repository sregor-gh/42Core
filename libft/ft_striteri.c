/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:54:01 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/19 15:11:57 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	example(unsigned int i, char c)

{
void(i);
if (c >= 'a' && c <= 'z')
return (c - 32);
return (c);
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))

{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)

{
char	*original = "holaprueba";
char	resultado;

resultado = ft_striteri(original, example);
printf("%s\n", resultado);
return (0);
}
*/
