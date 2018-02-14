/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:56:06 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:27:56 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	long len;
	char *ptr;

	len = 0;
	while (str[len] != '\0')
		len++;
	ptr = (char*)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[len] = '\0';
	len--;
	while (len != -1)
	{
		ptr[len] = str[len];
		len--;
	}
	return (ptr);
}
