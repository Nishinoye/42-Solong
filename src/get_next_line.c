/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedcarpi <tedcarpi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:00:47 by tedcarpi          #+#    #+#             */
/*   Updated: 2025/03/18 03:51:35 by tedcarpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*read_file(int fd, char *buffer)
{
	char	*temp;
	int		bytesread;

	bytesread = 1;
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		buffer = ft_calloc(1, sizeof(char));
	while (bytesread)
	{
		bytesread = read(fd, temp, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[bytesread] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*autrechose(char *buffer)
{
	char	*res;
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		res[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*after_line(char *buffer)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		res[j++] = buffer[i++];
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = autrechose(buffer);
	buffer = after_line(buffer);
	return (line);
}
