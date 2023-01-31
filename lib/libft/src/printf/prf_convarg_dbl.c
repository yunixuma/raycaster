/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg_dbl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/15 12:08:24 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prf_convarg_f(long double nb, t_conv *conv)
{
	char	*str;
	int		precision;

	if (ft_hasflag(conv->type, TYPE_E))
		precision = conv->precision + LEN_DEC_LDBL;
	else
		precision = conv->precision;
	str = prf_ftoa(nb, precision);
	if (nb >= 0)
	{
		if (ft_hasflag(conv->flag, FLAG_PLUS))
			str = prf_strjoin(STR_PLUS, str, 2);
		else if (ft_hasflag(conv->flag, FLAG_SPACE))
			str = prf_strjoin(STR_SPACE, str, 2);
	}
	if (ft_hasflag(conv->type, TYPE_E))
		str = prf_convarg_ftoe(str);
	str = prf_rounddigit(str, conv);
	return (str);
}

static char	*prf_convarg_g_ret(char *str, t_conv *conv, int precision)
{
	conv->precision = precision;
	return (str);
}

static char	*prf_convarg_g(long double nb, t_conv *conv)
{
	char	*str_e;
	char	*str_f;
	int		precision_f;
	int		precision_e;

	precision_f = conv->precision;
	str_e = prf_convarg_f(nb, conv);
	precision_e = conv->precision;
	conv->precision = precision_f;
	conv->type &= ~TFLAG_E;
	str_f = prf_convarg_f(nb, conv);
	precision_f = conv->precision;
	if (str_f == NULL)
		return (prf_convarg_g_ret(str_e, conv, precision_e));
	else if (str_e == NULL)
		return (prf_convarg_g_ret(str_f, conv, precision_f));
	else if (ft_strlen(str_e) <= ft_strlen(str_f))
	{
		free(str_f);
		return (prf_convarg_g_ret(str_e, conv, precision_e));
	}
	free(str_e);
	return (prf_convarg_g_ret(str_f, conv, precision_f));
}

char	*prf_convarg_dbl(long double nb, t_conv *conv)
{
	char	*str;
	t_ldbl	ldbl;

	ldbl.ldbl = nb;
	if ((ldbl.sht[4] & NUM_NAN) == NUM_NAN)
		str = prf_convarg_nan(ldbl, conv);
	else if (ft_hasflag(conv->type, TYPE_A))
	{
		if ((conv->type & TMASK_LEN) == sizeof(long double))
			str = prf_convarg_la(ldbl, conv);
		else
			str = prf_convarg_a((double)nb, conv);
	}
	else if (ft_hasflag(conv->type, TFLAG_G))
		str = prf_convarg_g(nb, conv);
	else
		str = prf_convarg_f(nb, conv);
	if (ft_hasflag(conv->type, TFLAG_CAP))
		prf_strtoupper(str);
	return (str);
}
