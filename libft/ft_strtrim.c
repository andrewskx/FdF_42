/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:48:50 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 19:35:25 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_check(char const *s)
{
	char *ptr;

	if (s)
	{
		if (*s == 0)
		{
			ptr = (char*)malloc(sizeof(char));
			ptr[0] = 0;
			return (ptr);
		}
		while (*s)
		{
			if (*s != ' ' && *s != '\n' && *s != '\t')
				break ;
			s++;
		}
		if (*s == 0)
		{
			ptr = (char*)malloc(sizeof(char));
			ptr[0] = 0;
			return (ptr);
		}
	}
	return (0);
}

static unsigned int	ft_start(unsigned int start, char const *s)
{
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	return (start);
}

static unsigned int	ft_end(unsigned int end, char const *s)
{
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	return (end);
}

char				*ft_strtrim(char const *s)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;
	char			*ptr;

	start = 0;
	if ((ptr = ft_check(s)) != 0)
		return (ptr);
	if (s)
	{
		i = 0;
		end = ft_strlen((char *)s) - 1;
		start = ft_start(start, s);
		end = ft_end(end, s);
		if ((ptr = (char*)malloc(sizeof(char) * (end - start + 2))) != 0)
		{
			while (start != end + 1)
				ptr[i++] = s[start++];
			ptr[i] = '\0';
			return (ptr);
		}
	}
	return (0);
}
