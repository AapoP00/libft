/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:39:57 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:40:04 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t		nu;
	char		*ret;
	const char	*sc;

	sc = src;
	ret = dest;
	nu = 0;
	while (nu < count)
	{
		*ret++ = *sc++;
		nu++;
	}
	return (dest);
}
