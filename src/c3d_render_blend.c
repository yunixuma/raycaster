/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_blend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 15:20:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_blend(t_img *img_dst, t_img *img_src, t_addr *zero)
{
	t_addr			i;
	t_color			fore;
	t_color			back;
	unsigned char	alpha;

	i.y = 0;
	while (i.y < img_src->height)
	{
		i.x = 0;
		while (i.x < img_src->width)
		{
			fore.code = img_src->data[i.y * img_src->width + i.x];
			alpha = fore.ch[N_CHANNEL - 1 - IDX_ALPHA];
			fore.ch[N_CHANNEL - 1 - IDX_ALPHA] = 0;
			back.code = img_dst->data[(zero->y + i.y) * img_dst->width \
				+ zero->x + i.x];
			back.ch[N_CHANNEL - 1 - IDX_ALPHA] = 0;
			img_dst->data[(zero->y + i.y) * img_dst->width + zero->x + i.x] \
				= (fore.code \
				* ((1 << BITS_CHANNEL) - alpha) + back.code * alpha) \
				>> BITS_CHANNEL;
			i.x++;
		}
		i.y++;
	}
}
