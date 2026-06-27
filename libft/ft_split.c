/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 06:08:31 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/26 19:56:59 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static void	ft_free_all(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	ft_fill_array(char **arr, char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		if (i > start)
		{
			arr[j] = ft_substr(s, start, i - start);
			if (arr[j] == NULL)
				return (ft_free_all(arr, j), 0);
			j++;
		}
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = ft_calloc(ft_count_word(s, c) + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (ft_fill_array(arr, s, c) == 0)
		return (NULL);
	return (arr);
}

/*#include <stdio.h>
int	main(void)
{
char	**res;
int		i;

res = ft_split("hola,como,estas", ',');
i = 0;
while (res[i] != NULL)
printf("ft_split [%d]: %s\n", i++, res[i]); // hola / como / estas
return (0);
}*/
