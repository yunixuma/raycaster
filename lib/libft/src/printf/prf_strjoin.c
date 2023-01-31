/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/23 14:32:01 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prf_strjoin_free(char **s1, char **s2, int flag_free)
{
	if (flag_free == 3)
	{
		free((void *)*s2);
		*s2 = NULL;
	}
	if ((flag_free & 1) == 1)
		return (*s1);
	if (flag_free == 2)
		return (*s2);
	return (NULL);
}

char	*prf_strjoin(char const *s1, char const *s2, int flag_free)
{
	char	*s3;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (prf_strjoin_free((char **)&s1, (char **)&s2, flag_free));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (s3 == NULL)
		return (prf_strjoin_free((char **)&s1, (char **)&s2, flag_free));
	ft_strlcpy(s3, s1, len_s1 + 1);
	ft_strlcpy(s3 + len_s1, s2, len_s2 + 1);
	if ((flag_free & 1) == 1)
		free((char *)s1);
	if ((flag_free & 2) == 2)
		free((char *)s2);
	s1 = NULL;
	s2 = NULL;
	return (s3);
}
