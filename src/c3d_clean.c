/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 13:24:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_clean(t_scene *scene, int errnum)
{
	size_t	i;

	if (scene == NULL)
		return (errnum);
	i = 0;
	while (i < N_TEXTURE)
	{
		if (scene->path[i])
			ft_free((void **)&scene->path[i]);
		i++;
	}
	c3d_map_clear_free(scene->map);
	return (errnum);
}
