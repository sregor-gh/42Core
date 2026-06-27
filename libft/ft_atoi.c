/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 06:29:21 by rzenteno          #+#    #+#             */
/*   Updated: 2026/05/18 09:13:40 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
int ft_atoi(const char *str)

{
int result;
int sign;
int digit;

result = 0;
sign = 1;

while (*str == ' ' || (*str >= 9 && *str <=13))
str++;
if(*str == '-' || *str == '+')
{ if(*str == '-')
sign = - 1;
str++;
}
while (*str >= '0' && *str <= '9')
{
digit = *str - '0';
if (result > 214748364 || (result == 214748364 && digit > 7))
{ if(sign == 1)
return(-1);
else
return (0);}
result = result * 10 + digit;
str++;
}
return ((int)(result * sign));

}*/
/*
int main(void)

{
char a[8] = "  ";
printf("%d\n", ft_atoi(a));
return(0);
}
*/
