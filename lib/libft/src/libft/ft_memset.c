/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:12:17 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/01 01:31:52 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	void	*buf_end;

	if (n == 0)
		return (buf);
	buf_end = buf + --n;
	while (buf <= buf_end)
		*(unsigned char *)(buf++) = (unsigned char)ch;
	return (buf_end - n);
}
