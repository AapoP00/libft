#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (nmemb * size == 0)
		return (malloc(0));
	ret = (void *)malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}



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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len2;
	size_t	len3;
	size_t	pos;
	char	*ret;

	len2 = 0;
	len3 = 0;
	pos = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	while (s1[len3])
		ret[pos++] = s1[len3++];
	while (s2[len2])
		ret[pos++] = s2[len2++];
	ret[pos] = 0;
	return (ret);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

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
	nbuffer = ft_calloc(ft_strlen(buffer) - i + 2, sizeof(char));
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
	return (connected);
}

char	*ft_read_buffer(int fd, char *buffer)
{
	char	*rbuffer;
	int		i;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	rbuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!rbuffer)
		return (NULL);
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
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(rbuffer);
	if (i == 0 && !*buffer)
	{
		free(buffer);
		return(NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char 		*rbuffer;
	char		*test;

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
	while (i < 4)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}