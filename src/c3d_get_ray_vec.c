/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_get_ray_vec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobayashi <kobayashi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:02:24 by kobayashi         #+#    #+#             */
/*   Updated: 2023/02/12 13:04:39 by kobayashi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ray_vec(t_ray_calculation *c, int x)
{
	double screen_x;

	screen_x = 2 * x / (double)WIDTH_VISION - 1;
	c->ray_vc.x = c->base_vc.x + c->screen_vc.x * screen_x;
	c->ray_vc.y = c->base_vc.y + c->screen_vc.y * screen_x;
}
