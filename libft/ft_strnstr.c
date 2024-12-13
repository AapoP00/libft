/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:43:22 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:43:25 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t		pos;
	size_t		tmp;
	int			pos2;

	pos = 0;
	pos2 = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[pos] != '\0' && pos < n)
	{
		if (str1[pos] == str2[0])
		{
			tmp = pos;
			while (str1[tmp] == str2[pos2] && str1[tmp] != '\0' && tmp < n)
			{
				tmp++;
				pos2++;
			}
			if (str2[pos2] == '\0')
				return ((char *)str1 + pos);
			pos2 = 0;
		}
		pos++;
	}
	return (0);
}
