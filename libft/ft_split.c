/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:08:39 by apuisto           #+#    #+#             */
/*   Updated: 2024/11/07 12:08:40 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_failcheck(char **arr, size_t w)
{
	size_t	pos;

	pos = 0;
	while (pos < w)
	{
		free(arr[pos]);
		pos++;
	}
	free(arr);
}

static size_t	ft_wcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (count);
}

static size_t	ft_wlen(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (s[ret] && s[ret] != c)
		ret++;
	return (ret);
}

char	*ft_pickword(const char **arr, char c)
{
	const char	*pos;
	char		*ret;
	size_t		wlen;

	pos = *arr;
	while (*pos && *pos == c)
		pos++;
	wlen = ft_wlen(pos, c);
	ret = (char *)malloc(sizeof(char) + wlen + 1);
	if (!ret)
		return (0);
	ft_strlcpy(ret, pos, wlen + 1);
	pos = pos + wlen;
	*arr = pos;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	size_t	wcount;
	size_t	wrd;
	char	**ret;

	wrd = 0;
	wcount = ft_wcount(s, c);
	ret = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!ret)
		return (0);
	while (wrd < wcount)
	{
		ret[wrd] = ft_pickword(&s, c);
		if (!ret[wrd])
		{
			ft_failcheck(ret, wrd);
			return (0);
		}
		wrd++;
	}
	ret[wrd] = 0;
	return (ret);
}
