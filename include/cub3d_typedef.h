/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_typedef.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/26 14:56:27 by Yoshihiro K      ###   ########.fr       */
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

typedef union u_color
{
	unsigned int	code;
	unsigned char	ch[N_CHANNEL];
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

typedef struct s_opt
{
	t_vec	*vecs[N_DIRECTION];
	t_addr	size;
}	t_opt;

typedef struct s_game
{
	t_angle	angle;
	t_coord	coord;
	double	fov;
	int		event;
	int		key;
	t_addr	cursor;
	int		speed;
	int		score;
}	t_game;

typedef struct s_mlx
{
	void	*conn;
	void	*win;
	t_img	img[N_IMAGE];
	t_scene	*scene;
	t_opt	*opt;
	t_game	game;
	int		scale;
}	t_mlx;

#endif
