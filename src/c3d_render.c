/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 09:04:05 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_rectangle(t_img *img, \
	t_addr *zero, t_addr *area, int color_code)
{
	ssize_t	i_col;
	ssize_t	i_row;

	i_row = 0;
	while (i_row < area->y)
	{
		i_col = 0;
		while (i_col < area->x)
		{
			img->data[img->width * (zero->y + i_row) + zero->x + i_col] \
				= color_code;
			i_col++;
		}
		i_row++;
	}
}

void	c3d_render_background(t_mlx *mlx)
{
	t_addr	zero;
	t_addr	area;

	zero.x = ZERO_VISION;
	zero.y = ZERO_VISION;
	area.x = WIDTH_VISION;
	area.y = HEIGHT_VISION \
		* (ANGLE_VISION + mlx->game.angle.yaw) / ANGLE_VISION / 2;
	if (area.y < 0)
		area.y = 0;
	else if (area.y > HEIGHT_VISION)
		area.y = HEIGHT_VISION;
	c3d_render_rectangle(&mlx->img[IDX_VISION], \
		&zero, &area, mlx->scene->color[IDX_CEILING]);
	zero.y = area.y;
	area.y = HEIGHT_VISION - zero.y;
	c3d_render_rectangle(&mlx->img[IDX_VISION], \
		&zero, &area, mlx->scene->color[IDX_FLOOR]);
}

void	c3d_render_visible(t_mlx *mlx)
{
	t_addr	zero;
	t_addr	area;

	zero.x = ZERO_VISION;
	zero.y = ZERO_VISION;
	area.x = WIDTH_VISION;
	area.y = HEIGHT_VISION \
		* (ANGLE_VISION + mlx->game.angle.yaw) / ANGLE_VISION / 2;
	if (area.y < 0)
		area.y = 0;
	else if (area.y > HEIGHT_VISION)
		area.y = HEIGHT_VISION;
	c3d_render_rectangle(&mlx->img[IDX_VISION], \
		&zero, &area, mlx->scene->color[IDX_CEILING]);
	zero.y = area.y;
	area.y = HEIGHT_VISION - zero.y;
	c3d_render_rectangle(&mlx->img[IDX_VISION], \
		&zero, &area, mlx->scene->color[IDX_FLOOR]);
}
