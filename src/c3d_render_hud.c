/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_hud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/19 22:12:24 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	c3d_render_hud_position(t_img *img, t_game *game, int scale)
{
	t_addr	zero;
	t_addr	area;

	if (scale > SIZE_CELL / 2)
		ft_addr_set(&area, scale >> 1, scale >> 1);
	else
		ft_addr_set(&area, SIZE_CELL / 4, SIZE_CELL / 4);
	zero.x = (ssize_t)(game->coord.x * scale) + WEIGHT_FRAME - (area.x >> 1);
	zero.y = (ssize_t)(game->coord.y * scale) + WEIGHT_FRAME - (area.y >> 1);
	c3d_render_rectangle(img, COLOR_POS, &zero, &area);
}

static void	c3d_render_hud_direction(t_img *img, t_game *game, int scale)
{
	t_addr	zero;
	t_coord	line;

	line.x = sin(ft_math_deg2rad(game->angle.yaw));
	line.y = -cos(ft_math_deg2rad(game->angle.yaw));
	line.z = LEN_POS * scale;
	if (line.z > SIZE_CELL)
		line.z = SIZE_CELL;
	zero.x = (ssize_t)(game->coord.x * scale) + WEIGHT_FRAME;
	zero.y = (ssize_t)(game->coord.y * scale) + WEIGHT_FRAME;
	c3d_render_line(img, COLOR_POS, &zero, &line);
}

void	c3d_render_hud(t_mlx *mlx)
{
	t_addr	zero;

	zero.x = 0;
	zero.y = 0;
	c3d_render_blend(&mlx->img[IDX_VISION], &mlx->img[IDX_HUD], &zero);
	c3d_render_hud_position(&mlx->img[IDX_VISION], &mlx->game, mlx->scale);
	c3d_render_hud_direction(&mlx->img[IDX_VISION], &mlx->game, mlx->scale);
}
