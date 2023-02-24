/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_keyhook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/24 12:17:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_game_keyhook_down(int key, t_mlx *mlx)
{
	mlx->game.key = key;
	mlx->game.event |= FLAG_KEYDOWN;
	mlx->game.event &= ~FLAG_KEYUP;
	return (true);
}

int	c3d_game_keyhook_up(int key, t_mlx *mlx)
{
	if (key == KEY_EXIT_1 || key == KEY_EXIT_2)
		return (c3d_exit_mlx_break(mlx));
	if (key != mlx->game.key)
		return (false);
	mlx->game.key = KEY_NONE;
	mlx->game.event |= FLAG_KEYUP;
	mlx->game.event &= ~FLAG_KEYDOWN;
	return (true);
}
