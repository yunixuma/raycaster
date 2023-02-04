/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_c3d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/04 11:29:55 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_cub3d.h"

void	debug_c3d_map_raw(char **map)
{
	ssize_t	size;
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (map == NULL || *map == NULL)
		return ;
	size = 0;
	while (map[size] != NULL)
		size++;
	dprintf(FD_DEBUG, "map\t%%p: %p\tsize: %zd\n", map, size);
	i = 0;
	while (i <= size)
	{
		dprintf(FD_DEBUG, "%3zd\t", i);
		dprintf(FD_DEBUG, "%%p: %p\t", map[i]);
		dprintf(FD_DEBUG, "line: %s\n", map[i]);
		i++;
	}
}

void	debug_c3d_map_flag(char **map)
{
	ssize_t	size;
	ssize_t	i;
	ssize_t	j;

	if (DEBUG_MODE == 0)
		return ;
	if (map == NULL || *map == NULL)
		return ;
	size = 0;
	while (map[size] != NULL)
		size++;
	dprintf(FD_DEBUG, "map\t%%p: %p\tsize: %zd\n", map, size);
	i = 0;
	while (i < size)
	{
		dprintf(FD_DEBUG, "%3zd\t", i);
		j = 0;
		while (map[i][j])
		{
			dprintf(FD_DEBUG, "%3x", (unsigned char)map[i][j]);
			j++;
		}
		dprintf(FD_DEBUG, "\t%3zd\n", j);
		i++;
	}
}
