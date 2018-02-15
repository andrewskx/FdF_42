/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:49:57 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/12 16:43:54 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	fdf_rotate_x(t_vector *curr, t_coord *p1, t_coord *p2, t_map *map)
{
	int		x;
	int		z;

	x = p1->x * map->step;
	z = p1->z * map->step;
	curr->x0 = cos(map->angle_y) * x + sin(map->angle_y) * z;
	curr->z0 = -sin(map->angle_y) * x + cos(map->angle_y) * z;
	x = p2->x * map->step;
	z = p2->z * map->step;
	curr->x1 = cos(map->angle_y) * x + sin(map->angle_y) * z;
	curr->z1 = -sin(map->angle_y) * x + cos(map->angle_y) * z;
}

inline void	fdf_rotate_y(t_vector *curr, t_coord *p1, t_coord *p2, t_map *map)
{
	int		y;
	int		z;

	y = p1->y * map->step;
	z = curr->z0;
	curr->y0 = cos(map->angle_x) * y - sin(map->angle_x) * z;
	curr->z0 = sin(map->angle_x) * y + cos(map->angle_x) * z;
	y = p2->y * map->step;
	z = curr->z1;
	curr->y1 = cos(map->angle_x) * y - sin(map->angle_x) * z;
	curr->z1 = sin(map->angle_x) * y + cos(map->angle_x) * z;
}

inline void	fdf_rotate_z(t_vector *curr, t_map *map)
{
	int		x;
	int		y;

	x = curr->x0;
	y = curr->y0;
	curr->x0 = cos(map->angle_z) * x - sin(map->angle_z) * y;
	curr->y0 = sin(map->angle_z) * x + cos(map->angle_z) * y;
	x = curr->x1;
	y = curr->y1;
	curr->x1 = cos(map->angle_z) * x - sin(map->angle_z) * y;
	curr->y1 = sin(map->angle_z) * x + cos(map->angle_z) * y;
}

void		fdf_rotate(t_vector *curr, t_coord *p1, t_coord *p2, t_map *map)
{
	fdf_rotate_x(curr, p1, p2, map);
	fdf_rotate_y(curr, p1, p2, map);
	fdf_rotate_z(curr, map);
	curr->color0 = p1->color;
	curr->color1 = p2->color;
	curr->x0 += map->offset_x;
	curr->x1 += map->offset_x;
	curr->y0 += map->offset_y;
	curr->y1 += map->offset_y;
}
