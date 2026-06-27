/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 06:44:07 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/18 09:14:15 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_str(char *res, long nb, int len, int n)

{
	int	i;

	i = len - 1;
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (nb > 0)
	{
		res[i] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
}

char	*ft_itoa(int n)

{
	int		len;
	char	*res;
	long	nb;
	long	temp;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	nb = n;
	if (nb < 0)
		nb = -nb;
	temp = nb;
	while (temp)
	{
		temp /= 10;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	fill_str(res, nb, len, n);
	return (res);
}
/*
len = (n <= 0) ? 1 : 0;
Si n es 0 o negativo, necesitas al menos un carácter extra: para el '0' o
para el signo '-'.*/
/*
int	main(void)

{
int	a = 42;

printf("%d\n", ft_itoa(a));
return (0);
}
*/
