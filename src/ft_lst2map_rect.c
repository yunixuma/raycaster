/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2map_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/31 16:50:39 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_lst2map_rect_getlen(t_list *lst, size_t *size)
{
	size_t	len;
	size_t	len_max;

	if (lst == NULL)
		return (0);
	len_max = ft_strlen(lst->content);
	while (lst != NULL)
	{
		len = ft_strlen(lst->content);
		if (len > len_max)
			len_max = len;
		(*size)++;
		lst = lst->next;
	}
	return (len_max);
}

static char	\
	*ft_lst2map_rect_copy_extend(char *content, size_t len_old, size_t len_max)
{
	char	*row;

	row = (char *)malloc((len_max + 1) * sizeof(char));
	if (row == NULL)
		return (NULL);
	ft_strlcpy(row, content, len_max + 1);
	ft_memset(row + len_old, CHRS_MAP[IDX_SPACE], len_max - len_old);
	row[len_max] = '\0';
	free(content);
	return (row);
}

static char	\
	**ft_lst2map_rect_copy(t_list *lst, size_t size, size_t len_max)
{
	char	**map;
	size_t	len_old;
	size_t	i;

	map = (char **)malloc((size + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		len_old = ft_strlen(lst->content);
		if (len_old == len_max)
			map[i] = lst->content;
		else
			map[i] = ft_lst2map_rect_copy_extend(lst->content, \
				len_old, len_max);
		if (map[i] == NULL)
			return (NULL);
		lst = lst->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**ft_lst2map_rect(t_list **lst)
{
	char	**map;
	size_t	size;
	size_t	len_max;

	size = 0;
	len_max = ft_lst2map_rect_getlen(*lst, &size);
	if (size == 0)
		c3d_exit_lst(ERR_ALLOC, lst);
	map = ft_lst2map_rect_copy(*lst, size, len_max);
	if (map == NULL)
		c3d_exit_lst(ERR_ALLOC, lst);
	ft_lstclear(lst, NULL);
	return (map);
}
