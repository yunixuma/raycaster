/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_setconv_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/04 16:22:30 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	prf_setconv_haszero(const char *str, ssize_t len)
{
	const char	*str_end;

	str_end = str + len - 1;
	while (str < str_end)
	{
		while (str < str_end && !prf_isdigit19(*str) && *str != CHR_POINT)
		{
			if (*str == CHR_ZERO)
				return (1);
			str++;
		}
		while (ft_isdigit(*str) || *str == CHR_POINT)
			str++;
	}
	return (0);
}

int	prf_setconv_flag(const char *str, ssize_t len)
{
	int		flag;

	flag = 0;
	if (prf_strnchr(str, CHR_LEFT, len) < len)
		flag |= FLAG_LEFT;
	if (prf_setconv_haszero(str, len))
		flag |= FLAG_ZERO;
	if (prf_strnchr(str, CHR_ALT, len) < len)
		flag |= FLAG_ALT;
	if (prf_strnchr(str, CHR_PLUS, len) < len)
		flag |= FLAG_PLUS;
	if (prf_strnchr(str, CHR_SPACE, len) < len)
		flag |= FLAG_SPACE;
	if (prf_strrnchr(str, CHR_PRECISION, len) < len)
		flag |= FLAG_PRECISION;
	return (flag);
}
