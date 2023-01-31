/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 01:05:28 by ykosaka           #+#    #+#             */
/*   Updated: 2022/11/10 19:06:46 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# elif BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# ifndef BUFFER_MARGIN
#  if BUFFER_SIZE < 1024
#   define BUFFER_MARGIN 1024
#  else
#   define BUFFER_MARGIN 0
#  endif
# elif BUFFER_MARGIN < 0
#  undef BUFFER_MARGIN
#  define BUFFER_MARGIN 0
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
size_t	gnl_strncpy(char *dst, const char *src, size_t len);
char	*gnl_strjoin(char *s1, char *s2, ssize_t len_s2, ssize_t *pos_eol);
char	*gnl_free(char *chrs);

#endif
