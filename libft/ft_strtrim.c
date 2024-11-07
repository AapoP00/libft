/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:44:39 by apuisto           #+#    #+#             */
/*   Updated: 2024/11/07 10:44:40 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chartest(char a, const char *set)
{
	while (*set)
	{
		if (a == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*str;
	char	*end;
	int		srem;
	int		erem;

	srem = 0;
	erem = 0;
	str = (char *)s1;
	end = str + ft_strlen(str);
	while (*str && ft_chartest(*str, set) == 1)
	{
		str++;
		srem++;
	}
	while (ft_chartest(*(end - 1), set) == 1)
	{
		end--;
		erem++;
	}
	ret = ft_substr(s1, srem, ft_strlen(s1) - (erem + srem));
	return (ret);
}
