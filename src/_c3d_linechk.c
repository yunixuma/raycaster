/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_linechk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/21 21:56:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_linechk_whole(const char *line, char c)
{
	while (*line != '\0')
	{
		if (*line != c)
			return (ERR_CHR);
		line++;
	}
	return (ERR_NOERR);
}

int	c3d_linechk_edge(const char *line, char c)
{
	if (*line != c)
		return (ERR_CHR);
	while (*(line + 1) != '\0' && *(line + 1) != '\n')
		line++;
	if (*line != c)
		return (ERR_CHR);
	return (ERR_NOERR);
}
