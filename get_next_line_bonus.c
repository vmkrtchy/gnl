/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmkrtchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:55:27 by vmkrtchy          #+#    #+#             */
/*   Updated: 2023/02/23 14:56:23 by vmkrtchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	infinity(int fd, char **str)
{
	char	start[BUFFER_SIZE + 1];
	char	*tmp;
	int		read_size;

	while (1)
	{
		read_size = read(fd, start, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(*str);
			str = NULL;
			return ;
		}
		start[read_size] = 0;
		if (*str)
		{
			tmp = ft_strjoin(*str, start);
			free(*str);
			*str = tmp;
		}
		else
			*str = ft_strdup(start);
		if (ft_strchr(*str, '\n') != -1 || read_size == 0)
			break ;
	}
}

void	f(char **s, char **str, int i)
{
	char	*tmp;

	*s = ft_substr(*str, 0, i + 1);
	tmp = ft_substr(*str, i + 1, ft_strlen(*str) - i - 1);
	free(*str);
	*str = tmp;
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*str[OPEN_MAX];
	int			i;

	infinity(fd, &str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	i = ft_strchr(str[fd], '\n');
	if (i != -1)
	{
		f(&s, &str[fd], i);
		return (s);
	}
	else
	{
		s = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		if (*s != 0)
			return (s);
		free(s);
		return (NULL);
	}
}
// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	char *buff;
// 	int fd;
// 	// long *i;

// 	fd = open("text.txt", O_RDONLY);
// 	/*buff = */
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
//     // get_next_line(fd);
// 	// printf("%s", buff);
// 	// free(buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	free(buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	free(buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	free(buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	free(buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	free(buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	free(buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	free(buff);
// 	buff = get_next_line(fd);
// 	printf("%s", buff);
// 	// free(buff);
// 	// buff = get_next_line(fd);
// 	// printf("%s", buff);
// 	// free(buff);
// 	// buff = get_next_line(fd);
// 	// printf("%s", buff);
// 	// free(buff);
// 	// buff = get_next_line(fd);
// 	// printf("%s", buff);
// 	// free(buff);
// 	// free(buff);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	system ("leaks a.out");
// 	close(fd);
// }
