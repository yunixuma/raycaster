/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2023/01/23 00:08:37 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug_common.h"
/*
int	debug_printf(const char *format, ...)
{
	va_list	ap[2];
	ssize_t	ret;

	if (DEBUG_MODE == 0)
		return (0);
	errno = 0;
	va_start(ap[0], format);
	va_copy(ap[1], ap[0]);
	ret = ft_dprintf_sub(FD_DEBUG, format, ap);
	va_end(ap[1]);
	va_end(ap[0]);
	if (ret > INT_MAX || errno != 0)
		return (ERR_PRF);
	return (ret);
}
*/