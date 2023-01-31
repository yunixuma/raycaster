/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_rounddigit_a_fill_len.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/09 03:41:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flen2	*prf_rounddigit_a_fill_len(t_conv *conv, t_flen *len)
{
	t_flen2	*len2;

	len2 = (t_flen2 *)malloc(sizeof(t_flen2));
	if (len2 == NULL)
		return (NULL);
	len2->new = len->pt + 1 + (ssize_t)conv->precision + len->exp;
	if (conv->width > len2->new && ft_hasflag(conv->flag, FLAG_ZERO) \
		&& !ft_hasflag(conv->flag, FLAG_LEFT))
		len2->new = conv->width;
	len2->pad = len2->new - len->pt - 1 - (ssize_t)conv->precision - len->exp;
	len2->fill = len->pt + 1 + conv->precision - len->sig;
	return (len2);
}
