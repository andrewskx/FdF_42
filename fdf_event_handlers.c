/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_event_handlers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:43:07 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/12 16:45:26 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_key(int key, t_map *map)
{
	if (key == 53 || key == 7 || key == 16 || key == 6)
	{
		if (key == 53)
		{
			fdf_map_deallocate(map);
			exit(0);
		}
		else if (key == 7)
			map->angle_x += map->reverse ? -5 * 0.0174 : 5 * 0.0174;
		else if (key == 16)
			map->angle_y += map->reverse ? -5 * 0.0174 : 5 * 0.0174;
		else if (key == 6)
			map->angle_z += map->reverse ? -5 * 0.0174 : 5 * 0.0174;
		fdf_draw(map);
	}
	else
	{
		key == 15 ? map->reverse = !map->reverse : 0;
		ft_putstr("\nkey -> ");
		ft_putnbr(key);
	}
	return (0);
}

int	fdf_mouse_hook(int button, int x, int y, t_map *map)
{
	map->button = button;
	map->last_x = x;
	map->last_y = y;
	return (0);
}

int	fdf_motion_hook(int x, int y, t_map *map)
{
	x = -1;
	if (map->button == 2)
	{
		map->step = map->last_y < y ? (map->step * 1.05) : (map->step / 1.05);
		fdf_draw(map);
	}
	return (0);
}

int	fdf_button_release_hook(int button, int x, int y, t_map *map)
{
	x = 0;
	y = 0;
	button = 0;
	map->button = 0;
	map->axe_key = 0;
	return (0);
}
