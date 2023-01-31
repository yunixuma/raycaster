/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/19 21:30:32 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ulltostr_getstr(unsigned long long ui, int dig)
{
	char				*str;
	unsigned long long	ui_tmp;

	str = (char *)malloc((dig + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str + dig) = '\0';
	if (ui == 0)
		return (ft_memset(str, '0', 1));
	while (ui > 0)
	{
		ui_tmp = ui / 10;
		dig--;
		*(str + dig) = ui - ui_tmp * 10 + '0';
		ui = ui_tmp;
	}
	if (dig > 0)
		*str = '-';
	return (str);
}

static int	ft_ulltostr_getdigs(unsigned long long ui)
{
	int		dig;

	dig = 1;
	while (ui >= 10)
	{
		dig++;
		ui = ui / 10;
	}
	return (dig);
}

char	*ft_ulltostr(unsigned long long ui)
{
	char	*str;
	int		dig;

	dig = ft_ulltostr_getdigs(ui);
	str = ft_ulltostr_getstr(ui, dig);
	return (str);
}
