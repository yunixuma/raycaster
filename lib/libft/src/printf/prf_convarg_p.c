/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/15 11:28:37 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_convarg_p(unsigned long long nb_llu, t_conv *conv)
{
	char	*str;

	if (nb_llu == 0 && ft_hasflag(conv->flag, FLAG_PRECISION))
		str = prf_chrtostr('\0');
	else
		str = prf_ulltostr_x(nb_llu, sizeof(unsigned long long));
	str = prf_adjustdigit(str, conv);
	str = prf_strjoin(STR_PRE_X, str, 2);
	return (str);
}
