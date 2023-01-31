/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:26:41 by ykosaka           #+#    #+#             */
/*   Updated: 2022/01/31 02:00:55 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_ret;

	s_ret = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			s_ret = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	if (s_ret == NULL)
		return (NULL);
	return ((char *)s_ret);
}
