/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_keyhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/24 23:49:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	c3d_game_keyhook_speed(int *new, int key, int old)
{
	if (key != KEY_SPEED)
		return (false);
	if (old == SPEED_FAST)
		*new = SPEED_SLOW;
	else
		*new = SPEED_FAST;
DI(*new);
	return (true);
}

int	c3d_game_keyhook_down(int key, t_mlx *mlx)
{
//debug_printf("key: %04x\n", key);
	mlx->game.key = key;
	mlx->game.event |= FLAG_KEY;
	return (true);
}

int	c3d_game_keyhook_up(int key, t_mlx *mlx)
{
	int		speed;

	if (key == KEY_EXIT_1 || key == KEY_EXIT_2)
		return (c3d_exit_mlx_break(mlx));
	else if (key == KEY_CURSOR)
	{
		if (ft_hasflag(mlx->game.event, FLAG_CURSOR))
			mlx->game.event &= ~FLAG_CURSOR;
		else
			mlx->game.event |= FLAG_CURSOR;
	}
	else if (c3d_game_keyhook_speed(&speed, key, mlx->game.speed))
		mlx->game.speed = speed;
	if (key != mlx->game.key)
		return (false);
	mlx->game.key = KEY_NONE;
	mlx->game.event &= ~FLAG_KEY;
	return (true);
}
