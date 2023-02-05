/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_distance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/05 21:25:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_math.h"

double	ft_math_distance_2d(t_coord *pt1, t_coord *pt2)
{
	double	dx;
	double	dy;

	if (!pt1 || !pt2)
		return (0);
	dx = pt1->x - pt2->x;
	dy = pt1->y - pt2->y;
	return (sqrt(dx * dx + dy * dy));
}

double	ft_math_distance_3d(t_coord *pt1, t_coord *pt2)
{
	double	dx;
	double	dy;
	double	dz;

	if (!pt1 || !pt2)
		return (0);
	dx = pt1->x - pt2->x;
	dy = pt1->y - pt2->y;
	dz = pt1->z - pt2->z;
	return (sqrt(dx * dx + dy * dy + dz * dz));
}
