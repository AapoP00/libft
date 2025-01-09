/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:07:57 by apuisto           #+#    #+#             */
/*   Updated: 2024/12/10 14:07:59 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (nmemb * size == 0)
		return (malloc(0));
	ret = (void *)malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}



char	*ft_strchr(const char *str, int chr)
{
	while (*str != '\0')
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (chr == '\0')
		return ((char *)str);
	return (0);
}

void	*ft_bzero(void *str, size_t co)
{
	size_t		nu;
	char		*dest;

	nu = 0;
	dest = str;
	while (nu < co)
	{
		dest[nu] = '\0';
		nu++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len2;
	size_t	len3;
	size_t	pos;
	char	*ret;

	len2 = 0;
	len3 = 0;
	pos = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (s1[len3])
		ret[pos++] = s1[len3++];
	while (s2[len2])
		ret[pos++] = s2[len2++];
	ret[pos] = 0;
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}