/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_imgpixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/07 22:00:33 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_imgpixel(t_img *img, int src_id, t_addr *dst, t_addr *src)
{
	img[IDX_VISION].data[img[IDX_VISION].width * dst->y + dst->x] \
		= img[src_id].data[img[src_id].width * src->y + src->x];
}
