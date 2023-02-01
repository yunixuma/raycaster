/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/01 19:44:14 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_win_init(t_mlx *mlx)
{
	mlx->win = mlx_new_window(mlx->conn, \
		WIDTH_VISION, HEIGHT_VISION, STR_TITLE);
}

int	c3d_win_draw_vision(t_mlx *mlx)
{
	c3d_render_background(mlx);
//	c3d_count_visible(mlx);	
	mlx_put_image_to_window(mlx->conn, mlx->win, mlx->img[IDX_VISION].ptr, \
		ZERO_VISION, ZERO_VISION);
debug_c3d_game(mlx->game);
	return (ERR_NOERR);
}

void	c3d_win_draw_pixel(t_mlx *mlx, int x, int y, int color)
{
	ssize_t	i_col;
	ssize_t	i_row;

	i_col = 0;
	while (i_col < SIZE_TILE)
	{
		i_row = 0;
		while (i_row < SIZE_TILE)
		{
			mlx_pixel_put(mlx->conn, mlx->win, \
				x * SIZE_TILE + i_col, y * SIZE_TILE + i_row, color);
			i_row++;
		}
		i_col++;
	}
}

void	c3d_win_destroy(t_mlx *mlx)
{
	if (mlx->conn != NULL && mlx->win != NULL)
		mlx_destroy_window(mlx->conn, mlx->win);
}
