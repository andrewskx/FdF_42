/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:48:05 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/28 13:52:03 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char *ptr;
	char *aux;

	ptr = (char *)str;
	aux = (char *)str;
	while (*ptr)
		ptr++;
	while (ptr != aux)
	{
		if (*ptr-- == c)
			return (++ptr);
	}
	if (*ptr == c)
		return (ptr);
	return (0);
}
