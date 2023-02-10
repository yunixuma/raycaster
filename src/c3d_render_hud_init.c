/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_hud_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 16:52:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	\
	c3d_render_hud_map_cell(t_img *img, char cell, t_addr *zero, t_addr *area)
{
	if (ft_hasflag(cell, FLAG_WALL))
		c3d_render_rectangle(img, COLOR_WALL, zero, area);
	else if (ft_hasflag(cell, FLAG_SPACE))
		c3d_render_rectangle(img, COLOR_SPACE, zero, area);
	else
		c3d_render_rectangle(img, COLOR_FREE, zero, area);
}

static void	c3d_render_hud_init_map(t_img *img, char **map, int scale)
{
	t_addr	i;
	t_addr	zero;
	t_addr	area;

	ft_addr_set(&area, scale, scale);
	zero.y = WEIGHT_FRAME;
	i.y = 0;
	while (map[i.y])
	{
		zero.x = WEIGHT_FRAME;
		i.x = 0;
		while (map[i.y][i.x])
		{
			c3d_render_hud_map_cell(img, map[i.y][i.x], &zero, &area);
			zero.x += scale;
			i.x++;
		}
		zero.y += scale;
		i.y++;
	}
}

static void	c3d_render_hud_init_frame(t_img *img)
{
	t_addr	zero;
	t_addr	area;

	ft_addr_set(&area, img->width, WEIGHT_FRAME);
	ft_addr_set(&zero, 0, 0);
	c3d_render_rectangle(img, COLOR_FRAME, &zero, &area);
	zero.y = img->height - WEIGHT_FRAME;
	c3d_render_rectangle(img, COLOR_FRAME, &zero, &area);
	ft_addr_set(&area, WEIGHT_FRAME, img->height);
	ft_addr_set(&zero, 0, 0);
	c3d_render_rectangle(img, COLOR_FRAME, &zero, &area);
	zero.x = img->width - WEIGHT_FRAME;
	c3d_render_rectangle(img, COLOR_FRAME, &zero, &area);
}

void	c3d_render_hud_init(t_mlx *mlx)
{
	c3d_render_hud_init_map(&mlx->img[IDX_HUD], mlx->scene->map, mlx->scale);
	c3d_render_hud_init_frame(&mlx->img[IDX_HUD]);
}
