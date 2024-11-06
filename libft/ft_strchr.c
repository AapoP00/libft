/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:41:51 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:41:54 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	while (*str != '\0')
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (chr == '\0')
		return ((char *)str);
	return (0);
}
