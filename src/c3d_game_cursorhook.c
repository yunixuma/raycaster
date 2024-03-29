/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_cursorhook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/19 22:00:08 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
static bool	c3d_game_cursorhook_turn(t_angle *turn, int x, int y)
{
	turn->yaw = 0;
	turn->pitch = 0;

	if (x < WIDTH_VISION / 2 - (HEIGHT_VISION >> 2))
		turn->yaw = -UNIT_TURN;
	else if (x > WIDTH_VISION / 2 + (HEIGHT_VISION >> 2))
		turn->yaw = UNIT_TURN;
	if (y < HEIGHT_VISION / 2 - (HEIGHT_VISION >> 2))
		turn->pitch = -UNIT_TURN;
	else if (y > HEIGHT_VISION / 2 + (HEIGHT_VISION >> 2))
		turn->pitch = UNIT_TURN;
	if (turn->yaw == 0 && turn->pitch == 0)
		return (false);
	return (true);
}
*/
static bool	c3d_game_cursorhook_turn(t_angle *turn, \
	t_addr *new, t_addr *old, int speed)
{
	turn->yaw = 0;
	turn->pitch = 0;
	if (new->x < old->x)
		turn->yaw = -UNIT_TURN * speed;
	else if (new->x > old->x && old->x > VAL_INVAL)
		turn->yaw = UNIT_TURN * speed;
	if (new->y < old->y)
		turn->pitch = UNIT_TURN * speed;
	else if (new->y > old->y && old->y > VAL_INVAL)
		turn->pitch = -UNIT_TURN * speed;
	if (turn->yaw == 0 && turn->pitch == 0)
		return (false);
	return (true);
}

int	c3d_game_cursorhook(int x, int y, t_mlx *mlx)
{
	t_angle	turn;
	t_addr	new;

	if (!ft_hasflag(mlx->game.event, FLAG_CURSOR))
		return (false);
//debug_printf("cursor(%d, %d)\n", x, y);
	ft_addr_set(&new, x, y);
	if (c3d_game_cursorhook_turn(&turn, \
		&new, &mlx->game.cursor, mlx->game.speed) \
		&& c3d_game_turn(mlx, &turn))
		mlx->game.event |= FLAG_PROMPT | FLAG_DRAW;
	mlx->game.cursor.x = x;
	mlx->game.cursor.y = y;
	return (true);
}
