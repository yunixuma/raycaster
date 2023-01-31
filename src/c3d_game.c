/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 16:30:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_game_move(t_mlx *mlx, t_coord *move)
{
	char	newcell;

	newcell = mlx->scene->map[(int)(mlx->game.coord.y + move->y)] \
		[(int)(mlx->game.coord.x + move->x)];
	if (newcell == FLAG_WALL || newcell == FLAG_SPACE)
		return (false);
	mlx->game.coord.y += move->y;
	mlx->game.coord.x += move->x;
	return (true);
}

int	c3d_game_turn(t_mlx *mlx, t_angle *turn)
{
	t_angle	bak;

	bak.pitch = mlx->game.angle.pitch;
	bak.yaw = mlx->game.angle.yaw;
	mlx->game.angle.pitch \
		= ft_math_angle_normalize(mlx->game.angle.pitch + turn->pitch);
	mlx->game.angle.yaw += turn->yaw;
	if (mlx->game.angle.yaw > (ANGLE_RIGHT - UNIT_TURN))
		mlx->game.angle.yaw = (ANGLE_RIGHT - UNIT_TURN);
	else if (mlx->game.angle.yaw < -(ANGLE_RIGHT - UNIT_TURN))
		mlx->game.angle.yaw = -(ANGLE_RIGHT - UNIT_TURN);
	if (mlx->game.angle.pitch == bak.pitch && mlx->game.angle.yaw == bak.yaw)
		return (false);
	return (true);
}

int	c3d_game_judge(t_mlx *mlx)
{
	if (mlx->scene->map[(int)mlx->game.coord.y][(int)mlx->game.coord.x] \
		!= CHRS_MAP[IDX_SOUTH])
		return (false);
	else if (ft_mapseek_exist(mlx->scene->map, CHRS_MAP[IDX_EAST]))
		return (false);
	return (true);
}
