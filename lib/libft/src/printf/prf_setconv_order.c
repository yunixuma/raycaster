/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_setconv_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/04 15:00:00 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prf_setconv_order(const char *str, ssize_t len)
{
	ssize_t		pos;

	if (str == NULL)
		return (0);
	pos = prf_strrnchr(str, CHR_ORDER, len);
	if (pos == len)
		return (0);
	while (pos > 0 && ft_isdigit(*(str + pos - 1)))
		pos--;
	return (ft_atoi(str + pos));
}
