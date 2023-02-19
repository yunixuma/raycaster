/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map2vectors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/19 00:42:01 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	c3d_map2vectors_count(char **map, size_t id, t_addr *size)
{
	t_addr	i;
	size_t	count;

	count = 0;
	i.y = 0;
	while (i.y < size->y)
	{
		i.x = 0;
		while (i.x < size->x)
		{
			if (ft_hasflag(map[i.y][i.x], \
				FLAG_WALL | c3d_idx2flag_direction(id)))
				count++;
			i.x++;
		}
		i.y++;
	}
	return (count);
}

t_vec	c3d_map2vectors_getvec(t_addr *addr, size_t id)
{
	t_vec	vec;

	ft_coord_set(&vec.pos, addr->x, addr->y, 1);
	if (id == IDX_NORTH)
		vec.pos.x += 1;
	else if (id == IDX_SOUTH)
		vec.pos.y += 1;
	else if (id == IDX_EAST)
	{
		vec.pos.x += 1;
		vec.pos.y += 1;
	}
	ft_coord_init(&vec.dir);
	if (id == IDX_NORTH)
		vec.dir.x = -1;
	else if (id == IDX_SOUTH)
		vec.dir.x = 1;
	else if (id == IDX_EAST)
		vec.dir.y = -1;
	else if (id == IDX_WEST)
		vec.dir.y = 1;
	return (vec);
}

t_vec	*c3d_map2vectors_sub(char **map, size_t id, t_addr *size)
{
	t_vec	*vecs;
	size_t	size_vec;
	t_addr	i;
	size_t	j;

	size_vec = c3d_map2vectors_count(map, id, size);
	vecs = (t_vec *)malloc((size_vec + 1) * sizeof(t_vec));
	if (vecs == NULL)
		return (ft_seterr_null(ERR_ALLOC));
	j = 0;
	i.y = 0;
	while (i.y < size->y)
	{
		i.x = 0;
		while (i.x < size->x)
		{
			if (ft_hasflag(map[i.y][i.x], \
				FLAG_WALL | c3d_idx2flag_direction(id)))
				vecs[j++] = c3d_map2vectors_getvec(&i, id);
			i.x++;
		}
		i.y++;
	}
	vecs[size_vec].pos.z = VAL_INVAL;
	return (vecs);
}

int	c3d_map2vectors(t_opt *opt, t_scene *scene)
{
	size_t	id;

	id = 0;
	while (id < N_DIRECTION)
	{
		opt->vecs[id] = c3d_map2vectors_sub(scene->map, id, &opt->size);
		if (opt->vecs[id] == NULL)
			return (errno);
		id++;
	}
	return (ERR_NOERR);
}

int	c3d_map2vectors_free(t_opt *opt, int errnum)
{
	size_t	i;

	if (opt != NULL)
		return (errnum);
	i = 0;
	while (i < N_DIRECTION)
	{
		if (opt->vecs[i])
		{
			free(opt->vecs[i]);
			opt->vecs[i] = NULL;
		}
		i++;
	}
	opt = NULL;
	return (c3d_exit(errnum));
}
