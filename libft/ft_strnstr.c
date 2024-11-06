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
	char		*sr1;

	pos = 0;
	sr1 = (char *)str1;
	pos2 = 0;
	if (str2 == NULL || str2[0] == '\0')
		return (sr1);
	while (sr1[pos] != '\0' && pos < n)
	{
		if (sr1[pos] == str2[0])
		{
			tmp = pos;
			while (sr1[tmp++] == str2[pos2] && sr1[tmp] != '\0' && tmp < n)
				pos2++;
			if (str2[pos2] == '\0')
				return (sr1 + pos);
			pos2 = 0;
		}
		pos++;
	}
	return (0);
}
