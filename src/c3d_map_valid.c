/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/01 18:10:07 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_map_valid_circuit_adjacent(char **map, t_addr *addr)
{
	if ((*addr).y == 0 || (*addr).x == 0)
		return (ERR_OUTER);
	if (map[(*addr).y] == NULL || map[(*addr).y + 1] == NULL)
		return (ERR_OUTER);
	if (map[(*addr).y][(*addr).x] == '\0' \
		|| map[(*addr).y][(*addr).x + 1] == '\0')
		return (ERR_OUTER);
	if (map[(*addr).y - 1][(*addr).x] == FLAG_SPACE)
		return (ERR_OUTER);
	if (map[(*addr).y + 1][(*addr).x] == FLAG_SPACE)
		return (ERR_OUTER);
	if (map[(*addr).y][(*addr).x - 1] == FLAG_SPACE)
		return (ERR_OUTER);
	if (map[(*addr).y][(*addr).x + 1] == FLAG_SPACE)
		return (ERR_OUTER);
	return (ERR_NOERR);
}

static int	c3d_map_valid_circuit(char **map)
{
	t_addr		addr;

	addr.y = 0;
	while (map[addr.y] != NULL)
	{
		addr.x = 0;
		while (map[addr.y][addr.x] != '\0')
		{
			if ((map[addr.y][addr.x] == FLAG_FREE \
				|| ft_hasflag(map[addr.y][addr.x], FLAG_START)) \
				&& c3d_map_valid_circuit_adjacent(map, &addr))
				return (ERR_OUTER);
			addr.x++;
		}
		addr.y++;
	}
	return (ERR_NOERR);
}

int	c3d_map_valid(char **map)
{
	int	errnum;

	errnum = c3d_map_valid_circuit(map);
	if (errnum)
		c3d_exit_map(errnum, map);
	return (ERR_NOERR);
}
