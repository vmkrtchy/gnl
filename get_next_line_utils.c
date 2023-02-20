#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_strlen (s1) + 1);
	if (dup == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		len;
	char		*concatenat;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	len = ft_strlen (s1) + ft_strlen (s2) + 1;
	concatenat = malloc (sizeof (char) * len);
	while (s1[i] != '\0')
	{
		concatenat[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		concatenat[i] = s2[j];
		i++;
		j++;
	}
	concatenat[i] = '\0';
	return (concatenat);
}

char	*ft_substr(char *s, int start, int len)
{
	int	    i;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen (s))
		len = ft_strlen(s);
	tmp = malloc(len + 1);
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy (tmp, s + start, len + 1);
	return (tmp);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	arrlen;

	arrlen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (arrlen);
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (arrlen);
}


int ft_strchr(char *s, int c)
{
    int i;

    i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}
