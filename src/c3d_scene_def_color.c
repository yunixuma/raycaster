/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_scene_def_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/14 00:36:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_scene_def_color_atoi(int *val, char *p)
{
	if (*p == CHR_SPACE)
		p++;
	if (!ft_stris(p, ft_isdigit))
		return (ERANGE);
	*val = ft_atoi(p);
	if ((*val | 0xff) != 0xff)
		return (ERANGE);
	return (ERR_NOERR);
}

static int	c3d_scene_def_color_combine(int *color_code, char *p[])
{
	t_color	color;

	if (c3d_scene_def_color_atoi(&color.r, p[IDX_RED]))
		return (EINVAL);
	if (c3d_scene_def_color_atoi(&color.g, p[IDX_GREEN]))
		return (EINVAL);
	if (c3d_scene_def_color_atoi(&color.b, p[IDX_BLUE]))
		return (EINVAL);
	*color_code = c3d_color_combine(&color);
	return (ERR_NOERR);
}

int	c3d_scene_def_color(int *color_code, char *line)
{
	char	*p[N_CHANNEL];
	size_t	i;

	p[0] = line;
	i = 1;
	while (i < N_CHANNEL)
	{
		p[i] = ft_strchr(p[i - 1], CHR_SEP);
		if (p[i] == NULL)
			return (EINVAL);
		*p[i] = '\0';
		p[i++] += 1;
	}
	if (c3d_scene_def_color_combine(color_code, p))
		return (EINVAL);
	return (ERR_NOERR);
}
