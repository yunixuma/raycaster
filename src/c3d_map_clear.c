/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 13:24:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_map_clear_check(char **map)
{
	size_t	y;
	size_t	x;

	if (map == NULL)
		return ;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			map[y][x] &= ~FLAG_CHECKED;
			x++;
		}
		y++;
	}
}

void	*c3d_map_clear_free(char **map)
{
	size_t	y;

	if (map == NULL)
		return (NULL);
	y = 0;
	while (map[y] != NULL)
	{
		ft_free((void **)&map[y]);
		y++;
	}
	ft_free((void **)&map);
	return (NULL);
}
