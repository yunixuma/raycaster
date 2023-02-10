/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 17:03:57 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_mlx_init_scale(t_addr *size)
{
	int	scale;

	scale = SIZE_CELL;
	while (scale > 0)
	{
		if (scale * size->x * RATIO_HUD < WIDTH_VISION \
			&& scale * size->y * RATIO_HUD < HEIGHT_VISION)
			return (scale);
		scale--;
	}
	return (1);
}

void	c3d_mlx_init(t_mlx *mlx)
{
	size_t	i;

	mlx->conn = mlx_init();
	c3d_game_init(&mlx->game, mlx->scene);
	mlx->win = NULL;
	i = 0;
	while (i < N_TEXTURE + 1)
		mlx->img[i++].ptr = NULL;
	mlx->scale = c3d_mlx_init_scale(&mlx->scene->size);
}

int	c3d_mlx_hook(t_mlx *mlx)
{
	if (mlx->game.event == EVENT_NONE)
		return (false);
	c3d_win_draw_vision(mlx);
	mlx->game.event = EVENT_NONE;
	return (true);
}
