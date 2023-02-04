/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/04 04:06:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_rectangle(t_img *img, \
	t_addr *zero, t_addr *area, int color_code)
{
	ssize_t	i_col;
	ssize_t	i_row;

	i_row = 0;
	while (i_row < area->y)
	{
		i_col = 0;
		while (i_col < area->x)
		{
			img->data[img->width * (zero->y + i_row) + zero->x + i_col] \
				= color_code;
			i_col++;
		}
		i_row++;
	}
}

void	c3d_render_background(t_mlx *mlx)
{
	t_addr	zero;
	t_addr	area;

	zero.x = ZERO_VISION;
	zero.y = ZERO_VISION;
	area.x = WIDTH_VISION;
	area.y = HEIGHT_VISION \
		* (ANGLE_VISION + mlx->game.angle.pitch) / ANGLE_VISION / 2;
	if (area.y < 0)
		area.y = 0;
	else if (area.y > HEIGHT_VISION)
		area.y = HEIGHT_VISION;
	c3d_render_rectangle(&mlx->img[IDX_VISION], \
		&zero, &area, mlx->scene->color[IDX_CEILING]);
	zero.y = area.y;
	area.y = HEIGHT_VISION - zero.y;
	c3d_render_rectangle(&mlx->img[IDX_VISION], \
		&zero, &area, mlx->scene->color[IDX_FLOOR]);
}

static void	c3d_render_imgline(t_img *img, int src_id, t_addr *dst, t_addr *src)
{
	ssize_t	i_row;

	i_row = 0;
	while (i_row < src->y)
	{
		img[IDX_VISION].data[WIDTH_VISION * (dst->y + i_row) + dst->x] \
			= img[src_id].data[img[src_id].width * i_row \
			* img[src_id].height / src->y + src->x];
		i_row++;
	}
}

/*# define ANGLE_RIGHT		90.
# define ANGLE_VISION		45.
# define WIDTH_VISION		720
# define HEIGHT_VISION		480
# define ZERO_VISION		0
# define WIDTH_BLOCK		120
# define HEIGHT_BLOCK		120*/

void	c3d_render_visible(t_mlx *mlx)
{
	t_addr	src;
	t_addr	dst;
	ssize_t	i_col;
	int		src_id;

	src_id = IDX_WEST;
//debug_c3d_img(mlx->img[src_id], 64);
	src.x = mlx->img[src_id].width * 0 / 10;
	src.y = mlx->img[src_id].height \
		* HEIGHT_VISION / mlx->img[src_id].height * 7 / 10;
	dst.x = WIDTH_VISION * 4 / 10;
	dst.y = HEIGHT_VISION * 2 / 10;
	i_col = 0;
	while (i_col < mlx->img[src_id].width * 10 / 10)
	{
		c3d_render_imgline(mlx->img, src_id, &dst, &src);
		src.x++;
		dst.x++;
		i_col++;
	}
}
