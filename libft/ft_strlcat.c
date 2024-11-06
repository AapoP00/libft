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
	size_t	len;
	size_t	len2;
	char	*sc;

	pos = 0;
	len = 0;
	len2 = 0;
	pos2 = 0;
	sc = (char *)src;
	while (sc[len])
		len++;
	while (dest[len2])
		len2++;
	pos2 = len2;
	if (len2 < s - 1 && s > 0)
	{
		while (src[pos] && len2 + pos < s - 1)
			dest[pos2++] = sc[pos++];
		dest[pos2] = '\0';
	}
	if (len2 >= s)
		len2 = s;
	return (len + len2);
}
