/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inrange.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/17 22:43:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
bool	ft_inrange(int nb, int lower, int upper)
{
	if (lower > upper)
		return (!ft_inrange(nb, upper + 1, lower - 1));
	return (lower <= nb && nb <= upper);
}
*/
bool	ft_inrange_dbl(double nb, double lower, double upper)
{
	if (lower > upper)
		return (ft_inrange_dbl(nb, upper, lower));
	return (lower <= nb && nb <= upper);
}
