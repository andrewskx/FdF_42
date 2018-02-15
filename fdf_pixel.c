#include "fdf.h"
#define DX 0
#define DY 1
#define YI 2
#define D 3
#define Y 4
#define X 5
#define XI 2

int		fdf_get_gradient(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

double		fdf_get_percent(double val, double first, double second)
{
	if (val == first)
		return (0.0);
	if (val == second)
		return (1.0);
	return ((val - first) / (second - first));
}

int		fdf_get_color(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = fdf_get_gradient((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = fdf_get_gradient((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = fdf_get_gradient(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}


void		fdf_set_pixel(int *aux, t_vector *curr, t_map *map)
{
	double	p;
	int	color;


	if (aux[X] >= 0 && aux[X] < WIDTH &&  aux[Y] < HEIGHT && aux[Y] >= 0)
	{
		p = (aux[DX] > aux[DY] ?
			fdf_get_percent(aux[X], curr->x0, curr->x1)
			: fdf_get_percent(aux[Y], curr->y0, curr->y1));
		color = fdf_get_color(curr->color0, curr->color1, p);
		*(int *)((map->image.mem + ((aux[X] + aux[Y] * WIDTH) * 4))) = color;
	}
}
