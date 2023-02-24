/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_turn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/24 14:47:43 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	c3d_game_turn_adjust(t_angle *angle, int speed)
{
	double	right;

	if (angle->pitch < UNIT_TURN * speed && angle->pitch > -UNIT_TURN * speed)
		angle->pitch = 0;
	right = -ANGLE_RIGHT * 2;
	while (right <= ANGLE_RIGHT * 2)
	{
		if (angle->yaw < right + UNIT_TURN * speed \
			&& angle->yaw > right - UNIT_TURN * speed)
			angle->yaw = right;
		right += ANGLE_RIGHT;
	}
}

bool	c3d_game_turn(t_mlx *mlx, t_angle *turn)
{
	t_angle	bak;

	bak.yaw = mlx->game.angle.yaw;
	bak.pitch = mlx->game.angle.pitch;
	mlx->game.angle.yaw \
		= ft_math_angle_normalize(mlx->game.angle.yaw + turn->yaw);
	mlx->game.angle.pitch += turn->pitch;
	if (mlx->game.angle.pitch > ANGLE_RIGHT - UNIT_TURN)
		mlx->game.angle.pitch = ANGLE_RIGHT - UNIT_TURN;
	else if (mlx->game.angle.pitch < -(ANGLE_RIGHT - UNIT_TURN))
		mlx->game.angle.pitch = -(ANGLE_RIGHT - UNIT_TURN);
	c3d_game_turn_adjust(&mlx->game.angle, mlx->game.speed);
	if (mlx->game.angle.yaw == bak.yaw && mlx->game.angle.pitch == bak.pitch)
		return (false);
debug_printf("turn: (%6.3lf, %6.3lf)\n", turn->yaw, turn->pitch);
debug_printf("angle: (y%6.3lf, p%6.3lf)\n", mlx->game.angle.yaw, mlx->game.angle.pitch);
	return (true);
}
