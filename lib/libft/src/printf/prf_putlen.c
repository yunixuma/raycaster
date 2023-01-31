/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_putlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/13 21:25:18 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	prf_putlen(char *str, t_conv *conv)
{
	ssize_t	len;

	if (ft_hasflag(conv->type, TFLAG_C) \
		&& (conv->type & TMASK_LEN) == sizeof(wchar_t))
		len = ft_wcslen(str);
	else
		len = ft_strlen(str);
	if (len == 0 && ft_hasflag(conv->type, TYPE_C))
		len = 1;
	if (ft_hasflag(conv->type, TYPE_S) \
		&& ft_hasflag(conv->flag, FLAG_PRECISION) \
		&& conv->precision < len && conv->precision >= 0)
		len = conv->precision;
	if (len < 0)
		return (SSIZE_MAX);
	return (len);
}
