/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_putpadding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/04 01:56:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	prf_putpadding(int fd, t_conv *conv, ssize_t len_put, short flag_tgt)
{
	int		flag_and_tgt;
	ssize_t	ret;
	ssize_t	len_pad;

	if (len_put < 0)
		return (0);
	ret = 0;
	flag_and_tgt = conv->flag & flag_tgt;
	len_pad = conv->width - len_put;
	if (flag_tgt < 0 && flag_and_tgt == conv->flag \
		&& ft_hasflag(conv->type, TFLAG_C) \
		&& ft_hasflag(conv->flag, FLAG_ZERO))
	{
		while (len_pad-- > 0)
			ret += prf_putchar(fd, CHR_ZERO);
	}
	else if ((flag_tgt < 0 && flag_and_tgt == conv->flag) \
		|| flag_and_tgt == flag_tgt)
	{
		while (len_pad-- > 0)
			ret += prf_putchar(fd, CHR_SPACE);
	}
	return (ret);
}
