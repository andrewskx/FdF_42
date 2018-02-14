/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:01:24 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:29:29 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = 0;
	if (s && f)
	{
		ptr = (char*)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
		if (ptr)
		{
			while (*s)
			{
				ptr[i] = f(*s);
				i++;
				s++;
			}
			ptr[i] = 0;
			return (ptr);
		}
	}
	return (0);
}
