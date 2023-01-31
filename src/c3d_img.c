/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 18:24:08 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_img_texture_load(t_mlx *mlx, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(mlx->conn, path, \
		&img->width, &img->height);
DP(img->ptr);
	if (img->ptr == NULL)
		return (false);
	img->data = (int *)mlx_get_data_addr(img->ptr, \
		&img->bpp, &img->len, &img->endian);
	return (true);
}

void	c3d_img_init(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (i < N_TEXTURE)
	{
		c3d_img_texture_load(mlx, &mlx->img[i], mlx->scene->path[i]);
		i++;
	}
	mlx->img[IDX_VISION].ptr \
		= mlx_new_image(mlx->conn, WIDTH_VISION, HEIGHT_VISION);
	mlx->img[IDX_VISION].width = WIDTH_VISION;
	mlx->img[IDX_VISION].height = HEIGHT_VISION;
	mlx->img[IDX_VISION].data = \
		(int *)mlx_get_data_addr(mlx->img[IDX_VISION].ptr, \
		&mlx->img[IDX_VISION].bpp, &mlx->img[IDX_VISION].len, \
		&mlx->img[IDX_VISION].endian);
	i = 0;
	while (i < N_TEXTURE + 1)
	{
		if (mlx->img[i++].ptr == NULL)
			c3d_exit_mlx(ERR_OPEN, mlx);
	}
}

void	c3d_img_destroy(t_mlx *mlx)
{
	size_t	i;

	if (mlx == NULL)
		return ;
	i = 0;
	while (i < N_TEXTURE + 1)
	{
		if (mlx->img[i].ptr != NULL)
			mlx_destroy_image(mlx->conn, mlx->img[i].ptr);
		i++;
	}
}
