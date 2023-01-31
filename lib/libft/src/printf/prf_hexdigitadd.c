/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_hexdigitadd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/08 20:15:54 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prf_hexdigitadd(int c, int n)
{
	if (('A' <= c && c <= 'F') || ('a' <= c && c <= 'f'))
		n += c - 'a' + 10;
	else
		n += c;
	n &= 0xf;
	if (n >= 0xa)
	{
		if ('A' <= c && c <= 'F')
			c = 'A' + n - 10;
		else
			c = 'a' + n - 10;
	}
	else
		c = '0' + n;
	return (c);
}
