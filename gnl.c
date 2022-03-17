/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:13:17 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:43:30 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_read_before_n(int fd, char *leftover)
{
	char	*buf;
	int		readed;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!ft_strchr(leftover, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		leftover = ft_strjoin(leftover, buf);
	}
	free(buf);
	return (leftover);
}

char	*ft_line_from_leftover(char *leftover)
{
	int		i;
	char	*line;

	i = 0;
	if (!leftover[i])
		return (NULL);
	while (leftover[i] && leftover[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_newleftover(char *leftover)
{
	int		i;
	int		j;
	char	*newleftover;

	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	if (!leftover[i])
	{
		free(leftover);
		return (NULL);
	}
	newleftover = (char *)malloc(sizeof(char) * \
		(ft_strlen_gnl(leftover) - i + 1));
	if (!newleftover)
		return (NULL);
	i++;
	j = 0;
	while (leftover[i])
		newleftover[j++] = leftover[i++];
	newleftover[j] = '\0';
	free(leftover);
	return (newleftover);
}

char	*gnl(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftover = ft_read_before_n(fd, leftover);
	if (!leftover)
		return (NULL);
	line = ft_line_from_leftover(leftover);
	leftover = ft_newleftover(leftover);
	return (line);
}
