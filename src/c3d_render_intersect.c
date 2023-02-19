/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_render_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/19 00:50:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_render_intersect_calc(t_coord *pt, t_vec *wall, t_vec *ray)
{
	if (!ft_math_intersect_2d(ray, wall, pt))
		return (false);
	if (ft_inrange_dbl(pt->x, wall->pos.x, wall->pos.x + wall->dir.x) \
		&& ft_inrange_dbl(pt->y, wall->pos.y, wall->pos.y + wall->dir.y) \
		&& (pt->x - ray->pos.x) * ray->dir.x >= 0 \
		&& (pt->y - ray->pos.y) * ray->dir.y >= 0)
	{
//debug_c3d_f_vec(ray);
//debug_c3d_f_vec(wall);
//debug_c3d_f_coord(pt);
		return (true);
	}
	return (false);
}

static void	c3d_render_intersect_update(t_coord (*pt)[2], \
	int (*tex_id)[2], t_coord *pos)
{
//DP(pt[0]);
//debug_c3d_f_coord(pt[0]);
	if ((*pt)[1].z == VAL_INVAL \
		|| ft_math_distance_2d(pos, &(*pt)[0]) \
		< ft_math_distance_2d(pos, &(*pt)[1]))
	{

		ft_coord_copy(&(*pt)[1], &(*pt)[0]);
		(*tex_id)[1] = (*tex_id)[0];
	}
}

static void	c3d_render_intersect_dir(t_vec *vecs, t_coord (*pt)[2], \
	int (*tex_id)[2], t_vec *ray)
{
	size_t	i;

	i = 0;
	while (vecs[i].pos.z != VAL_INVAL)
	{
		if (c3d_render_intersect_calc(&(*pt)[0], &vecs[i], ray))
			c3d_render_intersect_update(pt, tex_id, &ray->pos);
		i++;
	}
}

void	c3d_render_intersect(t_mlx *mlx, int i_col, t_vec *ray)
{
	t_coord	pt[2];
	int		tex_id[2];

	pt[0].z = 1;
	pt[1].z = VAL_INVAL;
	tex_id[1] = VAL_INVAL;
	tex_id[0] = IDX_NORTH;
	if (ray->dir.y > 0)
		c3d_render_intersect_dir(mlx->opt->vecs[tex_id[0]], &pt, &tex_id, ray);
	tex_id[0] = IDX_EAST;
	if (ray->dir.x < 0)
		c3d_render_intersect_dir(mlx->opt->vecs[tex_id[0]], &pt, &tex_id, ray);
	tex_id[0] = IDX_SOUTH;
	if (ray->dir.y < 0)
		c3d_render_intersect_dir(mlx->opt->vecs[tex_id[0]], &pt, &tex_id, ray);
	tex_id[0] = IDX_WEST;
	if (ray->dir.x > 0)
		c3d_render_intersect_dir(mlx->opt->vecs[tex_id[0]], &pt, &tex_id, ray);
//DI(tex_id[1]);
//debug_c3d_f_coord(&pt[1]);
	if (tex_id[1] != VAL_INVAL)
		c3d_render_elevation(mlx, &pt[1], i_col, tex_id[1]);
}
