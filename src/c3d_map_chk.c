/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_chk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/14 01:05:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_map_chk_chr_line(char *str, int countchr[SIZE_CHRS_MAP])
{
	const char	*chrs = CHRS_MAP;
	char		*pos;

	while (*str != '\0')
	{
		pos = ft_strchr(chrs, *str);
		if (pos == NULL)
			return (ft_seterr_return(ERR_CHR, ERR_CHR));
		(countchr[pos - chrs])++;
		str++;
	}
	return (ERR_NOERR);
}

static int	c3d_map_chk_chr_count(int countchr[])
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < N_DIRECTION)
		count += countchr[IDX_NORTH + i++];
	if (count != 1)
		return (ft_seterr_return(ERR_COUNT, ERR_COUNT));
	return (ERR_NOERR);
}

static int	c3d_map_chk_chr(t_list *lst)
{
	int		countchr[SIZE_CHRS_MAP];
	size_t	i;

	i = 0;
	while (i < SIZE_CHRS_MAP)
		countchr[i++] = 0;
	while (lst != NULL)
	{
		if (c3d_map_chk_chr_line(lst->content, countchr))
			return (errno);
		lst = lst->next;
	}
	if (c3d_map_chk_chr_count(countchr))
		return (errno);
	return (ERR_NOERR);
}

static int	c3d_map_chk_len(t_list *lst)
{
	if (lst == NULL || lst->content == NULL)
		return (ft_seterr_return(ERR_EMPTY, ERR_EMPTY));
	while (lst != NULL)
	{
		if (!lst->content || *(char *)lst->content == '\0')
			return (ft_seterr_return(ERR_EMPTY, ERR_EMPTY));
		lst = lst->next;
	}
	return (ERR_NOERR);
}

int	c3d_map_chk(t_list **lst)
{
	if (c3d_map_chk_len(*lst))
		return (errno);
	if (c3d_map_chk_chr(*lst))
		return (errno);
	return (ERR_NOERR);
}
