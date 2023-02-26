/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 19:58:13 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	c3d_game_move_valid_sub(char **map, \
	t_coord *move, t_coord *pos, t_coord *gap)
{
	if (map[(size_t)(pos->y + move->y + gap->y)] \
		[(size_t)(pos->x + move->x + gap->x)] & (FLAG_SPACE | FLAG_WALL))
	{
		move->y -= gap->y;
		move->x -= gap->x;
	}
	if (map[(size_t)(pos->y + move->y - gap->y)] \
		[(size_t)(pos->x + move->x + gap->x)] & (FLAG_SPACE | FLAG_WALL))
	{
		move->y += gap->y;
		move->x -= gap->x;
	}
	if (map[(size_t)(pos->y + move->y + gap->y)] \
		[(size_t)(pos->x + move->x - gap->x)] & (FLAG_SPACE | FLAG_WALL))
	{
		move->y -= gap->y;
		move->x += gap->x;
	}
	if (move->x == 0 && move->y == 0)
		return (false);
	return (true);
}

static bool	c3d_game_move_valid(char **map, t_coord *move, t_coord *pos)
{
	t_coord	gap;

	gap.y = ((move->y > 0) - 0.5) * UNIT_MOVE;
	if (map[(size_t)(pos->y + move->y)][(size_t)(pos->x)] \
		& (FLAG_SPACE | FLAG_WALL))
		move->y = 0;
	else if (map[(size_t)(pos->y + move->y + gap.y)][(size_t)(pos->x)] \
		& (FLAG_SPACE | FLAG_WALL))
		move->y -= gap.y;
	gap.x = ((move->x > 0) - 0.5) * UNIT_MOVE;
	if (map[(size_t)(pos->y)][(size_t)(pos->x + move->x)] \
		& (FLAG_SPACE | FLAG_WALL))
		move->x = 0;
	else if (map[(size_t)(pos->y)][(size_t)(pos->x + move->x + gap.x)] \
		& (FLAG_SPACE | FLAG_WALL))
		move->x -= gap.x;
	if (move->x == 0 && move->y == 0)
		return (false);
	return (c3d_game_move_valid_sub(map, move, pos, &gap));
}

bool	c3d_game_move(t_mlx *mlx, t_coord *move)
{
	if (!c3d_game_move_valid(mlx->scene->map, move, &mlx->game.coord))
		return (false);
	mlx->game.coord.y += move->y;
	mlx->game.coord.x += move->x;
//debug_printf("move: (%6.3lf, %6.3lf)\n", move->x, move->y);
//debug_printf("coord: (%6.3lf, %6.3lf)\n", mlx->game.coord.x, mlx->game.coord.y);
	return (true);
}
