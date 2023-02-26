/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 17:23:33 by Yoshihiro K      ###   ########.fr       */
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
	int		fd;
	char	*ext;
	size_t	len;

	len = ft_strlen(fpath);
	if (len > LEN_MAXPATH)
		return (ft_seterr_return(INVAL_FILENO, ERR_FPATH));
	else if (len <= ft_strlen(STR_EXT))
		return (ft_seterr_return(INVAL_FILENO, ERR_FEXT));
	ext = ft_strrchr(fpath, STR_EXT[0]);
	if (ext == NULL)
		return (ft_seterr_return(INVAL_FILENO, ERR_FEXT));
	else if (ft_strncmp(ext, STR_EXT, len + 1) || *(ext - 1) == CHR_DIR)
		return (ft_seterr_return(INVAL_FILENO, ERR_FEXT));
	fd = open(fpath, O_RDONLY);
	if (fd < 0)
		return (ft_seterr_return(fd, ERR_OPEN));
	return (fd);
}

char	**c3d_scene_getmap(int fd)
{
	char	**map;
	t_list	*lst;

	lst = c3d_map_read(fd);
	if (lst == NULL)
		return (NULL);
	if (c3d_map_trim(&lst))
		return (ft_lstclear_seterr(&lst, &free, errno));
	if (c3d_map_chk(&lst))
		return (ft_lstclear_seterr(&lst, &free, errno));
	map = c3d_lst2map_rect(&lst);
	if (map == NULL)
		return (ft_lstclear_seterr(&lst, &free, errno));
	ft_lstclear(&lst, NULL);
//debug_c3d_map_raw(map);
	c3d_map_encode(map);
//debug_c3d_map_flag(map);
	c3d_map_valid(map);
	return (map);
}

int	c3d_scene_clean(t_scene *scene, int errnum)
{
	size_t	i;

	if (errno == 0)
		errno = errnum;
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
