/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:35:50 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:31:07 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word(const char *s, char c)
{
	int		words;
	int		in_substring;

	in_substring = 0;
	words = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			words++;
		}
		s++;
	}
	return (words);
}

static int		ft_letter(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		words;
	int		index;

	if (s)
	{
		index = 0;
		words = ft_word((const char *)s, c);
		if (!(ptr = (char **)malloc(sizeof(char*) *
			(ft_word((const char *)s, c) + 1))))
			return (0);
		while (words--)
		{
			while (*s == c && *s != '\0')
				s++;
			ptr[index] = ft_strsub((const char *)s,
					0, ft_letter((const char *)s, c));
			if (ptr[index++] == 0)
				return (0);
			s = s + ft_letter(s, c);
		}
		ptr[index] = 0;
		return (ptr);
	}
	return (0);
}
