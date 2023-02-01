/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/01 17:08:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_wall_count(char **map, t_game *game)
{
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
