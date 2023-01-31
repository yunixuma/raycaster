/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_keyhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/30 13:35:09 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_game_keyhook_move(t_coord *move, int key)
{
	move->x = 0;
	move->y = 0;
	if (key == KEY_MOVELEFT)
		move->x -= UNIT_MOVE;
	else if (key == KEY_MOVERIGHT)
		move->x += UNIT_MOVE;
	else if (key == KEY_FORWARD)
		move->y -= UNIT_MOVE;
	else if (key == KEY_BACKWARD)
		move->y += UNIT_MOVE;
	if (move->x || move->y)
		return (true);
	return (false);
}

static int	c3d_game_keyhook_turn(t_angle *turn, int key)
{
	turn->pitch = 0;
	turn->yaw = 0;
	if (key == KEY_TURNLEFT)
		turn->pitch -= UNIT_TURN;
	else if (key == KEY_TURNRIGHT)
		turn->pitch += UNIT_TURN;
	else if (key == KEY_LOOKDOWN)
		turn->yaw -= UNIT_TURN;
	else if (key == KEY_LOOKUP)
		turn->yaw += UNIT_TURN;
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
	else if (c3d_game_keyhook_move(&move, key) && c3d_game_move(mlx, &move))
		c3d_print_score(++(mlx->game.score));
	if (c3d_game_judge(mlx))
		c3d_exit_mlx_goal(ERR_NOERR, mlx);
	mlx->game.key = key;
	return (ERR_NOERR);
}
