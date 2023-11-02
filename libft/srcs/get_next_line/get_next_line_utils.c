/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acostin <acostin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:36:43 by acostin           #+#    #+#             */
/*   Updated: 2023/03/15 22:38:33 by acostin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/get_next_line.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *storage, char *buf)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!storage)
	{
		storage = (char *)malloc(sizeof(char) * 1);
		storage[0] = '\0';
	}
	if (!storage || !buf)
		return (NULL);
	new_str = malloc(sizeof(char) * ((gnl_strlen(storage) + gnl_strlen(buf))
				+ 1));
	if (new_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (storage)
		while (storage[++i] != '\0')
			new_str[i] = storage[i];
	while (buf[j] != '\0')
		new_str[i++] = buf[j++];
	new_str[gnl_strlen(storage) + gnl_strlen(buf)] = '\0';
	free(storage);
	return (new_str);
}

char	*get_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_storage(char *storage)
{
	int		i;
	int		j;
	char	*new_storage;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = (char *)malloc(sizeof(char) * (gnl_strlen(storage) - i + 1));
	if (!storage)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free(storage);
	return (new_storage);
}
