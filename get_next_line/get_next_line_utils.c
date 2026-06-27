/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:48:43 by rzenteno          #+#    #+#             */
/*   Updated: 2026/06/26 18:53:09 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *string, int set)
{
	while (*string)
	{
		if (*string == (unsigned char)set)
			return ((char *)string);
		string++;
	}
	if ((unsigned char)set == '\0')
		return ((char *)string);
	return (NULL);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (start + len > s_len)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	*(sub + len) = '\0';
	return (sub);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
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
int	main(void)
{
	char *a = "hola mundo";
	printf("%s\n", *ft_substr (a, 5, 3));
	return(0);
}*/
