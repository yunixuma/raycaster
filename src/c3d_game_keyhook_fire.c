/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_keyhook_fire.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/27 05:45:14 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	c3d_game_keyhook_fire_move(t_coord *move, int key, \
	double angle, int speed)
{
	if (key == KEY_MOVELEFT)
		angle += ANGLE_RIGHT * 3;
	else if (key == KEY_MOVERIGHT)
		angle += ANGLE_RIGHT * 1;
	else if (key == KEY_BACKWARD)
		angle += ANGLE_RIGHT * 2;
	else if (key != KEY_FORWARD)
		return (false);
	move->x = UNIT_MOVE * speed * sin(ft_math_deg2rad(angle));
	move->y = UNIT_MOVE * speed * -cos(ft_math_deg2rad(angle));
	return (true);
}

static bool	c3d_game_keyhook_fire_turn(t_angle *turn, int key, int speed)
{
	turn->yaw = 0;
	turn->pitch = 0;
	if (key == KEY_TURNLEFT)
		turn->yaw = -UNIT_TURN * speed;
	else if (key == KEY_TURNRIGHT)
		turn->yaw = UNIT_TURN * speed;
	else if (key == KEY_LOOKUP)
		turn->pitch = UNIT_TURN * speed;
	else if (key == KEY_LOOKDOWN)
		turn->pitch = -UNIT_TURN * speed;
	else
		return (false);
	return (true);
}

static bool	c3d_game_keyhook_fire_zoom(t_angle *turn, int key, int speed)
{
	turn->roll = 0;
	if (key == KEY_WIDE)
		turn->roll = UNIT_TURN * speed;
	else if (key == KEY_TELE)
		turn->roll = -UNIT_TURN * speed;
	else
		return (false);
	return (true);
}

int	c3d_game_keyhook_fire(int key, t_mlx *mlx)
{
	t_angle	turn;
	t_coord	move;

	if (!ft_hasflag(mlx->game.event, FLAG_KEY))
		return (false);
	if (c3d_game_keyhook_fire_turn(&turn, key, mlx->game.speed) \
		&& c3d_game_turn(mlx, &turn))
		mlx->game.event |= FLAG_DRAW | FLAG_PROMPT;
	else if (c3d_game_keyhook_fire_move(&move, key, \
		mlx->game.angle.yaw, mlx->game.speed) \
		&& c3d_game_move(mlx, &move))
		mlx->game.event |= FLAG_DRAW | FLAG_PROMPT;
//		c3d_print_score(++(mlx->game.score));
	else if (c3d_game_keyhook_fire_zoom(&turn, key, mlx->game.speed) \
		&& c3d_game_zoom(&mlx->game, turn.roll))
		mlx->game.event |= FLAG_DRAW | FLAG_PROMPT;
//	if (c3d_game_judge(mlx))
//		c3d_exit_mlx_goal(mlx);
	return (true);
}
