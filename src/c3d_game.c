/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/19 15:42:16 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	c3d_game_move_valid(char **map, t_coord *move, t_coord *pos)
{
	char	testcell;

debug_printf("move: (%6.3lf, %6.3lf)\n", move->x, move->y);
	testcell = map[(size_t)(pos->y + move->y)][(size_t)(pos->x)];
	if (testcell == FLAG_SPACE || ft_hasflag(testcell, FLAG_WALL))
		move->y = 0;
	testcell = map[(size_t)(pos->y)][(size_t)(pos->x + move->x)];
	if (testcell == FLAG_SPACE || ft_hasflag(testcell, FLAG_WALL))
		move->x = 0;
	if (move->x == 0 && move->y == 0)
		return (false);
	return (true);
}

bool	c3d_game_move(t_mlx *mlx, t_coord *move)
{
	if (!c3d_game_move_valid(mlx->scene->map, move, &mlx->game.coord))
		return (false);
	mlx->game.coord.y += move->y;
	mlx->game.coord.x += move->x;
	return (true);
}

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
	if (mlx->game.angle.pitch > (ANGLE_RIGHT - UNIT_TURN * mlx->game.speed))
		mlx->game.angle.pitch = (ANGLE_RIGHT - UNIT_TURN * mlx->game.speed);
	else if (mlx->game.angle.pitch \
		< -(ANGLE_RIGHT - UNIT_TURN * mlx->game.speed))
		mlx->game.angle.pitch = -(ANGLE_RIGHT - UNIT_TURN * mlx->game.speed);
	c3d_game_turn_adjust(&mlx->game.angle, mlx->game.speed);
	if (mlx->game.angle.yaw == bak.yaw && mlx->game.angle.pitch == bak.pitch)
		return (false);
debug_printf("angle: (%6.3lf, %6.3lf)\n", mlx->game.angle.yaw, mlx->game.angle.pitch);
	return (true);
}

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