/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 18:23:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_mlx_init(t_mlx *mlx)
{
	size_t	i;

	mlx->conn = mlx_init();
	c3d_game_init(&mlx->game, mlx->scene);
	mlx->win = NULL;
	i = 0;
	while (i < N_TEXTURE + 1)
		mlx->img[i++].ptr = NULL;
}

int	c3d_mlx_hook(t_mlx *mlx)
{
	if (mlx->game.key != KEY_NONE)
		c3d_win_draw_vision(mlx);
	mlx->game.key = KEY_NONE;
	return (ERR_NOERR);
}
