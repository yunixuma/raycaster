/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/14 00:47:00 by Yoshihiro K      ###   ########.fr       */
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
		{
			ft_lstclear(&lst, &free);
			return (ft_seterr(ERR_ALLOC));
		}
		ft_lstadd_back(&lst, ele);
	}
	return (lst);
}
