/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/12 02:34:32 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prf_convarg_4(t_conv *conv, va_list *args)
{
	char	*str_put;

	str_put = NULL;
	if (ft_hasflag(conv->type, TYPE_C))
	{
		if ((conv->type & TMASK_LEN) == sizeof(wint_t))
			str_put = (char *)prf_wchrtostr(va_arg(*args, wint_t));
		else
			str_put = prf_chrtostr(va_arg(*args, int));
	}
	else if (ft_hasflag(conv->type, TYPE_S))
	{
		if ((conv->type & TMASK_LEN) == sizeof(wint_t))
			str_put = (char *)prf_convarg_ws(va_arg(*args, wchar_t *), conv);
		else
			str_put = prf_convarg_s(va_arg(*args, char *), conv);
	}
	else if (ft_hasflag(conv->type, TYPE_D))
		str_put = prf_convarg_i(va_arg(*args, int), conv);
	else if (ft_hasflag(conv->type, TFLAG_UI))
		str_put = prf_convarg_ui(va_arg(*args, unsigned int), conv);
	return (str_put);
}

static char	*prf_convarg_8(t_conv *conv, va_list *args)
{
	char	*str_put;

	str_put = NULL;
	if (ft_hasflag(conv->type, TFLAG_LL))
		str_put = prf_convarg_i(va_arg(*args, long long), conv);
	else if (ft_hasflag(conv->type, TFLAG_ULL))
		str_put = prf_convarg_ui(va_arg(*args, unsigned long long), conv);
	else if (ft_hasflag(conv->type, TFLAG_DBL))
	{
		if ((conv->type & TMASK_LEN) == sizeof(long double))
			str_put = prf_convarg_dbl(va_arg(*args, long double), conv);
		else
			str_put = prf_convarg_dbl((long double)va_arg(*args, double), conv);
	}
	return (str_put);
}

char	*prf_convarg(t_conv *conv, va_list *args, ssize_t ret_tmp)
{
	char	*str_put;

	str_put = NULL;
	if (ft_hasflag(conv->type, TYPE_LITERAL))
		str_put = prf_chrtostr(conv->type & TMASK_LEN);
	else if (ft_hasflag(conv->type, TYPE_P))
		str_put = prf_convarg_p(va_arg(*args, unsigned long long), conv);
	else if (ft_hasflag(conv->type, TYPE_N))
		prf_getpresentret(va_arg(*args, void *), ret_tmp);
	else if ((conv->type & TMASK_LEN) > 4)
		str_put = prf_convarg_8(conv, &*args);
	else if (conv->type != 0)
		str_put = prf_convarg_4(conv, &*args);
	return (str_put);
}
