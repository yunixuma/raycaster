/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_putstrn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:19:03 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/04 01:58:56 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	prf_putwchr(int fd, t_wchr wchr)
{
	ssize_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (i < sizeof(wchar_t))
	{
		if (wchr.chr[i] != '\0')
			ret += write(fd, &wchr.chr[i], 1);
		i++;
	}
	return (ret);
}

static ssize_t	prf_putwstrn(int fd, const wchar_t *s, ssize_t len)
{
	t_wchr	wchr;
	ssize_t	ret;

	ret = 0;
	if (s == NULL)
		return (prf_putstr(fd, STR_NULL));
	while (len > 0 && *s != '\0')
	{
		wchr.wchr = *s;
		ret += prf_putwchr(fd, wchr);
		s++;
		len--;
	}
	return (ret);
}

ssize_t	prf_putstrn(int fd, const char *s, ssize_t len, t_conv *conv)
{
	ssize_t	ret;

	if (len < 0)
	{
		errno = EINVAL;
		return (0);
	}
	if (conv != NULL && ft_hasflag(conv->type, TFLAG_C) \
		&& (conv->type & TMASK_LEN) == sizeof(wchar_t))
		return (prf_putwstrn(fd, (wchar_t *)s, len));
	ret = 0;
	if (s == NULL)
		return (prf_putstr(fd, STR_NULL));
	while (len > INT_MAX)
	{
		ret += write(fd, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
	}
	ret += write(fd, s, len);
	return (ret);
}
