/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_imgline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/07 22:00:29 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_imgline(t_img *img, int src_id, t_addr *dst, t_addr *src)
{
	ssize_t	i_row;

	if (src->x < 0 || src->x >= img[src_id].width || src->y <= 0 \
		|| dst->x < 0 || dst->x >= img[IDX_VISION].width)
		return ;
	i_row = 0;
	while (i_row < src->y && dst->y + i_row < img[IDX_VISION].height)
	{
		if (dst->y + i_row >= 0)
			img[IDX_VISION].data[img[IDX_VISION].width \
				* (dst->y + i_row) + dst->x] \
				= img[src_id].data[img[src_id].width \
				* (int)(i_row * img[src_id].height / src->y) + src->x];
		i_row++;
	}
}
