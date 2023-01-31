/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/01/31 21:54:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_split_setstr(char const *s, char c)
{
	char	*frag;
	size_t	k;
	size_t	len;

	k = 0;
	len = 0;
	while (*(s + len) != c && *(s + len) != '\0')
		len++;
	frag = (char *)malloc((len + 1) * sizeof(char));
	if (frag == NULL)
		return (NULL);
	while (k < len)
	{
		*(frag + k) = *(s + k);
		k++;
	}
	*(frag + len) = '\0';
	return (frag);
}

static void	*ft_split_free(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(arr[i]);
	free(arr);
	return (NULL);
}

static char	**ft_split_getarr(const char *s, char c, size_t size)
{
	char	**arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = (char **)malloc((size + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (i < size)
	{
		if (*(s + j) != c)
		{
			arr[i] = ft_split_setstr(s + j, c);
			if (arr[i] == NULL)
				return (ft_split_free(arr, i));
			j += ft_strlen(arr[i]);
			i++;
		}
		j++;
	}
	arr[i] = NULL;
	return (arr);
}

static size_t	ft_split_arrsize(char const *s, char c)
{
	size_t	left;
	size_t	right;
	size_t	size;

	left = 0;
	right = ft_strlen(s);
	size = 1;
	while (left < right && *(s + left) == c)
		left++;
	if (left == right)
		return (0);
	while (*(s + right - 1) == c)
		right--;
	while (right > left)
	{
		if (*(s + right - 1) == c)
		{
			while (*(s + right - 1) == c)
				right--;
			size++;
		}
		else
			right--;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	size;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
		size = 0;
	else
		size = ft_split_arrsize(s, c);
	arr = ft_split_getarr(s, c, size);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
