/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/13 23:11:16 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_free(void **p)
{
	if (p == NULL)
		return (NULL);
	if (*p != NULL)
		free(*p);
	*p = NULL;
	return (NULL);
}

void	*ft_free_seterr(void **p, int errnum)
{
	if (p)
		ft_free(p);
	return (ft_seterr(errnum));
}
