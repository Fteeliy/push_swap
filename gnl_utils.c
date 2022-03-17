/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:13:10 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:36:32 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if ((char)c == '\0')
		return ((char *)s);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strcpy(char *str, char *leftover)
{
	int	i;

	i = 0;
	while (leftover[i] != '\0')
	{
		str[i] = leftover[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcat(char *str, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (buf[j] != '\0')
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin(char *leftover, char *buf)
{
	char	*str;
	size_t	str_len;

	if (!leftover)
	{
		leftover = (char *)malloc(sizeof(char) * 1);
		leftover[0] = '\0';
	}
	if (!leftover || !buf)
		return (NULL);
	str_len = ft_strlen_gnl(leftover) + ft_strlen_gnl(buf) + 1;
	str = (char *)malloc(sizeof(char) * str_len);
	if (!str)
		return (NULL);
	if (leftover)
		ft_strcpy(str, leftover);
	ft_strcat(str, buf);
	free(leftover);
	return (str);
}
