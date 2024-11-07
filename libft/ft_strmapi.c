/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:32 by apuisto           #+#    #+#             */
/*   Updated: 2024/11/07 14:42:33 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	pos;
	size_t	len;
	char	*ret;

	pos = 0;
	len = ft_strlen(s);
	if (s == 0 || f == 0)
		return (0);
	ret = (char *)malloc(sizeof(*s) * len + 1);
	if (!ret)
		return (0);
	while (pos < len)
	{
		ret[pos] = (f)(pos, s[pos]);
		pos++;
	}
	ret[pos] = 0;
	return (ret);
}
