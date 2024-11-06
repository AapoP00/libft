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
	int	tmp;
	int	cha;

	cha = 0;
	while (str[cha] != '\0')
	{
		if (str[cha] == c)
			tmp = cha;
		cha++;
	}
	if (tmp != -1)
	{
		return ((char *)str + tmp);
	}
	if (c == '\0')
		return ((char *)str + cha);
	else
		return (0);
}
