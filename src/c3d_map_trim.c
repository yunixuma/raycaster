/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_map_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/03/11 21:45:29 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	c3d_map_trim_eol(t_list *lst)
{
	t_list	*ele;
	char	*eol;

	ele = lst;
	while (ele != NULL && ele->content != NULL)
	{
		eol = ft_strrchr(ele->content, '\n');
		if (eol != NULL)
			*eol = '\0';
		ele = ele->next;
	}
	return (ERR_NOERR);
}

static int	c3d_map_trim_top(t_list **lst)
{
	t_list	*ele;

	while ((*lst)->content == NULL || *(char *)(*lst)->content == '\0')
	{
		ele = *lst;
		*lst = ele->next;
		ft_free(&ele->content);
		ft_free((void **)&ele);
	}
	return (ERR_NOERR);
}

static int	c3d_map_trim_bottom(t_list *lst)
{
	t_list	*ele;

	ele = lst;
	while (ele->next->next != NULL)
		ele = ele->next;
	while (ele->next != NULL && (ele->next->content == NULL \
		|| *(char *)(ele->next->content) == '\0'))
	{
//DS((char *)lst->content);
//DP(lst->next);
		ft_free(&ele->next->content);
		ft_free((void **)&ele->next);
		ele->next = NULL;
		ele = lst;
		while (ele->next != NULL && ele->next->next != NULL)
			ele = ele->next;
	}
	return (ERR_NOERR);
}

int	c3d_map_trim(t_list **lst)
{
	if (lst == NULL || *lst == NULL \
		|| (*lst)->content == NULL || (*lst)->next == NULL)
		return (ft_seterr(ERR_EMPTY));
	c3d_map_trim_eol(*lst);
	c3d_map_trim_top(lst);
	c3d_map_trim_bottom(*lst);
	return (ERR_NOERR);
}
