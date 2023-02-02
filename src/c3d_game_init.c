/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_game_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/02 14:02:24 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	c3d_game_init_coord_set(t_game *game, t_addr *addr)
{
	game->coord.x = 1. / 2 + addr->x;
	game->coord.y = 1. / 2 + addr->y;
}

static void	c3d_game_init_coord(t_game *game, char **map, t_addr *addr)
{
	game->coord.x = 1. / 2 * HEIGHT_BLOCK;
	addr->y = 0;
	while (map[addr->y])
	{
		addr->x = 0;
		while (map[addr->y][addr->x])
		{
			if (ft_hasflag(map[addr->y][addr->x], FLAG_START))
				return (c3d_game_init_coord_set(game, addr));
			addr->x++;
		}
		addr->y++;
	}
	addr->x = 0;
	addr->y = 0;
	game->coord.x = 1. / 2;
	game->coord.y = 1. / 2;
}

static void	c3d_game_init_angle(t_game *game, char **map, t_addr *addr)
{
	game->angle.roll = 0;
	game->angle.pitch = 0;
	if (ft_hasflag(map[addr->y][addr->x], FLAG_EAST))
		game->angle.yaw = ANGLE_RIGHT * IDX_EAST;
	else if (ft_hasflag(map[addr->y][addr->x], FLAG_SOUTH))
		game->angle.yaw = ANGLE_RIGHT * IDX_SOUTH;
	else if (ft_hasflag(map[addr->y][addr->x], FLAG_WEST))
		game->angle.yaw = ANGLE_RIGHT * IDX_WEST;
	game->angle.yaw = ANGLE_RIGHT * IDX_NORTH;
}

void	c3d_game_init(t_game *game, t_scene *scene)
{
	t_addr	start;

	c3d_game_init_coord(game, scene->map, &start);
	c3d_game_init_angle(game, scene->map, &start);
	game->key = KEY_NONE;
	game->score = 0;
}
