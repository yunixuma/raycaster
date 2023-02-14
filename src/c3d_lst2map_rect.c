/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_lst2map_rect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/14 01:08:34 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	c3d_lst2map_rect_getlen(t_list *lst, size_t *size)
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

static char	*c3d_lst2map_rect_copy_extend(char *content, \
	size_t len_orig, size_t len_fixed)
{
	char	*row;

	row = (char *)malloc((len_fixed + 1) * sizeof(char));
	if (row == NULL)
		return (NULL);
	ft_strlcpy(row, content, len_fixed + 1);
	if (len_fixed > len_orig)
	{
		ft_memset(row + len_orig, CHRS_MAP[IDX_SPACE], len_fixed - len_orig);
		row[len_fixed] = '\0';
	}
	free(content);
	return (row);
}

static char	\
	**c3d_lst2map_rect_copy(t_list *lst, size_t size, size_t len_fixed)
{
	char	**map;
	size_t	len_orig;
	size_t	i;

	map = (char **)malloc((size + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		len_orig = ft_strlen(lst->content);
		if (len_orig == len_fixed)
			map[i] = lst->content;
		else
			map[i] = c3d_lst2map_rect_copy_extend(lst->content, \
				len_orig, len_fixed);
		if (map[i] == NULL)
			return (NULL);
		lst = lst->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**c3d_lst2map_rect(t_list **lst)
{
	char	**map;
	size_t	size;
	size_t	len_fixed;

	size = 0;
	len_fixed = c3d_lst2map_rect_getlen(*lst, &size);
	if (size == 0)
		return (ft_seterr(ERR_EMPTY));
	map = c3d_lst2map_rect_copy(*lst, size, len_fixed);
	if (map == NULL)
		return (ft_seterr(ERR_ALLOC));
	return (map);
}
