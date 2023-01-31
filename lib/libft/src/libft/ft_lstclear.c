/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:00:50 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/27 03:15:58 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	void	*next;
	t_list	*ele;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		ele = *lst;
		next = ele->next;
		ft_lstdelone(*lst, (*del));
		*lst = next;
	}
	lst = NULL;
}
