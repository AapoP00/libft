/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:40:31 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:40:35 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t byt)
{
	size_t			le;
	unsigned char	*s1;
	const char		*s2;

	s1 = dest;
	s2 = src;
	le = 0;
	if (dest > src)
	{
		le = byt;
		while (le > 0)
		{
			le--;
			s1[le] = s2[le];
		}
	}
	else
	{
		while (le < byt)
		{
			s1[le] = s2[le];
			le++;
		}
	}
	return (s1);
}
