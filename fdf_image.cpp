#include "fdf.h"

void	fdf_new_image(t_map *map)
{
	map->image.img_ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->image.img_data = mlx_get_data_addr(map->image.img_ptr,
			&(map->image.bits_per_pixel),
			&(map->image.size_line),
			&(map->image.endian));
	map->image.bits_per_pixel /= 8;
	ft_putstr("Succes\n");
	if (map->image.img_data == 0)
		ft_putstr("Something went wrong\n");
	ft_putstr(map->image.img_data);	
	printf("\nsize = %i, bpp = %i", map->image.size_line, map->image.bits_per_pixel);
}
