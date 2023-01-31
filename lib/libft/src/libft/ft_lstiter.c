/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka </var/mail/ykosaka>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:31:56 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/27 17:42:33 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if ((*f) != NULL)
	{
		while (lst != NULL)
		{
			if (lst->content != NULL)
				(*f)(lst->content);
			lst = lst->next;
		}
	}
}
