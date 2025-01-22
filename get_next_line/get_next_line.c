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
#include <stdio.h>

char	*next_buffer(char *buffer)
{
	char	*nbuffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	nbuffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!nbuffer)
		return (NULL);
	i++;
	while (buffer[i])
		nbuffer[j++] = buffer[i++];
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
	free(tbuffer);
	free(rbuffer);
	return (connected);
}

char	*ft_read_buffer(int fd, char *buffer)
{
	char	*rbuffer;
	int		i;

	if (!buffer)
		buffer = ft_calloc(1, 1);
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
			break;
	}
	if (i <= 0 && *buffer == '\0')
		return(NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char 		*rbuffer;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	rbuffer = ft_get_line(buffer);
	buffer = next_buffer(buffer);
	return (rbuffer);
}

int main()
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	//line = get_next_line(fd);
	//printf("%s", line);
	/*printf("Read lines from commandline untill ctrl+d\n");
	while ((line = get_next_line(STDIN_FILENO)) != NULL){
		printf("%s", line);
		free(line);
	}*/
	i = 0;
	while (i < 7)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}