/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/20 01:11:02 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	c3d_game_lens(t_mlx *mlx, double fov_add)
{
	double	fov_bak;

	fov_bak = mlx->game.fov;
	mlx->game.fov += fov_add;
	if (mlx->game.fov > ANGLE_FOV_MAX)
		mlx->game.fov = ANGLE_FOV_MAX;
	else if (mlx->game.fov < ANGLE_FOV_MIN)
		mlx->game.fov = ANGLE_FOV_MIN;
	if (mlx->game.fov == fov_bak)
		return (false);
	return (true);
}
/*
bool	c3d_game_judge(t_mlx *mlx)
{
	if (mlx->scene->map[(size_t)mlx->game.coord.y][(size_t)mlx->game.coord.x] \
		!= CHRS_MAP[IDX_SOUTH])
		return (false);
	else if (ft_mapseek_exist(mlx->scene->map, CHRS_MAP[IDX_EAST]))
		return (false);
	return (true);
}
*/