/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:41:30 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:41:33 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, const char *src, size_t s)
{
	size_t	pos;
	size_t	pos2;
	char	*sc;

	pos = 0;
	pos2 = 0;
	sc = (char *)src;
	while (dest[pos2])
		pos2++;
	if (s > 0)
	{
		while (src[pos] && pos2 < (s - 1))
		{
			dest[pos2] = sc[pos];
			pos++;
			pos2++;
		}
		dest[pos2] = '\0';
	}
	return (pos2);
}
