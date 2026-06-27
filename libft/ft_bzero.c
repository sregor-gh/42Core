/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 21:39:36 by rzenteno          #+#    #+#             */
/*   Updated: 2026/04/30 21:41:29 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)

{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n)
	{
		*p++ = '\0';
		n--;
	}
}
/*
int	main(void)

{
	char s[10];
	bzero(s, 6);
	return (0);
}
	*/