/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:42:08 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:42:12 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	signed int		len;
	unsigned char	found;

	len = ft_strlen(str);
	found = (char)c;
	while (len >= 0)
	{
		if (str[len] == found)
			return ((char *) &str[len]);
		len--;
	}
	return (NULL);
}
