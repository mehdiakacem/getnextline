/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makacem <makacem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:50:42 by makacem           #+#    #+#             */
/*   Updated: 2022/01/20 17:56:19 by makacem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!*str)
		return (0);
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

static int	src_size(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t size)
{
	unsigned int	i;
	int				s_size;

	i = 0;
	s_size = src_size((char *)src);
	if (size == 0)
		return (s_size);
	while (*src && (i < size - 1 && (size != 0)))
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	*dst = '\0';
	return (s_size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	int		src_len;
	char	*pdst_lc;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	pdst_lc = dst + dst_len;
	while (src_len > 0 && dstsize - 1 > dst_len)
	{
		*pdst_lc++ = *src++;
		dstsize--;
		src_len--;
	}
	*pdst_lc = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
	ft_strlcat(ptr, s2, len);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ps;
	char	cc;

	cc = (char)c;
	ps = (char *)s;
	while (*ps != '\0')
	{
		if (*ps == cc)
			return (ps);
		ps++;
	}
	if (*ps == cc)
		return (ps);
	return (NULL);
}

void	ft_bzero(void	*s, size_t n)
{
	char	*c;

	c = s;
	while (n > 0)
	{
		*c++ = '\0';
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero((char *)ptr, count * size);
	return ((void *)ptr);
}
