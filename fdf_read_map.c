/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:41:20 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/12 16:40:14 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_validate_line(t_list *start, char *str)
{
	int i;
	int columns;

	i = 0;
	columns = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) || str[i] == ' '))
			if (!((str[i] == '-' && ft_isdigit(str[i + 1]))))
			{
				ft_lstdel(&start, ft_del_lst);
				fdf_error("Invalid map");
			}
		if (str[i] == ' ' && (ft_isdigit(str[i + 1]) || str[i + 1] == '-'))
			columns++;
		i++;
	}
	start->content_size = (size_t)columns + 1;
}

t_list		*fdf_validation_first_step(char *file, t_map *map)
{
	int		fd;
	t_list	*start;
	char	*line;

	map->rows = 0;
	line = 0;
	start = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		fdf_error("Failed to open the file");
	while (get_next_line(fd, &line))
	{
		ft_lstadd(&start, ft_lstnew((void*)line, ft_strlen(line) + 1));
		fdf_validate_line(start, (char*)(start->content));
		(map->rows)++;
		free(line);
	}
	return (start);
}

void		fdf_fill_map(t_list *start, t_map *map, int rows, int columns)
{
	char	**str;
	t_list	*ptr;

	ptr = start;
	while (ptr)
	{
		columns = 0;
		str = ft_strsplit((char*)ptr->content, ' ');
		while (str[columns])
		{
			map->map[rows][columns].x = columns;
			map->map[rows][columns].y = rows;
			map->map[rows][columns].z = ft_atoi(str[columns]);
			columns++;
		}
		rows--;
		ft_free_double_char(str);
		ptr = ptr->next;
	}
}

void		fdf_validation_final_step(t_list *start, t_map *map)
{
	t_list	*ptr;
	size_t	columns;

	if (start)
	{
		ptr = start;
		columns = ptr->content_size;
		while (ptr)
		{
			if (columns != ptr->content_size)
			{
				ft_lstdel(&start, ft_del_lst);
				fdf_error("Invalid map");
			}
			ptr = ptr->next;
		}
	}
	map->columns = (int)start->content_size;
}

void		fdf_read_to_map(char *file, t_map *map)
{
	t_list *start;

	start = fdf_validation_first_step(file, map);
	fdf_validation_final_step(start, map);
	fdf_map_allocate(map);
	fdf_fill_map(start, map, map->rows - 1, 0);
	ft_lstdel(&start, ft_del_lst);
	fdf_move_to_origin(map);
}
