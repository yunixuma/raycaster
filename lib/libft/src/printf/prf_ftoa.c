/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_ftoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/12 16:43:58 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prf_ftoa_int(long double nb)
{
	char		*str;
	char		*str_sign;
	char		*str_tmp;
	long double	nb_tmp;

	str = prf_chrtostr('\0');
	if (nb < 0)
	{
		str_sign = STR_MINUS;
		nb = -nb;
	}
	else
		str_sign = STR_EMPTY;
	while (nb >= 1)
	{
		nb_tmp = nb / NUM_LLMAX10;
		str_tmp = ft_lltostr(nb - (long long)nb_tmp * NUM_LLMAX10);
		str = prf_strjoin(str_tmp, str, 3);
		nb = nb_tmp;
	}
	if (*str == '\0')
		*str = '0';
	str = prf_strjoin(str_sign, str, 2);
	return (str);
}

static char	*prf_ftoa_dec(char *str, long double nb, ssize_t pos, ssize_t len)
{
	char	*str_tmp;
	ssize_t	len_tmp;

	while (pos < len)
	{
		nb = (nb - (long long)nb) * NUM_LLMAX10;
		str_tmp = ft_lltostr(nb);
		len_tmp = ft_strlen(str_tmp);
		ft_memset(str + pos, '0', EXP_LLMAX - len_tmp);
		ft_strlcpy(str + pos + EXP_LLMAX - len_tmp, str_tmp, len_tmp + 1);
		free(str_tmp);
		pos += EXP_LLMAX;
	}
	return (str);
}

char	*prf_ftoa(long double nb, int precision)
{
	char	*str;
	char	*str_tmp;
	ssize_t	pos;

	precision += EXP_LLMAX - precision % EXP_LLMAX;
	str_tmp = prf_ftoa_int(nb);
	if (str_tmp == NULL)
		return (NULL);
	pos = ft_strlen(str_tmp);
	str = (char *)malloc((pos + 2 + precision) * sizeof(char));
	if (str == NULL)
	{
		free(str_tmp);
		return (NULL);
	}
	ft_strlcpy(str, str_tmp, pos + 1);
	free(str_tmp);
	*(str + pos++) = CHR_POINT;
	if (nb < 0)
		nb = -nb;
	str = prf_ftoa_dec(str, nb, pos, pos + precision);
	return (str);
}
