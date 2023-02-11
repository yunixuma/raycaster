/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/11 17:36:42 by Yoshihiro K      ###   ########.fr       */
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
		* (mlx->game.fov + mlx->game.angle.pitch) / mlx->game.fov / 2;
//	area.y = HEIGHT_VISION * (mlx->game.angle.pitch + mlx->game.fov * HEIGHT_VISION / WIDTH_VISION / 2) / (mlx->game.fov * HEIGHT_VISION / WIDTH_VISION);
	area.y = (mlx->game.angle.pitch * WIDTH_VISION \
		+ mlx->game.fov * HEIGHT_VISION / 2) / (mlx->game.fov);
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
