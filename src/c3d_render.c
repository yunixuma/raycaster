/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/08 14:41:47 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_background(t_mlx *mlx)
{
	t_addr	zero;
	t_addr	area;

	zero.x = ZERO_VISION;
	zero.y = ZERO_VISION;
	area.x = WIDTH_VISION;
	area.y = HEIGHT_VISION \
		* (ANGLE_FOV + mlx->game.angle.pitch) / ANGLE_FOV / 2;
	if (area.y < 0)
		area.y = 0;
	else if (area.y > HEIGHT_VISION)
		area.y = HEIGHT_VISION;
	c3d_render_rectangle(&mlx->img[IDX_VISION], \
		mlx->scene->color[IDX_CEILING], &zero, &area);
	zero.y = area.y;
	area.y = HEIGHT_VISION - zero.y;
	c3d_render_rectangle(&mlx->img[IDX_VISION], \
		mlx->scene->color[IDX_FLOOR], &zero, &area);
}

static void	c3d_render_elevation(t_mlx *mlx, t_coord *pt, int i_col, int tex_id)
{
	t_addr	src;
	t_addr	dst;
	double	dist;

	dist = ft_math_distance_2d(&mlx->game.coord, pt);
	dst.x = i_col;
	dst.y = HEIGHT_VISION * (1 - mlx->game.coord.z \
		- (ft_math_rad2deg(atan((1 - mlx->game.coord.z) / dist))) \
		/ (ANGLE_FOV * HEIGHT_VISION / WIDTH_VISION));
	src.x = mlx->img[tex_id].width * (pt->x + pt->y - (int)(pt->x + pt->y));
	src.y = (HEIGHT_VISION >> 1) - dst.y \
		+ HEIGHT_VISION * (ft_math_rad2deg(atan((mlx->game.coord.z) / dist))) \
		/ (ANGLE_FOV * HEIGHT_VISION / WIDTH_VISION);
debug_printf("pt(%3lf, %3lf)\t", pt->x, pt->y);
debug_printf("src(%3ld, %3ld)\t", src.x, src.y);
debug_printf("dst(%3ld, %3ld)\n", dst.x, dst.y);
	c3d_render_imgline(mlx->img, tex_id, &dst, &src);
}

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
			* tan(ft_math_deg2rad(ANGLE_FOV * i_col / WIDTH_VISION));
//debug_printf("i_col: %ld\tpt.x: %lf\n", i_col, pt.x);
		c3d_render_elevation(mlx, &pt, i_col + (WIDTH_VISION >> 1), tex_id);
		i_col++;
	}
//debug_c3d_img(mlx->img[tex_id], 0);
//debug_c3d_img(mlx->img[IDX_VISION], 0);
}
/*
# define ANGLE_RIGHT		90.
# define ANGLE_FOV		45.
# define WIDTH_VISION		720
# define HEIGHT_VISION		480
# define ZERO_VISION		0
# define WIDTH_BLOCK		120
# define HEIGHT_BLOCK		120

void	c3d_render_visible(t_mlx *mlx)
{
	t_addr	src;
	t_addr	dst;
	ssize_t	i_col;
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