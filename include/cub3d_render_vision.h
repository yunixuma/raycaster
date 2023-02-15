/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_render_vision.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:58:35 by kobayashi         #+#    #+#             */
/*   Updated: 2023/02/15 20:32:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_RENDER_VISION_H
# define CUB3D_RENDER_VISION_H

# include <stdint.h>
# include <math.h>

# include "mlx.h"
# include "libft.h"

#define mapWidth 24
#define mapHeight 24
// #define WIDTH_VISION 640
// #define HEIGHT_VISION 480
#define WALL_HEIGHT_BASE 500
#define texWidth 64
#define texHeight 64
#define IDX_VISION 4

// typedef enum e_chr
// {
// 	IDX_NORTH,
// 	IDX_EAST,
// 	IDX_SOUTH,
// 	IDX_WEST,
// 	IDX_FREE,
// 	IDX_WALL,
// 	IDX_SPACE,
// 	SIZE_CHRS_MAP
// }	t_chr;

// typedef struct s_img
// {
// 	void	*ptr;
// 	int		*data;
// 	int		len;
// 	int		bpp;
// 	int		endian;
// 	int		width;
// 	int		height;
// }	t_img;

// typedef struct s_mlx
// {
// 	void	*conn;
// 	void	*win;
// 	t_img	*img;
// }	t_mlx;

typedef struct s_vector {
    double	x;
    double	y;
}	t_vector;

typedef struct s_distance {
    double	x;
    double	y;
}	t_distance;

typedef struct s_double_position {
    double	x;
    double	y;
}	t_double_position;

typedef struct s_int_position {
    int	x;
    int	y;
}	t_int_position;

typedef struct s_ray_calculation {
    t_double_position	player_pos;
	t_int_position		grid_pos;
	t_int_position		player_step;
	t_int_position		tex_pos;
	t_vector			base_vc;
	t_vector			screen_vc;
	t_vector			ray_vc;
	t_distance			dist;
	t_distance			delta_dist;
	double				dist_wall;
	int					side;
	t_chr				wall_dir;
	int					wall_height;
	int					wall_start;
	int					wall_end;
	double				dist_tex_y;
	double				init_tex_y;
}	t_ray_calculation;

void	get_hit_wall(t_ray_calculation *c);
void	extend_ray(t_mlx *mlx, t_ray_calculation *c);
void	create_gridmap(t_ray_calculation *c);
void	get_ray_vec(t_ray_calculation *c, int x);
void	rotate_view(t_mlx *mlx, t_ray_calculation *c);

#endif