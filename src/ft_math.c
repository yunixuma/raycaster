/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/30 13:23:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_math.h"

long long	ft_math_dtoll(double num)
{
	return ((long long)num);
}

double	ft_math_deg2rad(int deg)
{
	return (M_PI * deg / 180);
}

int	ft_math_rad2deg(double rad)
{
	return ((int)(rad * 180 / M_PI));
}

int	ft_math_angle_normalize(int angle)
{
	if (angle > 180)
		angle -= 360;
	else if (angle < -180)
		angle += 360;
	return (angle);
}
