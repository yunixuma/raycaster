/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_ispath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/23 16:11:37 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_ispath(char **map, t_addr *addr)
{
	if (map == NULL || addr == NULL || map[addr->y] == NULL)
		return (false);
	if (ft_hasflag(map[addr->y][addr->x], FLAG_CHECKED))
		return (false);
	if (addr->x > 0 && ft_hasflag(map[addr->y][addr->x - 1], FLAG_CHECKED))
		return (true);
	if (map[addr->y][addr->x] == '\0' \
		&& ft_hasflag(map[addr->y][addr->x + 1], FLAG_CHECKED))
		return (true);
	if (addr->y > 0 && ft_hasflag(map[addr->y - 1][addr->x], FLAG_CHECKED))
		return (true);
	if (map[addr->y + 1] != NULL \
		&& ft_hasflag(map[addr->y + 1][addr->x], FLAG_CHECKED))
		return (true);
	return (false);
}
