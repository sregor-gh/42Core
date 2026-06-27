/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 02:46:22 by username          #+#    #+#             */
/*   Updated: 2026/05/13 02:47:03 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)

{
	const char	*p;
	size_t		len;

	p = s;
	len = 0;
	while (*p)
	{
		p++;
		len++;
	}
	return (len);
}
/*
int	main(void)

{
char	a[10] = "holatexto";

printf("%d\n," ft_strlen(a));
return (0);
}
*/
