/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:21:47 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:21:49 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t co)
{
	size_t		nr;
	char		*dest;

	dest = str;
	nr = 0;
	while (nr < co)
	{
		dest[nr] = ch;
		nr++;
	}
	return (str);
}
