/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_rounddigit_a_fill.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/11 11:19:44 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prf_rounddigit_a_up(char *str, ssize_t pos, ssize_t len)
{
	if (pos < 0 || ft_strchr(CHRS_SIGN, *(str + pos)))
	{
		ft_memmove(str + pos + 2, str + pos + 1, len - pos - 1);
		*(str + pos + 1) = '1';
		return (1);
	}
	else
	{
		if (*(str + pos) == CHR_EXP_A)
			return (prf_rounddigit_a_up(str, pos - 1, len));
		*(str + pos) = prf_hexdigitadd(*(str + pos), 1);
		if (*(str + pos) == '0')
			return (prf_rounddigit_a_up(str, pos - 1, len));
	}
	return (0);
}

static int	prf_rounddigit_a_down(char *str, ssize_t pos, ssize_t len)
{
	if (pos < 0 || ft_strchr(CHRS_SIGN, *(str + pos)))
	{
		ft_memmove(str + pos + 1, str + pos + 2, len - pos - 1);
		return (-1);
	}
	else
	{
		if (*(str + pos) == CHR_EXP_A)
			return (prf_rounddigit_a_up(str, pos - 1, len));
		*(str + pos) = prf_hexdigitadd(*(str + pos), -1);
		if (*(str + pos) == 'f')
			return (prf_rounddigit_a_up(str, pos - 1, len));
	}
	return (0);
}

static char	*prf_rounddigit_a_expdown(char *str, t_flen *len)
{
	ssize_t	pos_e;

	pos_e = len->exp - 1;
	len->pt = prf_strnchr(str, CHR_POINT, len->sig);
	if (len->pt > 1 && prf_isxdigit1f(*(str + len->pt - 2)))
	{
		*(str + len->pt) = *(str + len->pt - 1);
		*(str + len->pt - 1) = CHR_POINT;
		*(str + len->org - len->exp + pos_e) \
			= prf_hexdigitadd(*(str + len->org - len->exp + pos_e), -1);
		if (*(str + len->org - len->exp + pos_e) == 'f')
			prf_rounddigit_a_down(str + len->org - len->exp + 1, \
				pos_e, len->exp);
		len->sig--;
	}
	ft_strlcpy(str + len->sig, str + len->org - len->exp, len->exp + 1);
	return (str);
}

static char	*prf_rounddigit_a_exp(char *str, t_flen *len)
{
	ssize_t	pos_e;

	if (*(str + len->org - len->exp + 1) == CHR_MINUS)
		return (prf_rounddigit_a_expdown(str, len));
	pos_e = len->exp - 1;
	len->pt = prf_strnchr(str, CHR_POINT, len->sig);
	if (len->pt > 1 && prf_isxdigit1f(*(str + len->pt - 2)))
	{
		*(str + len->pt) = *(str + len->pt - 1);
		*(str + len->pt - 1) = CHR_POINT;
		*(str + len->org - len->exp + pos_e) \
			= prf_hexdigitadd(*(str + len->org - len->exp + pos_e), 1);
		if (*(str + len->org - len->exp + pos_e) == '0')
			prf_rounddigit_a_up(str + len->org - len->exp + 1, pos_e, len->exp);
		len->sig--;
	}
	ft_strlcpy(str + len->sig, str + len->org - len->exp, len->exp + 1);
	return (str);
}

char	*prf_rounddigit_a_fill(char *str, t_conv *conv, t_flen *len)
{
	char	*str_new;
	t_flen2	*len2;
	int		num_lo;

	len2 = prf_rounddigit_a_fill_len(conv, len);
	if (len == NULL)
		return (str);
	num_lo = *(str + len->sig);
	str_new = (char *)malloc((len2->new + 1) * sizeof(char));
	if (str_new == NULL)
		return (str);
	ft_strlcpy(str_new, str, len->pt);
	ft_memset(str_new + len->pt - 1, CHR_ZERO, len2->pad);
	ft_strlcpy(str_new + len->pt - 1 + len2->pad, str + len->pt - 1, \
		len->sig - len->pt + 2);
	ft_memset(str_new + len->sig, CHR_ZERO, len2->fill);
	ft_strlcpy(str_new + len2->new - len->exp, str + len->org - len->exp, \
		len->exp + 1);
	if ('8' <= num_lo && ft_isxdigit(num_lo) \
		&& prf_rounddigit_a_up(str_new, len->sig - 1, len2->new))
		str_new = prf_rounddigit_a_exp(str_new, len);
	free(len2);
	free(str);
	return (str_new);
}
