/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:04:05 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:35:39 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ptr;
	unsigned char	key;

	key = (unsigned char)c;
	ptr = (unsigned char*)s;
	i = 0;
	while (i++ < n)
		if (*ptr++ == key)
			return (--ptr);
	return (0);
}
