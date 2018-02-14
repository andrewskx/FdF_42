/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:00:31 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:22:27 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

static char	*ft_check(int n)
{
	char *ptr;

	if (n == -2147483648)
	{
		ptr = (char*)malloc(sizeof(char) * (ft_strlen("−2147483648") + 1));
		ft_strcpy(ptr, "-2147483648");
		return (ptr);
	}
	if (n == 2147483647)
	{
		ptr = (char*)malloc(sizeof(char) * (ft_strlen("2147483647") + 1));
		ft_strcpy(ptr, "2147483647");
		return (ptr);
	}
	return (0);
}

static void	ft_neg(int *neg, char *s)
{
	if (*neg)
		s[0] = '-';
}

char		*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		negative;
	char	*str;

	if ((str = ft_check(n)) == 0)
	{
		tmpn = n;
		len = 2;
		negative = 0;
		ft_itoa_isnegative(&n, &negative);
		while (tmpn /= 10)
			len++;
		len += negative;
		if ((str = (char*)malloc(sizeof(char) * len)) == 0)
			return (0);
		str[--len] = '\0';
		while (len--)
		{
			str[len] = n % 10 + '0';
			n = n / 10;
		}
		ft_neg(&negative, str);
	}
	return (str);
}
