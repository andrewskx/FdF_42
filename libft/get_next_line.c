/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:19:53 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/03 13:45:06 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy(char *str, char **aux)
{
	int		i;
	int		check;
	char	*ptr;

	check = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] != '\0')
		check = 1;
	str[i] = '\0';
	ptr = ft_strdup(str);
	if (check)
		*aux = ft_strdup(&str[i + 1]);
	else
		*aux = ft_strdup(&str[i]);
	if (str)
		free(str);
	return (ptr);
}

t_list	*check_existence_fd(const int fd, t_list **ptr)
{
	t_list *aux;

	aux = *ptr;
	while (aux)
	{
		if ((int)aux->content_size == (int)fd)
			return (aux);
		aux = aux->next;
	}
	aux = ft_lstnew((void *)"\0", fd);
	ft_lstadd(ptr, aux);
	aux = *ptr;
	return (aux);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*ptr;
	t_list			*aux;
	char			*str;
	char			buff[BUFF_SIZE + 1];
	int				symbol_read;

	str = 0;
	if (fd < 0 || !line || read(fd, &buff, 0) < 0)
		return (-1);
	aux = check_existence_fd(fd, &ptr);
	while ((symbol_read = read(fd, &buff, BUFF_SIZE)))
	{
		buff[symbol_read] = '\0';
		aux->content = (char*)ft_strjoin((char*)(aux->content), buff);
		if ((str = ft_strchr(aux->content, '\n')))
			break ;
	}
	if (str == 0)
		str = ft_strchr(aux->content, '\n');
	if (symbol_read < BUFF_SIZE && ft_strlen(aux->content) == 0)
		return (0);
	*line = ft_copy(aux->content, (char**)(&aux->content));
	return (1);
}
