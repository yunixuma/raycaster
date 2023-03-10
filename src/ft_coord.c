/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/17 06:54:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_coord_init(t_coord *pt)
{
	if (!pt)
		return ;
	pt->x = 0;
	pt->y = 0;
	pt->z = 0;
}

void	ft_coord_set(t_coord *pt, double x, double y, double z)
{
	if (!pt)
		return ;
	pt->x = x;
	pt->y = y;
	pt->z = z;
}

void	ft_coord_copy(t_coord *dst, t_coord *src)
{
	if (!dst)
		return ;
	if (!src)
		ft_coord_init(dst);
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}
