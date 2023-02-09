/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_c3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 01:38:07 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_cub3d.h"

void	debug_c3d_lst(t_list *lst)
{
	t_list	*ele;
	int		i;
	int		size;

	if (DEBUG_MODE == 0)
		return ;
	size = ft_lstsize(lst);
	ele = lst;
	dprintf(FD_DEBUG, "lst\t%%p: %p\tsize: %3d\n", ele, size);
	i = 0;
	while (ele != NULL && i < size)
	{
		dprintf(FD_DEBUG, "%3d\t", i);
		dprintf(FD_DEBUG, "%%p: %p\t", ele);
		dprintf(FD_DEBUG, "content: %s\t", (char *)ele->content);
		dprintf(FD_DEBUG, "next: %p\n", ele->next);
		ele = ele->next;
		i++;
	}
}

void	debug_c3d_game(t_game *game)
{
	dprintf(FD_DEBUG, "game.\t");
	dprintf(FD_DEBUG, "x: % 7.3lf\t", game->coord.x);
	dprintf(FD_DEBUG, "y: % 7.3lf\t", game->coord.y);
	dprintf(FD_DEBUG, "z: % 7.3lf\n", game->coord.z);
	dprintf(FD_DEBUG, "     \t");
	dprintf(FD_DEBUG, "yaw: % 6.1lf\t", game->angle.yaw);
	dprintf(FD_DEBUG, "pitch: % 6.1lf\t", game->angle.pitch);
	dprintf(FD_DEBUG, "roll: % 6.1lf\n", game->angle.roll);
	dprintf(FD_DEBUG, "     \t");
	dprintf(FD_DEBUG, "fov: %lf\t", game->fov);
	dprintf(FD_DEBUG, "key: %d\t", game->event);
	dprintf(FD_DEBUG, "score: %d\n", game->score);
}

void	debug_c3d_countchr(int *arr)
{
	ssize_t	size;
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (arr == NULL)
		return ;
	size = SIZE_CHRS_MAP;
	dprintf(FD_DEBUG, "counts\t%%p: %p\tsize: %zd\n", arr, size);
	i = 0;
	while (i < size)
	{
		dprintf(FD_DEBUG, "%3zd\t", i);
		dprintf(FD_DEBUG, "count: %d\n", arr[i]);
		i++;
	}
}

void	debug_c3d_scene(t_scene *scene)
{
	ssize_t	i;

	if (DEBUG_MODE == 0)
		return ;
	if (scene == NULL)
		return ;
	dprintf(FD_DEBUG, "scene\t%%p: %p\n", scene);
	i = 0;
	while (i < N_TEXTURE)
	{
		dprintf(FD_DEBUG, "path\t%3zd\t", i);
		dprintf(FD_DEBUG, "%%p: %p\t{%s}\n", scene->path[i], scene->path[i]);
		i++;
	}
	i = 0;
	while (i < N_COLOR)
	{
		dprintf(FD_DEBUG, "color\t%3zd\t%#x\n", i, scene->color[i]);
		i++;
	}
}
