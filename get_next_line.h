/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmendy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:38:49 by rmendy            #+#    #+#             */
/*   Updated: 2020/07/02 17:34:22 by rmendy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

char		*get_line(char *str);
int			ft_return(char **s, char **str);
int			ft_get_back(char *str);
void		ft_bzero(char *str);
void		ft_putstr(char *str);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(char *s);
int			get_next_line(int fd, char **line);
char		*ft_strchr(char *str, int c);
char		*ft_strjoin(char *s1, char *s2);
#endif
