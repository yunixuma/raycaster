/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_c3d_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/27 00:04:58 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	debug_c3d_img_data(int *data, int size_tile, int len)
{
	ssize_t	i_line;
	ssize_t	i_row;

	i_row = 0;
	while (i_row < size_tile)
	{
		i_line = 0;
		while (i_line < len)
		{
			*(data + i_row * size_tile + i_line) &= 0xffffff;
			*(data + i_row * size_tile + i_line) |= 0x7f0000ff;
			debug_printf("(%3zu, %3zu):\t", i_line, i_row);
			debug_printf("%8x\n", *(data + i_row * size_tile + i_line));
			i_line++;
		}
		i_row++;
	}
}

void	debug_c3d_img(t_img img, int size_tile)
{
	int		*data;
	int		len;
	int		bpp;
	int		endian;

	data = (int *)mlx_get_data_addr(img.ptr, &bpp, &len, &endian);
	debug_printf("len: %d\n", len);
	debug_printf("bpp: %d\n", bpp);
	debug_printf("endian: %d\n", endian);
	debug_c3d_img_data(data, size_tile, len);
}
