/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_setconv_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/07 10:02:31 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prf_setconv_specify_extend(char ch)
{
	if (ch == 'o' || ch == 'O')
		return (TYPE_O);
	else if (ch == 'f' || ch == 'F')
		return (TYPE_F);
	else if (ch == 'e' || ch == 'E')
		return (TYPE_E);
	else if (ch == 'g' || ch == 'G')
		return (TYPE_G);
	else if (ch == 'a' || ch == 'A')
		return (TYPE_A);
	else if (ch == 'n')
		return (TYPE_N);
	return (TYPE_LITERAL | ch);
}

static int	prf_setconv_specify(char ch)
{
	if (ch == CHR_CONV)
		return (TYPE_LITERAL | CHR_CONV);
	else if (ch == 'c' || ch == 'C')
		return (TYPE_C);
	else if (ch == 's' || ch == 'S')
		return (TYPE_S);
	else if (ch == 'd' || ch == 'i' || ch == 'D')
		return (TYPE_D);
	else if (ch == 'u' || ch == 'U')
		return (TYPE_U);
	else if (ch == 'x' || ch == 'X')
		return (TYPE_X);
	else if (ch == 'p')
		return (TYPE_P);
	return (prf_setconv_specify_extend(ch));
}

static int	prf_setconv_size(char ch)
{
	if (ch == CHR_CONV || ch == 'c' || ch == 's')
		return (sizeof(char));
	if (ch == 'C')
		return (sizeof(wint_t));
	if (ch == 'S')
		return (sizeof(wchar_t));
	else if (ch == 'd' || ch == 'i')
		return (sizeof(int));
	else if (ch == 'D')
		return (sizeof(long int));
	else if (ch == 'u' || ch == 'x' || ch == 'X' || ch == 'o')
		return (sizeof(unsigned int));
	else if (ch == 'U' || ch == 'O')
		return (sizeof(unsigned long));
	else if (ch == 'f' || ch == 'F' || ch == 'e' || ch == 'E')
		return (sizeof(double));
	else if (ch == 'g' || ch == 'G' || ch == 'a' || ch == 'A')
		return (sizeof(double));
	return (0);
}

static int	prf_setconv_upper(char ch)
{
	if (ch == 'X' || ch == 'E' || ch == 'F' || ch == 'G' || ch == 'A')
		return (TFLAG_CAP);
	return (0);
}

int	prf_setconv_type(const char *str, ssize_t len_conv)
{
	int	type;
	int	length;

	type = prf_setconv_specify(*(str + len_conv - 1));
	type |= prf_setconv_size(*(str + len_conv - 1));
	type |= prf_setconv_upper(*(str + len_conv - 1));
	if (!ft_hasflag(type, TYPE_LITERAL))
		length = prf_setconv_length(str, len_conv - 1, type);
	else
		length = 0;
	if (length > 0)
	{
		type &= ~TMASK_LEN;
		type |= length;
	}
	return (type);
}
