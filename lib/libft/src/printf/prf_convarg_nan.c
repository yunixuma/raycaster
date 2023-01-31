/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg_nan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/15 12:08:08 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_convarg_nan(t_ldbl ldbl, t_conv *conv)
{
	char	*str_sign;

	if (ldbl.sht[0] != 0 || ldbl.sht[1] != 0 || ldbl.sht[2] != 0 \
		|| (ldbl.sht[3] & ~NUM_INF))
		return (ft_strdup(STR_NAN));
	if (ldbl.sht[4] == (NUM_NEG | NUM_NAN))
		str_sign = STR_MINUS;
	else
	{
		if (ft_hasflag(conv->flag, FLAG_PLUS))
			str_sign = STR_PLUS;
		else if (ft_hasflag(conv->flag, FLAG_SPACE))
			str_sign = STR_SPACE;
		else
			str_sign = STR_EMPTY;
	}
	return (prf_strjoin(str_sign, STR_INF, 0));
}
