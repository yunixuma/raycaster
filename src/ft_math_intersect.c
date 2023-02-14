/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/13 18:57:08 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
static void	ft_math_intersect_2d_exception(t_vec *vec1, t_vec *vec2, t_coord *pt)
{
	if (vec1)
		ft_coord_copy(pt, &vec1->pos);
	else if (vec2)
		ft_coord_copy(pt, &vec2->pos);
	else
		ft_coord_init(pt);
}
*/

bool	ft_math_intersect_2d(t_vec *vec1, t_vec *vec2, t_coord *pt)
{
	double	a1;
	double	a2;

	if (!vec1 || !vec2)
	{
//		ft_math_intersect_2d_exception(vec1, vec2, pt);
		return (false);
	}
	a1 = vec1->dir.y / vec1->dir.x;
	a2 = vec2->dir.y / vec2->dir.x;
	if (a1 == a2)
		return (false);
	pt->x = a1 * vec1->pos.x - vec1->pos.y + a2 * vec2->pos.x - vec2->pos.y;
	pt->x /= a1 - a2;
	pt->y = a1 * a2 * (vec1->pos.x - vec2->pos.x + a1) \
		+ vec2->pos.y - vec1->pos.x;
	pt->y /= a1 - a2;
	return (true);
}
