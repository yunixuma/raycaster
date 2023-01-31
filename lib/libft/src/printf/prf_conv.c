/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/04 02:08:09 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	prf_conv(int fd, const char *fmt, va_list *ap, t_len *lens)
{
	t_conv	*conv;
	char	*str_put;
	ssize_t	len_put;
	ssize_t	ret;

	conv = prf_getconv(fmt, ap, &(lens->pos));
	if (conv == NULL)
		return (0);
	ret = 0;
	str_put = prf_convarg(conv, &ap[1], lens->ret_tmp);
	if (str_put == NULL)
		str_put = STR_EMPTY;
	len_put = prf_putlen(str_put, conv);
	ret += prf_putpadding(fd, conv, len_put, ~FLAG_LEFT);
	ret += prf_putstrn(fd, str_put, len_put, conv);
	ret += prf_putpadding(fd, conv, len_put, FLAG_LEFT);
	if (!ft_hasflag(conv->type, TYPE_S) && conv->type > TMASK_LEN)
		free(str_put);
	free(conv);
	return (ret);
}
