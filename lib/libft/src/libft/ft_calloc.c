/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:12:17 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/16 19:19:00 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	prod;

	if (count == 0 || size == 0)
		prod = 1;
	else
	{
		prod = size * count;
		if (prod / size < count)
			prod = (size_t)(-1);
	}
	ptr = malloc(prod);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, prod);
	return (ptr);
}
