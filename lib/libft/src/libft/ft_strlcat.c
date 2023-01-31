/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:26:41 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/16 13:02:07 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	pos_s;

	len_d = 0;
	pos_s = 0;
	if (dst != NULL || dstsize > 0)
	{
		len_d = ft_strlen(dst);
		while (len_d + pos_s + 1 < dstsize && *(src + pos_s) != '\0')
		{
			*(dst + len_d + pos_s) = *(src + pos_s);
			pos_s++;
		}
		if (dstsize > 0)
			*(dst + len_d + pos_s) = '\0';
		if (dstsize < len_d)
			len_d = dstsize;
	}
	while (*(src + pos_s) != '\0')
		pos_s++;
	return (len_d + pos_s);
}
