/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_c3d_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/17 15:54:10 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug_c3d_f_angle(t_angle *angle)
{
	debug_printf("%%p: %p (", angle);
	debug_printf("r: %6.3lf, ", angle->roll);
	debug_printf("p: %6.3lf, ", angle->pitch);
	debug_printf("y: %6.3lf)\n", angle->yaw);
}

void	debug_c3d_f_coord(t_coord *coord)
{
	debug_printf("%%p: %p (", coord);
	debug_printf("%6.3lf, ", coord->x);
	debug_printf("%6.3lf, ", coord->y);
	debug_printf("%6.3lf)\n", coord->z);
}

void	debug_c3d_f_vec(t_vec *vec)
{
	debug_printf("vec\t%%p: %p\n", vec);
	debug_printf("pos\t");
	debug_c3d_f_coord(&vec->pos);
	debug_printf("dir\t");
	debug_c3d_f_coord(&vec->dir);
}

void	debug_c3d_f_vecs(t_opt *opt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < N_DIRECTION)
	{
		debug_printf("%zu(%#04x)\n", i, c3d_idx2flag_direction(i));
		j = 0;
		while (opt->vecs[i][j].pos.z != VAL_INVAL)
		{
			debug_c3d_f_vec(&opt->vecs[i][j]);
			j++;
		}
		i++;
	}
}
