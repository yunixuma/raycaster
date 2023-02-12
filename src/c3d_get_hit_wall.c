/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_hit_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:04:07 by kobayashi         #+#    #+#             */
/*   Updated: 2023/02/12 14:15:01 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_wall_dist_direct(t_ray_calculation *c)
{
	if (c->side == 0)
		c->dist_wall = c->dist.x - c->delta_dist.x;
	else
		c->dist_wall = c->dist.y - c->delta_dist.y;
	if (c->side == 0)
	{
		if (c->player_step.x > 0)
			c->wall_dir = IDX_WEST;
		else
			c->wall_dir = IDX_EAST;
	}
	else
	{
		if (c->player_step.y > 0)
			c->wall_dir = IDX_NORTH;
		else
			c->wall_dir = IDX_SOUTH;
	}
}

void	get_wall_height(t_ray_calculation *c)
{
	c->wall_height = (int)(WALL_HEIGHT_BASE / c->dist_wall);
	c->wall_start = -c->wall_height / 2 + HEIGHT_VISION / 2;
	if (c->wall_start < 0)
		c->wall_start = 0;
	c->wall_end = c->wall_height / 2 + HEIGHT_VISION / 2;
	if (c->wall_end >= HEIGHT_VISION)
		c->wall_end = HEIGHT_VISION - 1;
}

void	get_wall_exact_pos_x(t_ray_calculation *c)
{
	double wallX;
	if (c->side == 0)
		wallX = c->player_pos.y + c->dist_wall * c->ray_vc.y;
	else
		wallX = c->player_pos.x + c->dist_wall * c->ray_vc.x;
	wallX -= floor(wallX);

	c->tex_pos.x = (int)(wallX * texWidth);
	if(c->side == 0 && c->ray_vc.x > 0) c->tex_pos.x = texWidth - c->tex_pos.x - 1;
	if(c->side == 1 && c->ray_vc.y < 0) c->tex_pos.x = texWidth - c->tex_pos.x - 1;
}

void	get_wall_exact_pos_y(t_ray_calculation *c)
{
	c->dist_tex_y = 1.0 * texHeight / c->wall_height;
	c->init_tex_y = (c->wall_start - HEIGHT_VISION / 2 + c->wall_height / 2) * c->dist_tex_y;
}

void	get_hit_wall(t_ray_calculation *c)
{
	get_wall_dist_direct(c);
	get_wall_height(c);
	get_wall_exact_pos_x(c);
	get_wall_exact_pos_y(c);
}