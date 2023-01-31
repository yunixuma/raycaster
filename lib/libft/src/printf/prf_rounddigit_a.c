/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_rounddigit_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/09 03:17:55 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_rounddigit_a(char *str, t_conv *conv)
{
	t_flen	*len;

	len = prf_rounddigit_a_getlen(str, conv);
	if (len == NULL)
		return (str);
	if ((conv->width > len->org && ft_hasflag(conv->flag, FLAG_ZERO) \
		&& !ft_hasflag(conv->flag, FLAG_LEFT)) \
		|| ft_hasflag(conv->flag, FLAG_PRECISION))
		str = prf_rounddigit_a_fill(str, conv, len);
	free (len);
	return (str);
}
