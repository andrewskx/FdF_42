/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:30:30 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/12 17:34:58 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_instruction(void)
{
	ft_putstr("\nWelcome here\n\
			\n1.Rotate towards X -> push x\
			\n2.Rotate towards Y -> push y\
			\n3.Rotate towards Z -> push z\
			\n4.Reverse direction -> push r\
			\n5.Zoom In -> right click && drag pointer down\
			\n6.Zoom Out -> right click && drag pointer up\
			\n7.Exit -> push ESC\n");
}

int		main(int arg, char **argv)
{
	t_map	map;

	if (arg != 2)
		fdf_error("No arguments provided");
	fdf_read_to_map(argv[1], &map);
	fdf_instruction();
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr, WIDTH, HEIGHT, argv[1]);
	fdf_draw(&map);
	mlx_hook(map.win_ptr, 2, 0, fdf_key, &map);
	mlx_hook(map.win_ptr, 4, 0, fdf_mouse_hook, &map);
	mlx_hook(map.win_ptr, 5, 0, fdf_button_release_hook, &map);
	mlx_hook(map.win_ptr, 6, 0, fdf_motion_hook, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
