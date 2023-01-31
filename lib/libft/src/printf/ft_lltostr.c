/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/02/12 17:29:24 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_lltostr_getstr(unsigned long long ui, int dig)
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

static int	ft_lltostr_getdigs(unsigned long long ui)
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

char	*ft_lltostr(long long n)
{
	char				*str;
	unsigned long long	ui;
	int					dig;

	if (n < 0)
		ui = -(unsigned long long)(n);
	else
		ui = n;
	dig = (n < 0) + ft_lltostr_getdigs(ui);
	str = ft_lltostr_getstr(ui, dig);
	return (str);
}
