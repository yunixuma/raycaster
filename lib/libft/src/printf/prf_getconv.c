/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_getconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/04 16:23:19 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	prf_getconv_len(const char *str)
{
	const char	*str_head;

	if (str == NULL)
		return (0);
	str_head = str;
	while (ft_strchr(CHRS_FLAG, *str) != NULL)
		str++;
	return (str - str_head + (*str != '\0'));
}

t_conv	*prf_getconv(const char *str, va_list *ap, ssize_t *pos)
{
	t_conv		*conv;

	if (str == NULL || *(str + *pos) != CHR_CONV)
		return (NULL);
	conv = (t_conv *)malloc(sizeof(t_conv));
	if (conv == NULL)
		return (NULL);
	conv->len = prf_getconv_len(str + ++(*pos));
	conv = prf_setconv(str + *pos, ap, conv);
	if (conv == NULL)
		return (NULL);
	*pos += conv->len;
	return (conv);
}
