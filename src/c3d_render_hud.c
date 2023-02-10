/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_hud.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 17:01:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	c3d_render_hud_pos(t_img *img, t_coord *coord, int scale)
{
	t_addr	zero;
	t_addr	area;

	if (scale > (SIZE_CELL >> 1))
		ft_addr_set(&area, scale >> 1, scale >> 1);
	else
		ft_addr_set(&area, SIZE_CELL >> 2, SIZE_CELL >> 2);
	zero.x = (ssize_t)(coord->x * scale) + WEIGHT_FRAME - (area.x >> 1);
	zero.y = (ssize_t)(coord->y * scale) + WEIGHT_FRAME - (area.y >> 1);
	c3d_render_rectangle(img, COLOR_POS, &zero, &area);
}

void	c3d_render_hud(t_mlx *mlx)
{
	t_addr	zero;

	zero.x = 0;
	zero.y = 0;
	c3d_render_blend(&mlx->img[IDX_VISION], &mlx->img[IDX_HUD], &zero);
	c3d_render_hud_pos(&mlx->img[IDX_VISION], &mlx->game.coord, mlx->scale);
}
