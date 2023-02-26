/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_keyhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/27 05:44:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_game_keyhook_down(int key, t_mlx *mlx)
{
//debug_printf("key: %04x\n", key);
	mlx->game.key = key;
	mlx->game.event |= FLAG_KEY;
	return (true);
}

int	c3d_game_keyhook_up(int key, t_mlx *mlx)
{
	if (key == KEY_EXIT_1 || key == KEY_EXIT_2)
		return (c3d_exit_mlx_break(mlx));
	else if (key == KEY_CURSOR && c3d_game_cursormode(&mlx->game))
		mlx->game.event |= FLAG_PROMPT;
	else if (key == KEY_SPEED \
		&& c3d_game_speed(&mlx->game))
		mlx->game.event |= FLAG_PROMPT;
	if (key != mlx->game.key)
		return (false);
	mlx->game.key = KEY_NONE;
//	if (key != KEY_CURSOR && key != KEY_SPEED)
	mlx->game.event &= ~FLAG_KEY;
	return (true);
}
