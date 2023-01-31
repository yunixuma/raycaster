/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 13:24:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*c3d_map_read(int fd)
{
	t_list	*lst;
	t_list	*ele;
	char	*line;

	lst = NULL;
	line = STR_EMPTY;
	while (line != NULL)
	{
		line = get_next_line(fd);
		ele = ft_lstnew(line);
		if (ele == NULL)
			c3d_exit_lst(ERR_ALLOC, &lst);
		ft_lstadd_back(&lst, ele);
	}
	return (lst);
}
