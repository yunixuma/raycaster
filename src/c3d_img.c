/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/14 02:10:42 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	c3d_img_texture_load(t_mlx *mlx, t_img *img, char *path)
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

static bool	c3d_img_init_empty(t_mlx *mlx, t_img *img, int width, int height)
{
debug_printf("width: %d\theight: %d\n", width, height);
	img->ptr = mlx_new_image(mlx->conn, width, height);
DP(img->ptr);
	img->width = width;
	img->height = height;
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
	c3d_img_init_empty(mlx, &mlx->img[IDX_VISION], WIDTH_VISION, HEIGHT_VISION);
	c3d_img_init_empty(mlx, &mlx->img[IDX_HUD], \
		mlx->scale * mlx->scene->size.x + WEIGHT_FRAME * 2, \
		mlx->scale * mlx->scene->size.y + WEIGHT_FRAME * 2);
	i = 0;
	while (i < N_IMAGE)
	{
		if (mlx->img[i++].ptr == NULL)
			c3d_exit_mlx(mlx, ERR_OPEN);
	}
}

void	c3d_img_clear(t_img *img, int color_code, int width, int height)
{
	t_addr	i;

	i.y = 0;
	while (i.y < height)
	{
		i.x = 0;
		while (i.x < width)
		{
			img->data[i.y * width + i.x] = color_code;
			i.x++;
		}
		i.y++;
	}
}

void	c3d_img_destroy(t_mlx *mlx)
{
	size_t	i;

	if (mlx == NULL)
		return ;
	i = 0;
	while (i < N_IMAGE)
	{
		if (mlx->img[i].ptr != NULL)
			mlx_destroy_image(mlx->conn, mlx->img[i].ptr);
		i++;
	}
}
