/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:17:37 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/16 15:18:03 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_image_create(t_map *map)
{
	map->image.img_ptr = mlx_new_image(map->mlx_ptr, WIDTH, HEIGHT);
	map->image.mem = mlx_get_data_addr(map->image.img_ptr,
			&map->image.bpp,
			&map->image.s_line,
			&map->image.endian);
	ft_bzero(map->image.mem, WIDTH * HEIGHT);
}
