/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:35:35 by apuisto           #+#    #+#             */
/*   Updated: 2024/11/07 13:35:36 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	char	*digit;
	int		len;

	digit = "0123456789";
	len = ft_numlen(n);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	ret[len] = 0;
	while (n)
	{
		if (n > 0)
			ret[--len] = digit[n % 10];
		else
			ret[--len] = digit[n % 10 * -1];
		n = n / 10;
	}
	return (ret);
}
