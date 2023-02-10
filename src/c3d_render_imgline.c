/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_imgline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/10 12:23:51 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_imgline(t_img *img_dst, t_img *img_src, \
	t_addr *dst, t_addr *src)
{
	ssize_t	i_row;

	if (src->x < 0 || src->x >= img_src->width || src->y <= 0 \
		|| dst->x < 0 || dst->x >= img_dst->width)
		return ;
	i_row = 0;
	while (i_row < src->y && dst->y + i_row < img_dst->height)
	{
		if (dst->y + i_row >= 0)
			img_dst->data[img_dst->width \
				* (dst->y + i_row) + dst->x] \
				= img_src->data[img_src->width \
				* (int)(i_row * img_src->height / src->y) + src->x];
		i_row++;
	}
}
