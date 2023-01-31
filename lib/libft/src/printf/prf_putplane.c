/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_putplane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:19:03 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/04 01:54:53 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	prf_putplane(int fd, const char *s, ssize_t *pos)
{
	ssize_t	len;
	ssize_t	ret;

	ret = 0;
	if (s == NULL)
		return (prf_putstr(fd, NULL));
	len = prf_strnchr(s + *pos, CHR_CONV, SSIZE_MAX);
	ret = prf_putstrn(fd, s + *pos, len, NULL);
	*pos += len;
	return (ret);
}
