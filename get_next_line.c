/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmendy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:36:32 by rmendy            #+#    #+#             */
/*   Updated: 2020/07/02 17:33:51 by rmendy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdoug(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen((char*)s1) + 1))))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}

int		ft_return(char **s, char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!*str)
	{
		*s = ft_strdoug("");
		return (0);
	}
	if (ft_strchr(*str, '\n'))
	{
		tmp = *str;
		*s = ft_strsub(*str, 0, ft_get_back(*str));
		*str = ft_strsub(*str, (ft_get_back(*str) + 1), ft_strlen(*str));
		free(tmp);
		return (1);
	}
	else
	{
		tmp = *str;
		*s = ft_strdoug(*str);
		free(tmp);
		*str = NULL;
	}
	return (0);
}

int		ft_get_back(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char		*str = NULL;
	char			*buf;
	char			*tmp;
	int				ret;
	int				i;

	if (fd < 0 || !line || BUFFER_SIZE == 0)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	while ((!(ft_strchr(str, '\n'))) &&
			((ret = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[ret] = '\0';
		tmp = str;
		if (str == NULL)
			str = ft_strjoin("", buf);
		else
			str = ft_strjoin(str, buf);
		free(tmp);
	}
	free(buf);
	if ((i = ft_return(line, &str)) && i == 1)
		return (1);
	return (0);
}
