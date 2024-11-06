/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:41:06 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:41:09 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dest, const char *src, size_t s)
{
	size_t	pos;
	char	*sc;

	pos = 0;
	sc = (char *)src;
	if (s > 0)
	{
		while (src[pos] && pos < (s - 1))
		{
			dest[pos] = sc[pos];
			pos++;
		}
		dest[pos] = '\0';
	}
	while (src[pos])
		pos++;
	return (pos);
}
