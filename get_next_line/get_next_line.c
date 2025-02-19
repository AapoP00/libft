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

char	*next_buffer(char *buffer)
{
	char	*nbuffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	nbuffer = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!nbuffer)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	while (buffer[i] != '\0')
		nbuffer[j++] = buffer[i++];
	nbuffer[j] = '\0';
	free(buffer);
	return (nbuffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*buffer_join(char *rbuffer, char *tbuffer)
{
	char	*connected;

	connected = ft_strjoin(rbuffer, tbuffer);
	free(rbuffer);
	return (connected);
}

char	*ft_read_buffer(int fd, char *buffer)
{
	char	*rbuffer;
	int		i;

	rbuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!rbuffer || !buffer)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, rbuffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(rbuffer);
			return (NULL);
		}
		rbuffer[i] = 0;
		buffer = buffer_join(buffer, rbuffer);
		if (ft_strchr(buffer, '\n') || i == 0)
			break ;
	}
	free(rbuffer);
	if (i <= 0 && *buffer == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*rbuffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	buffer[fd] = ft_read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		return (NULL);
	}
	rbuffer = ft_get_line(buffer[fd]);
	buffer[fd] = next_buffer(buffer[fd]);
	return (rbuffer);
}
