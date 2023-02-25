/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_clickhook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/25 18:23:25 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	c3d_game_clickhook_turn(t_angle *turn, int button, \
	t_addr *cursor, double fov)
{
	if (button != BUTTON_FOCUS)
		return (false);
	turn->yaw = fov * (cursor->x - (WIDTH_VISION >> 1)) / WIDTH_VISION;
DD(turn->yaw);
	turn->pitch = fov * ((HEIGHT_VISION >> 1) - cursor->y) / WIDTH_VISION;
DD(turn->pitch);
	if (turn->yaw == 0 && turn->pitch == 0)
		return (false);
	return (true);
}

static bool	c3d_game_clickhook_zoom(t_angle *turn, int button, int speed)
{
	turn->roll = 0;
	if (button == BUTTON_WIDE)
		turn->roll = UNIT_TURN * speed;
	else if (button == BUTTON_TELE)
		turn->roll = -UNIT_TURN * speed;
	else
		return (false);
	return (true);
}

/*
int	c3d_game_clickhook_up(int button, int x, int y, t_mlx *mlx)
{
debug_printf("up\tcursor(%d, %d)\tbutton: %d\n", x, y, button);
	mlx->game.cursor.x = x;
	mlx->game.cursor.y = y;
	mlx->game.event &= ~FLAG_CLICK;
	return (ERR_NOERR);
}
*/

int	c3d_game_clickhook(int button, int x, int y, t_mlx *mlx)
{
	t_angle	turn;
	t_addr	cursor;
	int		speed;

	ft_addr_set(&cursor, x, y);
debug_printf("down\tcursor(%d, %d)\tbutton: %d\n", x, y, button);
	if (c3d_game_clickhook_turn(&turn, button, &cursor, mlx->game.fov))
		c3d_game_turn(mlx, &turn);
	else if (c3d_game_clickhook_zoom(&turn, button, mlx->game.speed))
		c3d_game_zoom(mlx, turn.roll);
	else if (c3d_game_speed(&speed, button, mlx->game.speed))
		mlx->game.speed = speed;
	mlx->game.cursor.x = x;
	mlx->game.cursor.y = y;
	if (button == BUTTON_FOCUS || button == BUTTON_SPEED \
		|| button == BUTTON_WIDE || button == BUTTON_TELE)
		mlx->game.event |= FLAG_CLICK;
	else if (button == BUTTON_CURSOR)
	{
		if (ft_hasflag(mlx->game.event, FLAG_CURSOR))
			mlx->game.event &= ~FLAG_CURSOR;
		else
			mlx->game.event |= FLAG_CURSOR;
	}
	return (true);
}
