/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:26:41 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/14 20:31:23 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_h;
	size_t	len_n;

	if (haystack != NULL || len > 0)
	{
		i = 0;
		len_h = ft_strlen(haystack);
		len_n = ft_strlen(needle);
		if (len_h < len)
			len = len_h;
		while (i + len_n <= len)
		{
			j = 0;
			while (j < len_n && *(haystack + i + j) == *(needle + j))
				j++;
			if (j == len_n)
				return ((char *)haystack + i);
			i++;
		}
	}
	return (NULL);
}
