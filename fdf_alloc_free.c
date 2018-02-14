/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_alloc_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:47:51 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/03 15:51:00 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_map_deallocate(t_map *map)
{
	map->rows--;
	while (map->rows)
	{
		free(map->map[map->rows]);
		map->rows--;
	}
	free(map->map);
	ft_putstr("Map being freed");
}

void	fdf_map_allocate(t_map *map)
{
	int i;

	i = 0;
	map->map = (t_coord**)malloc(sizeof(t_coord*) * map->rows);
	while (i < map->rows)
	{
		map->map[i] = (t_coord*)malloc(sizeof(t_coord) * map->columns);
		i++;
	}
}
