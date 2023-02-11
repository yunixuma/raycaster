/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_blend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/11 12:01:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_blend(t_img *img_dst, t_img *img_src, t_addr *zero)
{
	t_addr			i;
	unsigned int	fore;
	unsigned int	back;
	unsigned int	alpha;

	i.y = 0;
	while (i.y < img_src->height)
	{
		i.x = 0;
		while (i.x < img_src->width)
		{
			fore = img_src->data[i.y * img_src->width + i.x];
			alpha = fore >> (BITS_CHANNEL * N_CHANNEL);
			fore &= ~(MASK_CHANNEL << (BITS_CHANNEL * N_CHANNEL));
			back = img_dst->data[(zero->y + i.y) * img_dst->width \
				+ zero->x + i.x];
			img_dst->data[(zero->y + i.y) * img_dst->width + zero->x + i.x] \
				= (fore * ((1 << BITS_CHANNEL) - alpha) + back * alpha) \
				>> BITS_CHANNEL;
			i.x++;
		}
		i.y++;
	}
}
