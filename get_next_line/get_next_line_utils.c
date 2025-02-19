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

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, size * count);
	return (res);
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char		*new_str;
	size_t		i;
	size_t		j;
	size_t		total;

	total = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (total + 1));
	if (!new_str || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_str[i] = s2[j];
		j++;
		i++;
	}
	new_str[total] = 0;
	return (new_str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
