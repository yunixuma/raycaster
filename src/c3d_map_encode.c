/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_encode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 14:14:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	c3d_map_encode_rewrite(char ch)
{
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

int	c3d_map_encode(char **map)
{
	t_addr	addr;

	addr.y = 0;
	while (map[addr.y] != NULL)
	{
		addr.x = 0;
		while (map[addr.y][addr.x] != '\0')
		{
			map[addr.y][addr.x] = c3d_map_encode_rewrite(map[addr.y][addr.x]);
			addr.x++;
		}
		addr.y++;
	}
	return (ERR_NOERR);
}
