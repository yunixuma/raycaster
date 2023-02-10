/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_blend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 15:53:27 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_blend(t_img *img_dst, t_img *img_src, t_addr *zero)
{
	t_addr	i;

	i.y = 0;
	while (i.y < img_src->height)
	{
		i.x = 0;
		while (i.x < img_src->width)
		{
			img_dst->data[(zero->y + i.y) * img_dst->width + zero->x + i.x] \
				= img_src->data[i.y * img_src->width + i.x];
			i.x++;
		}
		i.y++;
	}
}
