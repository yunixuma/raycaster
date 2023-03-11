/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_scene_def_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/11 21:36:58 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_scene_def_color_atoi(unsigned char *val, char *p)
{
	int	val_tmp;

	if (*p == CHR_SPACE)
		p++;
	if (!ft_stris(p, ft_isdigit))
		return (ft_seterr(ERR_RANGE));
	val_tmp = ft_atoi(p);
	if ((val_tmp | 0xff) != 0xff)
		return (ft_seterr(ERR_RANGE));
	*val = val_tmp;
	return (ERR_NOERR);
}

static int	c3d_scene_def_color_combine(int *color_code, char *p[])
{
	t_color	color;
	size_t	i;

	i = IDX_RED;
	while (i < N_CHANNEL)
	{
		if (c3d_scene_def_color_atoi(&color.ch[N_CHANNEL - 1 - i], p[i]))
			return (errno);
		i++;
	}
//debug_printf("%#x\n", color.code);
	*color_code = color.code;
	return (ERR_NOERR);
}

int	c3d_scene_def_color(int *color_code, char *line)
{
	char	*p[N_CHANNEL];
	size_t	i;

	i = 0;
	p[i++] = NULL;
	p[i++] = line;
	while (i < N_CHANNEL)
	{
		p[i] = ft_strchr(p[i - 1], CHR_SEP);
		if (p[i] == NULL)
			return (ft_seterr(ERR_MANYVALS));
		*p[i] = '\0';
		p[i++] += sizeof(char);
	}
	if (c3d_scene_def_color_combine(color_code, p))
		return (errno);
	return (ERR_NOERR);
}
