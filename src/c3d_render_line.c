/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/14 22:28:46 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_line(t_img *img, int color_code, t_addr *zero, t_coord *line)
{
	t_addr	addr;
	ssize_t	i;
	ssize_t	len;

	len = (ssize_t)line->z;
	i = 0;
	while (i < len)
	{
		addr.x = zero->x + (ssize_t)(i * line->x);
		addr.y = zero->y + (ssize_t)(i * line->y);
		if (addr.x >= 0 && addr.x < img->width \
			&& addr.y > 0 && addr.y < img->height)
			img->data[img->width * addr.y + addr.x] = color_code;
		i++;
	}
}
