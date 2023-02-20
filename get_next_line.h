/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:24:24 by vmkrtchy          #+#    #+#             */
/*   Updated: 2023/02/15 16:07:52 by vmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char    *get_next_line(int fd);
int	    ft_strchr(char *s, int c);
int	    ft_strlen(char *s);
char	*ft_substr(char *s, int start, int len);
int	ft_strlcpy(char *dst, char *src, int dstsize);

#endif
