/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_cursorhook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/09 03:08:30 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_game_cursorhook_turn(t_angle *turn, int x, int y)
{
	turn->yaw = 0;
	turn->pitch = 0;

	if (x < (WIDTH_VISION >> 1) - (HEIGHT_VISION >> 2))
		turn->pitch = -UNIT_TURN;
	else if (x > (WIDTH_VISION >> 1) + (HEIGHT_VISION >> 2))
		turn->pitch = UNIT_TURN;
	if (y < (HEIGHT_VISION >> 1) - (HEIGHT_VISION >> 2))
		turn->yaw = -UNIT_TURN;
	else if (y > (HEIGHT_VISION >> 1) + (HEIGHT_VISION >> 2))
		turn->yaw = UNIT_TURN;
	if (turn->yaw == 0 && turn->pitch == 0)
		return (false);
	return (true);
}

int	c3d_game_cursorhook(int x, int y, t_mlx *mlx)
{
	t_angle	turn;

debug_printf("cursor(%d, %d)\n", x, y);
	if (c3d_game_cursorhook_turn(&turn, x, y))
		c3d_game_turn(mlx, &turn);
	return (ERR_NOERR);
}
