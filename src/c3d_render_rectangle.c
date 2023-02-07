/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_rectangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/07 21:54:51 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	c3d_render_rectangle(t_img *img, \
	int color_code, t_addr *zero, t_addr *area)
{
	ssize_t	i_col;
	ssize_t	i_row;

	i_row = 0;
	while (i_row < area->y)
	{
		i_col = 0;
		while (i_col < area->x)
		{
			img->data[img->width * (zero->y + i_row) + zero->x + i_col] \
				= color_code;
			i_col++;
		}
		i_row++;
	}
}
