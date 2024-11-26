/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrami <hrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:11:08 by hrami             #+#    #+#             */
/*   Updated: 2024/11/26 01:44:56 by hrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*hnadle_eof(char **buffer, char *tmp)
{
	char	*line;
	char	*tmp2;

	tmp2 = *buffer;
	if (*tmp2)
		return (line = ft_strdup(*buffer), free(tmp),
			free(*buffer), *buffer = NULL, line);
	return (free(tmp), free(*buffer), *buffer = NULL, NULL);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (free(s1), NULL);
	if (s1)
		ft_strncpy(result, s1, len1 + 1);
	if (s2)
		ft_strncpy(result + len1, s2, len2 + 1);
	free(s1);
	return (result);
}

ssize_t	read_file(int fd, char *temp, char **buffer, ssize_t *bytes_read)
{
	*bytes_read = read(fd, temp, BUFFER_SIZE);
	if (*bytes_read < 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (-1);
	}
	temp[*bytes_read] = '\0';
	return (*bytes_read);
}

char	*handle_next_line(char **buffer, char *newline_pos)
{
	char	*line;
	char	*new_buffer;

	line = ft_substr(*buffer, 0, newline_pos - *buffer + 1);
	if (!line)
		return (free(*buffer), *buffer = NULL);
	new_buffer = ft_strdup(newline_pos + 1);
	if (!new_buffer)
		return (free(*buffer), free(line), *buffer = NULL);
	free(*buffer);
	*buffer = new_buffer;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	*buffer[10240];
	ssize_t		bytes_read;

	temp = malloc((size_t)BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 || !temp)
		return (free(temp), free(buffer[fd]), buffer[fd] = NULL);
	while (1)
	{
		read_file(fd, temp, &buffer[fd], &bytes_read);
		if (bytes_read < 0)
			return (free(temp), NULL);
		temp[bytes_read] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], temp);
		if (!buffer[fd])
			return (free(temp), NULL);
		if (ft_strchr(buffer[fd], '\n'))
			return (free(temp), handle_next_line
				(&buffer[fd], ft_strchr(buffer[fd], '\n')));
		if (bytes_read == 0)
			return (hnadle_eof(&buffer[fd], temp));
	}
}
