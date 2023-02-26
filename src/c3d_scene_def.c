/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_scene_def.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 17:34:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_scene_def_image(char **path, char *line)
{
	if (*path == NULL)
		*path = ft_strdup(line);
	else
		return (ERR_DUP);
	if (*path == NULL)
		return (ERR_ALLOC);
	return (ERR_NOERR);
}

static int	c3d_scene_def_sub(t_scene *scene, char *line)
{
	const char	*ids[N_TEXTURE + N_COLOR] = \
		{ID_NORTH, ID_SOUTH, ID_EAST, ID_WEST, ID_FLOOR, ID_CEILING};
	size_t		j;

	if (*line == '\n' || *line == '\0')
		return (ERR_EMPTY);
	*(line + ft_strlen(line) - 1) = '\0';
	j = 0;
	while (j < N_TEXTURE + N_COLOR)
	{
		if (!ft_strncmp(line, ids[j], ft_strlen(ids[j])))
		{
			if (j < N_TEXTURE)
				return (c3d_scene_def_image(&scene->path[j], \
					line + ft_strlen(ids[j])));
			else
				return (c3d_scene_def_color(&scene->color[j - N_TEXTURE], \
					line + ft_strlen(ids[j])));
		}
		j++;
//DL(j++);
	}
	return (EINVAL);
}

int	c3d_scene_def(t_scene *scene, int fd)
{
	char	*line;
	size_t	i;

	line = "";
	errno = 0;
	i = 0;
	while (i < N_TEXTURE + N_COLOR)
	{
		line = get_next_line(fd);
//DS(line);
		if (line == NULL)
			return (ERR_EMPTY);
		errno = c3d_scene_def_sub(scene, line);
		free(line);
		if (errno == ERR_EMPTY)
			continue ;
		else if (errno)
			return (errno);
		else
			i++;
	}
	return (ERR_NOERR);
}
