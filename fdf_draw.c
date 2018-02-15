/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:52:17 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/12 17:38:23 by anboscan         ###   ########.fr       */
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

int		ft_lerpi(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

double	ft_ilerp(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

int			clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}


void		mlx_set_pixel(int *aux, t_vector *curr, t_map *map)
{
	double p;
	int color;


	if (aux[X] >= 0 && aux[X] < WIDTH &&  aux[Y] < HEIGHT && aux[Y] >= 0)
	{
		p = (aux[DX] > aux[DY] ?
			ft_ilerp(aux[X], curr->x0, curr->x1)
			: ft_ilerp(aux[Y], curr->y0, curr->y1));
		color = clerp(curr->color0, curr->color1, p);
		*(int *)((map->image.mem + ((aux[X] + aux[Y] * WIDTH) * 4))) = color;
	}
}

void		fdf_draw(t_map *map)
{
	int			i;
	int			j;
	t_vector	vector;

	i = 0;
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
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->image.img_ptr, 0, 0);
	ft_bzero(map->image.mem, WIDTH * HEIGHT * 4);
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
	//	mlx_pixel_put(map->mlx_ptr, map->win_ptr, aux[X], aux[Y], 0xFF0000);
		mlx_set_pixel(aux, vector, map);
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
	//	mlx_pixel_put(map->mlx_ptr, map->win_ptr, aux[X], aux[Y], 0xFF0000);
		mlx_set_pixel(aux, vector, map);
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
