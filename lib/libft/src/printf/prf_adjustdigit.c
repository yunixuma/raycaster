/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_adjustdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/12 02:26:26 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	prf_adjdigit_offset(const char *str)
{
	const char	*str_head;

	str_head = str;
	while (*str != '\0' && !ft_isxdigit(*str))
		str++;
	return (str - str_head);
}

static ssize_t	prf_adjdigit_len(t_conv *conv, ssize_t offset, ssize_t digits)
{
	ssize_t		len;

	len = offset + digits;
	if (digits < conv->precision)
		len = offset + conv->precision;
	else if (len < conv->width && ft_hasflag(conv->flag, FLAG_ZERO) \
		&& !ft_hasflag(conv->flag, (FLAG_PRECISION | FLAG_LEFT)))
	{
		if ((ft_hasflag(conv->flag, FLAG_ALT) \
			&& ft_hasflag(conv->type, TYPE_X)) \
			|| ft_hasflag(conv->type, TYPE_P))
			len = conv->width - ft_strlen(STR_PRE_X);
		else
			len = conv->width;
	}
	return (len);
}

char	*prf_adjustdigit(char *str, t_conv *conv)
{
	char	*str_new;
	ssize_t	len;
	ssize_t	offset;
	ssize_t	digits;

	offset = prf_adjdigit_offset(str);
	digits = 0;
	while (*(str + offset + digits) != '\0')
		digits++;
	len = prf_adjdigit_len(conv, offset, digits);
	if (len == offset + digits)
		return (str);
	str_new = (char *)malloc((len + 1) * sizeof(char));
	if (str_new == NULL)
		return (str);
	ft_strlcpy(str_new, str, offset + 1);
	if ((ft_hasflag(conv->flag, FLAG_ZERO) \
		&& !ft_hasflag(conv->flag, FLAG_LEFT)) \
		|| ft_hasflag(conv->flag, FLAG_PRECISION))
		ft_memset(str_new + offset, CHR_ZERO, len - digits - offset);
	ft_strlcpy(str_new + len - digits, str + offset, digits + 1);
	free(str);
	return (str_new);
}
