/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_typedef.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/08 22:49:04 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPEDEF_H
# define CUB3D_TYPEDEF_H

# include <unistd.h>
# include "cub3d_const.h"

typedef struct s_addr
{
	ssize_t	x;
	ssize_t	y;
}	t_addr;

typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef struct s_angle
{
	double	pitch;
	double	yaw;
	double	roll;
}	t_angle;

typedef struct s_vec
{
	t_coord	pos;
	t_coord	dir;
}	t_vec;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		len;
	int		bpp;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_scene
{
	char	*path[N_TEXTURE];
	int		color[N_COLOR];
	char	**map;
}	t_scene;

typedef struct s_game
{
	t_angle	angle;
	t_coord	coord;
	double	fov;
	int		key;
	int		score;
}	t_game;

typedef struct s_mlx
{
	void	*conn;
	void	*win;
	t_img	img[N_TEXTURE + 1];
	t_scene	*scene;
	t_game	game;
}	t_mlx;

#endif
