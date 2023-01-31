/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_setconv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/14 20:52:57 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	*prf_setconv(const char *str, va_list *ap, t_conv *conv)
{
	if (conv->len == 0)
		conv->type = 0;
	else
		conv->type = prf_setconv_type(str, conv->len);
	conv->flag = prf_setconv_flag(str, conv->len);
	conv->order = prf_setconv_order(str, conv->len);
	if (conv->order > 0)
		prf_shiftarg(conv, ap);
	prf_setconv_wandp(str, &ap[1], &conv);
	return (conv);
}
