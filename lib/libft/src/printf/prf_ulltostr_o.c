/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_ulltostr_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/12 14:38:17 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_ulltostr_o(unsigned long long n_dec, int bytes)
{
	char	*n_oct;
	int		base;

	base = 8;
	bytes = (bytes * 8 + 2) / 3;
	n_oct = (char *)malloc((bytes + 1) * sizeof(char));
	*(n_oct + bytes) = '\0';
	if (n_dec == 0)
	{
		bytes--;
		*(n_oct + bytes) = '0';
	}
	while (bytes > 0 && n_dec > 0)
	{
		bytes--;
		*(n_oct + bytes) = n_dec % base + '0';
		n_dec = n_dec >> 3;
	}
	ft_strlcpy(n_oct, n_oct + bytes, ft_strlen(n_oct + bytes) + 1);
	return (n_oct);
}
