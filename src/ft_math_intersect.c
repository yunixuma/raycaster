/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/19 00:25:12 by Yoshihiro K      ###   ########.fr       */
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

static bool	ft_math_intersect_2d_vertical(t_vec *vec1, t_vec *vec2, t_coord *pt)
{
	if (vec1->dir.x == 0)
	{
		pt->x = vec1->pos.x;
		pt->y = vec2->pos.y \
			+ vec2->dir.y / vec2->dir.x * (vec1->pos.x - vec2->pos.x);
		return (true);
	}
	else if (vec2->dir.x == 0)
	{
		pt->x = vec2->pos.x;
		pt->y = vec1->pos.y \
			+ vec1->dir.y / vec1->dir.x * (vec2->pos.x - vec1->pos.x);
		return (true);
	}
	return (false);
}

static bool	\
	ft_math_intersect_2d_holizontal(t_vec *vec1, t_vec *vec2, t_coord *pt)
{
	if (vec1->dir.y == 0)
	{
		pt->y = vec1->pos.y;
		pt->x = vec2->pos.x \
			+ vec2->dir.x / vec2->dir.y * (vec1->pos.y - vec2->pos.y);
		return (true);
	}
	else if (vec2->dir.y == 0)
	{
		pt->y = vec2->pos.y;
		pt->x = vec1->pos.x \
			+ vec1->dir.x / vec1->dir.y * (vec2->pos.y - vec1->pos.y);
		return (true);
	}
	return (false);
}

static bool	ft_math_intersect_2d_diagonal(t_vec *vec1, t_vec *vec2, t_coord *pt)
{
	double	a1;
	double	a2;

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

bool	ft_math_intersect_2d(t_vec *vec1, t_vec *vec2, t_coord *pt)
{
	if (!vec1 || !vec2)
		return (false);
	if (vec1->dir.x == 0 && vec2->dir.x == 0)
		return (false);
	if (ft_math_intersect_2d_vertical(vec1, vec2, pt))
		return (true);
	if (ft_math_intersect_2d_holizontal(vec1, vec2, pt))
		return (true);
	else if (ft_math_intersect_2d_diagonal(vec1, vec2, pt))
		return (true);
	return (false);
}
