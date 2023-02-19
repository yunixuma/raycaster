/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_keyhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/16 19:04:24 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	c3d_game_keyhook_move(t_coord *move, int key, \
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
	move->x = UNIT_MOVE * speed * ft_math_sin_deg(angle);
	move->y = UNIT_MOVE * speed * -ft_math_cos_deg(angle);
	return (true);
}

static bool	c3d_game_keyhook_turn(t_angle *turn, int key, int speed)
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

static bool	c3d_game_keyhook_lens(t_angle *turn, int key, int speed)
{
	turn->roll = 0;
	if (key == KEY_WIDE)
		turn->roll = -UNIT_TURN * speed;
	else if (key == KEY_TELE)
		turn->roll = UNIT_TURN * speed;
	else
		return (false);
	return (true);
}

int	c3d_game_keyhook(int key, t_mlx *mlx)
{
	t_angle	turn;
	t_coord	move;

	if (key == KEY_EXIT_1 || key == KEY_EXIT_2)
		return (c3d_exit_mlx_break(mlx));
	if (c3d_game_keyhook_turn(&turn, key, mlx->game.speed))
		c3d_game_turn(mlx, &turn);
	else if (c3d_game_keyhook_move(&move, key, \
		mlx->game.angle.yaw, mlx->game.speed) \
		&& c3d_game_move(mlx, &move))
		c3d_print_score(++(mlx->game.score));
	else if (c3d_game_keyhook_lens(&turn, key, mlx->game.speed))
		c3d_game_lens(mlx, turn.roll);
	if (c3d_game_judge(mlx))
		c3d_exit_mlx_goal(mlx);
	mlx->game.event |= FLAG_KEY;
	return (c3d_mlx_hook(mlx));
}
