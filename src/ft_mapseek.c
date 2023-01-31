/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapseek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/23 16:11:37 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_addr	ft_mapseek(char **map, char ch)
{
	t_addr	addr;
	char	*pos;

	if (map == NULL)
	{
		addr.x = POS_NOEXIST;
		addr.y = POS_NOEXIST;
		return (addr);
	}
	addr.y = 0;
	while (map[addr.y] != NULL)
	{
		pos = ft_strchr(map[addr.y], ch);
		if (pos != NULL)
		{
			addr.x = pos - map[addr.y];
			return (addr);
		}
		(addr.y)++;
	}
	addr.x = POS_NOEXIST;
	addr.y = POS_NOEXIST;
	return (addr);
}

int	ft_mapseek_exist(char **map, char ch)
{
	t_addr	addr;

	addr = ft_mapseek(map, ch);
	if (addr.x < 0 || addr.y < 0)
		return (false);
	return (true);
}
