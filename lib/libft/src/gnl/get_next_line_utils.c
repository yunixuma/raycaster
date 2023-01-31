/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils copy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/10 19:07:16 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if (dst == NULL)
		return (0);
	i = 0;
	if (src != NULL)
	{
		while (i++ < len && *src != '\0')
			*dst++ = *src++;
		i--;
	}
	*dst = '\0';
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2, ssize_t len_s2, ssize_t *pos_eol)
{
	char	*s3;
	ssize_t	len_s1;
	ssize_t	len_s3;

	len_s1 = ft_strlen(s1);
	if (*pos_eol < 0 && BUFFER_SIZE * -(*pos_eol)-- < BUFFER_MARGIN)
		s3 = s1;
	else
	{
		len_s3 = len_s1 + len_s2 + BUFFER_MARGIN;
		s3 = (char *)malloc((len_s3 + 1) * sizeof(char));
		if (s3 == NULL)
			return (gnl_free(s1));
		gnl_strncpy(s3, s1, len_s1);
		free(s1);
		if (*pos_eol < -1)
			*pos_eol = -1;
	}
	gnl_strncpy(s3 + len_s1, s2, len_s2);
	*(s3 + len_s1 + len_s2) = '\0';
	return (s3);
}

char	*gnl_free(char *chrs)
{
	free(chrs);
	chrs = NULL;
	return (NULL);
}
