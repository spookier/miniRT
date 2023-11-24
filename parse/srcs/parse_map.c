/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:43:32 by yhwang            #+#    #+#             */
/*   Updated: 2023/11/21 19:05:14 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/miniRT_parse.h"

void	convert_line(char **line)
{
	int		i;
	int		len;
	char	*new_line;
	char	*temp;

	i = 0;
	while ((*line)[i] == ' ' || (*line)[i] == '\t')
		i++;
	if (i > 0)
	{
		new_line = ft_substr(*line, i, ft_strlen(*line) - i);
		free(*line);
		*line = new_line;
	}
	len = get_char_idx(*line, '#');
	if (len >= 0)
	{
		temp = ft_substr(*line, 0, len);
		new_line = ft_strjoin(temp, "\n");
		free(temp);
		free(*line);
		*line = new_line;
	}
}

void	finish_gnl(char **line, int fd, int flag)
{
	if (flag)
		err_msg("Map error: invalid character exists");
	free(*line);
	while (1)
	{
		*line = get_next_line(fd);
		if (*line == NULL)
			break ;
		free(*line);
	}
	close(fd);
}

int	parse_map(t_scene *scene, char *argv)
{
	int		fd;
	int		flag;
	char	*line;

	line = NULL;
	flag = 0;
	fd = open(argv, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		convert_line(&line);
		if (*line == '\n')
		{
			free(line);
			continue ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (check_id(scene, line, &flag))
			return (finish_gnl(&line, fd, flag), 1);
		free(line);
	}
	return (close(fd), 0);
}
