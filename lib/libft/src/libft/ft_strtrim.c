/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/01/17 02:17:15 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_len(char const *s1, char const *set)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = len_s1;
	while (i < len_s1 && ft_strchr(set, *(s1 + i)) != NULL)
	{
		len_s2--;
		i++;
	}
	len_s1 -= 1;
	while (len_s1 > 0 && len_s2 > 0 && ft_strchr(set, *(s1 + len_s1)) != NULL)
	{
		len_s2--;
		len_s1--;
	}
	return (len_s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	len_s2;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	len_s2 = ft_strtrim_len(s1, set);
	s2 = (char *)malloc(len_s2 + 1 * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (ft_strchr(set, *(s1 + i)) != NULL)
		i++;
	ft_strlcpy(s2, s1 + i, len_s2 + 1);
	return (s2);
}
