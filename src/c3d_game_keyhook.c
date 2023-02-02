/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_keyhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/02 10:33:16 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_game_keyhook_move(t_coord *move, int key, double angle)
{
	if (key == KEY_MOVELEFT)
		angle += ANGLE_RIGHT * 3;
	else if (key == KEY_MOVERIGHT)
		angle += ANGLE_RIGHT;
	else if (key == KEY_BACKWARD)
		angle += ANGLE_RIGHT;
	else if (key != KEY_FORWARD)
		return (false);
	move->x = UNIT_MOVE * sin(ft_math_deg2rad(angle));
	move->y = UNIT_MOVE * cos(ft_math_deg2rad(angle));
	return (true);
}

static int	c3d_game_keyhook_turn(t_angle *turn, int key)
{
	turn->pitch = 0;
	turn->yaw = 0;
	if (key == KEY_TURNLEFT)
		turn->pitch = -UNIT_TURN;
	else if (key == KEY_TURNRIGHT)
		turn->pitch = UNIT_TURN;
	else if (key == KEY_LOOKDOWN)
		turn->yaw = -UNIT_TURN;
	else if (key == KEY_LOOKUP)
		turn->yaw = UNIT_TURN;
	if (turn->pitch || turn->yaw)
		return (true);
	return (false);
}

int	c3d_game_keyhook(int key, t_mlx *mlx)
{
	t_angle	turn;
	t_coord	move;

	if (key == KEY_EXIT_1 || key == KEY_EXIT_2)
		return (c3d_exit_mlx_break(mlx));
	if (c3d_game_keyhook_turn(&turn, key))
		c3d_game_turn(mlx, &turn);
	else if (c3d_game_keyhook_move(&move, key, mlx->game.angle.pitch) \
		&& c3d_game_move(mlx, &move))
		c3d_print_score(++(mlx->game.score));
	if (c3d_game_judge(mlx))
		c3d_exit_mlx_goal(ERR_NOERR, mlx);
	mlx->game.key = key;
	return (ERR_NOERR);
}
