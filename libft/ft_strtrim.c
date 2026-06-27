/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 00:23:30 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/26 22:24:39 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)

{
	char const	*ptr;

	ptr = set;
	while (*ptr)
	{
		if (*ptr == c)
			return (1);
		ptr++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	char		*result;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = s1;
	while (*start && is_in_set(*start, set))
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (end > start && is_in_set(*end, set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	len = end - start + 1;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, start, len);
	*(result + len) = '\0';
	return (result);
}
/*
int main(void)

{
char a[10] = "   Hola	";
printf("%s\n", ft_strtrim(a, "oa"));
return(0);
}
*/
