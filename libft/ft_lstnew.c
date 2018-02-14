/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:53:36 by anboscan          #+#    #+#             */
/*   Updated: 2017/11/27 18:23:42 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	ptr = (t_list*)malloc(sizeof(t_list));
	if (ptr)
	{
		if (content == 0)
		{
			ptr->content_size = 0;
			ptr->content = 0;
		}
		else
		{
			ptr->content = (void*)malloc(sizeof(void) * content_size);
			ptr->content = ft_memcpy(ptr->content, content, content_size);
			ptr->content_size = content_size;
		}
		ptr->next = 0;
		return (ptr);
	}
	return (0);
}
