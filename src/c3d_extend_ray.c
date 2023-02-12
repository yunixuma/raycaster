/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_extend_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:03:31 by kobayashi         #+#    #+#             */
/*   Updated: 2023/02/12 14:08:24 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//void	extend_ray(t_ray_calculation *c)
void	extend_ray(t_mlx *mlx, t_ray_calculation *c) 
{
	while (1)
	{
		if (c->dist.x < c->dist.y)
		{
			c->dist.x += c->delta_dist.x;
			c->grid_pos.x += c->player_step.x;
			c->side = 0;
		}
		else
		{
			c->dist.y += c->delta_dist.y;
			c->grid_pos.y += c->player_step.y;
			c->side = 1;
		}
		// x座標とy座標が逆になっている。
		// if (worldMap[c->grid_pos.x][c->grid_pos.y] > 0)
		// if (ft_hasflag(map[addr->y][addr->x], FLAG_EAST))
		if (ft_hasflag(mlx->scene->map[c->grid_pos.y][c->grid_pos.x], FLAG_WALL))
			break ;
	}
}
