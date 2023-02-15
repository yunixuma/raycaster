/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_vision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:54:49 by kobayashi         #+#    #+#             */
/*   Updated: 2023/02/15 18:22:57 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	data->data[WIDTH_VISION * y + x] = color;
}

unsigned int	get_color(t_img *data, int x, int y)
{
	return (data->data[data->width * y + x]);
}

void	set_init_val(t_mlx *mlx, t_ray_calculation *c)
{
	// プレイヤーのポジション取得
	// c->player_pos.x = 22;
	// c->player_pos.y = 12;
	c->player_pos.x = mlx->game.coord.x;
	c->player_pos.y = mlx->game.coord.y;
	c->base_vc.x = -1;
	c->base_vc.y = 0;
	c->screen_vc.x = 0;
	c->screen_vc.y = 0.66;
	rotate_view(mlx, c);
}

void	draw_wall(t_mlx *mlx, t_ray_calculation *c, int x, int y)
{
	c->tex_pos.y = (int)c->init_tex_y;
	if (c->tex_pos.y > texHeight)
		c->tex_pos.y = texHeight - 1;
	my_mlx_pixel_put(&mlx->img[IDX_VISION], x, y,\
		get_color(&mlx->img[c->wall_dir], c->tex_pos.x, c->tex_pos.y));
	c->init_tex_y += c->dist_tex_y;
}

void	c3d_render_vision(t_mlx *mlx)
{
    t_ray_calculation	c;
	set_init_val(mlx, &c);

	int	x;
	int	y;

	x = 0;
	while (x < WIDTH_VISION)
    {
		get_ray_vec(&c, x);
		create_gridmap(&c);
		extend_ray(mlx, &c);
		get_hit_wall(&c);
		y = 0;
		while (y < WIDTH_VISION)
		{
			if (y >= c.wall_start && y < c.wall_end)
				draw_wall(mlx, &c, x, y);
			y++;
		}
		x++;
	}
}