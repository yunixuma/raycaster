/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_visible.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/23 14:50:40 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_visible(t_mlx *mlx)
{
	t_vec	ray;
	int		i_col;
	double	angle;

	i_col = -(WIDTH_VISION >> 1);
	while (i_col < (WIDTH_VISION >> 1))
	{
//DI(i_col);
//		angle = mlx->game.angle.yaw + mlx->game.fov * i_col / WIDTH_VISION;
		angle = mlx->game.angle.yaw + ft_math_rad2deg(asin(ft_math_sin_deg(mlx->game.fov / 2) * i_col * 2 / WIDTH_VISION));
/*
k sin(a) = i_col
k sin(fov/2) = WIDTH_VISION/2
i_col / sin(a) = WIDTH_VISION/2 / sin(fov/2)
sin(a) = sin(fov/2) * i_col * 2/WIDTH_VISION
a = asin(sin(fov/2) * i_col * 2/WIDTH_VISION)
*/
		ray.dir.x = ft_math_sin_deg(angle);
		ray.dir.y = -ft_math_cos_deg(angle);
		ft_coord_copy(&ray.pos, &mlx->game.coord);
		c3d_render_intersect(mlx, i_col, &ray);
		i_col++;
	}
}
/*
void	c3d_render_visible(t_mlx *mlx)
{
	t_coord	pt;
	int		tex_id;
	ssize_t	i_col;

	pt.z = 1;
	pt.y = 3;
	tex_id = IDX_NORTH;
	i_col = -(WIDTH_VISION >> 1);
	while (i_col < (WIDTH_VISION >> 1))
	{
		pt.x = mlx->game.coord.x + (mlx->game.coord.y - pt.y) \
			* tan(ft_math_deg2rad(mlx->game.fov * i_col / WIDTH_VISION));
//debug_printf("i_col: %ld\tpt.x: %lf\n", i_col, pt.x);
		c3d_render_elevation(mlx, &pt, i_col, tex_id);
		i_col++;
	}
//debug_c3d_img(mlx->img[tex_id], 0);
//debug_c3d_img(mlx->img[IDX_VISION], 0);
}

# define ANGLE_RIGHT		90.
# define mlx->game.fov			90.
# define WIDTH_VISION		720
# define HEIGHT_VISION		480
# define ZERO_VISION		0
# define WIDTH_BLOCK		120
# define HEIGHT_BLOCK		120

void	c3d_render_visible(t_mlx *mlx)
{
	t_addr	src;
	t_addr	dst;
c3d_lst2map_rect_col;
	int		src_id;

	src_id = IDX_NORTH;
	src.x = mlx->img[src_id].width * 0 / 10;
	src.y = mlx->img[src_id].height \
		* HEIGHT_VISION / mlx->img[src_id].height * 7 / 10;
	dst.x = WIDTH_VISION * 4 / 10;
	dst.y = HEIGHT_VISION * 2 / 10;
	i_col = 0;
	while (i_col < mlx->img[src_id].width * 10 / 10)
	{
		c3d_render_imgline(mlx->img, src_id, &dst, &src);
		src.x++;
		dst.x++;
		i_col++;
	}
debug_c3d_img(mlx->img[src_id], 0);
debug_c3d_img(mlx->img[IDX_VISION], 0);
}
*/