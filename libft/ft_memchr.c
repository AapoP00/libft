/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:42:47 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:42:50 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char	*sr;
	size_t		src;

	src = 0;
	sr = (const char *)str;
	while (src < n)
	{
		if (*sr == c)
			return ((void *)sr);
		src++;
		sr++;
	}
	return (0);
}
