/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:52:17 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/16 15:33:13 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define DX 0
#define DY 1
#define YI 2
#define D 3
#define Y 4
#define X 5
#define XI 2

void		fdf_draw(t_map *map, int i, int j)
{
	t_vector	vector;

	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (j + 1 < map->columns)
			{
				fdf_rotate(&vector, &map->map[i][j], &map->map[i][j + 1], map);
				fdf_put_line(&vector, map);
			}
			if (i + 1 < map->rows)
			{
				fdf_rotate(&vector, &map->map[i + 1][j], &map->map[i][j], map);
				fdf_put_line(&vector, map);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
			map->image.img_ptr, 0, 0);
}

static void	fdf_put_line_low(t_vector *vector, t_map *map)
{
	int	aux[6];

	aux[DX] = vector->x1 - vector->x0;
	aux[DY] = vector->y1 - vector->y0;
	aux[YI] = 1;
	if (aux[DY] < 0)
	{
		aux[YI] = -1;
		aux[DY] = -aux[DY];
	}
	aux[D] = 2 * aux[DY] - aux[DX];
	aux[Y] = vector->y0;
	aux[X] = vector->x0;
	while (aux[X] < vector->x1)
	{
		fdf_set_pixel(aux, vector, map);
		if (aux[D] > 0)
		{
			aux[Y] = aux[Y] + aux[YI];
			aux[D] = aux[D] - 2 * aux[DX];
		}
		aux[D] = aux[D] + 2 * aux[DY];
		aux[X]++;
	}
}

static void	fdf_put_line_high(t_vector *vector, t_map *map)
{
	int	aux[6];

	aux[DX] = vector->x1 - vector->x0;
	aux[DY] = vector->y1 - vector->y0;
	aux[XI] = 1;
	if (aux[DX] < 0)
	{
		aux[XI] = -1;
		aux[DX] = -aux[DX];
	}
	aux[D] = 2 * aux[DX] - aux[DY];
	aux[Y] = vector->y0;
	aux[X] = vector->x0;
	while (aux[Y] < vector->y1)
	{
		fdf_set_pixel(aux, vector, map);
		if (aux[D] > 0)
		{
			aux[X] = aux[X] + aux[XI];
			aux[D] = aux[D] - 2 * aux[DY];
		}
		aux[D] = aux[D] + 2 * aux[DX];
		aux[Y]++;
	}
}

static void	fdf_swap(t_vector *vector)
{
	int x;
	int y;

	x = vector->x0;
	y = vector->y0;
	vector->x0 = vector->x1;
	vector->y0 = vector->y1;
	vector->x1 = x;
	vector->y1 = y;
}

void		fdf_put_line(t_vector *vector, t_map *map)
{
	if (abs(vector->y1 - vector->y0) < abs(vector->x1 - vector->x0))
	{
		if (vector->x0 > vector->x1)
		{
			fdf_swap(vector);
			fdf_put_line_low(vector, map);
		}
		else
			fdf_put_line_low(vector, map);
	}
	else
	{
		if (vector->y0 > vector->y1)
		{
			fdf_swap(vector);
			fdf_put_line_high(vector, map);
		}
		else
			fdf_put_line_high(vector, map);
	}
}
