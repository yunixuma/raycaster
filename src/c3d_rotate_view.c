/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_rotate_view.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:22:50 by kobayashi         #+#    #+#             */
/*   Updated: 2023/02/15 18:23:10 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_rotate_rad(double rad)
{
	if (rad < 0)
		return (-rad);
	else
		return (2 * M_PI - rad);
}

void	rotate_vc(t_vector *vc, double r)
{
	double tmp = vc->x;
	vc->x = vc->x * cos(-r) - vc->y * sin(-r);
	vc->y = tmp * sin(-r) + vc->y * cos(-r);
}

void	rotate_view(t_mlx *mlx, t_ray_calculation *c)
{
	double	r;

	r = get_rotate_rad(ft_math_deg2rad(mlx->game.angle.yaw));
	rotate_vc(&c->base_vc, r);
	rotate_vc(&c->screen_vc, r);
}
