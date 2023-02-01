/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_encode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/01 20:16:47 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	c3d_map_encode_wall_rewrite(char **map, t_addr *addr)
{
	char	flag;

	flag = FLAG_WALL;
	if (map[addr->y][addr->x + 1] & (FLAG_FREE | FLAG_START))
		flag |= FLAG_EAST;
	if (addr->x > 0 \
		&& map[addr->y][addr->x - 1] & (FLAG_FREE | FLAG_START))
		flag |= FLAG_WEST;
	if (map[addr->y + 1] \
		&& map[addr->y + 1][addr->x] & (FLAG_FREE | FLAG_START))
		flag |= FLAG_SOUTH;
	if (addr->y > 0 \
		&& map[addr->y - 1][addr->x] & (FLAG_FREE | FLAG_START))
		flag |= FLAG_NORTH;
	return (flag);
}

static char	c3d_map_encode_rewrite(char **map, t_addr *addr)
{
	char	ch;

	ch = map[addr->y][addr->x];
	if (ch == CHRS_MAP[IDX_FREE])
		return (FLAG_FREE);
	else if (ch == CHRS_MAP[IDX_WALL])
		return (FLAG_WALL);
	else if (ch == CHRS_MAP[IDX_SPACE])
		return (FLAG_SPACE);
	else if (ch == CHRS_MAP[IDX_NORTH])
		return (FLAG_START | FLAG_NORTH);
	else if (ch == CHRS_MAP[IDX_SOUTH])
		return (FLAG_START | FLAG_SOUTH);
	else if (ch == CHRS_MAP[IDX_EAST])
		return (FLAG_START | FLAG_EAST);
	return (FLAG_START | FLAG_WEST);
}

static int	c3d_map_encode_wall(char **map)
{
	t_addr	addr;

	addr.y = 0;
	while (map[addr.y] != NULL)
	{
		addr.x = 0;
		while (map[addr.y][addr.x] != '\0')
		{
			if (map[addr.y][addr.x] == FLAG_WALL)
				map[addr.y][addr.x] = c3d_map_encode_wall_rewrite(map, &addr);
			addr.x++;
		}
		addr.y++;
	}
	return (ERR_NOERR);
}

int	c3d_map_encode(char **map)
{
	t_addr	addr;

	addr.y = 0;
	while (map[addr.y] != NULL)
	{
		addr.x = 0;
		while (map[addr.y][addr.x] != '\0')
		{
			map[addr.y][addr.x] = c3d_map_encode_rewrite(map, &addr);
			addr.x++;
		}
		addr.y++;
	}
	return (c3d_map_encode_wall(map));
}
