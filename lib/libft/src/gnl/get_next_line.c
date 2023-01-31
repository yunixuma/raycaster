/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:06:09 by ykosaka           #+#    #+#             */
/*   Updated: 2022/01/24 22:15:49 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	gnl_checkeol(const char *str, ssize_t len, ssize_t pos_eol)
{
	ssize_t	i;

	if (len == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (*(str + i) == '\n')
			return (i);
		i++;
	}
	return (pos_eol);
}

static char	*gnl_read(int fd, char *buf)
{
	ssize_t	len_read;
	ssize_t	len_toread;

	if (*buf == '\0')
	{
		len_read = 0;
		len_toread = BUFFER_SIZE;
		while (len_toread > INT_MAX)
		{
			len_toread = read(fd, buf + len_read, INT_MAX);
			if (len_toread < 0)
				return (gnl_free(buf));
			len_read += len_toread;
			if (len_toread < INT_MAX)
				len_toread = 0;
			else
				len_toread = BUFFER_SIZE - len_read;
		}
		len_toread = read(fd, buf + len_read, len_toread);
		if (len_toread < 0)
			return (gnl_free(buf));
		len_read += len_toread;
		*(buf + len_read) = '\0';
	}
	return (buf);
}

static char	*gnl_cache(char *str)
{
	static char	cache[BUFFER_SIZE];
	size_t		len;

	if (str == NULL)
		return (cache);
	len = gnl_strncpy(cache, str, (size_t)(-1));
	if (len < BUFFER_SIZE)
		*(cache + len) = '\0';
	free(str);
	return (NULL);
}

static char	*gnl_getline(char *line, int fd)
{
	char	*buf;
	ssize_t	len_buf;
	ssize_t	pos_eol;

	buf = (char *)malloc(((ssize_t)BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (gnl_free(line));
	pos_eol = -1;
	gnl_strncpy(buf, gnl_cache(NULL), BUFFER_SIZE);
	while (pos_eol < 0)
	{
		buf = gnl_read(fd, buf);
		if (buf == NULL)
			return (gnl_free(line));
		len_buf = ft_strlen(buf);
		pos_eol = gnl_checkeol(buf, len_buf, pos_eol);
		if (pos_eol >= 0)
			len_buf = pos_eol + 1;
		line = gnl_strjoin(line, buf, len_buf, &pos_eol);
		if (line == NULL)
			return (gnl_free(buf));
		gnl_strncpy(buf, buf + len_buf, ft_strlen(buf) - len_buf + 1);
	}
	gnl_cache(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	errno = 0;
	if (fd < 0)
	{
		errno = EBADF;
		return (NULL);
	}
	else if (BUFFER_SIZE <= 0)
	{
		errno = EINVAL;
		return (NULL);
	}
	line = (char *)malloc((BUFFER_MARGIN + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	*line = '\0';
	line = gnl_getline(line, fd);
	if (ft_strlen(line) == 0)
		return (gnl_free(line));
	return (line);
}
