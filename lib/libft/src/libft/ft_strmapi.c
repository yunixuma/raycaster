/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/28 15:08:06 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	len;
	size_t	i;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		*(s2 + i) = (*f)(i, *(s + i));
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
