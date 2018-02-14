/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:01:31 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:31:14 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	if ((!*big && !*little) || (*big && !*little))
		return ((char*)big);
	ptr = (char*)big;
	i = 0;
	j = 0;
	k = 0;
	while (ptr[i] && *little)
	{
		j = 0;
		k = i;
		while (ptr[k] == little[j] && ptr[k] && little[j])
		{
			j++;
			k++;
		}
		if (little[j] == '\0')
			return (&ptr[i]);
		i++;
	}
	return (0);
}
