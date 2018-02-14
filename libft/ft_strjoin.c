/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:40:38 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:28:48 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ptr;

	if (s1 && s2)
	{
		ptr = (char *)malloc(sizeof(char) *
				(ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1));
		if (ptr)
		{
			ft_strcpy(ptr, s1);
			ft_strcat(ptr, s2);
			ptr[ft_strlen((char*)s1) + ft_strlen((char*)s2)] = '\0';
			return (ptr);
		}
	}
	return (0);
}
