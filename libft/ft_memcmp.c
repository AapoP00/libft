/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:43:02 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:43:06 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t		nr;
	const char	*sr1;
	const char	*sr2;

	nr = 0;
	sr1 = (const char *)str1;
	sr2 = (const char *)str2;
	while (nr < n)
	{
		if (sr1[nr] != sr2[nr])
			return ((unsigned char)sr1[nr] - (unsigned char)sr2[nr]);
		nr++;
	}
	return (0);
}
