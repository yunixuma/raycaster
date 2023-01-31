/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_rounddigit_a_getlen.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/09 02:37:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flen	*prf_rounddigit_a_getlen(char *str, t_conv *conv)
{
	t_flen	*len;

	if (str == NULL)
		return (NULL);
	len = (t_flen *)malloc(sizeof(t_flen));
	if (len == NULL)
		return (NULL);
	len->org = ft_strlen(str);
	len->exp = len->org - prf_strnchr(str, CHR_EXP_A, len->org);
	len->pt = prf_strnchr(str, CHR_POINT, len->org);
	len->sig = len->pt + 1 + conv->precision;
	if (len->sig > len->org - len->exp)
		len->sig = len->org - len->exp;
	else if (conv->precision == 0 && !ft_hasflag(conv->flag, FLAG_ALT))
		conv->precision = -1;
	return (len);
}
