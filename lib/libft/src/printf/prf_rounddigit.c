/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_rounddigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/08 20:33:51 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prf_rounddigit_up(char *str, ssize_t pos, ssize_t len)
{
	if (pos < 0 || ft_strchr(CHRS_SIGN, *(str + pos)))
	{
		ft_memmove(str + pos + 2, str + pos + 1, len - pos - 1);
		*(str + pos + 1) = '1';
	}
	else if (prf_isdigit19(*(str + pos) + 1))
		*(str + pos) += 1;
	else
	{
		if (*(str + pos) == '9')
			*(str + pos) = '0';
		prf_rounddigit_up(str, pos - 1, len);
	}
	return ;
}

static void	prf_rounddigit_down(char *str, ssize_t pos, ssize_t len)
{
	if (pos < 0 || ft_strchr(CHRS_SIGN, *(str + pos)))
		ft_memmove(str + pos + 1, str + pos + 2, len - pos - 1);
	else if (prf_isdigit19(*(str + pos)))
		*(str + pos) -= 1;
	else
	{
		if (*(str + pos) == '0')
			*(str + pos) = '9';
		prf_rounddigit_down(str, pos - 1, len);
	}
	return ;
}

static char	*prf_rounddigit_expdown(char *str, t_flen *len)
{
	ssize_t	pos_e;

	pos_e = len->exp - 1;
	len->pt = prf_strnchr(str, CHR_POINT, len->sig);
	if (len->pt > 1 && ft_isdigit(*(str + len->pt - 2)))
	{
		*(str + len->pt) = *(str + len->pt - 1);
		*(str + len->pt - 1) = CHR_POINT;
		if (*(str + len->org - len->exp + pos_e) > '0')
			*(str + len->org - len->exp + pos_e) -= 1;
		else
		{
			*(str + len->org - len->exp + pos_e) = '9';
			*(str + len->org - len->exp + --pos_e) -= 1;
			prf_rounddigit_down(str + len->org - len->exp + 1, pos_e, len->exp);
		}
		len->sig--;
	}
	ft_strlcpy(str + len->sig, str + len->org - len->exp, len->exp + 1);
	return (str);
}

static char	*prf_rounddigit_exp(char *str, t_flen *len)
{
	ssize_t	pos_e;

	if (*(str + len->org - len->exp + 1) == CHR_MINUS)
		return (prf_rounddigit_expdown(str, len));
	pos_e = len->exp - 1;
	len->pt = prf_strnchr(str, CHR_POINT, len->sig);
	if (len->pt > 1 && ft_isdigit(*(str + len->pt - 2)))
	{
		*(str + len->pt) = *(str + len->pt - 1);
		*(str + len->pt - 1) = CHR_POINT;
		if (*(str + len->org - len->exp + pos_e) < '9')
			*(str + len->org - len->exp + pos_e) += 1;
		else
		{
			*(str + len->org - len->exp + pos_e) = '0';
			*(str + len->org - len->exp + --pos_e) += 1;
			prf_rounddigit_up(str + len->org - len->exp + 1, pos_e, len->exp);
		}
		len->sig--;
	}
	ft_strlcpy(str + len->sig, str + len->org - len->exp, len->exp + 1);
	return (str);
}

char	*prf_rounddigit(char *str, t_conv *conv)
{
	t_flen	*len;

	len = prf_rounddigit_getlen(str, conv);
	if (len == NULL)
		return (str);
	if ('5' <= *(str + len->sig) && *(str + len->sig) <= '9')
	{
		prf_rounddigit_up(str, len->sig - 1, len->sig);
		len->pt = prf_strnchr(str, CHR_POINT, len->sig);
		len->sig = len->pt + conv->precision + 1;
	}
	if (len->exp)
		prf_rounddigit_exp(str, len);
	if (*(str + len->sig - 1) == CHR_POINT \
		&& !ft_hasflag(conv->flag, FLAG_ALT))
	{
		ft_strlcpy(str + len->sig - 1, str + len->sig, len->exp + 1);
		len->sig--;
	}
	else
		*(str + len->sig + len->exp) = '\0';
	str = prf_rounddigit_fill(str, conv, len->sig + len->exp);
	free (len);
	return (str);
}
