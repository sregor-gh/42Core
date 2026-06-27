/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzenteno <rzenteno@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 22:48:26 by rzenteno          #+#    #+#             */
/*   Updated: 2026/06/26 22:48:46 by rzenteno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_all(char *stash, char *buffer)
{
	free(stash);
	free(buffer);
	return (NULL);
}

char	*read_fd(int fd, char *stash)
{
	char	*buffer;
	char	*aux;
	ssize_t	bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (free_all(stash, buffer));
		buffer[bytes] = '\0';
		aux = ft_strjoin(stash, buffer);
		free(stash);
		if (!aux)
		{
			free(buffer);
			return (NULL);
		}
		stash = aux;
	}
	free(buffer);
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*p;
	char	*aux;

	if (!stash || !*stash)
		return (NULL);
	p = stash;
	while (*p && *p != '\n')
		p++;
	if (*p == '\n')
		p++;
	aux = ft_substr(stash, 0, p - stash);
	if (!aux)
		return (NULL);
	return (aux);
}

static char	*keep_rest(char *stash)
{
	char	*p;
	char	*aux;

	p = stash;
	while (*p && *p != '\n')
		p++;
	if (*p == '\0')
	{
		free(stash);
		return (NULL);
	}
	p++;
	aux = ft_substr(stash, p - stash, ft_strlen(stash) - (p - stash));
	free(stash);
	if (!aux)
		return (NULL);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(1);
		if (!stash[fd])
			return (NULL);
		stash[fd][0] = '\0';
	}
	stash[fd] = read_fd(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = get_line(stash[fd]);
	stash[fd] = keep_rest(stash[fd]);
	return (line);
}
