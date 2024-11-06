/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:43:37 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:43:40 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	pos;
	int	ret;

	ret = 0;
	c = 0;
	pos = 1;
	while ((str[c] == ' ') || (str[c] >= 9 && str[c] <= 13))
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
		{
			pos = -1;
		}
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		ret = ret * 10 + (str[c] - '0');
		c++;
	}
	return (ret * pos);
}
