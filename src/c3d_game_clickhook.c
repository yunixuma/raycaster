/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_clickhook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/11 04:47:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_game_clickhook_turn(t_angle *turn, t_addr *cursor, double fov)
{
	turn->yaw = fov * ((WIDTH_VISION >> 1) - cursor->x) / WIDTH_VISION;
DD(turn->yaw);
	turn->pitch = fov * ((HEIGHT_VISION >> 1) - cursor->y) / WIDTH_VISION;
DD(turn->pitch);
	if (turn->yaw == 0 && turn->pitch == 0)
		return (false);
	return (true);
}

int	c3d_game_clickhook(int button, int x, int y, t_mlx *mlx)
{
	t_angle	turn;
	t_addr	cursor;

	ft_addr_set(&cursor, x, y);
debug_printf("cursor(%d, %d)\tbutton: %d\n", x, y, button);
	if (c3d_game_clickhook_turn(&turn, &cursor, mlx->game.fov))
		c3d_game_turn(mlx, &turn);
	mlx->game.cursor.x = x;
	mlx->game.cursor.y = y;
	mlx->game.event = EVENT_MOUSEPRESS;
	return (ERR_NOERR);
}
