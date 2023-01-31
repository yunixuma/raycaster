/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_rounddigit_fill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/08 13:39:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	prf_rounddigit_getoffset(const char *str)
{
	const char	*str_head;

	str_head = str;
	while (*str != '\0' && !ft_isdigit(*str))
		str++;
	if (str - str_head > SSIZE_MAX)
		return (SSIZE_MAX);
	return (str - str_head);
}

char	*prf_rounddigit_fill(char *str, t_conv *conv, ssize_t len)
{
	char	*str_new;
	ssize_t	offset;

	if (conv->width <= len || !ft_hasflag(conv->flag, FLAG_ZERO) \
		|| ft_hasflag(conv->flag, FLAG_LEFT))
		return (str);
	offset = prf_rounddigit_getoffset(str);
	str_new = (char *)malloc((conv->width + 1) * sizeof(char));
	if (str_new == NULL)
		return (str);
	ft_strlcpy(str_new, str, offset + 1);
	ft_memset(str_new + offset, CHR_ZERO, conv->width - len);
	ft_strlcpy(str_new + offset + conv->width - len, \
		str + offset, len - offset + 1);
	free(str);
	return (str_new);
}
