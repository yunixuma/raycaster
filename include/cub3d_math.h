/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/17 08:06:15 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_MATH_H
# define CUB3D_MATH_H

# define _USE_MATH_DEFINES

# include <math.h>
# include <stdbool.h>
# include "cub3d_typedef.h"

# ifndef M_PI
#  define M_PI	3.141592653589793
# endif

double	ft_math_deg2rad(double deg);
double	ft_math_rad2deg(double rad);
double	ft_math_angle_normalize(double angle);
double	ft_math_sin_deg(double deg);
double	ft_math_cos_deg(double deg);
double	ft_math_distance_2d(t_coord *pt1, t_coord *pt2);
double	ft_math_distance_3d(t_coord *pt1, t_coord *pt2);
bool	ft_math_intersect_2d(t_vec *vec1, t_vec *vec2, t_coord *pt);

#endif
