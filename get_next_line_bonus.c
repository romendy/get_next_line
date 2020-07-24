/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmendy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 10:12:55 by rmendy            #+#    #+#             */
/*   Updated: 2020/07/04 16:37:35 by rmendy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_get_back(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

int		ft_return(char **line, char **str)
{
	char	*tmp;

	if (!str)
		return (-1);
	if (ft_strchr(*str,'\n'))
	{
		tmp = *str;
		*line = ft_strsub(*str,0,ft_get_back(*str));
		*str = ft_strsub(*str, (ft_get_back(*str) + 1), ft_strlen(*str));
		free(tmp);
		return (1);
	}
	else
	{
		tmp = *str;
		*line = ft_strdup(*str);
		*str = NULL;
		free(tmp);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[1024] = NULL;
	char		*buf;
	char		*tmp;
	int			ret;
	int			i;

	if (read(fd,str[fd],0) || !line || BUFFER_SIZE == 0)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((!(ft_strchr(str[fd],'\n'))) && ((ret = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[ret] = '\0';
		tmp = str[fd];
		if (str[fd] == NULL)
			str[fd] = ft_strjoin("",buf);
		else
			str = ft_strjoin(str[fd], buf);
		free(tmp);
	}
	free(buf);
	return (ft_return(line,&str[fd]));
}
int		main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
	char	*line;

	while (get_next_line(fd, &line) > 0)
	{
		printf("ligne:%s\n",line);
		free(line);
	}
	printf("%s\n",line);
	system("leaks a.out");
	return (0);
}
