/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/16 11:03:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_win_init(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->conn, \
		WIDTH_VISION, HEIGHT_VISION, STR_TITLE);
	if (mlx->win == NULL)
		return (ft_seterr(ERR_MLX));
	return (ERR_NOERR);
}

int	c3d_win_draw_vision(t_mlx *mlx)
{
	c3d_render_background(mlx);
	//c3d_render_visible(mlx);
	c3d_render_vision(mlx);
	c3d_render_hud(mlx);
	mlx_put_image_to_window(mlx->conn, mlx->win, mlx->img[IDX_VISION].ptr, \
		ZERO_VISION, ZERO_VISION);
//debug_c3d_game(&mlx->game);
	return (ERR_NOERR);
}

void	c3d_win_draw_pixel(t_mlx *mlx, int x, int y, int color)
{
	t_addr	i;

	i.x = 0;
	while (i.x < SIZE_TILE)
	{
		i.y = 0;
		while (i.y < SIZE_TILE)
		{
			mlx_pixel_put(mlx->conn, mlx->win, \
				x * SIZE_TILE + i.x, y * SIZE_TILE + i.y, color);
			i.y++;
		}
		i.x++;
	}
}

void	c3d_win_destroy(t_mlx *mlx)
{
	if (mlx != NULL && mlx->conn != NULL && mlx->win != NULL)
		mlx_destroy_window(mlx->conn, mlx->win);
}
