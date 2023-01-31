/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_wchrtostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/17 01:03:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*prf_wchrtostr(wint_t ch)
{
	wchar_t	*str;

	str = (wchar_t *)malloc(2 * sizeof(wchar_t));
	if (str == NULL)
		return (NULL);
	*str = (wchar_t)ch;
	*(str + 1) = '\0';
	return (str);
}
