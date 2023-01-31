/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:19:03 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/04 01:55:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	prf_putstr(int fd, const char *s)
{
	if (s == NULL)
		return (prf_putstr(fd, STR_NULL));
	return (prf_putstrn(fd, s, ft_strlen(s), NULL));
}
