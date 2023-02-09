/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 00:52:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	\
	c3d_render_map_setaddr(t_addr *zero_map, t_addr *offset_cell, t_game *game)
{
	zero_map->x = (ssize_t)(game->coord.x - (SIZE_MAP >> 1));
	zero_map->y = (ssize_t)(game->coord.y - (SIZE_MAP >> 1));
	if (zero_map->x < 0)
		zero_map->x = 0;
	if (zero_map->y < 0)
		zero_map->y = 0;
	offset_cell->x = (ssize_t)(game->coord.x * SIZE_CELL);
	offset_cell->y = (ssize_t)(game->coord.y * SIZE_CELL);
	if (offset_cell->x > ((SIZE_MAP * SIZE_CELL) >> 1))
		offset_cell->x = (SIZE_MAP * SIZE_CELL) >> 1;
	if (offset_cell->y > ((SIZE_MAP * SIZE_CELL) >> 1))
		offset_cell->y = (SIZE_MAP * SIZE_CELL) >> 1;
}

static void	\
	c3d_render_map_cell(t_img *img, char cell, t_addr *addr, t_addr *offset)
{
	t_addr	zero;
	t_addr	area;

	zero.x = ((SIZE_MAP * SIZE_CELL) >> 1) - offset->x + addr->x * SIZE_CELL;
	zero.y = ((SIZE_MAP * SIZE_CELL) >> 1) - offset->y + addr->y * SIZE_CELL;
	ft_addr_set(&area, SIZE_CELL, SIZE_CELL);
	if (ft_hasflag(cell, FLAG_WALL))
		c3d_render_rectangle(img, COLOR_WALL, &zero, &area);
	else if (ft_hasflag(cell, FLAG_SPACE))
		c3d_render_rectangle(img, COLOR_SPACE, &zero, &area);
	else
		c3d_render_rectangle(img, COLOR_FREE, &zero, &area);
}

static void	c3d_render_map_loop(t_img *img, char **map, t_game *game)
{
	t_addr	i;
	t_addr	zero_map;
	t_addr	offset_cell;

	c3d_render_map_setaddr(&zero_map, &offset_cell, game);
	i.y = zero_map.y;
	while (i.y < zero_map.y + SIZE_MAP && map[i.y])
	{
		i.x = zero_map.x;
		while (i.x < zero_map.x + SIZE_MAP && map[i.y][i.x])
		{
			c3d_render_map_cell(img, map[i.y][i.x], &i, &offset_cell);
			i.x++;
		}
		i.y++;
	}
}

static void	c3d_render_map_center(t_img *img)
{
	t_addr	zero;
	t_addr	area;

	ft_addr_set(&area, SIZE_CELL >> 1, SIZE_CELL >> 1);
	zero.x = (img->width >> 1) - (area.x >> 1);
	zero.y = (img->height >> 1) - (area.y >> 1);
	c3d_render_rectangle(img, COLOR_POS, &zero, &area);
//	img->data[img->width * (img->height >> 1) + (img->width >> 1)] = COLOR_POS;
}

void	c3d_render_map(t_mlx *mlx)
{
	c3d_img_clear(&mlx->img[IDX_MAP], COLOR_SPACE, \
		SIZE_MAP * SIZE_CELL, SIZE_MAP * SIZE_CELL);
	c3d_render_map_loop(&mlx->img[IDX_MAP], mlx->scene->map, &mlx->game);
	c3d_render_map_center(&mlx->img[IDX_MAP]);
}
