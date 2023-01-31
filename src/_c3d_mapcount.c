/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_mapcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/21 21:56:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_mapcount_line(char *str, int countchr[SIZE_CHRS_MAP])
{
	const char	*chrs = CHRS_MAP;
	char		*pos;

	while (*str != '\0')
	{
		pos = ft_strchr(chrs, *str);
		if (pos != NULL)
			(countchr[pos - chrs])++;
		str++;
	}
	return (ERR_NOERR);
}

void	c3d_mapcount(int countchr[], char **map)
{
	size_t	i;

	i = 0;
	while (i < SIZE_CHRS_MAP)
		countchr[i++] = 0;
	i = 0;
	while (map[i] != NULL)
		c3d_mapcount_line(map[i++], countchr);
}
