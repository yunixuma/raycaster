/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/26 22:08:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_scene_init(t_scene *scene)
{
	size_t	i;

	i = 0;
	while (i < N_TEXTURE)
		scene->path[i++] = NULL;
	i = 0;
	while (i < N_COLOR)
		scene->color[i++] = VAL_INVAL;
	scene->map = NULL;
}

int	c3d_scene_open(char *fpath)
{
	char	*ext;
	size_t	len;
	int		fd;

	len = ft_strlen(fpath);
	if (len > LEN_MAXPATH)
		c3d_exit(ERR_FPATH);
	else if (len <= ft_strlen(STR_EXT))
		c3d_exit(ERR_FEXT);
	ext = ft_strrchr(fpath, STR_EXT[0]);
	if (ext == NULL)
		c3d_exit(ERR_FEXT);
	if (ft_strncmp(ext, STR_EXT, len + 1) || *(ext - 1) == CHR_DIR)
		c3d_exit(ERR_FEXT);
	fd = open(fpath, O_RDONLY);
	if (fd < 0)
		c3d_exit(ERR_OPEN);
	return (fd);
}
