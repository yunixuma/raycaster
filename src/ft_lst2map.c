/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/21 21:13:08 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_lst2map(t_list **lst)
{
	char	**map;
	t_list	*ele;
	size_t	size;
	size_t	i;

	size = ft_lstsize(*lst);
	ele = *lst;
	map = (char **)malloc((size + 1) * sizeof(char *));
	if (map == NULL)
		c3d_exit_lst(ERR_ALLOC, lst);
	i = 0;
	while (i < size)
	{
		map[i] = ele->content;
		ele = ele->next;
		i++;
	}
	map[i] = NULL;
	ft_lstclear(lst, NULL);
	return (map);
}
