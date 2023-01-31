/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_strrnchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/03/04 12:08:06 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	prf_strrnchr(const char *str, char ch, ssize_t len)
{
	const char	*str_head;
	const char	*str_end;

	if (str == NULL)
		return (0);
	str_head = str;
	str_end = str + len;
	if (str_end < str)
		str_end = (char *)(uintptr_t)(-1);
	while (*str != ch && str < str_end && *str != '\0')
		str++;
	return (str - str_head);
}
