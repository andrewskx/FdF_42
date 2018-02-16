/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboscan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 15:41:43 by anboscan          #+#    #+#             */
/*   Updated: 2018/02/16 15:39:57 by anboscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>
# define WIDTH 1200
# define HEIGHT 800

typedef	struct		s_image
{
	void	*img_ptr;
	char	*mem;
	int		bpp;
	int		s_line;
	int		endian;
}					t_image;

typedef struct		s_vector
{
	int x0;
	int y0;
	int x1;
	int y1;
	int z0;
	int z1;
	int color0;
	int color1;
}					t_vector;

typedef struct		s_coord
{
	int x;
	int y;
	int z;
	int color;
}					t_coord;

typedef	struct		s_map
{
	t_coord		**map;
	t_vector	**vec_map;
	t_image		image;
	void		*mlx_ptr;
	void		*win_ptr;
	int			axe_key;
	int			columns;
	int			rows;
	int			offset_x;
	int			offset_y;
	int			last_x;
	int			last_y;
	int			button;
	int			reverse;
	float		step;
	float		angle_x;
	float		angle_y;
	float		angle_z;
}					t_map;

extern inline void	fdf_rotate_x(t_vector *vector, t_coord *p1,
					t_coord *p2, t_map *map);
extern inline void	fdf_rotate_y(t_vector *vector, t_coord *p1,
					t_coord *p2, t_map *map);
extern inline void	fdf_rotate_z(t_vector *vector, t_map *map);
void				fdf_new_image(t_map *map);
int					fdf_motion_hook(int x, int y, t_map *map);
int					fdf_button_release_hook(int button, int x,
					int y, t_map *map);
int					fdf_mouse_hook(int button, int x, int y, t_map *map);
int					fdf_key(int key, t_map *map);
void				fdf_scale(t_vector *vector, t_map *map);
void				fdf_rotate(t_vector *vector, t_coord *p1,
					t_coord *p2, t_map *map);
void				ft_free_double_char(char **str);
void				ft_del_lst(void *content, size_t content_size);
void				fdf_error(char const *str);
void				fdf_map_deallocate(t_map *map);
void				fdf_map_allocate(t_map *map);
void				fdf_validate_line(t_list *start, char *str);
void				fdf_read_to_map(char *file, t_map *map);
void				fdf_validation_final_step(t_list *start, t_map *map);
void				fdf_move_to_origin(t_map *map);
void				fdf_fill_map(t_list *start, t_map *map,
					int rows, int columns);
t_list				*fdf_validation_first_step(char *file, t_map *map);
void				fdf_put_line(t_vector *vector, t_map *map);
void				fdf_draw(t_map *map, int i, int j);
void				fdf_set_pixel(int *aux, t_vector *curr, t_map *map);
int					fdf_get_color(int c1, int c2, double p);
double				fdf_get_percent(double val, double first, double second);
int					fdf_get_gradient(int first, int second, double p);
void				fdf_image_create(t_map *map);
#endif
