/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/27 05:43:09 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	c3d_game_speed(t_game *game)
{
	if (game->speed >= MAX_SPEED)
		game->speed = UNIT_SPEED;
	else if (game->speed + UNIT_SPEED >= MAX_SPEED)
		game->speed = MAX_SPEED;
	else
		game->speed += UNIT_SPEED;
	return (true);
}

bool	c3d_game_zoom(t_game *game, double fov_add)
{
	double	fov_bak;

	fov_bak = game->fov;
	game->fov += fov_add;
	if (game->fov > ANGLE_FOV_MAX)
		game->fov = ANGLE_FOV_MAX;
	else if (game->fov < ANGLE_FOV_MIN)
		game->fov = ANGLE_FOV_MIN;
	if (game->fov == fov_bak)
		return (false);
	return (true);
}

bool	c3d_game_cursormode(t_game *game)
{
	if (ft_hasflag(game->event, FLAG_CURSOR))
		game->event &= ~FLAG_CURSOR;
	else
		game->event |= FLAG_CURSOR;
	return (true);
}

/*
bool	c3d_game_judge(t_mlx *mlx)
{
	if (mlx->scene->map[(size_t)mlx->game.coord.y][(size_t)mlx->game.coord.x] \
		!= CHRS_MAP[IDX_SOUTH])
		return (false);
	else if (ft_mapseek_exist(mlx->scene->map, CHRS_MAP[IDX_EAST]))
		return (false);
	return (true);
}
*/