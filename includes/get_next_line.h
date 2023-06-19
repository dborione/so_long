/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dborione <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:51:16 by dborione          #+#    #+#             */
/*   Updated: 2022/12/06 11:57:29 by dborione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>

char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
char	*ft_strrchr(char *str, int c);

#endif
