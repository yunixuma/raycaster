/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_setconv_wandp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/14 21:49:34 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	prf_setconv_precision(const char **str, va_list *ap, t_conv **conv)
{
	int	precision;

	if (*(++*str) == CHR_REF)
		precision = va_arg(*ap, int);
	else
	{
		if (ft_strchr(CHRS_SIGN, **str) == NULL)
			precision = ft_atoi(*str);
		else
			precision = 0;
		while (ft_isdigit(*(*str + 1)))
			(*str)++;
	}
	if (precision < 0)
	{
		if (!ft_hasflag((*conv)->type, TFLAG_C))
			(*conv)->flag &= ~FLAG_PRECISION;
	}
	else
		(*conv)->precision = precision;
}

static void	prf_setconv_width(const char **str, va_list *ap, t_conv **conv)
{
	int			width_new;

	width_new = 0;
	if (ft_isdigit(**str))
	{
		width_new = ft_atoi(*str);
		while (ft_isdigit(*(*str + 1)))
			(*str)++;
	}
	else
		width_new = va_arg(*ap, int);
	if (width_new < 0)
	{
		(*conv)->flag |= FLAG_LEFT;
		(*conv)->width = -width_new;
	}
	else if (width_new > 0)
		(*conv)->width = width_new;
}

void	prf_setconv_wandp(const char *str, va_list *ap, t_conv **conv)
{
	const char	*str_end;

	(*conv)->width = 0;
	(*conv)->precision = 0;
	str_end = str - 1 + (*conv)->len;
	while (str < str_end)
	{
		if (*str == CHR_POINT)
			prf_setconv_precision(&str, &*ap, &(*conv));
		else if (ft_isdigit(*str) || *str == CHR_REF)
			prf_setconv_width(&str, &*ap, &(*conv));
		str++;
	}
	if (!ft_hasflag((*conv)->flag, FLAG_PRECISION))
	{
		if (ft_hasflag((*conv)->type, TFLAG_DBL))
			(*conv)->precision = PRECISION_F;
		else
			(*conv)->precision = 0;
	}
}
