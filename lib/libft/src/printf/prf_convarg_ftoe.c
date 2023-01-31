/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_convarg_ftoe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/08 14:54:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prf_convarg_ftoe_getexp(t_fpos *pos)
{
	int		exp;
	char	*s_exp;

	exp = 0;
	if (pos->hi >= 0)
		exp = pos->pt - pos->hi - (pos->hi < pos->pt);
	if (exp < 0)
		exp = -exp;
	s_exp = ft_ulltostr(exp);
	return (s_exp);
}

static t_fpos	*prf_convarg_ftoe_getpos(char *str)
{
	t_fpos	*pos;

	pos = (t_fpos *)malloc(sizeof(t_fpos));
	if (pos == NULL)
		return (NULL);
	pos->hi = -1;
	pos->pt = -1;
	pos->end = 0;
	while (*(str + pos->end) != '\0')
	{
		if (pos->hi < 0 && prf_isdigit19(*(str + pos->end)))
			pos->hi = pos->end;
		else if (*(str + pos->end) == CHR_POINT)
			pos->pt = pos->end;
		pos->end++;
	}
	if (pos->pt == -1)
		pos->pt = pos->end;
	return (pos);
}

static char	*prf_convarg_ftoe_shift(char *str, t_fpos *pos)
{
	if (pos->hi + 1 < pos->pt)
	{
		ft_memmove(str + pos->hi + 2, str + pos->hi + 1, \
			pos->pt - pos->hi - 1);
		*(str + pos->hi + 1) = CHR_POINT;
	}
	else if (pos->pt < pos->hi)
	{
		*(str + pos->pt - 1) = *(str + pos->hi);
		ft_memmove(str + pos->pt + 1, str + pos->hi + 1, \
			pos->end - pos->hi - 1);
		pos->end -= pos->hi - pos->pt;
		*(str + pos->end) = '\0';
	}
	return (str);
}

char	*prf_convarg_ftoe(char *str)
{
	t_fpos	*pos;
	ssize_t	pos_e;
	char	*s_exp;

	pos_e = -7;
	pos = prf_convarg_ftoe_getpos(str);
	if (pos == NULL)
		return (str);
	s_exp = prf_convarg_ftoe_getexp(pos);
	if (ft_strlen(s_exp) < 2)
		s_exp = prf_strjoin(STR_PAD_NUM, s_exp, 2);
	if (pos->hi >= 0)
		str = prf_convarg_ftoe_shift(str, pos);
	*(str + pos->end + pos_e++) = CHR_EXP;
	if (pos->hi < pos->pt)
		*(str + pos->end + pos_e++) = CHR_PLUS;
	else
		*(str + pos->end + pos_e++) = CHR_MINUS;
	ft_strlcpy(str + pos->end + pos_e, s_exp, ft_strlen(s_exp) + 1);
	free(s_exp);
	free (pos);
	return (str);
}
