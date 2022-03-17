/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:13:24 by wdwain            #+#    #+#             */
/*   Updated: 2022/03/17 18:05:02 by wdwain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 5

char	*gnl(int fd);
char	*ft_read_before_n(int fd, char *leftover);
char	*ft_line_from_leftover(char *leftover);
char	*ft_newleftover(char *leftover);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin(char *leftover, char *buf);
char	*ft_strcat(char *str, char *buf);
char	*ft_strcpy(char *str, char *leftover);

#endif