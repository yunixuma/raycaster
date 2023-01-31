/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_rounddigit_getlen.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/13 14:00:57 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_fpos	*prf_rounddigit_g_getpos(char *str, t_flen *len)
{
	t_fpos	*pos;

	pos = (t_fpos *)malloc(sizeof(t_fpos));
	if (pos == NULL)
		return (NULL);
	pos->end = len->org - len->exp - 1;
	while (pos->end > len->pt && *(str + pos->end) == '0')
		pos->end--;
	if (pos->end == len->pt)
		return (0);
	pos->hi = 0;
	while (pos->hi < pos->end && !prf_isdigit19(*(str + pos->hi)))
		pos->hi++;
	return (pos);
}

static int	prf_rounddigit_g(char *str, t_flen *len, int precision)
{
	t_fpos	*pos;

	if (len->pt == len->org)
		return (0);
	pos = prf_rounddigit_g_getpos(str, len);
	if (pos == NULL)
		return (precision);
	if (len->pt < pos->hi)
	{
		if (pos->end - pos->hi > precision)
			precision += pos->hi - len->pt - 1;
		else
			precision = pos->end - len->pt;
	}
	else
		precision -= len->pt - pos->hi;
	free(pos);
	if (precision < 0)
		return (0);
	return (precision);
}

t_flen	*prf_rounddigit_getlen(char *str, t_conv *conv)
{
	t_flen	*len;

	if (str == NULL)
		return (NULL);
	len = (t_flen *)malloc(sizeof(t_flen));
	if (len == NULL)
		return (NULL);
	len->org = ft_strlen(str);
	len->exp = len->org - prf_strnchr(str, CHR_EXP, len->org);
	len->pt = prf_strnchr(str, CHR_POINT, len->org);
	if (ft_hasflag(conv->type, TFLAG_G))
		conv->precision = prf_rounddigit_g(str, len, conv->precision);
	len->sig = len->pt + 1 + conv->precision;
	return (len);
}
