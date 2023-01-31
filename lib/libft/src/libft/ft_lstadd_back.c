/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:04:24 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/27 00:23:16 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*prev;

	if (lst == NULL)
		lst = &new;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		prev = ft_lstlast(*lst);
		prev->next = new;
	}
}
