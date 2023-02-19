/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_idx2flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/17 05:14:43 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	c3d_idx2flag_direction(size_t idx)
{
	if (idx == IDX_NORTH)
		return (FLAG_NORTH);
	else if (idx == IDX_EAST)
		return (FLAG_EAST);
	else if (idx == IDX_SOUTH)
		return (FLAG_SOUTH);
	else if (idx == IDX_WEST)
		return (FLAG_WEST);
	return (FLAG_NONE);
}
