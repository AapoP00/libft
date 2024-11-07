/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:30:19 by apuisto           #+#    #+#             */
/*   Updated: 2024/11/07 10:30:25 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
