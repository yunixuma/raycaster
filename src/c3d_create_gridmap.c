/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_create_gridmap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:00:32 by kobayashi         #+#    #+#             */
/*   Updated: 2023/02/12 14:00:07 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_to_gridmap(t_ray_calculation *c)
{
	c->grid_pos.x = (int)c->player_pos.x;
	c->grid_pos.y = (int)c->player_pos.y;
	if (c->ray_vc.x > 0)
		c->player_step.x = 1;
	else
		c->player_step.x = -1;
	if (c->ray_vc.y > 0)
		c->player_step.y = 1;
	else
		c->player_step.y = -1;
}

void	get_delta_dist(t_ray_calculation *c)
{
	if ((1 / c->ray_vc.x) < 0)
		c->delta_dist.x = -1 * (1 / c->ray_vc.x);
	else
		c->delta_dist.x = (1 / c->ray_vc.x);
	if ((1 / c->ray_vc.y) < 0)
		c->delta_dist.y = -1 * (1 / c->ray_vc.y);
	else
		c->delta_dist.y = (1 / c->ray_vc.y);
}

void	get_init_dist(t_ray_calculation *c)
{
	if (c->ray_vc.x < 0)
		c->dist.x = (c->player_pos.x - c->grid_pos.x) * c->delta_dist.x;
	else
		c->dist.x = (c->player_pos.x + 1 - c->grid_pos.x) * c->delta_dist.x;
	if (c->ray_vc.y < 0)
		c->dist.y = (c->player_pos.y - c->grid_pos.y) * c->delta_dist.y;
	else
		c->dist.y = (c->player_pos.y + 1 - c->grid_pos.y) * c->delta_dist.y;
}

void	create_gridmap(t_ray_calculation *c)
{
	convert_to_gridmap(c);
	get_delta_dist(c);
	get_init_dist(c);
}