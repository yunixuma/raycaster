/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_setconv_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/04 15:04:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prf_setconv_l(const char *str, ssize_t len_conv, int type)
{
	ssize_t	pos_found;

	pos_found = prf_strnchr(str, 'l', len_conv);
	if (pos_found < len_conv)
	{
		if (prf_strnchr(str + pos_found + 1, 'l', len_conv - pos_found - 1) \
			< len_conv - pos_found - 1)
			return (sizeof(long long));
		if (ft_hasflag(type, TFLAG_C))
			return (sizeof(wchar_t));
		return (sizeof(long));
	}
	return (0);
}

static int	prf_setconv_h(const char *str, ssize_t len_conv)
{
	ssize_t	pos_found;

	pos_found = prf_strnchr(str, 'h', len_conv);
	if (pos_found < len_conv)
	{
		if (prf_strnchr(str + pos_found + 1, 'h', len_conv - pos_found - 1) \
			< len_conv - pos_found - 1)
			return (sizeof(char));
		return (sizeof(short));
	}
	return (0);
}

static int	prf_setconv_lendbl(const char *str, ssize_t len_conv)
{
	if (prf_strnchr(str, 'L', len_conv) < len_conv)
		return (sizeof(long double));
	return (0);
}

int	prf_setconv_length(const char *str, ssize_t len_conv, int type)
{
	unsigned int	length;

	if (ft_hasflag(type, TFLAG_DBL))
		return (prf_setconv_lendbl(str, len_conv));
	length = prf_setconv_l(str, len_conv, type);
	if (length == 0)
		length = prf_setconv_h(str, len_conv);
	if (prf_strnchr(str, 'z', len_conv) < len_conv)
	{
		if (length < sizeof(size_t))
			length = sizeof(size_t);
	}
	if (prf_strnchr(str, 't', len_conv) < len_conv)
	{
		if (length < sizeof(ptrdiff_t))
			length = sizeof(ptrdiff_t);
	}
	if (prf_strnchr(str, 'j', len_conv) < len_conv)
	{
		if (length < sizeof(intmax_t))
			length = sizeof(intmax_t);
	}
	return (length);
}
