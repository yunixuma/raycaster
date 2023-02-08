/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_rectangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/08 15:23:35 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_rectangle(t_img *img, \
	int color_code, t_addr *zero, t_addr *area)
{
	t_addr	i;

	i.y = 0;
	while (i.y < area->y)
	{
		i.x = 0;
		while (i.x < area->x)
		{
			img->data[img->width * (zero->y + i.y) + zero->x + i.x] \
				= color_code;
			i.x++;
		}
		i.y++;
	}
}
