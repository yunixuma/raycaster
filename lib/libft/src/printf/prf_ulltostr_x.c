/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_ulltostr_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/12 14:38:21 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_ulltostr_x(unsigned long long n_dec, int bytes)
{
	char	*n_hex;
	int		base;

	base = 16;
	bytes *= 2;
	n_hex = (char *)malloc((bytes + 1) * sizeof(char));
	*(n_hex + bytes) = '\0';
	if (n_dec == 0)
	{
		bytes--;
		*(n_hex + bytes) = '0';
	}
	while (bytes > 0 && n_dec > 0)
	{
		bytes--;
		*(n_hex + bytes) = n_dec % base + '0';
		if (*(n_hex + bytes) > '9')
			*(n_hex + bytes) += 'a' - '9' - 1;
		n_dec = n_dec >> 4;
	}
	ft_strlcpy(n_hex, n_hex + bytes, ft_strlen(n_hex + bytes) + 1);
	return (n_hex);
}
