/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:16:19 by daniah            #+#    #+#             */
/*   Updated: 2025/03/09 14:15:45 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *buffer)
{
	char	*temp;
	int		r;

	if (!buffer)
		buffer = get_calloc(BUFFER_SIZE + 1, sizeof(char));
	temp = get_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	r = read(fd, temp, BUFFER_SIZE);
	buffer = ft_read_loop(fd, buffer, temp, r);
	free(temp);
	if (r == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_read_loop(int fd, char *buffer, char *temp, int r)
{
	while (r > 0)
	{
		temp[r] = '\0';
		buffer = get_strjoin(buffer, temp);
		if (!buffer)
		{
			free(temp);
			return (NULL);
		}
		if (get_strchr(buffer, '\n'))
			break ;
		r = read(fd, temp, BUFFER_SIZE);
	}
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = get_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = get_calloc((get_strlen(buffer) - i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_next(buffer);
	if (buffer && *buffer == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
