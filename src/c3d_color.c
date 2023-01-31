/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/26 22:21:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_color_combine(t_color *color)
{
	int	color_code;

	if (color == NULL)
		return (0);
	color_code = color->r & MASK_CHANNEL;
	color_code <<= BITS_CHANNEL;
	color_code = (color_code & ~MASK_CHANNEL) | (color->g & MASK_CHANNEL);
	color_code <<= BITS_CHANNEL;
	color_code = (color_code & ~MASK_CHANNEL) | (color->b & MASK_CHANNEL);
	return (color_code);
}

void	c3d_color_separate(t_color *color, int color_code)
{
	if (color == NULL)
		return ;
	color->b = color_code & MASK_CHANNEL;
	color_code >>= BITS_CHANNEL;
	color->g = color_code & MASK_CHANNEL;
	color_code >>= BITS_CHANNEL;
	color->r = color_code & MASK_CHANNEL;
}
