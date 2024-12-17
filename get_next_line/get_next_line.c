/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuisto <apuisto@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:07:36 by apuisto           #+#    #+#             */
/*   Updated: 2024/12/10 14:07:39 by apuisto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_get_line(char *pos)
{
	int		i;
	char	*ret;

	while (pos[i] && pos[i] != '\n')
	i++;
	ret = ft_calloc(i + 2, sizeof(char));
	ret[i + 1] = '\0';
	i = 0;
	while (pos[i] && pos[i] != '\n')
	{
		ret[i] = pos[i];
		i++;
	}
	if (pos[i] == '\n')
		ret[i] = '\n';
	return (ret);


}

char	*get_next_line(int fd)
{

}