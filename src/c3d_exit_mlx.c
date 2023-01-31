/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_exit_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 13:24:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_exit_mlx(int errnum, t_mlx *mlx)
{
	if (mlx != NULL)
	{
		c3d_img_destroy(mlx);
		c3d_win_destroy(mlx);
		c3d_map_clear_free(mlx->scene->map);
		mlx = NULL;
	}
	return (c3d_exit(errnum));
}

int	c3d_exit_mlx_break(t_mlx *mlx)
{
	c3d_print_break();
	return (c3d_exit_mlx(ERR_NOERR, mlx));
}

int	c3d_exit_mlx_goal(int errnum, t_mlx *mlx)
{
	c3d_print_goal(mlx->game.score);
	return (c3d_exit_mlx(errnum, mlx));
}
