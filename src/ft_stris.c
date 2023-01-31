/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stris.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:57:55 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/23 02:12:51 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_stris(const char *str, int (*f)(int))
{
	if (str == NULL || *str == '\0')
		return (false);
	while (*str)
	{
		if (f(*str) == false)
			return (false);
		str++;
	}
	return (true);
}
