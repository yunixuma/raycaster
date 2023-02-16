/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2023/02/16 13:28:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_seterr(int errnum)
{
	if (errno == 0)
		errno = errnum;
	return (errnum);
}

int	ft_seterr_return(int ret, int errnum)
{
	ft_seterr(errnum);
	return (ret);
}

void	*ft_seterr_null(int errnum)
{
	ft_seterr(errnum);
	return (NULL);
}
