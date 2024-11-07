/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:54:10 by apuisto           #+#    #+#             */
/*   Updated: 2024/11/06 17:54:12 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			pos;
	char			*ret;

	pos = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ret = (char *)malloc(sizeof(*s) * len + 1);
	if (!ret)
		return (NULL);
	while (s[start] != '\0' && pos < len)
	{
		ret[pos] = s[start];
		pos++;
		start++;
	}
	ret[pos] = 0;
	return (ret);
}
