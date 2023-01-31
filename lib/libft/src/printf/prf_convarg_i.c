/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/16 23:51:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_convarg_i(long long nb, t_conv *conv)
{
	char	*str;

	if ((conv->type & TMASK_LEN) == 1)
		nb = (char)nb;
	else if ((conv->type & TMASK_LEN) == 2)
		nb = (short)nb;
	if (nb == 0 && ft_hasflag(conv->flag, FLAG_PRECISION))
		str = prf_chrtostr('\0');
	else
		str = ft_lltostr(nb);
	if (str == NULL)
		return (NULL);
	if (nb >= 0)
	{
		if (ft_hasflag(conv->flag, FLAG_PLUS))
			str = prf_strjoin(STR_PLUS, str, 2);
		else if (ft_hasflag(conv->flag, FLAG_SPACE))
			str = prf_strjoin(STR_SPACE, str, 2);
	}
	str = prf_adjustdigit(str, conv);
	return (str);
}
