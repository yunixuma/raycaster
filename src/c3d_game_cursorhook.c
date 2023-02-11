/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_cursorhook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/11 12:54:42 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
static int	c3d_game_cursorhook_turn(t_angle *turn, int x, int y)
{
	turn->yaw = 0;
	turn->pitch = 0;

	if (x < (WIDTH_VISION >> 1) - (HEIGHT_VISION >> 2))
		turn->yaw = -UNIT_TURN;
	else if (x > (WIDTH_VISION >> 1) + (HEIGHT_VISION >> 2))
		turn->yaw = UNIT_TURN;
	if (y < (HEIGHT_VISION >> 1) - (HEIGHT_VISION >> 2))
		turn->pitch = -UNIT_TURN;
	else if (y > (HEIGHT_VISION >> 1) + (HEIGHT_VISION >> 2))
		turn->pitch = UNIT_TURN;
	if (turn->yaw == 0 && turn->pitch == 0)
		return (false);
	return (true);
}
*/
static int	c3d_game_cursorhook_turn(t_angle *turn, int x, int y, t_addr *prev)
{
	turn->yaw = 0;
	turn->pitch = 0;

	if (x < prev->x)
		turn->yaw = UNIT_TURN;
	else if (x > prev->x && prev->x > VAL_INVAL)
		turn->yaw = -UNIT_TURN;
	if (y < prev->y)
		turn->pitch = UNIT_TURN;
	else if (y > prev->y && prev->y > VAL_INVAL)
		turn->pitch = -UNIT_TURN;
	if (turn->yaw == 0 && turn->pitch == 0)
		return (false);
	return (true);
}

int	c3d_game_cursorhook(int x, int y, t_mlx *mlx)
{
	t_angle	turn;

	if (!ft_hasflag(mlx->game.event, FLAG_CURSOR))
		return (false);
//debug_printf("cursor(%d, %d)\n", x, y);
	if (c3d_game_cursorhook_turn(&turn, x, y, &mlx->game.cursor))
		c3d_game_turn(mlx, &turn);
	mlx->game.cursor.x = x;
	mlx->game.cursor.y = y;
	return (c3d_mlx_hook(mlx));
}
