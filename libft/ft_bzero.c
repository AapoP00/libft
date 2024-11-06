/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:39:28 by apuisto           #+#    #+#             */
/*   Updated: 2024/10/28 16:39:30 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t co)
{
	size_t		nu;
	char		*dest;

	nu = 0;
	dest = str;
	while (nu < co)
	{
		dest[nu] = '\0';
		nu++;
	}
	return (str);
}
