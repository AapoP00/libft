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

	pos = 0;
	pos2 = 0;
	if (s <= 0)
		return (ft_strlen(src));
	while (dest[pos] && pos < s)
		pos++;
	while (src[pos2] && (pos + pos2 + 1) < s)
	{
		dest[pos + pos2] = src[pos2];
		pos2++;
	}
	if (pos < s)
		dest[pos + pos2] = '\0';
	return (pos + ft_strlen(src));
}
