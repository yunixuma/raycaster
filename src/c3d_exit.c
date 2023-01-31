/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 13:24:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	c3d_exit(int errnum)
{
	if (errnum != ERR_NOERR)
		c3d_print_err(errnum);
	exit(errnum);
}

int	c3d_exit_lst(int errnum, t_list **lst)
{
	ft_lstclear(lst, free);
	return (c3d_exit(errnum));
}

int	c3d_exit_map(int errnum, char **map)
{
	c3d_map_clear_free(map);
	return (c3d_exit(errnum));
}
