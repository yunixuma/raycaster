/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:26:41 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/16 13:03:07 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		dif;

	if (n == 0 && (s1 == NULL || s2 == NULL))
		return (0);
	dif = 0;
	i = 0;
	while (dif == 0 && i < n && (*(s1 + i) != '\0' || *(s2 + i) != '\0'))
	{
		dif = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
		i++;
	}
	return (dif);
}
