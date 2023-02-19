/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_elevation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/19 15:23:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_elevation(t_mlx *mlx, t_coord *pt, int i_col, int tex_id)
{
	t_addr	src;
	t_addr	dst;
	double	dist;

//debug_printf("i_col: %d\t", i_col);
//debug_printf("pt(%3lf, %3lf)\n", pt->x, pt->y);
	dist = ft_math_distance_2d(&mlx->game.coord, pt) \
		* ft_math_cos_deg(mlx->game.fov * i_col / WIDTH_VISION);
	dst.x = i_col + (WIDTH_VISION >> 1);
	dst.y = HEIGHT_VISION * (1 - mlx->game.coord.z \
		- (ft_math_rad2deg(atan((1 - mlx->game.coord.z) / dist))) \
		/ (mlx->game.fov * HEIGHT_VISION / WIDTH_VISION));
	src.x = mlx->img[tex_id].width * (pt->x + pt->y - (int)(pt->x + pt->y));
	src.y = (HEIGHT_VISION >> 1) - dst.y \
		+ HEIGHT_VISION * (ft_math_rad2deg(atan((mlx->game.coord.z) / dist))) \
		/ (mlx->game.fov * HEIGHT_VISION / WIDTH_VISION);
//debug_printf("src(%3ld, %3ld)\t", src.x, src.y);
//debug_printf("dst(%3ld, %3ld)\n", dst.x, dst.y);
	c3d_render_imgline(&mlx->img[IDX_VISION], &mlx->img[tex_id], &dst, &src);
}
