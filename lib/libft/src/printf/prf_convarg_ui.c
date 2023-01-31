/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg_ui.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/16 23:51:47 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prf_convarg_x(unsigned long long nb_u, t_conv *conv)
{
	char	*str;

	if (nb_u == 0 && ft_hasflag(conv->flag, FLAG_PRECISION))
		str = prf_chrtostr('\0');
	else if ((conv->type & TMASK_LEN) > 4)
		str = prf_ulltostr_x(nb_u, sizeof(unsigned int));
	else
		str = prf_ulltostr_x(nb_u, sizeof(unsigned long long));
	if (str == NULL)
		return (NULL);
	str = prf_adjustdigit(str, conv);
	if (nb_u != 0 && ft_hasflag(conv->flag, FLAG_ALT))
		str = prf_strjoin(STR_PRE_X, str, 2);
	if (ft_hasflag(conv->type, TFLAG_CAP))
		prf_strtoupper(str);
	return (str);
}

static char	*prf_convarg_o(unsigned long long nb_u, t_conv *conv)
{
	char	*str;

	if (nb_u == 0 && ft_hasflag(conv->flag, FLAG_PRECISION))
		str = prf_chrtostr('\0');
	else if ((conv->type & TMASK_LEN) > 4)
		str = prf_ulltostr_o(nb_u, sizeof(unsigned int));
	else
		str = prf_ulltostr_o(nb_u, sizeof(unsigned long long));
	if (str == NULL)
		return (NULL);
	if (nb_u != 0 && ft_hasflag(conv->flag, FLAG_ALT))
		str = prf_strjoin(STR_PRE_O, str, 2);
	str = prf_adjustdigit(str, conv);
	return (str);
}

static char	*prf_convarg_u(unsigned long long nb_u, t_conv *conv)
{
	char	*str;

	if (nb_u == 0 && ft_hasflag(conv->flag, FLAG_PRECISION))
		str = prf_chrtostr('\0');
	else
		str = ft_ulltostr(nb_u);
	str = prf_adjustdigit(str, conv);
	return (str);
}

char	*prf_convarg_ui(unsigned long long nb_u, t_conv *conv)
{
	char	*str;

	str = NULL;
	if ((conv->type & TMASK_LEN) == 1)
		nb_u = (unsigned char)nb_u;
	else if ((conv->type & TMASK_LEN) == 2)
		nb_u = (unsigned short)nb_u;
	if (ft_hasflag(conv->type, TFLAG_DEC))
		str = prf_convarg_u(nb_u, conv);
	else if (ft_hasflag(conv->type, TFLAG_OCT))
		str = prf_convarg_o(nb_u, conv);
	else if (ft_hasflag(conv->type, TFLAG_HEX))
		str = prf_convarg_x(nb_u, conv);
	return (str);
}
