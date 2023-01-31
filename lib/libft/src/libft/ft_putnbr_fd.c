/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:55:08 by ykosaka           #+#    #+#             */
/*   Updated: 2022/01/07 16:21:05 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	remove_sign(int nb, int fd)
{
	unsigned int	n_abs;
	char			sign;

	sign = '-';
	if (nb < 0)
	{
		write(fd, &sign, 1);
		n_abs = 0 - nb;
	}
	else
		n_abs = nb;
	return (n_abs);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	n_tmp;
	unsigned int	n_abs;
	unsigned int	n_chr;
	unsigned int	scale;

	scale = 1000000000;
	n_abs = remove_sign(nb, fd);
	n_tmp = n_abs;
	while (scale >= 1)
	{
		n_chr = n_tmp / scale;
		n_tmp -= scale * n_chr;
		n_chr += '0';
		if (scale == 1 || n_abs != n_tmp)
			write(fd, &n_chr, 1);
		scale = scale / 10;
	}
}
