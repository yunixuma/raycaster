/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg_ws.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/17 01:22:45 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*prf_convarg_ws(wchar_t *str, t_conv *conv)
{
	if (ft_hasflag(conv->flag, FLAG_PRECISION) && conv->precision <= 0)
		return ((wchar_t *)STR_EMPTY);
	if (str == NULL)
		return ((wchar_t *)STR_NULL);
	return (str);
}
