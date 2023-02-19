/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/19 13:56:24 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_exit(int errnum)
{
	if (errnum != ERR_NOERR)
		c3d_print_err(errnum);
	exit(errnum);
}

int	c3d_exit_mlx(t_mlx *mlx, int errnum)
{
	if (mlx != NULL)
	{
		c3d_img_destroy(mlx);
		c3d_win_destroy(mlx);
		c3d_map2vectors_free(mlx->opt, errnum);
		c3d_scene_clean(mlx->scene, errnum);
		mlx = NULL;
	}
	return (c3d_exit(errnum));
}

int	c3d_exit_mlx_break(t_mlx *mlx)
{
	c3d_print_break();
	return (c3d_exit_mlx(mlx, ERR_NOERR));
}
/*
int	c3d_exit_mlx_goal(t_mlx *mlx)
{
	c3d_print_goal(mlx->game.score);
	return (c3d_exit_mlx(mlx, ERR_NOERR));
}
*/