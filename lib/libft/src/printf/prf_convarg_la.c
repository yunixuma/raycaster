/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg_la.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/09 01:46:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prf_convarg_la_exp(t_ldbl ldbl)
{
	char	*str_exp;
	int		exp;

	exp = (ldbl.sht[4] & ~NUM_NEG) - NUM_EXCESS;
	if (exp < 0)
		str_exp = prf_strjoin(STR_EXP_A, STR_EMPTY, 0);
	else
		str_exp = prf_strjoin(STR_EXP_A, STR_PLUS, 0);
	str_exp = prf_strjoin(str_exp, ft_lltostr(exp), 3);
	return (str_exp);
}

static char	*prf_convarg_la_sign(t_ldbl ldbl, t_conv *conv)
{
	if (ft_hasflag(ldbl.sht[4], NUM_NEG))
		return (STR_MINUS);
	else
	{
		if (ft_hasflag(conv->flag, FLAG_PLUS))
			return (STR_PLUS);
		else if (ft_hasflag(conv->flag, FLAG_SPACE))
			return (STR_SPACE);
	}
	return (STR_EMPTY);
}

char	*prf_convarg_la(t_ldbl ldbl, t_conv *conv)
{
	char	*str_ret;
	char	*str_exp;
	char	*str_sign;

	str_ret = prf_strjoin(STR_SPACE, \
		prf_ulltostr_x(ldbl.ll[0], sizeof(long long)), 2);
	if (str_ret == NULL)
		return (NULL);
	*str_ret = *(str_ret + 1);
	*(str_ret + 1) = CHR_POINT;
	str_exp = prf_convarg_la_exp(ldbl);
	str_sign = prf_convarg_la_sign(ldbl, conv);
	str_ret = prf_strjoin(STR_PRE_X, str_ret, 2);
	str_ret = prf_strjoin(str_sign, str_ret, 2);
	str_ret = prf_strjoin(str_ret, str_exp, 3);
	if (!ft_hasflag(conv->flag, FLAG_PRECISION))
		conv->precision = LEN_SIG_LA;
	str_ret = prf_rounddigit_a(str_ret, conv);
	return (str_ret);
}
