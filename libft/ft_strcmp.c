/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:41:43 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:27:33 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (*ptr2 && *ptr1)
	{
		if (*ptr1 != *ptr2)
			return ((int)*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return ((int)(*ptr1 - *ptr2));
}
