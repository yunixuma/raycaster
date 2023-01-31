/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 20:13:53 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/10 20:47:49 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	void	*dst_end;

	if (dst == NULL || src == NULL || n == 0)
		return (dst);
	dst_end = dst + --n;
	if (dst < src)
	{
		while (dst <= dst_end)
			*(unsigned char *)(dst++) = *(unsigned char *)(src++);
		return (dst_end - n);
	}
	else
	{
		src += n;
		while (dst <= dst_end)
			*(unsigned char *)(dst_end--) = *(unsigned char *)(src--);
	}
	return (dst);
}
