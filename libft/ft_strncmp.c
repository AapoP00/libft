/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:42:26 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:42:33 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t nr)
{
	if (nr < 0)
		return (0);
	while (*str1 && (*str1 == *str2) && --nr)
	{
		str1++;
		str2++;
	}
	if (nr == 0)
		return (0);
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
